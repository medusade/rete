///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 12/2/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKET_HPP
#define _RETE_NETWORK_SOCKET_HPP

#include "rete/network/Transport.hpp"
#include "rete/network/Endpoint.hpp"
#include "rete/network/Address.hpp"
#include "rete/base/Opened.hpp"

#include <sys/socket.h>

namespace rete {
namespace network {

typedef struct msghdr MsgHdr;

typedef int SocketBacklog;
typedef int SocketSendFlags;
typedef int SocketRecvFlags;
typedef int SocketOptLevel;
typedef int SocketOptName;

typedef int SocketLingerSeconds;
enum {
    SocketLingerSecondsDefault = -1,
    SocketLingerSecondsNone = 0
};

typedef int SocketShutdownHow;
enum {
    SocketShutdownNone = 0,
    SocketShutdownRead = 1,
    SocketShutdownWrite = 2,
    SocketShutdownBoth = (SocketShutdownRead | SocketShutdownWrite)
};

typedef int SocketAttachedTo;
typedef int SocketUnattachedTo;
enum { SocketUnattached = 0 };

typedef AddressFamily SocketDomain;
typedef TransportType SocketType;
typedef TransportProtocol SocketProtocol;
typedef Transport SocketTransport;
typedef Endpoint SocketEndpoint;

typedef ::patrona::AttacherT
<SocketAttachedTo, SocketUnattachedTo,
 SocketUnattached, Opener> SocketTAttacher;
typedef SocketTAttacher SocketTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: SocketT
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = SocketAttachedTo,
 typename TUnattached = SocketUnattachedTo,
 TUnattached VUnattached = SocketUnattached,
 typename TDomain = SocketDomain,
 typename TType = SocketType,
 typename TProtocol = SocketProtocol,
 class TTransport = SocketTransport,
 class TEndpoint = SocketEndpoint,
 class TImplements = SocketTImplements>

class _EXPORT_CLASS SocketT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TTransport Transport;
    typedef TEndpoint Endpoint;
    typedef TDomain Domain;
    typedef TType Type;
    typedef TProtocol Protocol;
    typedef TAttached Attached;
    enum { Unattached = VUnattached };

    typedef SocketLingerSeconds LingerSeconds;
    static const LingerSeconds defaultLingerSeconds = 10;
    typedef SocketShutdownHow ShutdownHow;
    static const ShutdownHow
        shutdownRead = SocketShutdownRead,
        shutdownWrite = SocketShutdownWrite,
        shutdownBoth = SocketShutdownBoth;
    typedef SocketBacklog Backlog;
    static const Backlog defaultBacklog = SOMAXCONN;
    typedef SocketSendFlags SendFlags;
    typedef SocketRecvFlags RecvFlags;
    typedef SocketOptLevel OptLevel;
    typedef SocketOptName OptName;

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
        Attached detached = ((Attached)Unattached);
        if (((Attached)Unattached) !=
            (detached = OpenAttached(domain, type, protocol))) {
            this->SetIsOpen();
            return true;
        }
        return false;
    }
    virtual bool Close() {
        if ((this->OnClose())) {
            Attached detached = ((Attached)Unattached);
            if (((Attached)Unattached) != (detached = this->Detach())) {
                if ((this->CloseDetached(detached))) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool Shutdown(ShutdownHow how) {
        Attached detached = ((Attached)Unattached);
        if (((Attached)Unattached) != (detached = this->AttachedTo())) {
            if ((this->ShutdownDetached(detached, how))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Shutdown() {
        if ((this->Shutdown(SocketShutdownBoth))) {
            return true;
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
        return detached;
    }
    virtual bool CloseDetached(Attached detached) const {
        return false;
    }
    virtual bool ShutdownDetached(Attached detached, ShutdownHow how) const {
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
    virtual bool Accept(SocketT& sock, const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Accept(sock, addr, &addrlen))) {
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
    virtual bool Connect(const SockAddr* addr, SockLen addrlen) { return false; }
    virtual bool Bind(const SockAddr* addr, SockLen addrlen) { return false; }
    virtual bool Accept(SocketT& sock, SockAddr* addr, SockLen* addrlen) { return false; }
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
    (bool on = true, LingerSeconds lingerSeconds = defaultLingerSeconds) { return false; }
    virtual bool SetDontLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = defaultLingerSeconds) { return false; }
    virtual bool GetLingerOpt(bool &on, int &lingerSeconds) const { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetOpt
    (OptLevel level, OptName name, const void* value, SockLen length) { return false; }
    virtual bool GetOpt
    (OptLevel level, OptName name, void* value, SockLen &length) const { return false; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Backlog DefaultBacklog() const {
        return defaultBacklog;
    }
    virtual LingerSeconds DefaultLingerSeconds() const {
        return defaultLingerSeconds;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnClose() { return true; }
};
typedef SocketT<> Socket;

} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKET_HPP 