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
///   Date: 2/8/2020
///////////////////////////////////////////////////////////////////////
#ifndef RETE_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP
#define RETE_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP

#include "rete/network/Address.hpp"
#include "xos/base/exception.hpp"
#include "xos/base/string.hpp"
#include "xos/base/to_string.hpp"
#include "xos/base/wrapped.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE 6

///////////////////////////////////////////////////////////////////////
/// OUI group/indiviual bit
///////////////////////////////////////////////////////////////////////
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP 0x01
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP 0
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP 0

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_INDIVIDUAL 0x00
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GROUP      0x01

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL 0
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP      1

///////////////////////////////////////////////////////////////////////
/// OUI local/global bit
///////////////////////////////////////////////////////////////////////
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_LOCAL 0x02
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_LOCAL 1
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_LOCAL 0

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GLOBAL 0x00
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_LOCAL  0x02

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GLOBAL 0
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_LOCAL  1

///////////////////////////////////////////////////////////////////////
/// OUI multicast/unicast bit
///////////////////////////////////////////////////////////////////////
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_UNICAST   NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_INDIVIDUAL
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GROUP

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_UNICAST   NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace rete {
namespace network {
namespace ethernet {

namespace actual {
#include "xos/platform/platform_packed_begin.h"
///////////////////////////////////////////////////////////////////////
/// Struct: Address
///////////////////////////////////////////////////////////////////////
struct PACKED_STRUCT Address {
    union {
        uint8_t m_b[NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE];

        struct PACKED_STRUCT {
            struct PACKED_STRUCT {
                uint8_t m_b[NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE/2];
            } m_oui;

            struct PACKED_STRUCT {
                uint8_t m_b[NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE/2];
            } m_nic;
        };
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    struct Oui {
        struct Grouped {
            typedef int Which;
            enum {
                Individual = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL,
                Group = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP
            };
            enum {
                Index = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP,
                Mask = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP,
                Shift = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP
            };
        };
        struct Located {
            typedef int Which;
            enum {
                Local = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_LOCAL,
                Global = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GLOBAL 
            };
            enum {
                Index = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_LOCAL,
                Mask = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_LOCAL,
                Shift = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_LOCAL
            };
        };
        struct Casted {
            typedef int Which;
            enum {
                Unicast = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_UNICAST,
                Multicast = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_MULTICAST
            };
            enum {
                Index = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_MULTICAST,
                Mask = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST,
                Shift = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_MULTICAST
            };
        };
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline Oui::Grouped::Which Grouped() const {
        uint8_t groupedB = m_oui.m_b[Oui::Grouped::Index];
        Oui::Grouped::Which grouped = (((groupedB)  & (Oui::Grouped::Mask)) >> (Oui::Grouped::Shift));
        return grouped;
    }
    inline Oui::Located::Which Located() const {
        uint8_t groupedB = m_oui.m_b[Oui::Located::Index];
        Oui::Located::Which grouped = (((groupedB)  & (Oui::Located::Mask)) >> (Oui::Located::Shift));
        return grouped;
    }
    inline Oui::Casted::Which Casted() const {
        uint8_t groupedB = m_oui.m_b[Oui::Casted::Index];
        Oui::Casted::Which grouped = (((groupedB)  & (Oui::Casted::Mask)) >> (Oui::Casted::Shift));
        return grouped;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline bool operator != (const Address& to) const {
        return (0 != memcmp(m_b, to.m_b, sizeof(m_b)));
    }
    inline bool operator == (const Address& to) const {
        return (0 == memcmp(m_b, to.m_b, sizeof(m_b)));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /* struct PACKED_STRUCT Address */
#include "xos/platform/platform_packed_end.h"
} /// namespace actual

///////////////////////////////////////////////////////////////////////
///  Class: Addresst
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = xos::base::wrappedt<actual::Address>, 
 class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Addresst Derives;
    
    typedef typename Extends::wrapped_t Actual;
    typedef xos::base::string String;
    typedef xos::base::exception Exception;
    enum { ExceptionFailed = xos::base::exception_failed };
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Addresst(const Addresst &copy)
    : Extends(copy), m_adapterName(copy.m_adapterName), m_adapterIndex(copy.m_adapterIndex) {
    }
    Addresst(): m_adapterIndex(-1) {
    }
    virtual ~Addresst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Set(const Actual& actual, const String& adapterName, int adapterIndex) {
        memcpy(&this->actual(), &actual, sizeof(Actual));
        m_adapterName.assign(adapterName);
        m_adapterIndex = adapterIndex;
    }
    virtual void Clear() {
        memset(&this->actual(), 0, sizeof(Actual));
        m_adapterName.clear();
        m_adapterIndex = -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Actual* SetToAdapter(const String& named) {
        return 0;
    }
    virtual Actual* SetToAdapter(int index) {
        return 0;
    }
    virtual Actual* SetToAdapter() {
        return SetToFirstAdapter();
    }
    virtual Actual* SetToFirstAdapter() {
        return SetToAdapter(0);
    }
    virtual Actual* SetToLastAdapter() {
        return SetToAdapter(-1);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Actual* GetFirst() const {
        return 0;
    }
    virtual const Actual* GetLast() const {
        return 0;
    }
    virtual const Actual* GetNext(const Actual* to) const {
        return 0;
    }
    virtual const Actual* GetPrev(const Actual* to) const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Actual& actual() const {
        return (Actual&)(this->wrapped_);
    }
    virtual size_t actualSize() const {
        return sizeof(Actual);
    }
    virtual String& adapterName() const {
        return (String&)(m_adapterName);
    }
    virtual int& adapterIndex() const {
        return (int&)(m_adapterIndex);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_adapterName;
    int m_adapterIndex;
}; /// class _EXPORT_CLASS Addresst
typedef Addresst<> Address;

} /// namespace ethernet
} /// namespace network
} /// namespace rete

#endif /// ndef RETE_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP 
