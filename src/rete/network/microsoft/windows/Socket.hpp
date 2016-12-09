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
///   Date: 12/3/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_MICROSOFT_WINDOWS_SOCKET_HPP
#define _RETE_NETWORK_MICROSOFT_WINDOWS_SOCKET_HPP

#include "rete/network/Socket.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <errno.h>

#if !defined(WINDOWS)
typedef int SOCKET;
enum { SOCKET_ERROR = -1 };
enum { INVALID_SOCKET = -1 };
enum {
    SD_RECEIVE = 0,
    SD_SEND    = 1,
    SD_BOTH    = 2
};
extern "C" {
int closesocket(
  _In_ SOCKET s
);
int WSAGetLastError(void);
}
#endif // !defined(WINDOWS)

namespace rete {
namespace network {
namespace microsoft {
namespace windows {

typedef SOCKET SocketAttachedTo;
typedef SOCKET SocketUnattachedTo;
static const SocketUnattachedTo SocketUnattached = INVALID_SOCKET;

typedef ::patrona::AttacherT
<SocketAttachedTo, SocketUnattachedTo,
 SocketUnattached, Opener> SocketTAttacher;

typedef ::patrona::AttachedT
<SocketAttachedTo, SocketUnattachedTo,
 SocketUnattached, Socket, Base> SocketTAttached;

typedef ::patrona::OpenedT
<SocketAttachedTo, SocketUnattachedTo, SocketUnattached,
 Socket, SocketTAttached> SocketTOpened;

typedef network::Socket SocketTImplements;
typedef SocketTOpened SocketTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: SocketT
///////////////////////////////////////////////////////////////////////
template
<class TImplemented = SocketTImplemented,
 typename TAttached = SocketAttachedTo,
 typename TUnattached = SocketUnattachedTo,
 TUnattached VUnattached = SocketUnattached,
 typename TDomain = SocketDomain,
 typename TType = SocketType,
 typename TProtocol = SocketProtocol,
 class TTransport = SocketTransport,
 class TEndpoint = SocketEndpoint,
 class TImplements = SocketTImplements, class TExtends = SocketTExtends>

class _EXPORT_CLASS SocketT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TImplemented SocketTImplemented;
    typedef TAttached Attached;
    static const TUnattached Unattached = VUnattached;

    typedef TTransport Transport;
    typedef TEndpoint Endpoint;
    typedef TDomain Domain;
    typedef TType Type;
    typedef TProtocol Protocol;

