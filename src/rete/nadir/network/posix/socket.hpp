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
///   File: socket.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NADIR_NETWORK_POSIX_SOCKET_HPP
#define _RETE_NADIR_NETWORK_POSIX_SOCKET_HPP

#include "rete/nadir/network/socket.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <errno.h>

namespace rete {
namespace network {
namespace posix {

typedef int socket_t;
typedef socket_t socket_attached_t;
typedef int socket_unattached_t;
enum { socket_unattached = 0 };

typedef socket_extendt_implements sockett_implements;
typedef network::socket_extendt
<socket_attached_t, socket_unattached_t,
 socket_unattached, sockett_implements> sockett_extends;
///////////////////////////////////////////////////////////////////////
///  Class: sockett
///////////////////////////////////////////////////////////////////////
template
<class TImplements = sockett_implements,
 class TExtends = sockett_extends>

class _EXPORT_CLASS sockett: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Implements::domain_t domain_t;
    typedef typename Implements::type_t type_t;
    typedef typename Implements::protocol_t protocol_t;

    typedef typename Implements::address_t address_t;
    typedef typename Implements::transport_t transport_t;
    typedef typename Implements::endpoint_t endpoint_t;

    typedef typename Extends::attached_t attached_t;
    typedef typename Extends::unattached_t unattached_t;
    enum { unattached = Extends::unattached };

    typedef socket_shutdown_how_t shutdown_how_t;
    static const shutdown_how_t shutdown_read = socket_shutdown_read;
    static const shutdown_how_t shutdown_write = socket_shutdown_write;
    static const shutdown_how_t shutdown_both = socket_shutdown_both;

