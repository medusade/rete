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
#include "xos/base/String.hpp"

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

typedef Address AddressExtendTImplements;
typedef Base AddressExtendTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: AddressExtendT
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = AddressExtendTImplements, 
 class TExtends = AddressExtendTExtends>

class _EXPORT_CLASS AddressExtendT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;    

    typedef typename Implements::family_t family_t;
    typedef typename Implements::version_t version_t;
    typedef ByteString string_t;
    typedef string_t::char_t char_t;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AddressExtendT
    (const family_t& family, const version_t& version, const char_t* data, size_t len)
    : m_family(family), m_version(version), m_data(data, len) {
    }
    AddressExtendT
    (const family_t& family, const version_t& version)
    : m_family(family), m_version(version) {
    }
    AddressExtendT(const family_t& family): m_family(family) {
    }
    AddressExtendT(const char_t* data, size_t len): m_data(data, len) {
    }
    AddressExtendT(const AddressExtendT& copy)
    : m_version(copy.m_version), m_family(copy.m_family), m_data(copy.m_data) {
    }
    AddressExtendT() {
    }
    virtual ~AddressExtendT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& SetData(const string_t& to) {
        m_data.Assign(to);
        return m_data;
    }
    virtual const string_t& SetData(const char_t* to, size_t len) {
        m_data.Assign(to, len);
        return m_data;
    }
    virtual const string_t& Data() const {
        return m_data;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual family_t SetFamily(const family_t& to) {
        m_family = to;
        return m_family;
    }
    virtual family_t Family() const {
        return m_family;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual version_t SetVersion(const version_t& to) {
        m_version = to;
        return m_version;
    }
    virtual version_t Version() const {
        return m_version;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    family_t m_family;
    version_t m_version;
    string_t m_data;
};
typedef AddressExtendT<> AddressExtend;

namespace link {

typedef sockets::Address AddressTImplements;
typedef sockets::AddressExtend AddressTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = AddressTImplements, class TExtends = AddressTExtends>

class _EXPORT_CLASS AddressT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Implements::family_t family_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AddressT(const AddressT& copy): Extends(copy) {
    }
    AddressT(): Extends(family_t(AF_LINK)) {
    }
    virtual ~AddressT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual family_t Family() const {
        family_t family(AF_LINK);
        return family;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AddressT<> Address;

} // namespace link

namespace unspec {

typedef AddressExtend Address;

} // namespace unspec

} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_ADDRESS_HPP 
