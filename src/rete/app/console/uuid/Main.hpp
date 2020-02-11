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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 2/9/2020
///////////////////////////////////////////////////////////////////////
#ifndef RETE_APP_CONSOLE_UUID_MAIN_HPP
#define RETE_APP_CONSOLE_UUID_MAIN_HPP

#include "rete/app/console/uuid/MainOpt.hpp"
#include "rete/network/unique/posix/Identifier.hpp"
#include "rete/network/ethernet/os/Address.hpp"
#include "cifra/crypto/random/pseudo/generator.hpp"
#include "cifra/crypto/hash/openssl/md5.hpp"
#include "cifra/crypto/hash/openssl/sha1.hpp"

namespace rete {
namespace app {
namespace console {
namespace uuid {

///////////////////////////////////////////////////////////////////////
///  Class: Maint
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = MainOpt, class TImplements = typename TExtends::Implements>

class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;

    typedef typename Extends::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Maint() {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///  Class: From
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS From: public rete::network::unique::Identifier::From {
    public:
        typedef rete::network::unique::Identifier::From Extends;
        typedef Extends::Random Random;
        typedef Extends::Md5 Md5;
        typedef Extends::Sha1 Sha1;
        typedef Extends::MacAddress MacAddress;
        typedef Extends::Ethernet Ethernet;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        From(Ethernet& ethernet, Random& random, Md5& md5, Sha1& sha1)
        : m_ethernet(ethernet), m_random(random), m_md5(md5), m_sha1(sha1) {}
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual Ethernet& ethernet() const { return m_ethernet; }
        virtual Random& random() const { return m_random; }
        virtual Md5& md5() const { return m_md5; }
        virtual Sha1& sha1() const { return m_sha1; }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        Ethernet& m_ethernet;
        Random& m_random;
        Md5& m_md5;
        Sha1& m_sha1;
    }; /// class _EXPORT_CLASS From

    ///////////////////////////////////////////////////////////////////////
    ///  Class: Ethernet
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Ethernet: public rete::network::unique::Identifier::From::Ethernet {
    public:
        typedef rete::network::unique::Identifier::From::Ethernet Extends;
        typedef Extends::MacAddress MacAddress;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        Ethernet(rete::network::ethernet::Address& address): m_address(address) {}
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual const MacAddress* Address() const { return &m_address.actual(); }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        rete::network::ethernet::Address& m_address; 
    }; /// class _EXPORT_CLASS Ethernet

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cifra::crypto::random::pseudo::generator random;
        cifra::crypto::hash::openssl::md5 md5;
        cifra::crypto::hash::openssl::sha1 sha1;
        rete::network::ethernet::os::Address address;
        Ethernet ethernet(address);
        From from(ethernet, random, md5, sha1);
        rete::network::unique::posix::Identifier uuid;

        this->OutL("uuid.Generate(from)...", "\n", NULL);
        if ((uuid.Generate(from))) {
            this->OutL("...uuid.Generate(from)", "\n", NULL);
            this->OutL(uuid.String().chars(), "\n", NULL);
        } else {
            this->OutL("...failed on uuid.Generate(from)", "\n", NULL);
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class _EXPORT_CLASS Maint

typedef Maint<> Main;


} /// namespace uuid
} /// namespace console
} /// namespace app
} /// namespace rete

#endif /// ndef RETE_APP_CONSOLE_UUID_MAIN_HPP
