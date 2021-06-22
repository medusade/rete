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
///   Date: 6/19/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPT_HPP

#include "xos/app/console/rete/hello/base/main.hpp"
#include "xos/app/console/rete/hello/processor.hpp"
#include "xos/app/console/rete/hello/tcp/connections.hpp"
#include "xos/app/console/rete/hello/tcp/processor.hpp"
#include "xos/app/console/rete/hello/tcp/service.hpp"

#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPT "accept"
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTARG "[{ * | name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTUSE "Accept"
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPT "accept-1"
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTARG XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTARG
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTUSE "Accept 1"
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTVAL_S "1::"
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C '1'
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTVAL_S \
   XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTVAL_S \

#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTION \
   XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTION \

#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ARGS 0
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {
namespace server {

/// class main_optt
template 
<class TExtends = xos::app::console::rete::hello::base::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::short_t short_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
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

    /// ...host / ...port
    virtual string_t& use_accept_host() const {
        return this->accept_host();
    }
    virtual short_t& use_accept_port() const {
        return this->accept_port();
    }
    virtual string_t& use_connect_host() const {
        return this->connect_host();
    }
    virtual short_t& use_connect_port() const {
        return this->connect_port();
    }
    string_t& (derives::*use_host_)() const;
    virtual string_t& host() const {
        if ((this->use_host_)) {
            return (this->*use_host_)();
        }
        return this->connect_host();
    }

    /// ...use_host / ...use_port
    virtual string_t& set_use_accept_host() {
        use_host_ = &derives::use_accept_host;
        return host();
    }
    virtual string_t& set_use_connect_host() {
        use_host_ = &derives::use_connect_host;
        return host();
    }
    virtual string_t& unset_use_host() {
        use_host_ = 0;
        return host();
    }
    short_t& (derives::*use_port_)() const;
    virtual short_t& port() const {
        if ((this->use_port_)) {
            return (this->*use_port_)();
        }
        return this->connect_port();
    }
    virtual short_t& set_use_accept_port() {
        use_port_ = &derives::use_accept_port;
        return port();
    }
    virtual short_t& set_use_connect_port() {
        use_port_ = &derives::use_connect_port;
        return port();
    }
    virtual short_t& unset_use_port() {
        use_port_ = 0;
        return port();
    }

    /// ...option...
    virtual int on_accept_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        if (!(err = this->all_set_accept_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* accept_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTARG;
        return chars;
    }
    virtual int on_accept_one_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        if (!(err = this->all_set_accept_one_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* accept_one_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTARG;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTVAL_C:
            err = this->on_accept_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C:
            err = this->on_accept_one_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_OPTVAL_C:
            chars = accept_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C:
            chars = accept_one_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace server
} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_OPT_HPP
