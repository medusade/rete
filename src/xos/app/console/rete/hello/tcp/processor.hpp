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
///   File: processor.hpp
///
/// Author: $author$
///   Date: 6/21/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_TCP_PROCESSOR_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_TCP_PROCESSOR_HPP

#include "xos/app/console/rete/hello/tcp/connections.hpp"
#include "xos/app/console/rete/hello/processor.hpp"

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {
namespace tcp {

/// class processort
template <class TExtends = hello::processor, class TImplements = typename TExtends::implements>
class exported processort: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef processort derives; 
    
    typedef typename extends::char_t char_t;
    typedef typename extends::chars_t chars_t;
    typedef typename extends::string_t string_t;

    /// enum status
    typedef typename extends::status status;
    enum {
        processing_done = extends::processing_done,
        processing_failed = extends::processing_failed,
        processing_continued = extends::processing_continued
    }; /// enum status

    /// enum matched
    typedef typename extends::matched matched;
    enum {
        message_none = extends::message_none,
        message_again = extends::message_again,
        message_bye = extends::message_bye,
        message_hello = extends::message_hello
    }; /// enum matched

    /// constructors / destructor
    processort
    (const string_t& again_message, const string_t& bye_message, const string_t& hello_message,
     int optind, int argc, const char_t*const* argv, const char_t*const* env)
    : extends(again_message, bye_message, hello_message, optind, argc, argv, env) {
    }
    processort() {
    }
    virtual ~processort() {
    }
private:
    processort(const processort& copy) {
    }

public:
    /// operator()
    virtual status operator()(matched& match, network::socket& s, const request& rq) {
        const char_t* chars = 0;
        size_t length = 0;

        match = message_none;
        if ((chars = this->client_message(length, match, rq))) {
            if (!(message_again != (match))) {
            } else {
                if (!(message_bye != (match))) {
                } else {
                    if (!(message_hello != (match))) {
                    } else {
                    }
                }
            }
        } else {
        }

        if ((chars)) {
            status done = processing_done;
            response rs;
            
            if ((chars = this->server_message(length, rs, match, rq))) {

                LOGGER_LOG_DEBUG("send \"" << chars << "\"...");
                if (length <= (s.send(chars, length, 0))) {
                    LOGGER_LOG_DEBUG("...sent \"" << chars << "\"");
                    return done;
                } else {
                    LOGGER_LOG_DEBUG("...failed to send \"" << chars << "\"");
                }
            } else {
            }
        } else {
        }
        return processing_failed;
    }

protected:
}; /// class processort
typedef processort<> processor;

} /// namespace tcp
} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_RETE_HELLO_TCP_PROCESSOR_HPP
