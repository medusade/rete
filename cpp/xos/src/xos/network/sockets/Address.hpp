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
///   Date: 8/23/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_ADDRESS_HPP
#define _XOS_NETWORK_SOCKETS_ADDRESS_HPP

#include "xos/network/sockets/address/Interface.hpp"

namespace xos {
namespace network {
namespace sockets {

typedef network::sockets::address::Interface AddressTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template <class TImplements = AddressTImplements>

class _EXPORT_CLASS AddressT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef typename Implements::family_t family_t;
    typedef typename Implements::version_t version_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef AddressT<> AddressImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Address
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Address: virtual public AddressImplements {
public:
    typedef AddressImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_ADDRESS_HPP 
