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
///   Date: 11/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP
#define _XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP

#include "xos/network/address/Interface.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE 6

///////////////////////////////////////////////////////////////////////
/// OUI group/indiviual bit
///////////////////////////////////////////////////////////////////////
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP 0x01
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP 0
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP 0

#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_INDIVIDUAL 0x00
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GROUP      0x01

#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL 0
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP      1

///////////////////////////////////////////////////////////////////////
/// OUI local/global bit
///////////////////////////////////////////////////////////////////////
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_LOCAL 0x02
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_LOCAL 1
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_LOCAL 0

#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GLOBAL 0x00
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_LOCAL  0x02

#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GLOBAL 0
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_LOCAL  1

///////////////////////////////////////////////////////////////////////
/// OUI multicast/unicast bit
///////////////////////////////////////////////////////////////////////
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_MULTICAST XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_MULTICAST XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP

#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_UNICAST   XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_INDIVIDUAL
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_MULTICAST XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GROUP

#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_UNICAST   XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL
#define XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_MULTICAST XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace xos {
namespace network {
namespace ethernet {
namespace actual {

#include "xos/platform/platform_packed_begin.h"
///////////////////////////////////////////////////////////////////////
/// Struct: Address
///////////////////////////////////////////////////////////////////////
struct PACKED_STRUCT Address {
    union {
        uint8_t m_b[XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE];

        struct PACKED_STRUCT {
            struct PACKED_STRUCT {
                uint8_t m_b[XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE/2];
            } m_oui;

            struct PACKED_STRUCT {
                uint8_t m_b[XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE/2];
            } m_nic;
        };
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    struct Oui {
        struct Grouped {
            typedef int Which;
            enum {
                Individual = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL,
                Group = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP
            };
            enum {
                Index = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP,
                Mask = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP,
                Shift = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP
            };
        };
        struct Located {
            typedef int Which;
            enum {
                Local = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_LOCAL,
                Global = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GLOBAL 
            };
            enum {
                Index = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_LOCAL,
                Mask = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_LOCAL,
                Shift = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_LOCAL
            };
        };
        struct Casted {
            typedef int Which;
            enum {
                Unicast = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_UNICAST,
                Multicast = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_MULTICAST
            };
            enum {
                Index = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_MULTICAST,
                Mask = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST,
                Shift = XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_MULTICAST
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
};
#include "xos/platform/platform_packed_end.h"

} // namespace actual 
} // namespace ethernet 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP 
