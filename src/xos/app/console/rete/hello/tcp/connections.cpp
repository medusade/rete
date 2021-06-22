///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: connections.cpp
///
/// Author: $author$
///   Date: 6/21/2021
///////////////////////////////////////////////////////////////////////
#include "xos/app/console/rete/hello/tcp/connections.hpp"

#if !defined(XOS_APP_CONSOLE_RETE_HELLO_TCP_CONNECTIONS_INSTANCE)
///#define XOS_APP_CONSOLE_RETE_HELLO_TCP_CONNECTIONS_INSTANCE
#endif /// !defined(XOS_APP_CONSOLE_RETE_HELLO_TCP_CONNECTIONS_INSTANCE)

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {
namespace tcp {

///  Class: connectionst
#if defined(XOS_APP_CONSOLE_RETE_HELLO_TCP_CONNECTIONS_INSTANCE)
static connections the_connections;
#endif /// defined(XOS_APP_CONSOLE_RETE_HELLO_TCP_CONNECTIONS_INSTANCE)


} /// namespace tcp
} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos
