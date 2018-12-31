///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_APP_CONSOLE_NETWORK_MAINOPT_HPP
#define _RETE_APP_CONSOLE_NETWORK_MAINOPT_HPP

#include "rete/console/getopt/Main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPT "client"
#define RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTARG_RESULT 0
#define RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTARG ""
#define RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTUSE "Run as client"
#define RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTVAL_S "c"
#define RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTVAL_C 'c'
#define RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTION \
   {RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTARG_REQUIRED, \
    RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTARG_RESULT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTVAL_C}, \

#define RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPT "server"
#define RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTARG_RESULT 0
#define RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTARG ""
#define RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTUSE "Run as server"
#define RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTVAL_S "s"
#define RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTVAL_C 's'
#define RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTION \
   {RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTARG_REQUIRED, \
    RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTARG_RESULT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTVAL_C}, \

#define RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPT "host"
#define RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTARG_RESULT 0
#define RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTARG "string"
#define RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTUSE "Host name or address"
#define RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTVAL_S "o:"
#define RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTVAL_C 'o'
#define RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTION \
   {RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTARG_REQUIRED, \
    RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTARG_RESULT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTVAL_C}, \

#define RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPT "port"
#define RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTARG_RESULT 0
#define RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTARG "number"
#define RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTUSE "Port number"
#define RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTVAL_S "p:"
#define RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTVAL_C 'p'
#define RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTION \
   {RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTARG_REQUIRED, \
    RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTARG_RESULT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTVAL_C}, \

#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPT "family"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_RESULT 0
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_LOCAL_C "l"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_LOCAL "local"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_IPV4_C "4"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_IPV4 "ipv4"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_IPV6_C "6"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_IPV6 "ipv6"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG "{ "\
    "(" RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_LOCAL_C ")" \
    RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_LOCAL " | " \
    "(" RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_IPV4_C ")" \
    RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_IPV4 " | " \
    "(" RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_IPV6_C ")" \
    RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_IPV6 " }"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTUSE "Address family"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTVAL_S "f:"
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTVAL_C 'f'
#define RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTION \
   {RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_REQUIRED, \
    RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG_RESULT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTVAL_C}, \

#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPT "transport"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_RESULT 0
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_RAW_C "r"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_RAW "raw"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_STREAM_C "s"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_STREAM "stream"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_DGRAM_C "d"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_DGRAM "dgram"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_TCP_C "t"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_TCP "tcp"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_UDP_C "u"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_UDP "udp"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG "{ " \
    "(" RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_RAW_C ")" \
    RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_RAW " | " \
    "(" RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_STREAM_C ")" \
    RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_STREAM "/" \
    "(" RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_TCP_C ")" \
    RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_TCP " | " \
    "(" RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_DGRAM_C ")" \
    RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_DGRAM "/" \
    "(" RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_UDP_C ")" \
    RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_UDP " }"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTUSE "Transport type"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTVAL_S "t:"
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTVAL_C 't'
#define RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTION \
   {RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_REQUIRED, \
    RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG_RESULT, \
    RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define RETE_APP_CONSOLE_NETWORK_MAIN_OPTIONS_CHARS \
   RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTVAL_S \
   RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTVAL_S \
   RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTVAL_S \
   RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTVAL_S \
   RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTVAL_S \
   RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTVAL_S \
   RETE_CONSOLE_GETOPT_MAIN_OPTIONS_CHARS

#define RETE_APP_CONSOLE_NETWORK_MAIN_OPTIONS_OPTIONS \
   RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTION \
   RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTION \
   RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTION \
   RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTION \
   RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTION \
   RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTION \
   RETE_CONSOLE_GETOPT_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define RETE_APP_CONSOLE_NETWORK_MAIN_ARGS 0
#define RETE_APP_CONSOLE_NETWORK_MAIN_ARGV

namespace rete {
namespace app {
namespace console {
namespace network {

typedef rete::console::getopt::Main MainOptExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainOpt
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainOpt: public MainOptExtends {
public:
    typedef MainOptExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainOpt() {
    }
    virtual ~MainOpt() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnClientOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnServerOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnPortOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnFamilyOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnTransportOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
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
        case RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTVAL_C:
            err = OnClientOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTVAL_C:
            err = OnServerOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTVAL_C:
            err = OnHostOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTVAL_C:
            err = OnPortOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTVAL_C:
            err = OnFamilyOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTVAL_C:
            err = OnTransportOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTVAL_C:
            optarg = RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTARG;
            chars = RETE_APP_CONSOLE_NETWORK_MAIN_CLIENT_OPTUSE;
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTVAL_C:
            optarg = RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTARG;
            chars = RETE_APP_CONSOLE_NETWORK_MAIN_SERVER_OPTUSE;
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTVAL_C:
            optarg = RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTARG;
            chars = RETE_APP_CONSOLE_NETWORK_MAIN_HOST_OPTUSE;
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTVAL_C:
            optarg = RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTARG;
            chars = RETE_APP_CONSOLE_NETWORK_MAIN_PORT_OPTUSE;
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTVAL_C:
            optarg = RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTARG;
            chars = RETE_APP_CONSOLE_NETWORK_MAIN_FAMILY_OPTUSE;
            break;
        case RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTVAL_C:
            optarg = RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTARG;
            chars = RETE_APP_CONSOLE_NETWORK_MAIN_TRANSPORT_OPTUSE;
            break;
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = RETE_APP_CONSOLE_NETWORK_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            RETE_APP_CONSOLE_NETWORK_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = RETE_APP_CONSOLE_NETWORK_MAIN_ARGS;
        static const char_t* _argv[] = {
            RETE_APP_CONSOLE_NETWORK_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace network
} // namespace console 
} // namespace app 
} // namespace rete 

#endif // _RETE_APP_CONSOLE_NETWORK_MAINOPT_HPP 
