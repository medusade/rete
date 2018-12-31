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
///   File: Endpoint.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_LOCAL_ENDPOINT_HPP
#define _RETE_NETWORK_LOCAL_ENDPOINT_HPP

#include "rete/network/local/Address.hpp"
#include "rete/network/Endpoint.hpp"

namespace rete {
namespace network {
namespace local {

typedef struct sockaddr_un SockAddr;

typedef network::Endpoint EndpointTImplements;
typedef patrona::AttachedT
<SockAddrAttached, int, 0, EndpointTImplements, Address> EndpointTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: EndpointT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = EndpointTImplements, class TExtends = EndpointTExtends>

class _EXPORT_CLASS EndpointT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    EndpointT(const char* path): m_socketAddressLen(0) {
        Clear();
        if (!(this->Attach(path))) {
            AttachException e(AttachFailed);
            CRONO_LOG_ERROR("...throw (AttachException e(AttachFailed))...");
            throw (e);
        }
    }
    EndpointT(const EndpointT& copy)
    : m_socketAddressLen(0) {
        Copy(copy);
    }
    EndpointT(): m_socketAddressLen(0) {
        Clear();
    }
    virtual ~EndpointT() {
        if (!(this->Detached())) {
            AttachException e(DetachFailed);
            CRONO_LOG_ERROR("...throw (AttachException e(DetachFailed))...");
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach(const char* path) {
        if ((path) && (path[0])) {
            Clear();
            strncpy
            (m_socketAddress.sun_path, path,
             sizeof(m_socketAddress.sun_path)-1);
            return Extends::Attach((SockAddrAttached)(&m_socketAddress));
        } else {
            CRONO_LOG_ERROR("...invalid path = " << CharsToString(path));
        }
        return 0;
    }
    virtual EndpointT& Copy(const EndpointT& copy) {
        memcpy
        (&m_socketAddress, &copy.m_socketAddress,
         this->m_socketAddressLen = (this->SocketAddressLen()));
        return *this;
    }
    virtual EndpointT& Clear() {
        memset
        (&m_socketAddress, 0,
         this->m_socketAddressLen = (this->SocketAddressLen()));
        m_socketAddress.sun_family = this->Family();
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockLen SocketAddressLen() const {
        return ((SockLen)sizeof(m_socketAddress));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    SockLen m_socketAddressLen;
    SockAddr m_socketAddress;
};
typedef EndpointT<> Endpoint;

} // namespace local
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_LOCAL_ENDPOINT_HPP 