    typedef socket_linger_seconds_t linger_seconds_t;
    typedef socket_backlog_t backlog_t;
    typedef socket_sendflags_t sendflags_t;
    typedef socket_recvflags_t recvflags_t;
    typedef socket_optlevel_t optlevel_t;
    typedef socket_optname_t optname_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    sockett() {
    }
    virtual ~sockett() {
        if (!(this->closed())) {
            open_exception e(close_failed);
            CRONO_LOG_ERROR("...throwing open_exception e(close_failed)...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::open;
    virtual bool open(domain_t domain, type_t type, protocol_t protocol) {
        attached_t detached = unattached;
        if (unattached != (detached = this->open_attached(domain, type, protocol))) {
            this->set_is_open();
            return true;
        }
        return false;
    }
    virtual bool close() {
        if ((this->on_close())) {
            attached_t detached = unattached;
            if (unattached != (detached = this->detach())) {
                if ((this->close_detached(detached))) {
                    return true;
                }
            }
        }
        return false;
    }
    using Implements::shutdown;
    virtual bool shutdown(shutdown_how_t how) {
        attached_t detached = unattached;
        if (unattached  != (detached)) {
            if ((shutdown_detached(detached, how))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t open_attached
    (domain_t domain, type_t type, protocol_t protocol) {
        if ((this->closed())) {
            attached_t detached = unattached;
            if (unattached != (detached = this->open_detached(domain, type, protocol))) {
                this->attach(detached);
                return detached;
            }
        }
        return 0;
    }
    virtual attached_t open_detached
    (domain_t domain, type_t type, protocol_t protocol) const {
        attached_t detached = unattached;
        CRONO_LOG_DEBUG("socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")...");
        if (0 <= (detached = ::socket(domain, type, protocol))) {
            CRONO_LOG_DEBUG("...socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        } else {
            CRONO_LOG_ERROR("failed errno = " << errno << " on socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        }
        return detached;
    }
    virtual bool close_detached(attached_t detached) const {
        if (0 <= (detached)) {
            int err = 0;
            CRONO_LOG_DEBUG("close(" << detached << ")...");
            if (!(err = ::close(detached))) {
                CRONO_LOG_DEBUG("...close(" << detached << ")");
                return true;
            } else {
                CRONO_LOG_ERROR("failed errno = " << errno << " on close(" << detached << ")");
            }
        }
        return false;
    }
    virtual bool shutdown_detached(attached_t detached, shutdown_how_t how) const {
        if (unattached  != (detached)) {
            int sd_how = ((how == this->shutdown_read)?(SHUT_RD)
                          :((how == this->shutdown_write)?(SHUT_WR)
                          :((how == this->shutdown_both)?(SHUT_RDWR):(0))));
            int err = 0;
            CRONO_LOG_DEBUG("::shutdown(detached, sd_how)...");
            if (!(err = ::shutdown(detached, sd_how))) {
                return true;
            } else {
                CRONO_LOG_ERROR("...failed " << errno << " on shutdown(detached, sd_how)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::connect;
    virtual bool connect(const sockaddr_t* addr, socklen_t addrlen) {
        attached_t detached = unattached;
        if (0  <= (detached = this->attached_to()) && (addr) && (addrlen)) {
            int err = 0;
            CRONO_LOG_DEBUG("connect(..., addrlen = " << addrlen << ")...");
            if (!(err = ::connect(detached, addr, addrlen))) {
                CRONO_LOG_DEBUG("...connect(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on connect(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }
    using Implements::bind;
    virtual bool bind(const sockaddr_t* addr, socklen_t addrlen) {
        attached_t detached = unattached;
        if (0  <= (detached = this->attached_to()) && (addr) && (addrlen)) {
            int err = 0;
            if ((this->bind_as_reuseaddr())) {
                this->set_reuseaddr_opt();
            }
            CRONO_LOG_DEBUG("bind(..., addrlen = " << addrlen << ")...");
            if (!(err = ::bind(detached, addr, addrlen))) {
                CRONO_LOG_DEBUG("...bind(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on bind(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }
    using Implements::listen;
    virtual bool listen(backlog_t backlog) {
        attached_t detached = unattached;
        if (0  <= (detached = this->attached_to())) {
            int err = 0;
            CRONO_LOG_DEBUG("listen(..., backlog = " << backlog << ")...");
            if (!(err = ::listen(detached, backlog))) {
                CRONO_LOG_DEBUG("...listen(..., backlog = " << backlog << ")...");
                return true;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on listen(..., backlog = " << backlog << ")");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t sendto
    (const void* buf, size_t len, sendflags_t flags,
     const sockaddr_t* addr, socklen_t addrlen) {
        attached_t detached = unattached;
        if (0  <= (detached = this->attached_to())
            && (buf) && (len) && (addr) && (addrlen)) {
            ssize_t count = 0;
            CRONO_LOG_DEBUG("sendto(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::sendto(detached, buf, len, flags, addr, addrlen))) {
                CRONO_LOG_DEBUG("..." << count << " = sendto(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on sendto(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    virtual ssize_t recvfrom
    (void* buf, size_t len, recvflags_t flags,
     sockaddr_t* addr, socklen_t* addrlen) {
        attached_t detached = unattached;
        if (0  <= (detached = this->attached_to())
            && (buf) && (len) && (addr) && (addrlen)) {
            ssize_t count = 0;
            CRONO_LOG_DEBUG("recvfrom(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::recvfrom(detached, buf, len, flags, addr, addrlen))) {
                CRONO_LOG_DEBUG("..." << count << " = recvfrom(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on recvfrom(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t send(const void* buf, size_t len, sendflags_t flags) {
        attached_t detached = unattached;
        if (0  <= (detached = this->attached_to()) && (buf) && (len)) {
            ssize_t count = 0;
            CRONO_LOG_DEBUG("send(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::send(detached, buf, len, flags))) {
                CRONO_LOG_DEBUG("..." << count << " = send(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on send(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    virtual ssize_t recv(void* buf, size_t len, recvflags_t flags) {
        attached_t detached = unattached;
        if (0  <= (detached = this->attached_to()) && (buf) && (len)) {
            ssize_t count = 0;
            CRONO_LOG_DEBUG("recv(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::recv(detached, buf, len, flags))) {
                CRONO_LOG_DEBUG("..." << count << " = recv(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on recv(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_reuseaddr_opt(bool on = true) {
        int value = (on)?(1):(0);
        CRONO_LOG_DEBUG("set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value))...");
        if ((this->set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool set_noreuseaddr_opt(bool on = true) {
        int value = (on)?(0):(1);
        CRONO_LOG_DEBUG("set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value))...");
        if ((this->set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool get_reuseaddr_opt(bool &on) const {
        int value = 0;
        socklen_t length = sizeof(value);
        CRONO_LOG_DEBUG("get_opt(SOL_SOCKET, SO_REUSEADDR, &value, length)...");
        if ((this->get_opt(SOL_SOCKET, SO_REUSEADDR, &value, length))) {
            on = (value != 0);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_delay_opt(bool on = true) {
        int value = (on)?(0):(1);
        CRONO_LOG_DEBUG("set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value))...");
        if ((this->set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool set_nodelay_opt(bool on = true) {
        int value = (on)?(1):(0);
        CRONO_LOG_DEBUG("set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value))...");
        if ((this->set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool get_delay_opt(bool &on) const {
        int value = 0;
        socklen_t length = sizeof(value);
        CRONO_LOG_DEBUG("get_opt(IPPROTO_TCP, TCP_NODELAY, &value, length))...");
        if ((this->get_opt(IPPROTO_TCP, TCP_NODELAY, &value, length))) {
            on = (value == 0);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_linger_opt
    (bool on = true, linger_seconds_t linger_seconds = -1) {
        struct linger value;
        value.l_onoff = (on)?(1):(0);
        value.l_linger = (0>linger_seconds)?(this->default_linger_seconds()):(linger_seconds);
        CRONO_LOG_DEBUG("set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value))...");
        if ((this->set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool set_dont_linger_opt
    (bool on = true, linger_seconds_t linger_seconds = -1) {
        struct linger value;
        value.l_onoff = (on)?(0):(1);
        value.l_linger = (0>linger_seconds)?(this->default_linger_seconds()):(linger_seconds);
        CRONO_LOG_DEBUG("set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value))...");
        if ((this->set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool get_linger_opt(bool &on, linger_seconds_t &linger_seconds) const {
        struct linger value = {0, 0};
        socklen_t length = sizeof(value);
        CRONO_LOG_DEBUG("get_opt(SOL_SOCKET, SO_LINGER, &value, length)...");
        if ((this->get_opt(SOL_SOCKET, SO_LINGER, &value, length))) {
            on = (value.l_onoff == 0);
            linger_seconds = (value.l_linger);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_opt
    (optlevel_t level, optname_t name, const void* value, socklen_t length) {
        attached_t detached = unattached;
        if (0 <= (detached = this->attached_to()) && (value) && (length)) {
            int err = 0;
            CRONO_LOG_DEBUG("setsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
            if (!(err = ::setsockopt(detached, level, name, value, length))) {
                CRONO_LOG_DEBUG("...setsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
                return true;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on setsockopt(..., level = " << level << ", name = " << name << ", ..., length)");
            }
        }
        return false;
    }
    virtual bool get_opt
    (optlevel_t level, optname_t name, void* value, socklen_t &length) const {
        attached_t detached = unattached;
        if (0 <= (detached = this->attached_to()) && (value)) {
            int err = 0;
            CRONO_LOG_DEBUG("getsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
            if (!(err = ::getsockopt(detached, level, name, value, &length))) {
                CRONO_LOG_DEBUG("...getsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
                return true;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on getsockopt(..., level = " << level << ", name = " << name << ", ..., length)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool get_family(address_family_t &family, sockaddr_t &addr) const {
        socklen_t addrlen = sizeof(addr);
        memset(&addr, 0, addrlen);
        if ((get_name(&addr, addrlen))) {
            family = (addr.sa_family);
            return true;
        }
        return false;
    }
    virtual bool get_name(sockaddr_t* addr, socklen_t &addrlen) const {
        attached_t detached = unattached;
        if (0 <= (detached = this->attached_to()) && (addr)) {
            int err = 0;
            CRONO_LOG_DEBUG("getsockname(..., addrlen = " << addrlen << ")...");
            if (!(err = ::getsockname(detached, addr, &addrlen))) {
                CRONO_LOG_DEBUG("...getsockname(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                CRONO_LOG_ERROR("...failed errno = " << errno << " on getsockname(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace posix 

typedef posix::sockett_implements sockett_implemented_implements;
typedef posix::sockett
<sockett_implemented_implements> sockett_implemented_extends;
///////////////////////////////////////////////////////////////////////
///  Class: sockett_implemented
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS sockett_implemented
: virtual public sockett_implemented_implements,
  public sockett_implemented_extends {
public:
    typedef sockett_implemented_implements Implements;
    typedef sockett_implemented_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    sockett_implemented() {
    }
    virtual ~sockett_implemented() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::accept;
    virtual bool accept
    (sockett_implemented& sock, sockaddr_t* addr, socklen_t& addrlen) {
        if ((sock.closed())) {
            attached_t detached = unattached;
            if (0  <= (detached = this->attached_to()) && (addr)) {
                attached_t accepted = unattached;
                CRONO_LOG_DEBUG("accept(..., addrlen = " << addrlen << ")...");
                if (0 <= (accepted = ::accept(detached, addr, &addrlen))) {
                    CRONO_LOG_DEBUG("..." << accepted << " = accept(..., addrlen = " << addrlen << ")...");
                    sock.attach_opened(accepted);
                    return true;
                } else {
                    CRONO_LOG_ERROR("...failed errno = " << errno << " on accept(..., addrlen = " << addrlen << ")");
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

namespace posix {

typedef sockett_implemented_implements socket_implements;
typedef sockett_implemented socket_extends;
///////////////////////////////////////////////////////////////////////
///  Class: socket
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS socket
: virtual public socket_implements, public socket_extends {
public:
    typedef socket_implements Implements;
    typedef socket_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    socket(const socket& copy): Extends(copy) {
    }
    socket() {
    }
    virtual ~socket() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::accept;
    virtual sockett_implemented* accept(sockaddr_t* addr, socklen_t& addrlen) {
        if ((this->accept(accepted_, addr, addrlen))) {
            accepted_.set_is_open(false);
            return &accepted_;
        }
        return 0;
    }
    virtual sockett_implemented* implemented() const {
        return ((sockett_implemented*)this);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    sockett_implemented accepted_;
};

} // namespace posix
} // namespace network
} // namespace rete 

#endif // _RETE_NADIR_NETWORK_POSIX_SOCKET_HPP 
