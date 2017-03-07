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
///   Date: 2/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_LOCAL_ADDRESS_HPP
#define _RETE_NETWORK_LOCAL_ADDRESS_HPP

#include "rete/network/Address.hpp"
#include <sys/un.h>

namespace rete {
namespace network {
namespace local {

typedef network::Address AddressTImplements;
typedef Base AddressTExtends;
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
        return AF_LOCAL;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AddressT<> Address;

} // namespace local
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_LOCAL_ADDRESS_HPP 
