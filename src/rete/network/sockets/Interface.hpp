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
///   Date: 7/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETS_INTERFACE_HPP
#define _RETE_NETWORK_SOCKETS_INTERFACE_HPP

#include "rete/network/sockets/Endpoint.hpp"
#include "rete/network/sockets/Location.hpp"
#include "rete/network/sockets/Address.hpp"
#include "rete/network/sockets/Transport.hpp"
#include "rete/base/Opened.hpp"

#include <sys/socket.h>

namespace rete {
namespace network {
namespace sockets {

typedef struct msghdr MsgHdr;

typedef int Backlog;
enum {
    BacklogNone = 0,
    BacklogDefault = SOMAXCONN
};
typedef int SendFlags;
typedef int RecvFlags;
typedef int OptLevel;
typedef int OptName;

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

typedef AddressFamily Domain;
typedef TransportType Type;
typedef TransportProtocol Protocol;

class _EXPORT_CLASS Interface;
class _EXPORT_CLASS InterfaceImplemented;
typedef Opener InterfaceTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template
<class TImplemented = InterfaceImplemented,
 typename TDomain = Domain,
 typename TType = Type,
 typename TProtocol = Protocol,
 class TTransport = Transport,
 class TEndpoint = Endpoint,
 class TImplements = InterfaceTImplements>

class _EXPORT_CLASS InterfaceT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TImplemented InterfaceImplemented;
    typedef TTransport Transport;
    typedef TEndpoint Endpoint;
    typedef TDomain Domain;
    typedef TType Type;
    typedef TProtocol Protocol;

    typedef sockets::LingerSeconds LingerSeconds;
    static const LingerSeconds defaultLingerSeconds = sockets::LingerSecondsDefault;

    typedef sockets::ShutdownHow ShutdownHow;
    static const ShutdownHow shutdownRead = sockets::ShutdownRead;
    static const ShutdownHow shutdownWrite = sockets::ShutdownWrite;
    static const ShutdownHow shutdownBoth = sockets::ShutdownBoth;

    typedef sockets::Backlog Backlog;
    static const Backlog defaultBacklog = sockets::BacklogDefault;

    typedef sockets::SendFlags SendFlags;
    typedef sockets::RecvFlags RecvFlags;
    typedef sockets::OptLevel OptLevel;
    typedef sockets::OptName OptName;

    static const bool defaultBindAsReuseAddr = true;

    typedef sockets::MsgHdr MsgHdr;

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
        ShutdownHow how = ShutdownBoth;
        return this->Shutdown(how);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const SockAddr* addr, SockLen addrlen) {
        return false; }
    virtual bool Bind(const SockAddr* addr, SockLen addrlen) {
        return false; }
    virtual bool Accept
    (InterfaceImplemented& sock, SockAddr* addr, SockLen& addrlen) {
        return false; }
    virtual bool Listen(Backlog backlog) { return false; }
    virtual bool Listen() {
        Backlog backlog = this->DefaultBacklog();
        return this->Listen(backlog);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send
    (const void* buf, size_t len, SendFlags flags) { return 0; }
    virtual ssize_t Recv
    (void* buf, size_t len, RecvFlags flags) { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendTo
    (const void* buf, size_t len, SendFlags flags,
     const SockAddr* addr, SockLen addrlen) { return 0; }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, RecvFlags flags,
     SockAddr* addr, SockLen* addrlen) { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendMsg(const MsgHdr* msg, SendFlags flags) { return 0; }
    virtual ssize_t RecvMsg(MsgHdr* msg, RecvFlags flags) { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetFamily(AddressFamily &family, SockAddr &addr) const
    { return false; }
    virtual bool GetName(SockAddr* addr, SockLen &addrlen) const
    { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetReuseAddrOpt(bool on = true) { return false; }
    virtual bool SetNoreuseAddrOpt(bool on = true) { return false; }
    virtual bool GetReuseAddrOpt(bool &on) const { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDelayOpt(bool on = true) { return false; }
    virtual bool SetNodelayOpt(bool on = true) { return false; }
    virtual bool GetDelayOpt(bool &on) const { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = -1) {
        return false; }
    virtual bool SetDontLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = -1) {
        return false; }
    virtual bool GetLingerOpt(bool &on, int &lingerSeconds) const {
        return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetOpt
    (OptLevel level, OptName name, const void* value, SockLen length) {
        return false; }
    virtual bool GetOpt
    (OptLevel level, OptName name, void* value, SockLen &length) const {
        return false; }

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
    virtual InterfaceImplemented* Implemented() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace sockets
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETS_INTERFACE_HPP 
