// csamisc_cstylecastused.t.cpp                                       -*-C++-*-
// -----------------------------------------------------------------------------
// Copyright 2012 Dietmar Kuehl http://www.dietmar-kuehl.de              
// Distributed under the Boost Software License, Version 1.0. (See file  
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt).     
// -----------------------------------------------------------------------------

#include "csamisc_cstylecastused.t.hpp"
#include <bdes_ident.h>

namespace bde_verify
{
    namespace csamisc
    {
        namespace
        {
            template <class T>
            T* t()
            {
                return (T*)1;
            }
        }

        static char* f()
        {
            t<char>();
            return (char*)1;
        }

        static void g()
        {
            int m = 0;
            (void) m;
        }
    }
}