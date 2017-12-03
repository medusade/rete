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
///   Date: 8/23/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_INTERFACE_HPP
#define _XOS_NETWORK_SOCKETS_INTERFACE_HPP

#include "xos/network/sockets/Endpoint.hpp"
#include "xos/network/sockets/Location.hpp"
#include "xos/network/sockets/Address.hpp"
#include "xos/network/sockets/Transport.hpp"
#include "xos/network/Interface.hpp"
#include "xos/base/Opened.hpp"

namespace xos {
namespace network {
namespace sockets {

///////////////////////////////////////////////////////////////////////
///  Class: Platform
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Platform: virtual public Sockets {
public:
    typedef Sockets Implements;

    typedef sockets::Transport Transport;
    typedef Transport::domain_t::which_t Domain;
    typedef Transport::type_t::which_t Type;
    typedef Transport::protocol_t::which_t Protocol;

    typedef sockets::Endpoint Endpoint;
    typedef Endpoint::AddressFamily AddressFamily;

    typedef struct msghdr MsgHdr;

    typedef int Backlog;
    enum {
        BacklogNone = 0,
        BacklogDefault = SOMAXCONN
    };

    typedef int LingerSeconds;
    enum {
        LingerSecondsNone = 0,
        LingerSecondsDefault = 10
    };

    typedef int ShutdownHow;
    enum {
        ShutdownRead,
        ShutdownWrite,
        ShutdownBoth
    };

    typedef int SendFlags;
    typedef int RecvFlags;
    typedef int OptLevel;
    typedef int OptName;

    static const bool defaultBindAsReuseAddr = true;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

class _EXPORT_CLASS Interface;
class _EXPORT_CLASS InterfaceImplemented;
typedef OpenT<OpenException, network::Interface> InterfaceTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template
<class TPlatform = Platform, class TImplements = InterfaceTImplements>

class _EXPORT_CLASS InterfaceT: virtual public TImplements {
public:
    typedef TImplements Implements;

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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open(const network::Transport& tp) {
        const Transport* _tp = 0;
        if ((_tp = tp.const_SocketsTransport())) {
            return this->Open(*_tp);
        }
        return false;
    }
    virtual bool Open(const Transport& tp) {
        Domain domain = tp.Domain();
        Type type = tp.Type();
        Protocol protocol = tp.Protocol();

        if ((this->Open(domain, type, protocol))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const network::Endpoint& ep) {
        const Endpoint* _ep = 0;
        if ((_ep = ep.const_SocketsEndpoint())) {
            return this->Connect(*_ep);
        }
        return false;
    }
    virtual bool Listen(const network::Endpoint& ep, Backlog backlog) {
        const Endpoint* _ep = 0;
        if ((_ep = ep.const_SocketsEndpoint())) {
            return this->Listen(*_ep, backlog);
        }
        return false;
    }
    virtual bool Listen(const network::Endpoint& ep) {
        const Endpoint* _ep = 0;
        if ((_ep = ep.const_SocketsEndpoint())) {
            return this->Listen(*_ep);
        }
        return false;
    }
    virtual bool Accept
    (network::Interface& in, const network::Endpoint& ep) {
        Interface* _in = 0;
        if ((_in = in.SocketsInterface())) {
            return this->Accept(*_in, ep);
        }
        return false;
    }
    virtual bool Accept
    (Interface& in, const network::Endpoint& ep) {
        const Endpoint* _ep = 0;
        if ((_ep = ep.const_SocketsEndpoint())) {
            return this->Accept(in, *_ep);
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Connect(addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Listen(const Endpoint& ep, Backlog backlog) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Bind(addr, addrlen))) {
                if ((this->Listen(backlog))) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool Listen(const Endpoint& ep) {
        Backlog backlog = this->DefaultBacklog();
        if ((this->Listen(ep, backlog))) {
            return true;
        }
        return false;
    }
    virtual bool Accept(InterfaceImplemented& sock, const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Accept(sock, addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Accept(Interface& sock, const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Accept(sock, addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Bind(const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Bind(addr, addrlen))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendTo
    (const void* buf, size_t len, SendFlags flags, const Endpoint& ep) {
        const SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            ssize_t count = this->SendTo(buf, len, flags, addr, addrlen);
            return count;
        }
        return 0;
    }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, RecvFlags flags, const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            ssize_t count = this->RecvFrom(buf, len, flags, addr, &addrlen);
            return count;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open(Domain domain, Type type, Protocol protocol) {
        return false;
    }
    virtual bool Close() {
        return false;
    }
    virtual bool Shutdown(ShutdownHow how) {
        return false;
    }
    virtual bool Shutdown() {
        ShutdownHow how = shutdownBoth;
        return this->Shutdown(how);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const SockAddr* addr, SockLen addrlen) {
        return false;
    }
    virtual bool Bind(const SockAddr* addr, SockLen addrlen) {
        return false;
    }
    virtual bool Accept
    (InterfaceImplemented& sock, SockAddr* addr, SockLen& addrlen) {
        return false;
    }
    virtual bool Accept
    (Interface& sock, SockAddr* addr, SockLen& addrlen) {
        return false;
    }
    virtual bool Listen(Backlog backlog) {
        return false;
    }
    virtual bool Listen() {
        Backlog backlog = this->DefaultBacklog();
        return this->Listen(backlog);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send
    (const void* buf, size_t len, SendFlags flags) {
        return 0;
    }
    virtual ssize_t Recv
    (void* buf, size_t len, RecvFlags flags) {
        return 0;
    }
    virtual ssize_t Send(const void* buf, size_t len) {
        SendFlags flags = 0;
        return Send(buf, len, flags);
    }
    virtual ssize_t Recv(void* buf, size_t len) {
        RecvFlags flags = 0;
        return Recv(buf, len, flags);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendTo
    (const void* buf, size_t len, SendFlags flags,
     const SockAddr* addr, SockLen addrlen) {
        return 0;
    }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, RecvFlags flags,
     SockAddr* addr, SockLen* addrlen) {
        return 0;
    }
    virtual ssize_t SendTo
    (const void* buf, size_t len, const SockAddr* addr, SockLen addrlen) {
        SendFlags flags = 0;
        return SendTo(buf, len, flags, addr, addrlen);
    }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, SockAddr* addr, SockLen* addrlen) {
        RecvFlags flags = 0;
        return RecvFrom(buf, len, flags, addr, addrlen);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendMsg(const MsgHdr* msg, SendFlags flags) {
        return 0;
    }
    virtual ssize_t RecvMsg(MsgHdr* msg, RecvFlags flags) {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetFamily(AddressFamily &family, SockAddr &addr) const {
        return false;
    }
    virtual bool GetName(SockAddr* addr, SockLen &addrlen) const{
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetKeepAliveOpt(bool on = true) {
        return false;
    }
    virtual bool SetDontKeepAliveOpt(bool on = true) {
        return false;
    }
    virtual bool GetKeepAliveOpt(bool &on) const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetReuseAddrOpt(bool on = true) {
        return false;
    }
    virtual bool SetDontReuseAddrOpt(bool on = true) {
        return false;
    }
    virtual bool GetReuseAddrOpt(bool &on) const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDelayOpt(bool on = true) {
        return false;
    }
    virtual bool SetNodelayOpt(bool on = true) {
        return false;
    }
    virtual bool GetDelayOpt(bool &on) const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = -1) {
        return false;
    }
    virtual bool SetDontLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = -1) {
        return false;
    }
    virtual bool GetLingerOpt(bool &on, int &lingerSeconds) const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetOpt
    (OptLevel level, OptName name, const void* value, SockLen length) {
        return false;
    }
    virtual bool GetOpt
    (OptLevel level, OptName name, void* value, SockLen &length) const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Backlog DefaultBacklog() const {
        return defaultBacklog;
    }
    virtual LingerSeconds DefaultLingerSeconds() const {
        return defaultLingerSeconds;
    }
    virtual bool DefaultBindAsReuseAddr() const {
        return defaultBindAsReuseAddr;
    }
    virtual bool BindAsReuseAddr() const {
        return DefaultBindAsReuseAddr();
    }
    virtual InterfaceImplemented* Implemented() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef InterfaceT<> InterfaceImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Interface: virtual public InterfaceImplements {
public:
    typedef InterfaceImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Accept;
    virtual bool Accept
    (Interface& sock, SockAddr* addr, SockLen& addrlen) {
        InterfaceImplemented* implemented = 0;
        if ((implemented = sock.Implemented())) {
            return Accept(*implemented, addr, addrlen);
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Interface* SocketsInterface() const {
        return (Interface*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef Base InterfaceExtends;

} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_INTERFACE_HPP 
