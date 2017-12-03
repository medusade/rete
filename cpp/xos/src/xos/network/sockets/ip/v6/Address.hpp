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
///   File: Address.hpp
///
/// Author: $author$
///   Date: 8/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_IP_V6_ADDRESS_HPP
#define _XOS_NETWORK_SOCKETS_IP_V6_ADDRESS_HPP

#include "xos/network/sockets/ip/Address.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace ip {
namespace v6 {

typedef ip::Address AddressTImplements;
typedef sockets::AddressExtendT<AddressTImplements, Base> AddressTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = AddressTImplements, class TExtends = AddressTExtends>

class _EXPORT_CLASS AddressT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    
    typedef typename Implements::family_t family_t;
    typedef typename Implements::version_t version_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AddressT(const AddressT& copy): Extends(copy) {
    }
    AddressT(): Extends(family_t(AF_INET6), version_t(6)) {
    }
    virtual ~AddressT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual family_t Family() const {
        family_t family(AF_INET6);
        return family;
    }
    virtual version_t Version() const {
        version_t version(6);
        return version;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AddressT<> Address;

} // namespace v6
} // namespace ip 
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_IP_V6_ADDRESS_HPP 
