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
///   File: Address.hpp
///
/// Author: $author$
///   Date: 11/30/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_IP_V4_ADDRESS_HPP
#define _RETE_NETWORK_IP_V4_ADDRESS_HPP

#include "rete/network/ip/Address.hpp"

namespace rete {
namespace network {
namespace ip {
namespace v4 {

typedef ip::AddressTImplements AddressTImplements;
typedef ip::Address AddressTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template
<typename TFamily = AddressFamily, typename TVersion = AddressVersion,
 class TImplements = AddressTImplements, class TExtends = AddressTExtends>

class _EXPORT_CLASS AddressT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TFamily tFamily;
    typedef TVersion tVersion;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AddressT() {
    }
    virtual ~AddressT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tFamily Family() const {
        return AF_INET;
    }
    virtual tVersion Version() const {
        return 4;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AddressT<> Address;

} // namespace v4 
} // namespace ip 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_IP_V4_ADDRESS_HPP 