    typedef SocketLingerSeconds LingerSeconds;
    static const LingerSeconds defaultLingerSeconds = SocketLingerSecondsDefault;
    typedef SocketShutdownHow ShutdownHow;
    typedef SocketBacklog Backlog;
    typedef SocketSendFlags SendFlags;
    typedef SocketRecvFlags RecvFlags;
    typedef SocketOptLevel OptLevel;
    typedef SocketOptName OptName;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    SocketT(const SocketT& copy): Extends(copy.AttachedTo()) {
    }
    SocketT() {
    }
    virtual ~SocketT() {
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
        CRONO_LOG_DEBUG("socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")...");
        if (INVALID_SOCKET != (detached = ::socket(domain, type, protocol))) {
            CRONO_LOG_DEBUG("...socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        } else {
            int error = WSAGetLastError();
            CRONO_LOG_ERROR("failed error = " << error << " on socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        }
        return detached;
    }
    virtual bool CloseDetached(Attached detached) const {
        if (((Attached)Unattached) != (detached)) {
            int err = 0;
            CRONO_LOG_DEBUG("closesocket(" << detached << ")...");
            if (SOCKET_ERROR != (err = ::closesocket(detached))) {
                CRONO_LOG_DEBUG("...closesocket(" << detached << ")");
                return true;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on closesocket(" << detached << ")");
            }
        }
        return false;
    }
    virtual bool ShutdownDetached(Attached detached, ShutdownHow how) const {
        if (((Attached)Unattached) != (detached)) {
            int sdHow = ((how == this->shutdownRead)?(SD_RECEIVE)
                        :((how == this->shutdownWrite)?(SD_SEND)
                        :((how == this->shutdownBoth)?(SD_BOTH):(0)))),
                err = 0;
            CRONO_LOG_DEBUG("shutdown(" << detached << ", " << sdHow << ")...");
            if (SOCKET_ERROR != (err = ::shutdown(detached, sdHow))) {
                CRONO_LOG_DEBUG("...shutdown(" << detached << ", " << sdHow << ")");
                return true;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on shutdown(" << detached << ", " << sdHow << ")");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Connect;
    virtual bool Connect(const SockAddr* addr, SockLen addrlen) {
        Attached detached = ((Attached)Unattached);
        if ((((Attached)Unattached) != (detached = this->AttachedTo())) && (addr) && (addrlen)) {
            int err = 0;
            CRONO_LOG_DEBUG("connect(..., addrlen = " << addrlen << ")...");
            if (SOCKET_ERROR != (err = ::connect(detached, addr, addrlen))) {
                CRONO_LOG_DEBUG("...connect(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on connect(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }
    virtual bool Bind(const SockAddr* addr, SockLen addrlen) {
        Attached detached = ((Attached)Unattached);
        if ((((Attached)Unattached) != (detached = this->AttachedTo())) && (addr) && (addrlen)) {
            int err = 0;
            if ((this->BindAsReuseAddr())) {
                this->SetReuseAddrOpt();
            }
            CRONO_LOG_DEBUG("bind(..., addrlen = " << addrlen << ")...");
            if (SOCKET_ERROR != (err = ::bind(detached, addr, addrlen))) {
                CRONO_LOG_DEBUG("...bind(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on bind(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }
    virtual bool Listen(Backlog backlog) {
        Attached detached = ((Attached)Unattached);
        if ((((Attached)Unattached) != (detached = this->AttachedTo()))) {
            int err = 0;
            CRONO_LOG_DEBUG("listen(..., backlog = " << backlog << ")...");
            if (SOCKET_ERROR != (err = ::listen(detached, backlog))) {
                CRONO_LOG_DEBUG("...listen(..., backlog = " << backlog << ")...");
                return true;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on listen(..., backlog = " << backlog << ")");
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
        const char* msg = 0;
        if ((((Attached)Unattached) != (detached = this->AttachedTo()))
            && (msg = ((const char*)buf)) && (len) && (addr) && (addrlen)) {
            ssize_t count = 0;
            CRONO_LOG_DEBUG("sendto(..., len = " << len << ", flags = " << flags << ")...");
            if (SOCKET_ERROR != (count = ::sendto(detached, msg, len, flags, addr, addrlen))) {
                CRONO_LOG_DEBUG("..." << count << " = sendto(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on sendto(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, RecvFlags flags,
     SockAddr* addr, SockLen* addrlen) {
        Attached detached = ((Attached)Unattached);
        char* msg = 0;
        if ((((Attached)Unattached) != (detached = this->AttachedTo()))
            && (msg = ((char*)buf)) && (len) && (addr) && (addrlen)) {
            ssize_t count = 0;
            CRONO_LOG_DEBUG("recvfrom(..., len = " << len << ", flags = " << flags << ")...");
            if (SOCKET_ERROR != (count = ::recvfrom(detached, msg, len, flags, addr, addrlen))) {
                CRONO_LOG_DEBUG("..." << count << " = recvfrom(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on recvfrom(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(const void* buf, size_t len, SendFlags flags) {
        Attached detached = ((Attached)Unattached);
        const char* buff = 0;
        if ((((Attached)Unattached) != (detached = this->AttachedTo())) 
            && (buff = ((const char*)buf)) && (len)) {
            ssize_t count = 0;
            CRONO_LOG_DEBUG("send(..., len = " << len << ", flags = " << flags << ")...");
            if (SOCKET_ERROR != (count = ::send(detached, buff, len, flags))) {
                CRONO_LOG_DEBUG("..." << count << " = send(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on send(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    virtual ssize_t Recv(void* buf, size_t len, RecvFlags flags) {
        Attached detached = ((Attached)Unattached);
        char* buff = 0;
        if ((((Attached)Unattached) != (detached = this->AttachedTo())) 
            && (buff = ((char*)buf)) && (len)) {
            ssize_t count = 0;
            CRONO_LOG_DEBUG("recv(..., len = " << len << ", flags = " << flags << ")...");
            if (SOCKET_ERROR != (count = ::recv(detached, buff, len, flags))) {
                CRONO_LOG_DEBUG("..." << count << " = recv(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on recv(..., len = " << len << ", flags = " << flags << ")");
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
        if ((((Attached)Unattached) != (detached = this->AttachedTo())) && (addr)) {
            int err = 0;
            CRONO_LOG_DEBUG("getsockname(..., addrlen = " << addrlen << ")...");
            if (SOCKET_ERROR != (err = ::getsockname(detached, addr, &addrlen))) {
                CRONO_LOG_DEBUG("...getsockname(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on getsockname(..., addrlen = " << addrlen << ")");
            }
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
    virtual bool SetNoreuseAddrOpt(bool on = true) {
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
        int value = (on)?(1):(0); // Note opposite of posix
        if ((this->SetOpt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool SetNodelayOpt(bool on = true) {
        int value = (on)?(0):(1); // Note opposite of posix
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
        const char* optval = 0;
        if ((((Attached)Unattached) != (detached = this->AttachedTo())) 
            && (optval = ((const char*)value)) && (length)) {
            int err = 0;
            CRONO_LOG_DEBUG("setsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
            if (SOCKET_ERROR != (err = ::setsockopt(detached, level, name, optval, length))) {
                CRONO_LOG_DEBUG("...setsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
                return true;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on setsockopt(..., level = " << level << ", name = " << name << ", ..., length)");
            }
        }
        return false;
    }
    virtual bool GetOpt
    (OptLevel level, OptName name, void* value, SockLen &length) const {
        Attached detached = ((Attached)Unattached);
        char* optval = 0;
        if ((((Attached)Unattached) != (detached = this->AttachedTo())) && (value)) {
            int err = 0;
            CRONO_LOG_DEBUG("getsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
            if (SOCKET_ERROR != (err = ::getsockopt(detached, level, name, optval, &length))) {
                CRONO_LOG_DEBUG("...getsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
                return true;
            } else {
                int error = WSAGetLastError();
                CRONO_LOG_ERROR("failed error = " << error << " on getsockopt(..., level = " << level << ", name = " << name << ", ..., length)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace windows 
} // namespace microsoft 

typedef microsoft::windows::SocketTImplements SocketTImplementedImplements;
typedef microsoft::windows::SocketT<> SocketTImplementedExtends;
///////////////////////////////////////////////////////////////////////
///  Class: SocketTImplemented
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS SocketTImplemented
: virtual public SocketTImplementedImplements, public SocketTImplementedExtends {
public:
    typedef SocketTImplementedImplements Implements;
    typedef SocketTImplementedExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    SocketTImplemented(const SocketTImplemented& copy): Extends(copy) {}
    SocketTImplemented() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Accept(SocketTImplemented& sock, SockAddr* addr, SockLen& addrlen) {
        if ((sock.Closed())) {
            Attached detached = ((Attached)Unattached);
            if ((((Attached)Unattached) != (detached = this->AttachedTo())) && (addr) && (addrlen)) {
                Attached unattached = ((Attached)Unattached);
                CRONO_LOG_DEBUG("accept(..., addrlen = " << addrlen << ")...");
                if (INVALID_SOCKET != (unattached = ::accept(detached, addr, &addrlen))) {
                    CRONO_LOG_DEBUG("..." << unattached << " = accept(..., addrlen = " << addrlen << ")...");
                    sock.AttachOpened(unattached);
                    return true;
                } else {
                    int error = WSAGetLastError();
                    CRONO_LOG_ERROR("failed error = " << error << " on accept(..., addrlen = " << addrlen << ")");
                }
            }
        }
        return false;
    }
    virtual SocketTImplemented* Implemented() const {
        return ((SocketTImplemented*)this);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

namespace microsoft {
namespace windows {

typedef SocketTImplementedImplements SocketImplements;
typedef SocketTImplemented SocketExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Socket
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Socket
: virtual public SocketImplements, public SocketExtends {
public:
    typedef SocketImplements Implements;
    typedef SocketExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Socket(const Socket& copy): Extends(copy) {}
    Socket() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Accept;
    virtual SocketTImplemented* Accept(SockAddr* addr, SockLen& addrlen) {
        if ((this->Accept(m_accepted, addr, addrlen))) {
            m_accepted.SetIsOpen(false);
            return &m_accepted;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    SocketTImplemented m_accepted;
};

} // namespace windows
} // namespace microsoft
} // namespace network
} // namespace rete 

#endif // _RETE_NETWORK_MICROSOFT_WINDOWS_SOCKET_HPP 
