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
#ifndef _RETE_NETWORK_ETHERNET_POSIX_ADDRESS_HPP
#define _RETE_NETWORK_ETHERNET_POSIX_ADDRESS_HPP

#include "rete/network/ethernet/Address.hpp"
#include <sys/socket.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <net/if_types.h>
#include <ifaddrs.h>

namespace rete {
namespace network {
namespace ethernet {
namespace posix {

///////////////////////////////////////////////////////////////////////
///  Class: Addresst
///////////////////////////////////////////////////////////////////////
template <class TExtends = ethernet::Address, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Addresst Derives;
    
    typedef typename Extends::Actual Actual;
    typedef typename Extends::String String;
    typedef typename Extends::Exception Exception;
    enum { ExceptionFailed = Extends::ExceptionFailed };
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Addresst(const String& adapterNamed) {
        if (!(this->SetToAdapter(adapterNamed))) {
            throw Exception(ExceptionFailed);
        }
    }
    Addresst(const Addresst &copy) {
    }
    Addresst() {
    }
    virtual ~Addresst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Actual* SetToAdapter(const String& named) {
        size_t namedLength = 0;
        const char* namedChars = 0;

        if ((namedChars = named.chars(namedLength)) && (0 < (namedLength))) {
            struct ifaddrs* ifa = 0;
            const Actual* actual = 0;

            this->Clear();

            if ((actual = this->GetFirst(ifa))) {
                struct sockaddr_dl* dl = 0;
                const char* nameChars = 0;
                size_t nameLength = 0;
                int unequal = 0;

                do {
                    if ((dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {
                        if ((nameChars = (const char*)(dl->sdl_data)) 
                            && (0 < (nameLength = (size_t)(dl->sdl_nlen)))) {
                            String name(nameChars, nameLength);

                            if (!(unequal = name.compare(named))) {
                                this->Set(*actual, name, dl->sdl_index);
                                return &this->actual();
                            }
                        }
                    }
                } while ((actual = this->GetNext(ifa)));
            }
        } else {
            return this->SetToFirstAdapter();
        }
        return 0;
    }
    virtual Actual* SetToAdapter(int index) {
        struct ifaddrs* ifa = 0;
        const Actual* actual = 0;

        this->Clear();

        if ((actual = this->GetFirst(ifa))) {
            struct sockaddr_dl* dl = 0;
            const char* nameChars = 0;
            size_t nameLength = 0;

            do {
                if ((dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {
                    if ((nameChars = (const char*)(dl->sdl_data))
                         && (0 < (nameLength = (size_t)(dl->sdl_nlen)))) {

                        if ((1 > index) || ((dl->sdl_index) && (index == dl->sdl_index))) {
                            String name(nameChars, nameLength);
                            this->Set(*actual, name, dl->sdl_index);
                            return &this->actual();
                        }
                    }
                }
            } while ((actual = this->GetNext(ifa)));

            if ((dl) && (nameChars) && (nameLength)) {
                if ((0 > index)) {
                    String name(nameChars, nameLength);
                    this->Set(*actual, name, dl->sdl_index);
                    return &this->actual();
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Actual* GetFirst() const {
        return this->GetNext(0);
    }
    virtual const Actual* GetNext(const Actual* to) const {
        struct ifaddrs* ifa = 0;
        const Actual* actual = 0;
        if ((actual = this->GetFirst(ifa))) {
            if ((to)) {
                do {
                    if ((*to) == (*actual)) {
                        actual = this->GetNext(ifa);
                        break;
                    }
                } while ((actual = this->GetNext(ifa)));
            }
        }
        return actual;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Actual* GetFirst(struct ifaddrs*& ifa) const {
        int err = 0;
        if (!(err = getifaddrs(&ifa)) && (ifa)) {
            const Actual* actual = 0;
            do {
                if ((actual = this->Get(ifa)))
                    return actual;
            } while ((ifa = ifa->ifa_next));
        } else {
        }
        return 0;
    }
    virtual const Actual* GetNext(struct ifaddrs*& ifa) const {
        if ((ifa)) {
            const Actual* actual = 0;
            while ((ifa = ifa->ifa_next)) {
                if ((actual = this->Get(ifa)))
                    return actual;
            }
        }
        return 0;
    }
    virtual const Actual* Get(struct ifaddrs*& ifa) const {
        if ((ifa)) {
            struct sockaddr* sa = 0;
            struct sockaddr_dl* dl = 0;
            const Actual* actual = 0;
            const char* nameChars = 0;
            size_t nameLength = 0;

            if ((sa = (ifa->ifa_addr))) {
                if ((AF_LINK == (sa->sa_family))
                    && (dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {
                    if ((IFT_ETHER == (dl->sdl_type))
                         && (sizeof(Actual) == (dl->sdl_alen))
                         && (actual = (const Actual*)(LLADDR(dl)))
                         && (nameChars = (const char*)(dl->sdl_data))
                         && (0 < (nameLength = (size_t)(dl->sdl_nlen)))) {
                        String name(nameChars, nameLength);
                        return actual;
                    }
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS Addresst
typedef Addresst<> Address;

} /// namespace posix
} /// namespace ethernet
} /// namespace network
} /// namespace rete

#endif /// _RETE_NETWORK_ETHERNET_POSIX_ADDRESS_HPP 
