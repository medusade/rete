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
///   Date: 7/11/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_LOCATION_HPP
#define _RETE_NETWORK_LOCATION_HPP

#include "rete/network/Sockets.hpp"

namespace rete {
namespace network {

namespace local {

class _EXPORT_CLASS Location;

} // namespace local

typedef ImplementBase LocationTImplements;
typedef Base LocationTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LocationT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = LocationTImplements, class TExtends = LocationTExtends>
class _EXPORT_CLASS LocationT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LocationT() {
    }
    virtual ~LocationT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const local::Location* const_LocalLocation() const {
        return LocalLocation();
    }
    virtual local::Location* LocalLocation() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const sockets::Location* const_SocketsLocation() const {
        return SocketsLocation();
    }
    virtual sockets::Location* SocketsLocation() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef LocationT<> Location;

} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_LOCATION_HPP 
