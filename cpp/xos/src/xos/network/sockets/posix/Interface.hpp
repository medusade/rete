///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   Date: 8/24/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_POSIX_INTERFACE_HPP
#define _XOS_NETWORK_SOCKETS_POSIX_INTERFACE_HPP

#include "xos/network/sockets/Interface.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace posix {

typedef int SocketAttachedTo;
typedef int SocketUnattachedTo;
enum { SocketUnattached = 0 };

typedef AttachT
<SocketAttachedTo, SocketUnattachedTo,
 SocketUnattached, AttachException, sockets::Interface> SocketTAttach;

typedef AttachedT
<SocketAttachedTo, SocketUnattachedTo,
 SocketUnattached, AttachException, SocketTAttach, Base> SocketTAttached;

typedef OpenedT
<SocketAttachedTo, SocketUnattachedTo, SocketUnattached,
 OpenException, SocketTAttach, SocketTAttached> SocketTOpened;

typedef SocketTAttach InterfaceTImplements;
typedef SocketTOpened InterfaceTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template
<class TPlatform = sockets::Platform,
 class TImplements = InterfaceTImplements, class TExtends = InterfaceTExtends>

class _EXPORT_CLASS InterfaceT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TPlatform Platform;

    typedef typename Platform::Transport Transport;
    typedef typename Transport::domain_t::which_t Domain;
    typedef typename Transport::type_t::which_t Type;
    typedef typename Transport::protocol_t::which_t Protocol;

    typedef typename Platform::Endpoint Endpoint;
    typedef typename Endpoint::AddressFamily AddressFamily;

    typedef typename Platform::LingerSeconds LingerSeconds;
    static const LingerSeconds defaultLingerSeconds = Platform::LingerSecondsDefault;

    typedef typename Platform::ShutdownHow ShutdownHow;
    static const ShutdownHow shutdownRead = Platform::ShutdownRead;
    static const ShutdownHow shutdownWrite = Platform::ShutdownWrite;
    static const ShutdownHow shutdownBoth = Platform::ShutdownBoth;

    typedef typename Platform::Backlog Backlog;
    static const Backlog defaultBacklog = Platform::BacklogDefault;

    typedef typename Platform::SendFlags SendFlags;
    typedef typename Platform::RecvFlags RecvFlags;
    typedef typename Platform::OptLevel OptLevel;
    typedef typename Platform::OptName OptName;

    typedef typename Platform::MsgHdr MsgHdr;

    static const bool defaultBindAsReuseAddr = Platform::defaultBindAsReuseAddr;

    typedef typename Extends::Attached Attached;
    typedef typename Extends::Unattached_t Unattached_t;
    static const Unattached_t Unattached = Extends::Unattached;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: InterfaceT
    ///////////////////////////////////////////////////////////////////////
    InterfaceT(const InterfaceT& copy): Extends(copy.AttachedTo()) {
    }
    InterfaceT() {
    }
    virtual ~InterfaceT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Open;
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
    using Extends::Shutdown;
    virtual bool Shutdown(ShutdownHow how) {
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
    virtual bool ShutdownDetached(Attached detached, ShutdownHow how) const {
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
    using Extends::Connect;
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
    using Extends::Listen;
    virtual bool Listen(Backlog backlog) {
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
    (const void* buf, size_t len, SendFlags flags,
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
    (void* buf, size_t len, RecvFlags flags,
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
    virtual ssize_t Send(const void* buf, size_t len, SendFlags flags) {
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
    virtual ssize_t Recv(void* buf, size_t len, RecvFlags flags) {
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
    virtual bool SetReuseAddrOpt(bool on = true) {
        int value = (on)?(1):(0);
        if ((this->SetOpt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool SetDontReuseAddrOpt(bool on = true) {
        int value = (on)?(0):(1);
        if ((this->SetOpt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool GetReuseAddrOpt(bool &on) const {
        int value = 0;
        SockLen length = sizeof(value);
        if ((this->GetOpt(SOL_SOCKET, SO_REUSEADDR, &value, length))) {
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
    /// Constructor: InterfaceImplemented
    ///////////////////////////////////////////////////////////////////////
    InterfaceImplemented(const InterfaceImplemented& copy): Extends(copy) {
    }
    InterfaceImplemented() {
    }
    virtual ~InterfaceImplemented() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Accept;
    virtual bool Accept(InterfaceImplemented& sock, SockAddr* addr, SockLen& addrlen) {
        if ((sock.Closed())) {
            Attached detached = ((Attached)Unattached);

            if ((0 <= (detached = this->AttachedTo())) && (addr) && (addrlen)) {
                Attached unattached = ((Attached)Unattached);

                XOS_LOG_DEBUG("::accept(..., addrlen = " << addrlen << ")...");
                if (0 <= (unattached = ::accept(detached, addr, &addrlen))) {
                    XOS_LOG_DEBUG("..." << unattached << " = ::accept(..., addrlen = " << addrlen << ")...");
                    sock.AttachOpened(unattached);
                    return true;
                } else {
                    XOS_LOG_ERROR("failed errno = " << errno << " on ::accept(..., addrlen = " << addrlen << ")");
                }
            }
        }
        return false;
    }
    virtual InterfaceImplemented* Implemented() const {
        return ((InterfaceImplemented*)this);
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
    /// Constructor: Interface
    ///////////////////////////////////////////////////////////////////////
    Interface(const Interface& copy): Extends(copy) {
    }
    Interface() {
    }
    virtual ~Interface() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Accept;
    virtual InterfaceImplemented* Accept(SockAddr* addr, SockLen& addrlen) {
        if ((this->Accept(m_accepted, addr, addrlen))) {
            m_accepted.SetIsOpen(false);
            return &m_accepted;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    InterfaceImplemented m_accepted;
};

} // namespace posix
} // namespace sockets
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_POSIX_INTERFACE_HPP 
