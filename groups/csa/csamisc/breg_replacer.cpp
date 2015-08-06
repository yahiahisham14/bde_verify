#include "breg_replacer.h"

#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>
#include <clang/Lex/Lexer.h>
#include <clang/AST/Stmt.h>

#include <csabase_analyser.h>
#include <csabase_debug.h>
#include <csabase_diagnostic_builder.h>
#include <csabase_registercheck.h>
#include <csabase_report.h>
#include <csabase_util.h>
#include <csabase_visitor.h>

#include <set>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace csabase;
using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;

static std::string const check_name("breg-replacer");

namespace {

    struct data {

    };

   
    struct report : Report<data>
    {
        std::vector<std::pair<std::string, boolValue>> bregs;
        std::vector<unsigned> bregLocations;

        int offset;

        report(Analyser& analyser, PPObserver::CallbackType type = PPObserver::e_None);

        void matchBreg(BoundNodes const & nodes);

        void operator()();
        void operator()(SourceLocation where, bool, std::string const& name); 
    };


    report::report(Analyser& analyser, PPObserver::CallbackType type)
        : Report<data>(analyser, type)
    {
        offset = 0;
        std::string csvFile = a.config()->value("breg_file"); 
        
        bregs = readCSV(csvFile);
    }
    

    //matches string initialization as a variable or in an initialization list
    static const internal::DynTypedMatcher& dyn_matchBreg()
    {
        static const internal::DynTypedMatcher& matcher = findAll( functionDecl( hasDescendant( 
                                                             stmt ( findAll (                                                                                                                                                       ifStmt( hasCondition( expr( findAll( 
                                                                    callExpr().bind("call"))))).bind("ifstmt") )))));
        return matcher; 
    }

    void report::operator()()
    {
        MatchFinder finder;
        csabase::OnMatch<report, &report::matchBreg> m(this);
        finder.addDynamicMatcher(dyn_matchBreg(), &m);
        finder.match(*d_analyser.context()->getTranslationUnitDecl(), *d_analyser.context());

        //write locations of breg if stmts
        std::ofstream bregFile;
        bregFile.open(".bregLocs");

        for (auto i : bregLocations) {
            bregFile << i << "\n";
        }

        bregFile.close();
    }

    //replace with actual breg
    static bool getBregValue(std::pair<std::string, boolValue> pair) 
    {
        if (pair.second == defaultValue) {
            //hook database code in here
            return false;
        }
        
        return pair.second;
    } 


    void report::matchBreg(BoundNodes const & nodes)
    {
        clang::CallExpr const * call = nodes.getNodeAs<clang::CallExpr>("call");
        clang::IfStmt const * ifStmt = nodes.getNodeAs<clang::IfStmt>("ifstmt");

        if ( a.manager().isMacroBodyExpansion( call->getLocStart() ) ) {
            auto r = a.manager().getExpansionRange( call->getLocStart() );

            SourceRange expansionRange = SourceRange(r.first, r.second.getLocWithOffset(-1));
            std::string bregName = a.get_source(expansionRange, true).str();

            for (auto e : bregs) {
                if ( call->getDirectCallee() != NULL ) {
                    if ( bregName == (e.first+"__value") ) {
                        SourceLocation end = m.getFileLoc(Lexer::getLocForEndOfToken( call->getLocEnd(), 0, m, a.context()->getLangOpts()));
                        auto callRange = SourceRange(call->getLocStart(), end);

                        std::string replacement = getBregValue(e) ? "true" : "false";

                        a.ReplaceText(callRange, replacement);
                        bregLocations.push_back( ifStmt->getLocStart().getRawEncoding() - offset );

                        //offset of if stmt before and after replacing breg calls 
                        offset += ( callRange.getEnd().getRawEncoding() - expansionRange.getBegin().getRawEncoding() ) - replacement.size();
                    }
                }
            }
        }
    }


    void subscribe(Analyser& analyser, Visitor& visitor, PPObserver& observer) {
        analyser.onTranslationUnitDone += report(analyser);
    }

}  // close anonymous namespace

// -----------------------------------------------------------------------------

static RegisterCheck register_check(check_name, &subscribe);







