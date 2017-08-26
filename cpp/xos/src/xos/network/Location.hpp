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
///   Date: 8/21/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_LOCATION_HPP
#define _XOS_NETWORK_LOCATION_HPP

#include "xos/network/Sockets.hpp"

namespace xos {
namespace network {

typedef ImplementBase LocationTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LocationT
///////////////////////////////////////////////////////////////////////
template <class TImplements = LocationTImplements>

class _EXPORT_CLASS LocationT: virtual public TImplements {
public:
    typedef TImplements Implements;
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
} // namespace xos 

#endif // _XOS_NETWORK_LOCATION_HPP 
