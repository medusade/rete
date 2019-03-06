///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   File: Version.hpp
///
/// Author: $author$
///   Date: 3/4/2019
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_LIB_RETE_VERSION_HPP
#define _RETE_LIB_RETE_VERSION_HPP

#include "rete/lib/Version.hpp"

namespace rete {
namespace lib {
namespace rete {

///////////////////////////////////////////////////////////////////////
///  Class: Version
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Version {
public:
    static const lib::Version& Which();
}; /// class _EXPORT_CLASS Version

} /// namespace rete
} /// namespace lib
} /// namespace rete

#endif /// _RETE_LIB_RETE_VERSION_HPP 
