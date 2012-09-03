// csabbg_allocatornewwithpointer.t.hpp                               -*-C++-*-
// -----------------------------------------------------------------------------
// Copyright 2012 Dietmar Kuehl http://www.dietmar-kuehl.de              
// Distributed under the Boost Software License, Version 1.0. (See file  
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt).     
// -----------------------------------------------------------------------------

#if !defined(INCLUDED_BSLMA_ALLOCATOR)
#define INCLUDED_BSLMA_ALLOCATOR 1
#ident "$Id$"

// -----------------------------------------------------------------------------

#include <new>
#include <unistd.h> //-dk:TODO fix including standard headers!

namespace BloombergLP
{
    struct bslma_Allocator
    {
    };
    
    bslma_Allocator& get_allocator();
}

void* operator new(size_t, BloombergLP::bslma_Allocator&);

// -----------------------------------------------------------------------------

#endif
