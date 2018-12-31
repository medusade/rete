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
///   File: Interface.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETS_POSIX_INTERFACE_HPP
#define _RETE_NETWORK_SOCKETS_POSIX_INTERFACE_HPP

#include "rete/network/sockets/Interface.hpp"

namespace rete {
namespace network {
namespace sockets {
namespace posix {

typedef int SocketAttachedTo;
typedef int SocketUnattachedTo;
enum { SocketUnattached = 0 };

typedef ::patrona::AttacherT
<SocketAttachedTo, SocketUnattachedTo,
 SocketUnattached, sockets::Interface> SocketTAttacher;

typedef ::patrona::AttachedT
<SocketAttachedTo, SocketUnattachedTo,
 SocketUnattached, SocketTAttacher, sockets::InterfaceExtend> SocketTAttached;

typedef ::patrona::OpenedT
<SocketAttachedTo, SocketUnattachedTo, SocketUnattached,
 SocketTAttacher, SocketTAttached> SocketTOpened;

typedef SocketTAttacher InterfaceTImplements;
typedef SocketTOpened InterfaceTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = InterfaceTImplements, class TExtends = InterfaceTExtends>

class _EXPORT_CLASS InterfaceT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef SocketAttachedTo Attached;
    static const SocketUnattachedTo Unattached = SocketUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    InterfaceT(const InterfaceT& copy): Extends(copy.AttachedTo()) {
    }
    InterfaceT() {
    }
    virtual ~InterfaceT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open
    (Domain domain, Type type, Protocol protocol) {
        Attached detached = ((Attached)Unattached);

        if (((Attached)Unattached) !=
            (detached = OpenAttached(domain, type, protocol))) {
            this->SetIsOpen();
            return true;
        }
        return false;
    }
    virtual bool Close() {
        Attached detached = ((Attached)Unattached);

        if (((Attached)Unattached) != (detached = this->Detach())) {
            if ((this->CloseDetached(detached))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Shutdown() {
        sockets::ShutdownHow how = this->ShutdownHow();
        return this->Shutdown(how);
    }
    virtual bool Shutdown(sockets::ShutdownHow how) {
        Attached detached = ((Attached)Unattached);

        if (((Attached)Unattached) != (detached = this->AttachedTo())) {
            if ((this->ShutdownDetached(detached, how))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached OpenAttached
    (Domain domain, Type type, Protocol protocol) {
        Attached detached = ((Attached)Unattached);

        if ((this->Closed())) {
            if (((Attached)Unattached) !=
                (detached = OpenDetached(domain, type, protocol))) {
                this->Attach(detached);
            }
        }
        return detached;
    }
    virtual Attached OpenDetached
    (Domain domain, Type type, Protocol protocol) const {
        Attached detached = ((Attached)Unattached);

        XOS_LOG_DEBUG("::socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")...");
        if (0 <= (detached = ::socket(domain, type, protocol))) {
            XOS_LOG_DEBUG("...::socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        } else {
            XOS_LOG_ERROR("failed errno = " << errno << " on ::socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        }
        return detached;
    }
    virtual bool CloseDetached(Attached detached) const {
        if (0 <= (detached)) {
            int err = 0;

            XOS_LOG_DEBUG("::close(" << detached << ")...");
            if (!(err = ::close(detached))) {
                XOS_LOG_DEBUG("...::close(" << detached << ")");
                return true;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::close(" << detached << ")");
            }
        }
        return false;
    }
    virtual bool ShutdownDetached(Attached detached, sockets::ShutdownHow how) const {
        if (0 <= (detached)) {
            int sdHow = ((how == this->shutdownRead)?(SHUT_RD)
                        :((how == this->shutdownWrite)?(SHUT_WR)
                        :((how == this->shutdownBoth)?(SHUT_RDWR):(0)))),
                err = 0;

            XOS_LOG_DEBUG("::shutdown(" << detached << ", " << sdHow << ")...");
            if (!(err = ::shutdown(detached, sdHow))) {
                XOS_LOG_DEBUG("...::shutdown(" << detached << ", " << sdHow << ")");
                return true;
            } else {
                bool opt = false, gotOpt = false;

                gotOpt = GetKeepAliveOpt(opt);
                if (!((gotOpt) && (!opt))) {
                    XOS_LOG_ERROR("...failed errno = " << errno << " on ::shutdown(" << detached << ", " << sdHow << ")");
                } else {
                    XOS_LOG_DEBUG("...errno = " << errno << " on ::shutdown(" << detached << ", " << sdHow << ")");
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const SockAddr* addr, SockLen addrlen) {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo())) && (addr) && (addrlen)) {
            int err = 0;

            XOS_LOG_DEBUG("::connect(..., addrlen = " << addrlen << ")...");
            if (!(err = ::connect(detached, addr, addrlen))) {
                XOS_LOG_DEBUG("...::connect(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::connect(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }
    virtual bool Bind(const SockAddr* addr, SockLen addrlen) {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo())) && (addr) && (addrlen)) {
            int err = 0;

            if ((this->BindAsReuseAddr())) {
                this->SetReuseAddrOpt();
            }
            XOS_LOG_DEBUG("::bind(..., addrlen = " << addrlen << ")...");
            if (!(err = ::bind(detached, addr, addrlen))) {
                XOS_LOG_DEBUG("...::bind(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::bind(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }
    virtual bool Listen(sockets::Backlog backlog) {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo()))) {
            int err = 0;

            XOS_LOG_DEBUG("::listen(..., backlog = " << backlog << ")...");
            if (!(err = ::listen(detached, backlog))) {
                XOS_LOG_DEBUG("...::listen(..., backlog = " << backlog << ")...");
                return true;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::listen(..., backlog = " << backlog << ")");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendTo
    (const void* buf, size_t len, const SockAddr* addr, SockLen addrlen) {
        sockets::SendFlags flags = this->SendFlags();
        return this->SendTo(buf, len, flags, addr, addrlen);
    }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, SockAddr* addr, SockLen* addrlen) {
        sockets::RecvFlags flags = this->RecvFlags();
        return this->RecvFrom(buf, len, flags, addr, addrlen);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(const void* buf, size_t len) {
        sockets::SendFlags flags = this->SendFlags();
        return this->Send(buf, len, flags);
    }
    virtual ssize_t Recv(void* buf, size_t len) {
        sockets::RecvFlags flags = this->RecvFlags();
        return this->Recv(buf, len, flags);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendTo
    (const void* buf, size_t len, sockets::SendFlags flags,
     const SockAddr* addr, SockLen addrlen) {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo()))
            && (buf) && (len) && (addr) && (addrlen)) {
            ssize_t count = 0;

            XOS_LOG_DEBUG_TRACE((len > 1), "::sendto(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::sendto(detached, buf, len, flags, addr, addrlen))) {
                XOS_LOG_DEBUG_TRACE((len > 1), "..." << count << " = ::sendto(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::sendto(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, sockets::RecvFlags flags,
     SockAddr* addr, SockLen* addrlen) {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo()))
            && (buf) && (len) && (addr) && (addrlen)) {
            ssize_t count = 0;

            XOS_LOG_DEBUG_TRACE((len > 1), "::recvfrom(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::recvfrom(detached, buf, len, flags, addr, addrlen))) {
                XOS_LOG_DEBUG_TRACE((len > 1), "..." << count << " = ::recvfrom(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::recvfrom(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(const void* buf, size_t len, sockets::SendFlags flags) {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo())) && (buf) && (len)) {
            ssize_t count = 0;

            XOS_LOG_DEBUG_TRACE((len > 1), "::send(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::send(detached, buf, len, flags))) {
                XOS_LOG_DEBUG_TRACE((len > 1), "..." << count << " = ::send(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::send(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    virtual ssize_t Recv(void* buf, size_t len, sockets::RecvFlags flags) {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo())) && (buf) && (len)) {
            ssize_t count = 0;

            XOS_LOG_DEBUG_TRACE((len > 1), "::recv(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::recv(detached, buf, len, flags))) {
                XOS_LOG_DEBUG_TRACE((len > 1), "..." << count << " = ::recv(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::recv(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetFamily(AddressFamily &family, SockAddr &addr) const {
        SockLen addrlen = sizeof(addr);

        memset(&addr, 0, addrlen);
        if ((GetName(&addr, addrlen))) {
            family = (addr.sa_family);
            return true;
        }
        return false;
    }
    virtual bool GetName(SockAddr* addr, SockLen &addrlen) const {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo())) && (addr)) {
            int err = 0;

            XOS_LOG_DEBUG("::getsockname(..., addrlen = " << addrlen << ")...");
            if (!(err = ::getsockname(detached, addr, &addrlen))) {
                XOS_LOG_DEBUG("...::getsockname(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::getsockname(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetKeepAliveOpt(bool on = true) {
        int value = (on)?(1):(0);
        if ((this->SetOpt(SOL_SOCKET, SO_KEEPALIVE, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool SetDontKeepAliveOpt(bool on = true) {
        int value = (on)?(0):(1);
        if ((this->SetOpt(SOL_SOCKET, SO_KEEPALIVE, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool GetKeepAliveOpt(bool &on) const {
        int value = 0;
        SockLen length = sizeof(value);
        XOS_LOG_DEBUG("GetOpt(SOL_SOCKET, SO_KEEPALIVE, &value, length)...");
        if ((this->GetOpt(SOL_SOCKET, SO_KEEPALIVE, &value, length))) {
            XOS_LOG_DEBUG("...GetOpt(SOL_SOCKET, SO_KEEPALIVE, &value = " << value << ", length)");
            on = (value != 0);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDelayOpt(bool on = true) {
        int value = (on)?(0):(1);
        if ((this->SetOpt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool SetNodelayOpt(bool on = true) {
        int value = (on)?(1):(0);
        if ((this->SetOpt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool GetDelayOpt(bool &on) const {
        int value = 0;
        SockLen length = sizeof(value);
        if ((this->GetOpt(IPPROTO_TCP, TCP_NODELAY, &value, length))) {
            on = (value == 0);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = -1) {
        struct linger value;
        value.l_onoff = (on)?(0):(1);
        value.l_linger = (0>lingerSeconds)?(this->DefaultLingerSeconds()):(lingerSeconds);
        if ((this->SetOpt(SOL_SOCKET, SO_LINGER, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool SetDontLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = -1) {
        struct linger value;
        value.l_onoff = (on)?(0):(1);
        value.l_linger = (0>lingerSeconds)?(this->DefaultLingerSeconds()):(lingerSeconds);
        if ((this->SetOpt(SOL_SOCKET, SO_LINGER, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool GetLingerOpt(bool &on, int &lingerSeconds) const {
        struct linger value = {0, 0};
        SockLen length = sizeof(value);
        if ((this->GetOpt(SOL_SOCKET, SO_LINGER, &value, length))) {
            on = (value.l_onoff != 0);
            lingerSeconds = (value.l_linger);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetOpt
    (OptLevel level, OptName name, const void* value, SockLen length) {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo())) && (value) && (length)) {
            int err = 0;

            XOS_LOG_DEBUG("::setsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
            if (!(err = ::setsockopt(detached, level, name, value, length))) {
                XOS_LOG_DEBUG("...::setsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
                return true;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::setsockopt(..., level = " << level << ", name = " << name << ", ..., length)");
            }
        }
        return false;
    }
    virtual bool GetOpt
    (OptLevel level, OptName name, void* value, SockLen &length) const {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo())) && (value)) {
            int err = 0;

            XOS_LOG_DEBUG("::getsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
            if (!(err = ::getsockopt(detached, level, name, value, &length))) {
                XOS_LOG_DEBUG("...::getsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
                return true;
            } else {
                XOS_LOG_ERROR("failed errno = " << errno << " on ::getsockopt(..., level = " << level << ", name = " << name << ", ..., length)");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool BindAsReuseAddr() const {
        return this->DefaultBindAsReuseAddr();
    }
    virtual sockets::Backlog Backlog() const {
        return this->DefaultBacklog();
    }
    virtual sockets::ShutdownHow ShutdownHow() const {
        return this->DefaultShutdownHow();
    }
    virtual sockets::RecvFlags RecvFlags() const {
        return this->DefaultRecvFlags();
    }
    virtual sockets::SendFlags SendFlags() const {
        return this->DefaultSendFlags();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace posix 

typedef posix::InterfaceTImplements InterfaceImplementedImplements;
typedef posix::InterfaceT<> InterfaceImplementedExtends;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceImplemented
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS InterfaceImplemented
: virtual public InterfaceImplementedImplements, public InterfaceImplementedExtends {
public:
    typedef InterfaceImplementedImplements Implements;
    typedef InterfaceImplementedExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    InterfaceImplemented(const InterfaceImplemented& copy): Extends(copy) {
    }
    InterfaceImplemented() {
    }
    virtual ~InterfaceImplemented() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

namespace posix {

typedef sockets::InterfaceImplementedImplements InterfaceImplements;
typedef sockets::InterfaceImplemented InterfaceExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Interface
: virtual public InterfaceImplements, public InterfaceExtends {
public:
    typedef InterfaceImplements Implements;
    typedef InterfaceExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Interface(const Interface& copy): Extends(copy) {
    }
    Interface() {
    }
    virtual ~Interface() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace posix 
} // namespace sockets 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETS_POSIX_INTERFACE_HPP 
