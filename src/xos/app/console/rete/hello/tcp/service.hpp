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
///   File: service.hpp
///
/// Author: $author$
///   Date: 6/21/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_TCP_SERVICE_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_TCP_SERVICE_HPP

#include "xos/app/console/rete/hello/tcp/processor.hpp"

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {
namespace tcp {

/// class servicet
template <class TExtends = extend, class TImplements = typename TExtends::implements>
class exported servicet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef servicet derives; 
    
    typedef message::char_t char_t;
    typedef message::chars_t chars_t;
    typedef message::string_t string_t;
    
    /// constructors / destructor
    servicet
    (const string_t& again_message, const string_t& bye_message, const string_t& hello_message,
     int optind, int argc, const char_t*const* argv, const char_t*const* env)
    : again_message_(again_message), bye_message_(bye_message), hello_message_(hello_message),
      optind_(optind), argc_(argc), argv_(argv), env_(env) {
    }
    servicet()
    : again_message_(this_again_message_), bye_message_(this_bye_message_), hello_message_(this_hello_message_),
      optind_(0), argc_(0), argv_(0), env_(0) {
    }
    virtual ~servicet() {
    }
private:
    servicet(const servicet& copy)
    : again_message_(this_again_message_), bye_message_(this_bye_message_), hello_message_(this_hello_message_),
      optind_(0), argc_(0), argv_(0), env_(0) {
    }

public:
    /// operator()
    virtual void operator()(signaler& again, signaler& bye, signaler& hello, connections& cn, bool is_repeated = true) {
        char_t *chars = 0;
        size_t size = 0;
        
        if ((chars = this->chars(size))) {
            processor p(again_message_, bye_message_, hello_message_, optind_, argc_, argv_, env_);
            network::os::socket s;
            request rq;

            do {
                LOGGER_LOG_INFO("dequeue socket...");
                if ((cn.dequeue(s))) {
                    bool continued = false;
                    ssize_t count = 0;

                    LOGGER_LOG_INFO("...dequeued socket");
                    do {
                        if ((rq.on_read_start())) {
                            do {
                                LOGGER_LOG_DEBUG("recv[" << size << "]...");
                                if (0 < (count = s.recv(chars, size, 0))) {

                                    LOGGER_LOG_DEBUG("...recv[" << count << "]");
                                    if (!(rq.on_read_finish(chars, count))) {
                                        continue;
                                    } else {
                                        processor::matched pm = processor::message_none;
                                        processor::status ps = processor::processing_done;

                                        LOGGER_LOG_DEBUG("...read \"" << rq << "\"");
                                        switch (ps = p(pm, s, rq)) {
                                        case processor::processing_done:
                                            if (!(processor::message_again != pm)) {
                                                LOGGER_LOG_INFO("...Again \"" << rq.line() << "\"");
                                                again();
                                            } else {
                                                if (!(processor::message_bye != pm)) {
                                                    LOGGER_LOG_INFO("...Bye \"" << rq.line() << "\"");
                                                    bye();
                                                } else {
                                                    if (!(processor::message_hello != pm)) {
                                                        LOGGER_LOG_INFO("...Hello \"" << rq.line() << "\"");
                                                        hello();
                                                    } else {
                                                        LOGGER_LOG_INFO("...\"" << rq.line() << "\"");
                                                    }
                                                }
                                            }
                                            break;
                                        case processor::processing_continued:
                                            continued = true;
                                            break;
                                        default:
                                            break;
                                        } /// switch (ps = p(pm, s, rq)) 
                                    }
                                } else {
                                    LOGGER_LOG_DEBUG("...failed with recv[" << count << "]");
                                }
                                break;
                            } while (0 < count);
                        } else {
                        }
                    } while (continued);
                } else {
                    LOGGER_LOG_ERROR("...failed to dequeue socket");
                }
            } while (is_repeated);
        } else {
        }
    }

protected:
    /// ...chars
    virtual char_t* chars(size_t& size) const {
        size  = sizeof(chars_);
        return ((char_t*)chars_);
    }
    
protected:
    string_t this_again_message_, this_bye_message_, this_hello_message_;
    const string_t& again_message_, & bye_message_, & hello_message_;
    int optind_, argc_;
    const char_t *const* argv_, *const* env_;
    char_t chars_[4096];
}; /// class servicet
typedef servicet<> service;

} /// namespace tcp
} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_RETE_HELLO_TCP_SERVICE_HPP
