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
///   Date: 6/20/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_PROCESSOR_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_PROCESSOR_HPP

#include "xos/app/console/rete/hello/message.hpp"
#include "xos/app/console/rete/hello/request.hpp"
#include "xos/app/console/rete/hello/response.hpp"
#include "xos/app/console/rete/hello/signaler.hpp"
#include "xos/io/reader.hpp"
#include "xos/io/writer.hpp"

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {

/// class processort
template <class TExtends = extend, class TImplements = typename TExtends::implements>
class exported processort: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef processort derives; 
   
    typedef message::char_t char_t;
    typedef message::chars_t chars_t;
    typedef message::string_t string_t;
    
    /// enum status
    typedef int status;
    enum {
        processing_done,
        processing_failed,
        processing_continued
    }; /// enum status

    /// enum matched
    typedef int matched;
    enum {
        message_none,
        message_again,
        message_bye,
        message_hello
    }; /// enum matched

    /// constructors / destructor
    processort
    (const string_t& again_message, const string_t& bye_message, const string_t& hello_message,
     int optind, int argc, const char_t*const* argv, const char_t*const* env)
    : again_message_(again_message), bye_message_(bye_message), hello_message_(hello_message),
      optind_(optind), argc_(argc), argv_(argv), env_(env) {
    }
    processort()
    : again_message_(this_again_message_), bye_message_(this_bye_message_), hello_message_(this_hello_message_),
      optind_(0), argc_(0), argv_(0), env_(0) {
    }
    virtual ~processort() {
    }
private:
    processort(const processort& copy)
    : again_message_(this_again_message_), bye_message_(this_bye_message_), hello_message_(this_hello_message_),
      optind_(0), argc_(0), argv_(0), env_(0) {
    }

public:
    /// operator()
    virtual status operator()(signaler& again, signaler& bye, signaler& hello, io::writer& writer, const request& rq) {
        const char_t* chars = 0;
        size_t length = 0;
        matched match = message_none;

        if ((chars = client_message(length, match, rq))) {
            if (!(message_again != (match))) {
                again();
            } else {
                if (!(message_bye != (match))) {
                    bye();
                } else {
                    if (!(message_hello != (match))) {
                        hello();
                    } else {
                    }
                }
            }
        } else {
        }

        if ((chars)) {
            status done = processing_done;
            response rs;
            
            if ((chars = server_message(length, rs, match, rq))) {

                LOGGER_LOG_DEBUG("write \"" << chars << "\"...");
                if (length <= (writer.write(chars, length))) {

                    LOGGER_LOG_DEBUG("...wrote \"" << chars << "\"");
                    writer.flush();
                    return done;
                } else {
                    LOGGER_LOG_DEBUG("...failed to write \"" << chars << "\"");
                }
            } else {
            }
        } else {
        }
        return processing_failed;
    }

protected:
    /// ...client_message / ...server_message
    virtual const char_t* client_message(size_t& length, matched& match, const request& rq) {
        const char_t* chars = 0;

        length = 0;
        match = message_none;
        if (!(again_message_.compare(rq.line()))) {
            chars = again_message_.has_chars(length);
            match = message_again;
        } else {
            if (!(bye_message_.compare(rq.line()))) {
                chars = bye_message_.has_chars(length);
                match = message_bye;
            } else {
                if (!(hello_message_.compare(rq.line()))) {
                    chars = hello_message_.has_chars(length);
                    match = message_hello;
                } else {
                    chars = rq.line().has_chars(length);
                }
            }
        }
        return chars;
    }
    virtual const char_t* server_message(size_t& length, response& rs, const matched& match, const request& rq) {
        const char_t* chars = 0;
        chars = combine_server_message(length, rs, match, rq);
        return chars;
    }
    virtual const char_t* combine_server_message(size_t& length, response& rs, const matched& match, const request& rq) {
        const char_t* chars = 0;

        if (!(match != message_again)) {
            chars = again_message_.has_chars(length);
        } else {
            if (!(match != message_bye)) {
                chars = bye_message_.has_chars(length);
            } else {
                if (!(match != message_hello)) {
                    chars = hello_message_.has_chars(length);
                } else {
                    chars = rq.line().has_chars(length);
                }
            }
        }
        if ((chars)) {
            if ((rs.on_write_start())) {
    
                LOGGER_LOG_DEBUG("line = \"" << chars << "\"");
                if ((rs.on_write_line(chars, length))) {
                    for (int i = optind_; i < argc_; ++i) {
                        if ((chars = argv_[i]) && (chars[0]) && (length = (chars_t::count(chars)))) {
    
                            LOGGER_LOG_DEBUG("header = \"" << chars << "\"");
                            if ((rs.on_write_header(chars, length))) {
                            } else {
                                length = 0;
                                return 0;
                            }
                        } else {
                        }
                    }
                    for (request::list_t::const_iterator end = rq.headers().end(), 
                         i = rq.headers().begin(); i != end; ++i) {
                        const string_t& header = *i;
                        if ((chars = header.has_chars(length))) {
    
                            LOGGER_LOG_DEBUG("header \"" << chars << "\"");
                            if ((rs.on_write_header(chars, length))) {
                            } else {
                                length = 0;
                                return 0;
                            }
                        } else {
                        }
                    }
                    if ((rs.on_write_finish())) {
                        if ((chars = rs.has_chars(length))) {
                            return chars;
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        length = 0;
        return 0;
    }

protected:
    string_t this_again_message_, this_bye_message_, this_hello_message_;
    const string_t& again_message_, & bye_message_, & hello_message_;
    int optind_, argc_;
    const char_t *const* argv_, *const* env_;
}; /// class processort
typedef processort<> processor;

} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_RETE_HELLO_PROCESSOR_HPP
