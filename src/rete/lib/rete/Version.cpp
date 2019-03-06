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
///   File: Version.cpp
///
/// Author: $author$
///   Date: 3/4/2019
///////////////////////////////////////////////////////////////////////
#include "rete/lib/rete/Version.hpp"

#if !defined(RETE_LIB_RETE_VERSION_NAME)
#define RETE_LIB_RETE_VERSION_NAME "librete"
#endif /// !defined(RETE_LIB_RETE_VERSION_NAME)

#if !defined(RETE_LIB_RETE_VERSION_MAJOR)
#define RETE_LIB_RETE_VERSION_MAJOR 0
#endif /// !defined(RETE_LIB_RETE_VERSION_MAJOR)

#if !defined(RETE_LIB_RETE_VERSION_MINOR)
#define RETE_LIB_RETE_VERSION_MINOR 0
#endif /// !defined(RETE_LIB_RETE_VERSION_MINOR)

#if !defined(RETE_LIB_RETE_VERSION_RELEASE)
#define RETE_LIB_RETE_VERSION_RELEASE 0
#endif /// !defined(RETE_LIB_RETE_VERSION_RELEASE)

namespace rete {
namespace lib {
namespace rete {

namespace which {
typedef lib::Version VersionImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Version
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Version: virtual public VersionImplements {
public:
    typedef VersionImplements Implements;
    Version() {
    }
    virtual const char_t* Name() const {
        return RETE_LIB_RETE_VERSION_NAME;
    }
    virtual unsigned Major() const {
        return RETE_LIB_RETE_VERSION_MAJOR;
    }
    virtual unsigned Minor() const {
        return RETE_LIB_RETE_VERSION_MINOR;
    }
    virtual unsigned Release() const {
        return RETE_LIB_RETE_VERSION_RELEASE;
    }
}; /// class _EXPORT_CLASS Version
} /// namespace which

///////////////////////////////////////////////////////////////////////
///  Class: Version
///////////////////////////////////////////////////////////////////////
const lib::Version& Version::Which() {
    static const which::Version version;
    return version;
}

} /// namespace rete
} /// namespace lib
} /// namespace rete
