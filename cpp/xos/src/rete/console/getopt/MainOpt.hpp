///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 8/26/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_CONSOLE_GETOPT_MAINOPT_HPP
#define _RETE_CONSOLE_GETOPT_MAINOPT_HPP

#include "crono/console/getopt/MainOpt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define RETE_CONSOLE_MAIN_METHOD_OPT "method"
#define RETE_CONSOLE_MAIN_METHOD_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_CONSOLE_MAIN_METHOD_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_METHOD_OPTARG ""
#define RETE_CONSOLE_MAIN_METHOD_OPTUSE "XTTP request method (GET)"
#define RETE_CONSOLE_MAIN_METHOD_OPTVAL_S "m:"
#define RETE_CONSOLE_MAIN_METHOD_OPTVAL_C 'm'
#define RETE_CONSOLE_MAIN_METHOD_OPTION \
   {RETE_CONSOLE_MAIN_METHOD_OPT, \
    RETE_CONSOLE_MAIN_METHOD_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_METHOD_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_METHOD_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_ARGUMENTS_OPT "arguments"
#define RETE_CONSOLE_MAIN_ARGUMENTS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_CONSOLE_MAIN_ARGUMENTS_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_ARGUMENTS_OPTARG ""
#define RETE_CONSOLE_MAIN_ARGUMENTS_OPTUSE "XTTP request arguments (/)"
#define RETE_CONSOLE_MAIN_ARGUMENTS_OPTVAL_S "a:"
#define RETE_CONSOLE_MAIN_ARGUMENTS_OPTVAL_C 'a'
#define RETE_CONSOLE_MAIN_ARGUMENTS_OPTION \
   {RETE_CONSOLE_MAIN_ARGUMENTS_OPT, \
    RETE_CONSOLE_MAIN_ARGUMENTS_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_ARGUMENTS_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_ARGUMENTS_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_RESULT_OPT "result"
#define RETE_CONSOLE_MAIN_RESULT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_CONSOLE_MAIN_RESULT_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_RESULT_OPTARG ""
#define RETE_CONSOLE_MAIN_RESULT_OPTUSE "XTTP result code (200)"
#define RETE_CONSOLE_MAIN_RESULT_OPTVAL_S "r:"
#define RETE_CONSOLE_MAIN_RESULT_OPTVAL_C 'r'
#define RETE_CONSOLE_MAIN_RESULT_OPTION \
   {RETE_CONSOLE_MAIN_RESULT_OPT, \
    RETE_CONSOLE_MAIN_RESULT_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_RESULT_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_RESULT_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_REASON_OPT "reason"
#define RETE_CONSOLE_MAIN_REASON_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_CONSOLE_MAIN_REASON_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_REASON_OPTARG ""
#define RETE_CONSOLE_MAIN_REASON_OPTUSE "XTTP result reason (Ok)"
#define RETE_CONSOLE_MAIN_REASON_OPTVAL_S "e:"
#define RETE_CONSOLE_MAIN_REASON_OPTVAL_C 'e'
#define RETE_CONSOLE_MAIN_REASON_OPTION \
   {RETE_CONSOLE_MAIN_REASON_OPT, \
    RETE_CONSOLE_MAIN_REASON_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_REASON_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_REASON_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_PROTOCOL_OPT "protocol"
#define RETE_CONSOLE_MAIN_PROTOCOL_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_CONSOLE_MAIN_PROTOCOL_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_PROTOCOL_OPTARG ""
#define RETE_CONSOLE_MAIN_PROTOCOL_OPTUSE "XTTP protocol (HTTP/1.0)"
#define RETE_CONSOLE_MAIN_PROTOCOL_OPTVAL_S "o:"
#define RETE_CONSOLE_MAIN_PROTOCOL_OPTVAL_C 'o'
#define RETE_CONSOLE_MAIN_PROTOCOL_OPTION \
   {RETE_CONSOLE_MAIN_PROTOCOL_OPT, \
    RETE_CONSOLE_MAIN_PROTOCOL_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_PROTOCOL_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_PROTOCOL_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_CLIENT_OPT "client"
#define RETE_CONSOLE_MAIN_CLIENT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define RETE_CONSOLE_MAIN_CLIENT_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_CLIENT_OPTARG ""
#define RETE_CONSOLE_MAIN_CLIENT_OPTUSE "Run as client"
#define RETE_CONSOLE_MAIN_CLIENT_OPTVAL_S "c"
#define RETE_CONSOLE_MAIN_CLIENT_OPTVAL_C 'c'
#define RETE_CONSOLE_MAIN_CLIENT_OPTION \
   {RETE_CONSOLE_MAIN_CLIENT_OPT, \
    RETE_CONSOLE_MAIN_CLIENT_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_CLIENT_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_CLIENT_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_SERVER_OPT "server"
#define RETE_CONSOLE_MAIN_SERVER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define RETE_CONSOLE_MAIN_SERVER_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_SERVER_OPTARG ""
#define RETE_CONSOLE_MAIN_SERVER_OPTUSE "Run as server"
#define RETE_CONSOLE_MAIN_SERVER_OPTVAL_S "s"
#define RETE_CONSOLE_MAIN_SERVER_OPTVAL_C 's'
#define RETE_CONSOLE_MAIN_SERVER_OPTION \
   {RETE_CONSOLE_MAIN_SERVER_OPT, \
    RETE_CONSOLE_MAIN_SERVER_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_SERVER_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_SERVER_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_SOCKETS_OPT "sockets"
#define RETE_CONSOLE_MAIN_SOCKETS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define RETE_CONSOLE_MAIN_SOCKETS_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_SOCKETS_OPTARG ""
#define RETE_CONSOLE_MAIN_SOCKETS_OPTUSE "Use sockets"
#define RETE_CONSOLE_MAIN_SOCKETS_OPTVAL_S "k"
#define RETE_CONSOLE_MAIN_SOCKETS_OPTVAL_C 'k'
#define RETE_CONSOLE_MAIN_SOCKETS_OPTION \
   {RETE_CONSOLE_MAIN_SOCKETS_OPT, \
    RETE_CONSOLE_MAIN_SOCKETS_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_SOCKETS_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_SOCKETS_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_HOST_OPT "host"
#define RETE_CONSOLE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_CONSOLE_MAIN_HOST_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_HOST_OPTARG "{name | ddd.ddd.ddd.ddd | *}"
#define RETE_CONSOLE_MAIN_HOST_OPTUSE "Host name, address or any"
#define RETE_CONSOLE_MAIN_HOST_OPTVAL_S "h:"
#define RETE_CONSOLE_MAIN_HOST_OPTVAL_C 'h'
#define RETE_CONSOLE_MAIN_HOST_OPTION \
   {RETE_CONSOLE_MAIN_HOST_OPT, \
    RETE_CONSOLE_MAIN_HOST_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_HOST_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_HOST_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_PORT_OPT "port"
#define RETE_CONSOLE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_CONSOLE_MAIN_PORT_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_PORT_OPTARG "{0..2^16-1}"
#define RETE_CONSOLE_MAIN_PORT_OPTUSE "Port number"
#define RETE_CONSOLE_MAIN_PORT_OPTVAL_S "p:"
#define RETE_CONSOLE_MAIN_PORT_OPTVAL_C 'p'
#define RETE_CONSOLE_MAIN_PORT_OPTION \
   {RETE_CONSOLE_MAIN_PORT_OPT, \
    RETE_CONSOLE_MAIN_PORT_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_PORT_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_PORT_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_FAMILY_OPT "family"
#define RETE_CONSOLE_MAIN_FAMILY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_CONSOLE_MAIN_FAMILY_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_FAMILY_OPTARG_IPV4 "(4)ipv4"
#define RETE_CONSOLE_MAIN_FAMILY_OPTARG_IPV6 "(6)ipv6"
#define RETE_CONSOLE_MAIN_FAMILY_OPTARG_LOCAL "(l)local"
#define RETE_CONSOLE_MAIN_FAMILY_OPTARG \
    "{" RETE_CONSOLE_MAIN_FAMILY_OPTARG_IPV4 \
    " | " RETE_CONSOLE_MAIN_FAMILY_OPTARG_IPV6 \
    " | " RETE_CONSOLE_MAIN_FAMILY_OPTARG_LOCAL "}"
#define RETE_CONSOLE_MAIN_FAMILY_OPTUSE "Address family"
#define RETE_CONSOLE_MAIN_FAMILY_OPTVAL_S "f:"
#define RETE_CONSOLE_MAIN_FAMILY_OPTVAL_C 'f'
#define RETE_CONSOLE_MAIN_FAMILY_OPTION \
   {RETE_CONSOLE_MAIN_FAMILY_OPT, \
    RETE_CONSOLE_MAIN_FAMILY_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_FAMILY_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_FAMILY_OPTVAL_C}, \

#define RETE_CONSOLE_MAIN_TRANSPORT_OPT "transport"
#define RETE_CONSOLE_MAIN_TRANSPORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_CONSOLE_MAIN_TRANSPORT_OPTARG_RESULT 0
#define RETE_CONSOLE_MAIN_TRANSPORT_OPTARG_TCP "(t)tcp"
#define RETE_CONSOLE_MAIN_TRANSPORT_OPTARG_UDP "(u)udp"
#define RETE_CONSOLE_MAIN_TRANSPORT_OPTARG \
    "{" RETE_CONSOLE_MAIN_TRANSPORT_OPTARG_TCP \
    " | " RETE_CONSOLE_MAIN_TRANSPORT_OPTARG_UDP "}"
#define RETE_CONSOLE_MAIN_TRANSPORT_OPTUSE ""
#define RETE_CONSOLE_MAIN_TRANSPORT_OPTVAL_S "t:"
#define RETE_CONSOLE_MAIN_TRANSPORT_OPTVAL_C 't'
#define RETE_CONSOLE_MAIN_TRANSPORT_OPTION \
   {RETE_CONSOLE_MAIN_TRANSPORT_OPT, \
    RETE_CONSOLE_MAIN_TRANSPORT_OPTARG_REQUIRED, \
    RETE_CONSOLE_MAIN_TRANSPORT_OPTARG_RESULT, \
    RETE_CONSOLE_MAIN_TRANSPORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define RETE_CONSOLE_MAIN_OPTIONS_CHARS \
    RETE_CONSOLE_MAIN_METHOD_OPTVAL_S \
    RETE_CONSOLE_MAIN_ARGUMENTS_OPTVAL_S \
    RETE_CONSOLE_MAIN_RESULT_OPTVAL_S \
    RETE_CONSOLE_MAIN_REASON_OPTVAL_S \
    RETE_CONSOLE_MAIN_PROTOCOL_OPTVAL_S \
   RETE_CONSOLE_MAIN_CLIENT_OPTVAL_S \
   RETE_CONSOLE_MAIN_SERVER_OPTVAL_S \
   RETE_CONSOLE_MAIN_SOCKETS_OPTVAL_S \
   RETE_CONSOLE_MAIN_HOST_OPTVAL_S \
   RETE_CONSOLE_MAIN_PORT_OPTVAL_S \
   RETE_CONSOLE_MAIN_FAMILY_OPTVAL_S \
   RETE_CONSOLE_MAIN_TRANSPORT_OPTVAL_S \
   CRONO_CONSOLE_MAIN_OPTIONS_CHARS

#define RETE_CONSOLE_MAIN_OPTIONS_OPTIONS \
    RETE_CONSOLE_MAIN_METHOD_OPTION \
    RETE_CONSOLE_MAIN_ARGUMENTS_OPTION \
    RETE_CONSOLE_MAIN_RESULT_OPTION \
    RETE_CONSOLE_MAIN_REASON_OPTION \
    RETE_CONSOLE_MAIN_PROTOCOL_OPTION \
   RETE_CONSOLE_MAIN_CLIENT_OPTION \
   RETE_CONSOLE_MAIN_SERVER_OPTION \
   RETE_CONSOLE_MAIN_SOCKETS_OPTION \
   RETE_CONSOLE_MAIN_HOST_OPTION \
   RETE_CONSOLE_MAIN_PORT_OPTION \
   RETE_CONSOLE_MAIN_FAMILY_OPTION \
   RETE_CONSOLE_MAIN_TRANSPORT_OPTION \
   CRONO_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define RETE_CONSOLE_MAIN_ARGS 0
#define RETE_CONSOLE_MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace rete {
namespace console {
namespace getopt {

typedef crono::console::getopt::MainOpt MainOptImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOptT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainOptImplements>

class _EXPORT_CLASS MainOptT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnClientOption() {}
    virtual void OnServerOption() {}
    virtual void OnSocketsOption() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnMethodOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //    RETE_LOG_DEBUG("optarg = \"" << optarg << "\"...");
        //    if (!(set_Method(optarg))) {
        //        RETE_LOG_ERROR("...failed on set_Method(\"" << optarg << "\")");
        //    }
        //}
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnArgumentsOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //    RETE_LOG_DEBUG("optarg = \"" << optarg << "\"...");
        //    if (!(set_Arguments(optarg))) {
        //        RETE_LOG_ERROR("...failed on set_Arguments(\"" << optarg << "\")");
        //    }
        //}
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnResultOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //    RETE_LOG_DEBUG("optarg = \"" << optarg << "\"...");
        //    if (!(set_Result(optarg))) {
        //        RETE_LOG_ERROR("...failed on set_Result(\"" << optarg << "\")");
        //    }
        //}
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnReasonOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //    RETE_LOG_DEBUG("optarg = \"" << optarg << "\"...");
        //    if (!(set_Reason(optarg))) {
        //        RETE_LOG_ERROR("...failed on set_Reason(\"" << optarg << "\")");
        //    }
        //}
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnProtocolOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        //if ((optarg) && (optarg[0])) {
        //    RETE_LOG_DEBUG("optarg = \"" << optarg << "\"...");
        //    if (!(set_Protocol(optarg))) {
        //        RETE_LOG_ERROR("...failed on set_Protocol(\"" << optarg << "\")");
        //    }
        //}
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnClientOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        OnClientOption();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnServerOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        OnServerOption();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnSocketsOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        OnSocketsOption();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnHostOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnPortOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnFamilyOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnTransportOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case RETE_CONSOLE_MAIN_METHOD_OPTVAL_C:
            err = OnMethodOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_ARGUMENTS_OPTVAL_C:
            err = OnArgumentsOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_RESULT_OPTVAL_C:
            err = OnResultOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_REASON_OPTVAL_C:
            err = OnReasonOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_PROTOCOL_OPTVAL_C:
            err = OnProtocolOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_CLIENT_OPTVAL_C:
            err = OnClientOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_SERVER_OPTVAL_C:
            err = OnServerOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_SOCKETS_OPTVAL_C:
            err = OnSocketsOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_HOST_OPTVAL_C:
            err = OnHostOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_PORT_OPTVAL_C:
            err = OnPortOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_FAMILY_OPTVAL_C:
            err = OnFamilyOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_CONSOLE_MAIN_TRANSPORT_OPTVAL_C:
            err = OnTransportOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Implements::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case RETE_CONSOLE_MAIN_METHOD_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_METHOD_OPTARG;
            chars = RETE_CONSOLE_MAIN_METHOD_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_ARGUMENTS_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_ARGUMENTS_OPTARG;
            chars = RETE_CONSOLE_MAIN_ARGUMENTS_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_RESULT_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_RESULT_OPTARG;
            chars = RETE_CONSOLE_MAIN_RESULT_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_REASON_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_REASON_OPTARG;
            chars = RETE_CONSOLE_MAIN_REASON_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_PROTOCOL_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_PROTOCOL_OPTARG;
            chars = RETE_CONSOLE_MAIN_PROTOCOL_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_CLIENT_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_CLIENT_OPTARG;
            chars = RETE_CONSOLE_MAIN_CLIENT_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_SERVER_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_SERVER_OPTARG;
            chars = RETE_CONSOLE_MAIN_SERVER_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_SOCKETS_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_SOCKETS_OPTARG;
            chars = RETE_CONSOLE_MAIN_SOCKETS_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_HOST_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_HOST_OPTARG;
            chars = RETE_CONSOLE_MAIN_HOST_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_PORT_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_PORT_OPTARG;
            chars = RETE_CONSOLE_MAIN_PORT_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_FAMILY_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_FAMILY_OPTARG;
            chars = RETE_CONSOLE_MAIN_FAMILY_OPTUSE;
            break;
        case RETE_CONSOLE_MAIN_TRANSPORT_OPTVAL_C:
            optarg = RETE_CONSOLE_MAIN_TRANSPORT_OPTARG;
            chars = RETE_CONSOLE_MAIN_TRANSPORT_OPTUSE;
            break;
        default:
            chars = Implements::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = RETE_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            RETE_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    virtual const char_t* Arguments(const char_t**& argv) {
        static const char_t* _args = RETE_CONSOLE_MAIN_ARGS;
        static const char_t* _argv[] = {
            RETE_CONSOLE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainOptT<> MainOpt;

} // namespace getopt
} // namespace console 
} // namespace rete 

#endif // _RETE_CONSOLE_GETOPT_MAINOPT_HPP 
