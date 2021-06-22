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
///   File: main.hpp
///
/// Author: $author$
///   Date: 6/19/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_HPP

#include "xos/app/console/rete/hello/server/main_opt.hpp"
#include "xos/app/console/rete/hello/tcp/connections.hpp"
#include "xos/app/console/rete/hello/tcp/processor.hpp"
#include "xos/app/console/rete/hello/tcp/service.hpp"

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {
namespace server {

/// class maint
template 
<class TExtends = main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::short_t short_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint(): default_run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
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

    /// ...server...
    virtual int server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        listen_t listen = 0;

        this->set_use_accept_host();
        this->set_use_accept_port();
        if ((listen = (this->listen()))) {
            network::endpoint* ep = 0;

            if ((ep = this->new_ep())) {
                network::transport* tp = 0;

                if ((tp = this->new_tp())) {
                    network::os::socket s;

                    if ((s.open(*tp))) {

                        (this->*listen)(s, *ep, argc, argv, env);
                        s.close();
                    } else {
                    }
                    this->delete_tp(tp);
                } else {
                }
                this->delete_ep(ep);
            } else {
            }
        } else {
        }
        this->unset_use_port();
        this->unset_use_host();
        return err;
    }
    virtual int server_tcp_listen
    (network::socket& s, network::endpoint& ep, int argc, char_t** argv, char_t** env) {
        int err = 0;

        LOGGER_LOG_INFO("s.listen(ep)...");
        if ((s.listen(ep))) {
            bool &restart = this->restart(), &stop = this->stop(), hi = false;
            signaler again(restart), bye(stop), hello(hi);
            const string_t &again_message = this->again_message(), &bye_message = this->bye_message(), &hello_message = this->hello_message();
            tcp::service sv(again_message, bye_message, hello_message, optind, argc, argv, env);
            tcp::connections cn;
            network::os::socket sk;

            for (bool done = false; !done; done = (restart || stop), hi = false) {

                if (!(done = !(sk.closed()))) {

                    LOGGER_LOG_INFO("s.accept()...");
                    if (!(done = !(s.accept(sk, ep)))) {

                        LOGGER_LOG_INFO("...s.accept()");
                        if ((cn.queue(sk))) {
                            sv(again, bye, hello, cn, false);
                        } else {
                        }
                    } else {
                        LOGGER_LOG_ERROR("...failed on s.accept()");
                    }
                } else {
                }
            }
        } else {
            LOGGER_LOG_ERROR("...failed on s.listen(ep)");
        }
        return err;
    }

protected:
}; /// class maint
typedef maint<> main;

} /// namespace server
} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_RETE_HELLO_SERVER_MAIN_HPP
