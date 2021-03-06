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
///   File: Sockets.hpp
///
/// Author: $author$
///   Date: 12/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_OS_SOCKETS_HPP
#define _RETE_NETWORK_OS_SOCKETS_HPP

#include "rete/network/os/Socket.hpp"
#include "rete/network/Sockets.hpp"

#if defined(WINDOWS)
// Windows
#include "rete/network/microsoft/windows/Sockets.hpp"
#elif defined(MACOSX)
// MacOSX
#include "rete/network/apple/osx/Sockets.hpp"
#else // defined(WINDOWS)
// Posix
#include "rete/network/posix/Sockets.hpp"
#endif // defined(WINDOWS)

namespace rete {
namespace network {
namespace os {

typedef os::Sockets Sockets;

} // namespace os
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_OS_SOCKETS_HPP 
