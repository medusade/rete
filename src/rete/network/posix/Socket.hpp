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
#ifndef _RETE_NETWORK_POSIX_SOCKET_HPP
#define _RETE_NETWORK_POSIX_SOCKET_HPP

#include "rete/network/Socket.hpp"

namespace rete {
namespace network {
namespace posix {

typedef ::patrona::AttachedT
<SocketAttachedTo, SocketUnattachedTo,
 SocketUnattached, Socket, Base> SocketTAttached;
typedef ::patrona::OpenedT
<SocketAttachedTo, SocketUnattachedTo, SocketUnattached,
 Socket, SocketTAttached> SocketTOpened;
typedef Socket SocketTImplements;
typedef SocketTOpened SocketTExtends;
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
 class TImplements = SocketTImplements,
 class TExtends = SocketTExtends>

class _EXPORT_CLASS SocketT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TTransport Transport;
    typedef TEndpoint Endpoint;
    typedef TDomain Domain;
    typedef TType Type;
    typedef TProtocol Protocol;
    typedef TAttached Attached;
    enum { Unattached = VUnattached };
    typedef SocketShutdownHow ShutdownHow;

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
    virtual Attached OpenDetached
    (Domain domain, Type type, Protocol protocol) const {
        Attached detached = ((Attached)Unattached);
        CRONO_LOG_DEBUG("socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")...");
        if (0 <= (detached = ::socket(domain, type, protocol))) {
            CRONO_LOG_DEBUG("...socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        } else {
            CRONO_LOG_ERROR("failed errno = " << errno << " on socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        }
        return detached;
    }
    virtual bool CloseDetached(Attached detached) const {
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
    virtual bool ShutdownDetached(Attached detached, ShutdownHow how) const {
        if (0 <= (detached)) {
            int sdHow = ((how & this->shutdownRead)?(SHUT_RD):(0))
                        | ((how & this->shutdownWrite)?(SHUT_WR):(0))
                        | ((how & this->shutdownBoth)?(SHUT_RDWR):(0)),
                err = 0;
            CRONO_LOG_DEBUG("shutdown(" << detached << ", " << sdHow << ")...");
            if (!(err = ::shutdown(detached, sdHow))) {
                CRONO_LOG_DEBUG("...shutdown(" << detached << ", " << sdHow << ")");
                return true;
            } else {
                CRONO_LOG_ERROR("failed errno = " << errno << " on shutdown(" << detached << ", " << sdHow << ")");
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
            CRONO_LOG_DEBUG("connect(..., addrlen = " << addrlen << ")...");
            if (!(err = ::connect(detached, addr, addrlen))) {
                CRONO_LOG_DEBUG("...connect(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                CRONO_LOG_ERROR("failed errno = " << errno << " on connect(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef SocketT<> Socket;

} // namespace posix 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_POSIX_SOCKET_HPP 
