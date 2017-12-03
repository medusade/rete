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
///   File: Addresses.hpp
///
/// Author: $author$
///   Date: 11/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_INTERFACES_ADDRESSES_HPP
#define _XOS_NETWORK_SOCKETS_INTERFACES_ADDRESSES_HPP

#include "xos/network/sockets/address/Interface.hpp"
#include "xos/network/sockets/Address.hpp"
#include "xos/network/sockets/ip/Address.hpp"
#include "xos/network/sockets/ip/v4/Address.hpp"
#include "xos/network/sockets/ip/v6/Address.hpp"
#include "xos/network/ethernet/actual/Address.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace interfaces {

///////////////////////////////////////////////////////////////////////
///  Class: AddressesT
///////////////////////////////////////////////////////////////////////
template <class TImplements = ImplementBase>

class _EXPORT_CLASS AddressesT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef address::Interface Address;
    typedef const void* AddressAt;
    typedef unspec::Address UnspecAddress;
    typedef link::Address LinkAddress;
    typedef ip::Address IpAddress;
    typedef ip::v4::Address IpV4Address;
    typedef ip::v6::Address IpV6Address;
    typedef ethernet::actual::Address EthernetAddress;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Address* GetFirst() {
        return 0;
    }
    virtual const Address* GetNext() {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AddressesT<> Addresses;

} // namespace interfaces 
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_INTERFACES_ADDRESSES_HPP 
