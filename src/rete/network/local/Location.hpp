///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: Location.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_LOCAL_LOCATION_HPP
#define _RETE_NETWORK_LOCAL_LOCATION_HPP

#include "rete/network/Location.hpp"

namespace rete {
namespace network {
namespace local {

typedef network::LocationTImplements LocationImplements;
typedef network::Location LocationExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Location
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Location
: virtual public LocationImplements, public LocationExtends {
public:
    typedef LocationImplements Implements;
    typedef LocationExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Location(const String& path): m_path(path) {
    }
    Location(const Location& copy): m_path(copy.m_path) {
    }
    Location() {
    }
    virtual ~Location() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual local::Location* LocalLocation() const {
        return (local::Location*)this;
    }
    virtual const char* SetPath(const char* to) {
        m_path.assign(to);
        return m_path.has_chars();
    }
    virtual const char* Path() const {
        return m_path.has_chars();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_path;
};

} // namespace local 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_LOCAL_LOCATION_HPP 
