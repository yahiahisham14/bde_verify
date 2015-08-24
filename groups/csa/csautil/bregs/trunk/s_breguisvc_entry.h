// s_breguisvc_entry.h       -- GENERATED FILE - DO NOT EDIT --       -*-C++-*-
#ifndef INCLUDED_S_BREGUISVC_ENTRY
#define INCLUDED_S_BREGUISVC_ENTRY

#ifndef INCLUDED_BDES_IDENT
#include <bdes_ident.h>
#endif
BDES_IDENT_RCSID(s_breguisvc_entry_h,"$Id$ $CSID$")
BDES_IDENT_PRAGMA_ONCE

//@PURPOSE: Provide a BREGUISVC service entry point
//
//@CLASSES:
//
//@AUTHOR: Zheng LIN (zlin1@bloomberg.net)
//
//@DESCRIPTION: This component provides entry points to the BREGUISVC
// service.  Two sets of entry point functions are provided: One is defined
// inside the package namespace and is used as the entry point from
// applications with a C++ main (e.g., a service deployed as a process).  The
// other set of entry point functions is defined in the enterprise namespace,
// and is provided explicitly for the purpose of initializing in-process
// services (i.e., baslets deployed in the Big).  This latter set of entry
// point functions provides demangled symbols that facilitate maintenance of
// Big code.

#ifndef INCLUDED_S_BREGUISVC_VERSION
#include <s_breguisvc_version.h>
#endif

#ifndef INCLUDED_S_BREGUISVC_BUILDOPTS
#include <s_breguisvc_buildopts.h>
#endif

#ifndef INCLUDED_BSL_MEMORY
#include <bsl_memory.h>
#endif

#ifndef INCLUDED_STRING
#include <string>
#endif

#ifndef INCLUDED_BSLFWD_BSLMA_ALLOCATOR
#include <bslfwd_bslma_allocator.h>
#endif

namespace BloombergLP {

class bcem_Aggregate;

namespace bassvc { class AggregateRequestRouter; }
namespace bassvc { class ServiceManifest; }

namespace s_breguisvc { class RequestRouter; }
namespace s_breguisvc {

                                // ============
                                // struct Entry
                                // ============

struct Entry {
    // This class provides a namespace for a set of entry points to the
    // BREGUISVC service.  The 'createService' methods are factory methods
    // that return a request router, used to process application-level
    // requests, and a manifest describing the service.  The 'createService'
    // methods take a 'bcem_Aggregate' configuration parameter, used to further
    // configure the service.

    static int createService(
            bsl::shared_ptr<RequestRouter>            *requestRouter,
            bassvc::ServiceManifest                   *manifest,
            const std::string&                         serviceName,
            const bcem_Aggregate&                      configuration,
            bdema_Allocator                           *basicAllocator = 0);
        // Load into the specified 'requestRouter' a pointer to an allocated
        // BREGUISVC 'RequestRouter' object configured with the specified
        // 'serviceName' and 'configuration'.  If the specified 'manifest' is
        // not 0, load into 'manifest' a description of the service.
        // Optionally specify a 'basicAllocator', used to supply memory.  If
        // 'basicAllocator' is 0, the currently installed default allocator is
        // used.  Return 0 on success, and a non-zero value otherwise.

    static int createService(
            bsl::shared_ptr<BuildOpts::RequestRouter> *requestRouter,
            bassvc::ServiceManifest                   *manifest,
            const bcem_Aggregate&                      configuration,
            bdema_Allocator                           *basicAllocator = 0);
        // Load into the specified 'requestRouter' a pointer to an allocated
        // BREGUISVC 'RequestRouter' object configured with the specified
        // 'configuration'.  If the specified 'manifest' is not 0, load into
        // 'manifest' a description of the service.  Optionally specify a
        // 'basicAllocator', used to supply memory.  If 'basicAllocator' is 0,
        // the currently installed default allocator is used.  Return 0 on
        // success, and a non-zero value otherwise.
};

}  // close namespace s_breguisvc

int s_breguisvc_Entry__createService(
        bsl::shared_ptr<bassvc::AggregateRequestRouter> *requestRouter,
        bassvc::ServiceManifest                         *manifest,
        const bcem_Aggregate&                            configuration,
        bdema_Allocator                                 *basicAllocator = 0);
    // Load into the specified 'requestRouter' a pointer to an allocated
    // BREGUISVC 'RequestRouter' object configured with the specified
    // 'configuration' and 'serviceName', used to identify instance-specific
    // metrics and elements of the 'configuration'.  If the specified
    // 'manifest' is not 0, load into 'manifest' a description of the service.
    // Optionally specify a 'basicAllocator', used to supply memory.  If
    // 'basicAllocator' is 0, the currently installed default allocator is
    // used.  Return 0 on success, and a non-zero value otherwise.

}  // close namespace BloombergLP
#endif

// GENERATED BY BLP_BAS_CODEGEN_3.8.4 Wed Apr 22 09:48:00 2015
// ----------------------------------------------------------------------------
// NOTICE:
//      Copyright (C) Bloomberg L.P., 2012
//      All Rights Reserved.
//      Property of Bloomberg L.P. (BLP)
//      This software is made available solely pursuant to the
//      terms of a BLP license agreement which governs its use.
// ------------------------------- END-OF-FILE --------------------------------
