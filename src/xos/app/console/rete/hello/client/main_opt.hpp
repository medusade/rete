///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 6/17/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPT_HPP

#include "xos/app/console/rete/hello/base/main.hpp"

#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPT "connect"
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTUSE "Connect"
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTVAL_S "c::"
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTVAL_C 'c'
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTVAL_S \

#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTION \

#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_ARGS 0
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {
namespace client {

/// class main_optt
template 
<class TExtends = xos::app::console::rete::hello::base::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::chars_t chars_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): default_run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;
    
    typedef typename extends::request_t request_t;
    typedef typename extends::response_t response_t;
    
    typedef typename extends::send_t send_t;
    typedef typename extends::listen_t listen_t;

    /// ...run
    int (derives::*default_run_)(int argc, char_t** argv, char_t** env);
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((default_run_)) {
            err = (this->*default_run_)(argc, argv, env);
        } else {
            err = extends::default_run(argc, argv, env);
        }
        return err;
    }

    /// ...option...
    virtual int on_connect_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        if (!(err = this->all_set_connect_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* connect_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTARG;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTVAL_C:
            err = this->on_connect_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_CONNECT_OPTVAL_C:
            chars = connect_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace client
} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_OPT_HPP
