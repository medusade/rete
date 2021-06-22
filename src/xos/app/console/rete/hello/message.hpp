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
///   File: message.hpp
///
/// Author: $author$
///   Date: 6/17/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_MESSAGE_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_MESSAGE_HPP

#include "xos/base/string.hpp"
#include "xos/io/logger.hpp"
#include <list>

#define XOS_APP_CONSOLE_HELLO_AGAIN_MESSAGE "Again"
#define XOS_APP_CONSOLE_HELLO_BYE_MESSAGE "Bye"
#define XOS_APP_CONSOLE_HELLO_HELLO_MESSAGE "Hello"
#define XOS_APP_CONSOLE_HELLO_MESSAGE_LINE_SEPARATOR "\r\n"
#define XOS_APP_CONSOLE_HELLO_MESSAGE_BODY_SEPARATOR "\r\n\r\n"

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {

/// class messaget
template <class TExtends = xos::base::string, class TImplements = typename TExtends::Implements>
class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives; 
    
    typedef typename extends::char_t char_t;
    typedef xos::base::typest<char_t> chars_t;
    typedef extends string_t;
    typedef std::list<string_t> list_t;
    typedef typename list_t::const_iterator const_iterator_t;

    /// constructors / destructor
    messaget(const messaget& copy): on_read_(0) {
    }
    messaget(): on_read_(0) {
    }
    virtual ~messaget() {
    }

    /// on_write / on_read.
    virtual bool on_write(const char_t* chars, size_t length, int argc, const char_t** argv) {
        if ((chars) && (length)) {
            if ((on_write_start())) {
                if ((on_write_line(chars, length))) {
                    for (int arg = 0; arg < argc; ++arg) {
                        if ((chars = argv[arg]) && (length = chars_t::count(chars))) {
                            if (!(on_write_header(chars, length))) {
                                return false;
                            }
                        }
                    }
                    if ((on_write_finish())) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    virtual bool on_read(const char_t* chars, size_t length) {
        if ((on_read_start())) {
            if ((on_read_finish(chars, length))) {
                return true;
            }
        }
        return false;
    }

    /// ...on_write...
    virtual bool on_write_start() {
        this->clear();
        line_.clear();
        header_.clear();
        body_.clear();
        headers_.clear();
        on_read_ = 0;
        return true;
    }
    virtual bool on_write_finish() {
        const char_t* chars;
        size_t length;
        if ((chars = line_.has_chars(length))) {
            LOGGER_LOG_INFO("...write line \"" << chars << "\"");
            this->assign(chars, length);
            this->append(&cr(), 1);
            this->append(&lf(), 1);
            if (0 < (headers_.size())) {
                const_iterator_t end = headers_.end();
                for (const_iterator_t i = headers_.begin(); i != end; ++i) {
                    const string_t& header = *i;
                    if ((chars = header.has_chars(length))) {
                        LOGGER_LOG_INFO("...write header \"" << chars << "\"");
                        this->append(chars, length);
                        this->append(&cr(), 1);
                        this->append(&lf(), 1);
                    }
                }
            }
            this->append(&cr(), 1);
            this->append(&lf(), 1);
            if ((chars = body_.has_chars(length))) {
                LOGGER_LOG_INFO("...write body \"" << chars << "\"");
                this->append(chars, length);
            }
            return true;
        }
        return false;
    }
    virtual bool on_write_line(const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            line_.assign(chars, length);
            return true;
        }
        return false;
    }
    virtual bool on_write_header(const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            header_.assign(chars, length);
            headers_.push_back(header_);
            return true;
        }
        return false;
    }
    virtual bool on_write_body(const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            body_.assign(chars, length);
            return true;
        }
        return false;
    }

    /// ...on_read...
    typedef bool (derives::*on_read_t)(const char_t*& chars, size_t& length);
    on_read_t on_read_;
    virtual bool on_read_start() {
        this->clear();
        line_.clear();
        header_.clear();
        body_.clear();
        headers_.clear();
        on_read_ = &derives::on_read_line;
        return true;
    }
    virtual bool on_read_finish(const char_t* chars, size_t length) {
        if ((on_read_) && (chars) && (length)) {
            while (0 < (length)) {
                LOGGER_LOG_TRACE("...on_read_finish \"" << string_t(chars,length) << "\"");
                if ((this->*on_read_)(chars, length)) {
                    on_read_ = 0;
                    return true;
                }
            }
            return false;
        }
        return true;
    }
    virtual bool on_read_line(const char_t*& chars, size_t& length) {
        if ((chars)) {
            for (bool more = true; more && length; --length, ++chars) {
                this->append(chars, 1);
                if (cr() != (*chars)) {
                    if (lf() != (*chars)) {
                        line_.append(chars, 1);
                    } else {
                        LOGGER_LOG_DEBUG("...read line \"" << line_ << "\"");
                        LOGGER_LOG_DEBUG("...from \"" << *this << "\"");
                        return true;
                    }
                } else {
                    LOGGER_LOG_TRACE("...cr in line");
                    on_read_ = &derives::on_read_line_cr;
                    more = false;
                }
            }
        }
        return false;
    }
    virtual bool on_read_line_cr(const char_t*& chars, size_t& length) {
        if ((chars)) {
            for (bool more = true; more && length; --length, ++chars) {
                this->append(chars, 1);
                if (cr() != (*chars)) {
                    if (lf() != (*chars)) {
                        LOGGER_LOG_DEBUG("...invalid char after cr in line");
                        return true;
                    } else {
                        LOGGER_LOG_DEBUG("...read line \"" << line_ << "\"");
                        on_read_ = &derives::on_read_header;
                        more = false;
                    }
                } else {
                    LOGGER_LOG_DEBUG("...invalid cr after cr in line");
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool on_read_header(const char_t*& chars, size_t& length) {
        if ((chars)) {
            for (bool more = true; more && length; --length, ++chars) {
                this->append(chars, 1);
                if (cr() != (*chars)) {
                    if (lf() != (*chars)) {
                        header_.append(chars, 1);
                    } else {
                        LOGGER_LOG_DEBUG("...skipping lf in header");
                    }
                } else {
                    LOGGER_LOG_TRACE("...cr in header");
                    on_read_ = &derives::on_read_header_cr;
                    more = false;
                }
            }
        }
        return false;
    }
    virtual bool on_read_header_cr(const char_t*& chars, size_t& length) {
        if ((chars)) {
            for (bool more = true; more && length; --length, ++chars) {
                if (cr() != (*chars)) {
                    if (lf() != (*chars)) {
                        LOGGER_LOG_DEBUG("...invalid char after cr in header");
                        return true;
                    } else {
                        if (0 < (header_.length())) {
                            LOGGER_LOG_DEBUG("...read header \"" << header_ << "\"");
                            headers_.push_back(header_);
                            header_.clear();
                            on_read_ = &derives::on_read_header;
                            more = false;
                        } else {
                            LOGGER_LOG_DEBUG("...read end header");
                            LOGGER_LOG_DEBUG("...from \"" << *this << "\"");
                            return true;
                        }
                    }
                } else {
                    LOGGER_LOG_DEBUG("...invalid cr after cr in header");
                    return true;
                }
            }
        }
        return false;
    }
 
    /// line / body / headers
    virtual string_t& line() const {
        return (string_t&)line_;
    }
    virtual string_t& body() const {
        return (string_t&)body_;
    }
    virtual list_t& headers() const {
        return (list_t&)headers_;
    }
    
    /// cr / lf
    virtual const char_t& cr() const {
        static const char_t c = ((char_t)'\r');
        return c;
    }
    virtual const char_t& lf() const {
        static const char_t c = ((char_t)'\n');
        return c;
    }

protected:
    string_t line_, header_, body_;
    list_t headers_;
}; /// class messaget
typedef messaget<> message;

} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_RETE_HELLO_MESSAGE_HPP
