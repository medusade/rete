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
///   File: Library.hpp
///
/// Author: $author$
///   Date: 8/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_LIBRARY_HPP
#define _XOS_NETWORK_LIBRARY_HPP

#include "xos/base/Base.hpp"

namespace xos {
namespace network {

typedef ImplementBase LibraryTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LibraryT
///////////////////////////////////////////////////////////////////////
template <class TImplements = LibraryTImplements>

class _EXPORT_CLASS LibraryT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Startup() { return true; }
    virtual bool Cleanup() { return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef LibraryT<> Library;

} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_LIBRARY_HPP 
