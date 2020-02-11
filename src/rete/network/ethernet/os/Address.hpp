///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   Date: 2/9/2020
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_ETHERNET_OS_ADDRESS_HPP
#define _RETE_NETWORK_ETHERNET_OS_ADDRESS_HPP

#include "rete/network/ethernet/Address.hpp"
#include "rete/network/ethernet/os/Os.hpp"

#if defined(WINDOWS)
#include "rete/network/ethernet/windows/Address.hpp"
#else /// defined(WINDOWS)
#include "rete/network/ethernet/posix/Address.hpp"
#endif /// defined(WINDOWS)

namespace rete {
namespace network {
namespace ethernet {
namespace os {

typedef os::Address Address;

} /// namespace os
} /// namespace ethernet
} /// namespace network
} /// namespace rete

#endif /// _RETE_NETWORK_ETHERNET_OS_ADDRESS_HPP 
