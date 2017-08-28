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
///   File: Location.hpp
///
/// Author: $author$
///   Date: 8/23/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_LOCATION_HPP
#define _XOS_NETWORK_SOCKETS_LOCATION_HPP

#include "xos/network/Location.hpp"
#include "xos/base/String.hpp"

namespace xos {
namespace network {
namespace sockets {

typedef network::Location LocationTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LocationT
///////////////////////////////////////////////////////////////////////
template <class TImplements = LocationTImplements>

class _EXPORT_CLASS LocationT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef LocationT<> LocationImplements;
typedef Base LocationExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Location
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Location
: virtual public LocationImplements, public LocationExtends {
public:
    typedef LocationImplements Implements;
    typedef LocationExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Location(const String& host, ushort port): m_host(host), m_port(port) {
    }
    Location(ushort port): m_port(port) {
    }
    Location(const Location& copy)
    : m_host(copy.Host()), m_port(copy.Port()) {
    }
    Location(): m_port(0) {
    }
    virtual ~Location() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetHost(const char* to) {
        m_host.Assign(to);
        return m_host.HasChars();
    }
    virtual const char* Host() const {
        return m_host.HasChars();
    }
    virtual ushort SetPort(ushort to) {
        m_port = to;
        return m_port;
    }
    virtual ushort Port() const {
        return m_port;
    }
    virtual Location& operator = (const Location& copy) {
        m_host = copy.Host();
        m_port = copy.Port();
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Location* SocketsLocation() const {
        return (Location*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_host;
    ushort m_port;
};

} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_LOCATION_HPP 
