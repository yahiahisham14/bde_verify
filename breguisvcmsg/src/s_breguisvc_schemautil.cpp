// s_breguisvc_schemautil.cpp     *GENERATED FILE - DO NOT EDIT*      -*-C++-*-

#include <bdes_ident.h>
BDES_IDENT_RCSID(s_breguisvc_schemautil_cpp,"$Id$ $CSID$")

#include <s_breguisvc_schemautil.h>

#include <s_breguisvc_schema.h>

#include <bscapi_codecutilraw.h>

namespace BloombergLP {

namespace s_breguisvc {

                              // ----------------                              
                              // class SchemaUtil                              
                              // ----------------                              

int SchemaUtil::encode(
        bsct::ErrorInfo             *errorInfo,
        bsl::streambuf              *result,
        const Request&               object,
        bsct::EncodingType::Value    encoding,
        const bscapi::CodecOptions&  options)
{
    return bscapi::CodecUtilRaw::encode(errorInfo,
                                        result,
                                        object,
                                        encoding,
                                        options);
}

int SchemaUtil::encode(
        bsct::ErrorInfo             *errorInfo,
        bsl::streambuf              *result,
        const Response&              object,
        bsct::EncodingType::Value    encoding,
        const bscapi::CodecOptions&  options)
{
    return bscapi::CodecUtilRaw::encode(errorInfo,
                                        result,
                                        object,
                                        encoding,
                                        options);
}

int SchemaUtil::decode(
        bsct::ErrorInfo             *errorInfo,
        bsl::streambuf              *result,
        Request                     *object,
        bsct::EncodingType::Value    encoding,
        const bscapi::CodecOptions&  options)
{
    return bscapi::CodecUtilRaw::decode(errorInfo,
                                        result,
                                        object,
                                        encoding,
                                        options);
}

int SchemaUtil::decode(
        bsct::ErrorInfo             *errorInfo,
        bsl::streambuf              *result,
        Response                    *object,
        bsct::EncodingType::Value    encoding,
        const bscapi::CodecOptions&  options)
{
    return bscapi::CodecUtilRaw::decode(errorInfo,
                                        result,
                                        object,
                                        encoding,
                                        options);
}

}  // close package namespace
}  // close enterprise namespace

// GENERATED BY BLP_BAS_CODEGEN_3.8.4 Wed Aug 19 13:24:51 2015
// USING bas_codegen.pl --mode msg --bidirectional --serviceInfo breguisvc:64730-1 --destination src config/breguisvc.xsd
// ----------------------------------------------------------------------------
// NOTICE:
//      Copyright (C) Bloomberg L.P., 2015
//      All Rights Reserved.
//      Property of Bloomberg L.P. (BLP)
//      This software is made available solely pursuant to the
//      terms of a BLP license agreement which governs its use.
// ------------------------------- END-OF-FILE --------------------------------
