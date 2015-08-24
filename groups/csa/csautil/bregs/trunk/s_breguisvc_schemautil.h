// s_breguisvc_schemautil.h      *GENERATED FILE - DO NOT EDIT*       -*-C++-*-
#ifndef INCLUDED_S_BREGUISVC_SCHEMAUTIL
#define INCLUDED_S_BREGUISVC_SCHEMAUTIL

#ifndef INCLUDED_BDES_IDENT
#include <bdes_ident.h>
#endif
BDES_IDENT_RCSID(s_breguisvc_schemautil_h,"$Id$ $CSID$")
BDES_IDENT_PRAGMA_ONCE

//@PURPOSE: Provide a server-side codec utility for S_BREGUISVC messages
//
//@CLASSES:
// SchemaUtil: server-side message codec
//
//@AUTHOR: 
//
//@DESCRIPTION: This component provides a server-side codec utility for the
// types declared in the s_breguisvc_schema component.

#ifndef INCLUDED_BSCT_ENCODINGTYPE
#include <bsct_encodingtype.h>
#endif

#ifndef INCLUDED_BSL_IOSFWD
#include <bsl_iosfwd.h>
#endif

namespace BloombergLP {

namespace bscapi { class CodecOptions; }
namespace bsct   { class ErrorInfo;    }

namespace s_breguisvc { class Request;  }
namespace s_breguisvc { class Response; }
namespace s_breguisvc {

                              // ================                              
                              // class SchemaUtil                              
                              // ================                              

class SchemaUtil {
    // This class provides a namespace for a set of server-side utility methods
    // for encoding and decoding message types corresponding to top-level
    // elements of the schema used to render this component.

  public:
    // CLASS METHODS
    static int encode(
            bsct::ErrorInfo             *errorInfo,
            bsl::streambuf              *result,
            const Request&               object,
            bsct::EncodingType::Value    encoding,
            const bscapi::CodecOptions&  options);
        // Encode the specified 'object' into the specified 'stream' using the
        // specified 'encoding' and the specified 'options'.  Return 0 on
        // success, and a non-zero value otherwise.  Load any diagnostics into
        // the specified 'errorInfo'.

    static int encode(
            bsct::ErrorInfo             *errorInfo,
            bsl::streambuf              *result,
            const Response&              object,
            bsct::EncodingType::Value    encoding,
            const bscapi::CodecOptions&  options);
        // Encode the specified 'object' into the specified 'stream' using the
        // specified 'encoding' and the specified 'options'.  Return 0 on
        // success, and a non-zero value otherwise.  Load any diagnostics into
        // the specified 'errorInfo'.

    static int decode(
            bsct::ErrorInfo             *errorInfo,
            bsl::streambuf              *result,
            Request                     *object,
            bsct::EncodingType::Value    encoding,
            const bscapi::CodecOptions&  options);
        // Decode the specified 'stream' into the specified 'object' according
        // to the specified 'encoding' and the specified 'options'.  Return
        // 0 on success, and a non-zero value otherwise.  Load any diagnostics
        // into the specified 'errorInfo'.

    static int decode(
            bsct::ErrorInfo             *errorInfo,
            bsl::streambuf              *result,
            Response                    *object,
            bsct::EncodingType::Value    encoding,
            const bscapi::CodecOptions&  options);
        // Decode the specified 'stream' into the specified 'object' according
        // to the specified 'encoding' and the specified 'options'.  Return
        // 0 on success, and a non-zero value otherwise.  Load any diagnostics
        // into the specified 'errorInfo'.
};

}  // close package namespace
}  // close enterprise namespace
#endif

// GENERATED BY BLP_BAS_CODEGEN_3.8.4 Fri Apr 24 17:04:51 2015
// USING bas_codegen.pl -m msg --bidirectional breguisvc.xsd
// ----------------------------------------------------------------------------
// NOTICE:
//      Copyright (C) Bloomberg L.P., 2015
//      All Rights Reserved.
//      Property of Bloomberg L.P. (BLP)
//      This software is made available solely pursuant to the
//      terms of a BLP license agreement which governs its use.
// ------------------------------- END-OF-FILE --------------------------------
