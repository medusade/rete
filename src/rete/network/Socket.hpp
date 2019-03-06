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
///   File: Socket.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKET_HPP
#define _RETE_NETWORK_SOCKET_HPP

#include "rete/network/Transport.hpp"
#include "rete/network/Endpoint.hpp"
#include "rete/network/Address.hpp"
#include "rete/network/Connection.hpp"

#include <sys/socket.h>

namespace rete {
namespace network {

typedef struct msghdr MsgHdr;

typedef int SocketBacklog;
enum {
    SocketBacklogNone = 0,
    SocketBacklogDefault = SOMAXCONN
};
typedef int SocketSendFlags;
enum {
    SocketSendFlagsDefault = 0
};
typedef int SocketRecvFlags;
enum {
    SocketRecvFlagsDefault = 0
};
typedef int SocketOptLevel;
typedef int SocketOptName;

typedef int SocketLingerSeconds;
enum {
    SocketLingerSecondsNone = 0,
    SocketLingerSecondsDefault = 10
};

typedef int SocketShutdownHow;
enum {
    SocketShutdownRead,
    SocketShutdownWrite,
    SocketShutdownBoth,
    SocketShutdownDefault = SocketShutdownBoth
};

typedef AddressFamily SocketDomain;
typedef TransportType SocketType;
typedef TransportProtocol SocketProtocol;
typedef Transport SocketTransport;
typedef Endpoint SocketEndpoint;

class _EXPORT_CLASS Socket;
class _EXPORT_CLASS SocketTImplemented;

namespace sockets {
typedef network::Connection ConnectionImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Connection
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Connection: virtual public ConnectionImplements {
public:
    typedef ConnectionImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SocketTImplemented* Implemented() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace sockets

typedef sockets::Connection SocketTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: SocketT
///////////////////////////////////////////////////////////////////////
template
<class TImplemented = SocketTImplemented,
 typename TDomain = SocketDomain,
 typename TType = SocketType,
 typename TProtocol = SocketProtocol,
 class TTransport = SocketTransport,
 class TEndpoint = SocketEndpoint,
 class TImplements = SocketTImplements>

class _EXPORT_CLASS SocketT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef network::Connection Connection;
    typedef TImplemented SocketTImplemented;
    typedef TTransport Transport;
    typedef TEndpoint Endpoint;
    typedef TDomain Domain;
    typedef TType Type;
    typedef TProtocol Protocol;

    typedef SocketLingerSeconds LingerSeconds;
    static const LingerSeconds defaultLingerSeconds = SocketLingerSecondsDefault;

    typedef SocketShutdownHow ShutdownHow;
    static const ShutdownHow shutdownRead = SocketShutdownRead;
    static const ShutdownHow shutdownWrite = SocketShutdownWrite;
    static const ShutdownHow shutdownBoth = SocketShutdownBoth;
    static const ShutdownHow defaultShutdownHow = SocketShutdownDefault;

    typedef SocketBacklog Backlog;
    static const Backlog defaultBacklog = SocketBacklogDefault;

    typedef SocketSendFlags SendFlags;
    static const SendFlags defaultSendFlags = SocketSendFlagsDefault;
    
    typedef SocketRecvFlags RecvFlags;
    static const RecvFlags defaultRecvFlags = SocketRecvFlagsDefault;
    
    typedef SocketOptLevel OptLevel;
    typedef SocketOptName OptName;
    
    static const bool bindAsReuseAddr = true;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open(const Transport& transport) {
        Domain domain = transport.Domain();
        Type type = transport.Type();
        Protocol protocol = transport.Protocol();
        if ((this->Open(domain, type, protocol))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open
    (Domain domain, Type type, Protocol protocol) {
        return false;
    }
    virtual bool Close() {
        return false;
    }
    virtual bool Shutdown(ShutdownHow how) {
        return false;
    }
    virtual bool Shutdown() {
        if ((this->Shutdown(this->DefaultShutdownHow()))) {
            return true;
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
    virtual bool Accept(Connection& cn, const Endpoint& ep) {
        sockets::Connection* sc = 0;
        if ((sc = cn.SocketsConnection())) {
            SocketTImplemented* sock = 0;
            if ((sock = sc->Implemented())) {
                return Accept(*sock, ep);
            }
        }
        return false;
    }
    virtual bool Accept(SocketTImplemented& sock, const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Accept(sock, addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual SocketTImplemented* Accept(const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            SocketTImplemented* sock = 0;
            if (sock = (this->Accept(addr, addrlen))) {
                return sock;
            }
        }
        return 0;
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
    virtual bool Connect(const SockAddr* addr, SockLen addrlen) { return false; }
    virtual bool Bind(const SockAddr* addr, SockLen addrlen) { return false; }
    virtual bool Accept(SocketTImplemented& sock, SockAddr* addr, SockLen& addrlen) { return false; }
    virtual SocketTImplemented* Accept(SockAddr* addr, SockLen& addrlen) { return 0; }
    virtual bool Listen(Backlog backlog) { return false; }
    virtual bool Listen() {
        Backlog backlog = this->DefaultBacklog();
        if ((this->Listen(backlog))) {
            return true;
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
    virtual ssize_t SendTo
    (const void* buf, size_t len, SendFlags flags,
     const SockAddr* addr, SockLen addrlen) { return 0; }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, RecvFlags flags,
     SockAddr* addr, SockLen* addrlen) { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(const void* message, size_t length) {
        ssize_t count = this->Send(message, length, this->DefaultSendFlags());
        return count;
    }
    virtual ssize_t Recv(void* message, size_t size) {
        ssize_t count = this->Recv(message, size, this->DefaultRecvFlags());
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send
    (const void* buf, size_t len, SendFlags flags) { return 0; }
    virtual ssize_t Recv
    (void* buf, size_t len, RecvFlags flags) { return 0; }

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
    (bool on = true, LingerSeconds lingerSeconds = -1) { return false; }
    virtual bool SetDontLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = -1) { return false; }
    virtual bool GetLingerOpt(bool &on, int &lingerSeconds) const { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetOpt
    (OptLevel level, OptName name, const void* value, SockLen length) { return false; }
    virtual bool GetOpt
    (OptLevel level, OptName name, void* value, SockLen &length) const { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SendFlags DefaultSendFlags() const {
        return defaultSendFlags;
    }
    virtual RecvFlags DefaultRecvFlags() const {
        return defaultRecvFlags;
    }
    virtual ShutdownHow DefaultShutdownHow() const {
        return defaultShutdownHow;
    }
    virtual Backlog DefaultBacklog() const {
        return defaultBacklog;
    }
    virtual LingerSeconds DefaultLingerSeconds() const {
        return defaultLingerSeconds;
    }
    virtual bool BindAsReuseAddr() const {
        return bindAsReuseAddr;
    }
    virtual SocketTImplemented* Implemented() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnClose() { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sockets::Connection* SocketsConnection() const {
        return (sockets::Connection*)this;
    }
};

typedef SocketT<> SocketImplements;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Socket: virtual public SocketImplements {
public:
    typedef SocketImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Clone(Socket*& sock) {
        sock = 0;
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKET_HPP 
