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
///   File: version.cpp
///
/// Author: $author$
///   Date: 6/14/2021
///////////////////////////////////////////////////////////////////////
#include "xos/lib/rete/version.hpp"

#if !defined(XOS_LIB_RETE_VERSION_NAME)
#define XOS_LIB_RETE_VERSION_NAME   librete
#endif /// !defined(XOS_LIB_RETE_VERSION_NAME)

#if !defined(XOS_LIB_RETE_VERSION_NAME_CHARS)
#define XOS_LIB_RETE_VERSION_NAME_CHARS   XOS_2CHARS(XOS_LIB_RETE_VERSION_NAME)
#endif /// !defined(XOS_LIB_RETE_VERSION_NAME_CHARS)

#if !defined(XOS_LIB_RETE_VERSION_MAJOR)
#define XOS_LIB_RETE_VERSION_MAJOR   0
#endif /// !defined(XOS_LIB_RETE_VERSION_MAJOR)

#if !defined(XOS_LIB_RETE_VERSION_MINOR)
#define XOS_LIB_RETE_VERSION_MINOR   0
#endif /// !defined(XOS_LIB_RETE_VERSION_MINOR)

#if !defined(XOS_LIB_RETE_VERSION_RELEASE)
#define XOS_LIB_RETE_VERSION_RELEASE 0
#endif /// !defined(XOS_LIB_RETE_VERSION_RELEASE)

#if !defined(XOS_LIB_RETE_VERSION_BUILD)
#define XOS_LIB_RETE_VERSION_BUILD   6/14/2021
#endif /// !defined(XOS_LIB_RETE_VERSION_BUILD)

#if !defined(XOS_LIB_RETE_VERSION_BUILD_CHARS)
#define XOS_LIB_RETE_VERSION_BUILD_CHARS   XOS_2CHARS(XOS_LIB_RETE_VERSION_BUILD)
#endif /// !defined(XOS_LIB_RETE_VERSION_BUILD_CHARS)

namespace xos {
namespace lib {
namespace rete {

namespace which {
/// class versiont
template <class TExtends = lib::extended::version, class TImplements = typename TExtends::implements>
class exported versiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef versiont derives;

    /// constructor / destructor
    versiont(const versiont& copy): extends(copy) {
    }
    versiont(): extends
    (XOS_LIB_RETE_VERSION_NAME_CHARS, 
     XOS_LIB_RETE_VERSION_MAJOR, XOS_LIB_RETE_VERSION_MINOR, 
     XOS_LIB_RETE_VERSION_RELEASE, XOS_LIB_RETE_VERSION_BUILD_CHARS) {
    }
    virtual ~versiont() {
    }
}; /// class versiont
typedef versiont<> version;
} /// namespace which

/// class version
const lib::version& version::which() {
    static const rete::which::version version;
    return version;
}

} /// namespace rete
} /// namespace lib
} /// namespace xos
