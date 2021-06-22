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
///   Date: 6/17/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_HPP

#include "xos/app/console/rete/hello/client/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {
namespace client {

/// class maint
template 
<class TExtends = main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::chars_t chars_t;
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

    /// ...client...
    virtual int client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        send_t send = 0;

        if ((send = (this->send()))) {
            size_t length = 0;
            const char_t* chars = 0;
            request_t rq = this->request();

            if ((chars = (client_message(length, rq, argc, argv, env)))) {
                network::endpoint* ep = 0;

                if ((ep = this->new_ep())) {
                    network::transport* tp = 0;
    
                    if ((tp = this->new_tp())) {
                        network::os::socket cn;

                        if ((cn.open(*tp))) {
                            (this->*send)(cn, *ep, chars, length, argc, argv, env);
                            cn.close();
                        }
                        this->delete_tp(tp);
                    } else {
                    }
                    this->delete_ep(ep);
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int client_tcp_send
    (network::socket& s, network::endpoint& ep,
     const char_t* chars, size_t length, int argc, char_t** argv, char_t** env) {

        LOGGER_LOG_INFO("s.connect()...");
        if ((s.connect(ep))) {
            ssize_t count;

            LOGGER_LOG_INFO("sending \"" << chars << "\"...");
            if (0 < (count = s.send(chars, length, 0))) {
                size_t size = 0;
                char_t* recv = 0;
        
                LOGGER_LOG_INFO("...sent \"" << chars << "\"");
                if ((recv = this->chars(size))) {
                    do {
    
                        LOGGER_LOG_INFO("recv[" << size << "]...");
                        if (0 < (count = s.recv(recv, size, 0))) {
    
                            LOGGER_LOG_DEBUG("...recv[" << count << "]");
                            this->out(recv, count);
                            continue;
                        } else {
                            LOGGER_LOG_DEBUG("...failed with recv[" << count << "]");
                        }
                        break;
                    } while (0 < count);
                } else {
                }
            } else {
                LOGGER_LOG_ERROR("... failed to send \"" << chars << "\"");
            }
        } else {
            LOGGER_LOG_DEBUG("...failed on s.connect()");
        }
        return 0;
    }
    virtual int client_udp_send
    (network::socket& s, network::endpoint& ep,
     const char_t* chars, size_t length,  int argc, char_t** argv, char_t** env) {
        ssize_t count;

        LOGGER_LOG_INFO("sending \"" << chars << "\"...");
        if (0 < (count = s.sendto(chars, length, 0, ep))) {

            LOGGER_LOG_INFO("...sent \"" << chars << "\"");
        } else {
            LOGGER_LOG_ERROR("... failed to send \"" << chars << "\"");
        }
        return 0;
    }
    
    /// ...client_message
    virtual const char_t* client_message(size_t& length, request& rq, int argc, char_t** argv, char_t** env) {
        const char_t* chars = 0;

        if ((chars = this->message().has_chars(length))) {
            int argn = (optind < argc)?(argc - optind):(0);
            const char_t** args = ((const char_t**)((optind < argc)?(argv + optind):(argv)));

            LOGGER_LOG_INFO("rq.on_write(chars = \"" << chars << "\", length = " << length << ", argn = " << argn << ", args)...");
            if ((rq.on_write(chars, length, argn, args))) {

                LOGGER_LOG_INFO("...rq.on_write(chars = \"" << chars << "\", length = " << length << ", argn = " << argn << ", args)");
                if ((chars = rq.has_chars(length))) {

                    LOGGER_LOG_INFO("message \"" << chars << "\"");
                    return chars;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }
    virtual const char_t* combine_client_message(size_t& length, request& rq, int argc, char_t** argv, char_t** env) {

        if ((rq.on_write_start())) {
            const char_t* chars = 0;

            if ((chars = this->message().has_chars(length))) {

                LOGGER_LOG_INFO("line \"" << chars << "\"...");
                if ((rq.on_write_line(chars, length))) {

                    LOGGER_LOG_INFO("...line \"" << chars << "\"");
                    for (int arg = optind; arg < argc; ++arg) {
                        if ((chars = (argv[arg])) && (0 < (length = chars_t::count(chars)))) {

                            LOGGER_LOG_INFO("header \"" << chars << "\"...");
                            if (!(rq.on_write_header(chars, length))) {
                                return 0;
                            } else {
                                LOGGER_LOG_INFO("...header \"" << chars << "\"");
                            }
                        }
                    }
                    if ((rq.on_write_finish())) {
                        if ((chars = rq.has_chars(length))) {
                            LOGGER_LOG_INFO("message \"" << chars << "\"");
                            return chars;
                        }
                    }
                }
            }
        }
        return 0;
    }

protected:
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_RETE_HELLO_CLIENT_MAIN_HPP
