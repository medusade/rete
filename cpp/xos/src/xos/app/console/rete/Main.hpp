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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 9/16/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_RETE_MAIN_HPP
#define _XOS_APP_CONSOLE_RETE_MAIN_HPP

#include "xos/app/console/rete/MainOpt.hpp"
#include "xos/app/console/fila/Main.hpp"
#include "xos/network/posix/Sockets.hpp"
#include "xos/network/sockets/Location.hpp"
#include "xos/network/sockets/ip/v6/Endpoint.hpp"
#include "xos/network/sockets/ip/v4/Endpoint.hpp"
#include "xos/network/sockets/ip/tcp/Transport.hpp"
#include "xos/network/sockets/ip/udp/Transport.hpp"
#include "xos/network/Transport.hpp"
#include "xos/network/InterfaceReader.hpp"

namespace xos {
namespace app {
namespace console {
namespace rete {

typedef fila::MainImplements MainImplements;
typedef fila::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TOptImplements = MainOpt,
 class TImplements = MainImplements, class TExtends = MainExtends>

class _EXPORT_CLASS MainT
: virtual public TOptImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TOptImplements OptImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef MainT Derives;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: MainT
    ///////////////////////////////////////////////////////////////////////
    MainT()
    : m_run(0),
      m_message("Hello"),
      m_clientPort(80), m_serverPort(8080),
      m_clientHost("localhost"), m_serverHost(""),
      m_clientSocketLocation(m_clientHost, m_clientPort),
      m_serverSocketLocation(m_serverHost, m_serverPort),
      m_socketEndpoint(0), m_socketTransport(0),
      m_clientLocation(0), m_serverLocation(0),
      m_endpoint(0), m_transport(0),
      m_interface(0), m_interfaceAccept(0) {
    }
    virtual ~MainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        network::Library& nl = this->Library();

        if ((nl.Startup())) {
            network::Interface& in = this->Interface();
            network::Transport& tp = this->Transport();
            network::Endpoint& ep = this->Endpoint();

            if ((in.Open(tp))) {

                err = this->Run(in, ep, tp, argc, argv, env);
                in.Close();
            }
            nl.Cleanup();
        }
        return err;
    }

    int (Derives::*m_run)
    (network::Interface& in, network::Endpoint& ep,
     network::Transport& tp, int argc, char_t** argv, char_t** env);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (network::Interface& in, network::Endpoint& ep,
     network::Transport& tp, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((m_run)) {
            err = (this->*m_run)(in, ep, tp, argc, argv, env);
        } else {
            err = this->RunClient(in, ep, tp, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunClient
    (network::Interface& in, network::Endpoint& ep,
     network::Transport& tp, int argc, char_t** argv, char_t** env) {
        int err = 0;
        network::Location& _lc = ClientLocation();
        network::Location* _lp = 0;

        if (_lp = (ep.Attach(_lc))) {

            if ((in.Connect(ep))) {

                this->SendRequest(in, argc, argv, env);
                in.Shutdown();
            }
            ep.Detach(*_lp);
        }
        return err;
    }
    virtual int RunServer
    (network::Interface& in, network::Endpoint& ep,
     network::Transport& tp, int argc, char_t** argv, char_t** env) {
        int err = 0;
        network::Location& _lc = ServerLocation();
        network::Location* _lp = 0;

        if ((_lp = ep.Attach(_lc))) {

            if ((in.Listen(ep))) {
                network::Interface& _cn = InterfaceAccept();

                if ((in.Accept(_cn, ep))) {

                    this->RecvRequest(_cn, argc, argv, env);
                    _cn.Close();
                }
            }
            ep.Detach(*_lp);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendRequest
    (network::Interface& in, int argc, char_t** argv, char_t** env) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;
        String r, s;

        this->MakeRequest(r, argc, argv, env);

        if (0 < (count = this->SendRequest(in, s, r))) {
            if ((chars = s.HasChars(length))) {
                this ->Out(chars, length);
            }
        }
        return count;
    }
    virtual ssize_t RecvRequest
    (network::Interface& in, int argc, char_t** argv, char_t** env) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;
        String r, s;

        this->MakeResponse(s, argc, argv, env);

        if (0 < (count = this->SendResponse(in, r, s))) {
            if ((chars = r.HasChars(length))) {
                this ->Out(chars, length);
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendRequest
    (network::Interface& in, String& rs, const String& rq) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;

        if ((chars = rq.HasChars(length))) {

            XOS_LOG_DEBUG("in.Send(chars = \"" << chars << "\", length = " << length << ")...")
            if (0 < (amount = in.Send(chars, length))) {
                count += amount;
            }
            amount = this->RecvResponse(in, rs);
        }
        return count;
    }
    virtual ssize_t SendResponse
    (network::Interface& in, String& rq, const String& rs) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;

        if ((chars = rs.HasChars(length))) {

            if ((amount = this->RecvRequest(in, rq))) {

                XOS_LOG_DEBUG("in.Send(chars = \"" << chars << "\", length = " << length << ")...")
                if (0 < (amount = in.Send(chars, length))) {
                    count += amount;
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual String& MakeRequest
    (String& r, int argc, char_t** argv, char_t** env) {
        this->MakeXttpRequest(r, argc, argv, env);
        return r;
    }
    virtual String& MakeResponse
    (String& s, int argc, char_t** argv, char_t** env) {
        this->MakeXttpResponse(s, argc, argv, env);
        return s;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t RecvRequest
    (network::Interface& in, String& rq) {
        ssize_t count = 0;
        count = this->RecvXttpRequest(in, rq);
        return count;
    }
    virtual ssize_t RecvResponse
    (network::Interface& in, String& rs) {
        ssize_t count = 0;
        count = this->RecvXttpResponse(in, rs);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t RecvXttpRequest
    (network::Interface& in, String& rs) {
        network::InterfaceCharReader reader(in);
        ssize_t count = this->ReadXttpRequest(reader, rs);
        return count;
    }
    virtual ssize_t RecvXttpResponse
    (network::Interface& in, String& rs) {
        network::InterfaceCharReader reader(in);
        ssize_t count = this->ReadXttpResponse(reader, rs);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadXttpRequest
    (io::CharReader& in, String& rs) {
        ssize_t count = 0;
        count = ReadXttp(in, rs);
        return count;
    }
    virtual ssize_t ReadXttpResponse
    (io::CharReader& in, String& rs) {
        ssize_t count = 0;
        count = ReadXttp(in, rs);
        return count;
    }
    virtual ssize_t ReadXttp
    (io::CharReader& in, String& rs) {
        ssize_t count = 0, amount = 0;
        enum { C, CR, CRLF, CRLFCR, CONTENT } s = C;
        char c = 0;

        if (0 < (amount = in.Read(&c, 1))) {
            rs.Clear();
            do {
                count += amount;
                rs.Append(&c, 1);

                if ((CONTENT != (s))) {
                    if (CRLFCR == (s)) {
                        if ('\n' == (c)) { s = CONTENT; break; }
                        else {
                            if ('\r' == (c)) { s = CR; }
                            else { s = C; }
                        }
                    } else {
                        if (CRLF == (s)) {
                            if ('\r' == (c)) { s = CRLFCR; }
                            else { s = C; }
                        } else {
                            if (CR == (s)) {
                                if ('\n' == (c)) { s = CRLF; }
                                else {
                                    if ('\r' != (c)) { s = C; }
                                }
                            } else {
                                if ('\r' == (c)) { s = CR; }
                            }
                        }
                    }
                }
            } while (0 < (amount = in.Read(&c, 1)));
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual String& MakeXttpRequest
    (String& r, int argc, char_t** argv, char_t** env) {
        const String& message = this->Message();
        const char* chars = 0;
        size_t length = 0;

        r.Assign("POST /");

        if ((chars = message.HasChars(length))) {
            r.Append(chars, length);
            r.Append("/");
        }
        r.Append(" HTTP/1.0\r\n\r\n");

        if ((optind < argc) && (argv)) {
            const char* separator = 0;

            for (int i = optind; i < argc; ++i) {
                if ((chars = argv[i]) && (chars[0])) {
                    if ((separator)) {
                        r.Append(separator);
                    } else {
                        separator = " ";
                    }
                    r.Append(chars);
                }
            }
            if ((separator)) {
                r.Append("\r\n");
            }
        }
        return r;
    }
    virtual String& MakeXttpResponse
    (String& s, int argc, char_t** argv, char_t** env) {
        const String& message = this->Message();
        const char* chars = 0;
        size_t length = 0;

        s.Assign("HTTP/1.0 200 Ok\r\n\r\n");

        if ((chars = message.HasChars(length))) {
            s.Append(chars, length);

            if ((optind < argc) && (argv)) {
                for (int i = optind; i < argc; ++i) {
                    if ((chars = argv[i]) && (chars[0])) {
                        s.Append(" ");
                        s.Append(chars);
                    }
                }
            }
            s.Append("\r\n");
        }
        return s;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const String& Message() const {
        return m_message;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Location& ClientLocation() {
        if ((m_clientLocation)) {
            return (this->*m_clientLocation)();
        }
        return m_clientSocketLocation;
    }
    virtual network::Location& ServerLocation() {
        if ((m_serverLocation)) {
            return (this->*m_serverLocation)();
        }
        return m_serverSocketLocation;
    }
    virtual network::Transport& Transport() {
        if ((m_transport)) {
            return (this->*m_transport)();
        }
        return SocketTransport();
    }
    virtual network::Endpoint& Endpoint() {
        if ((m_endpoint)) {
            return (this->*m_endpoint)();
        }
        return SocketEndpoint();
    }
    virtual network::Interface& Interface() {
        if ((m_interface)) {
            return (this->*m_interface)();
        }
        return Socket();
    }
    virtual network::Interface& InterfaceAccept() {
        if ((m_interfaceAccept)) {
            return (this->*m_interfaceAccept)();
        }
        return SocketAccept();
    }
    virtual network::Library& Library() {
        return Sockets();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::sockets::Transport& SocketTransport() {
        if ((m_socketTransport)) {
            return (this->*m_socketTransport)();
        }
        return m_tcpTransport;
    }
    virtual network::sockets::Endpoint& SocketEndpoint() {
        if ((m_socketEndpoint)) {
            return (this->*m_socketEndpoint)();
        }
        return m_ip4Endpoint;
    }
    virtual network::sockets::Interface& Socket() {
        return m_socket;
    }
    virtual network::sockets::Interface& SocketAccept() {
        return m_socketAccept;
    }
    virtual network::Sockets& Sockets() {
        return m_sockets;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnClientOption() {
        m_run = &Derives::RunClient;
    }
    virtual void OnServerOption() {
        m_run = &Derives::RunServer;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_message;
    ushort m_clientPort, m_serverPort;
    String m_clientHost, m_serverHost;

    network::sockets::Location
        m_clientSocketLocation, m_serverSocketLocation;

    network::sockets::Endpoint& (Derives::*m_socketEndpoint)();
    network::sockets::ip::v4::Endpoint m_ip4Endpoint;
    network::sockets::ip::v6::Endpoint m_ip6Endpoint;

    network::sockets::Transport& (Derives::*m_socketTransport)();
    network::sockets::ip::tcp::Transport m_tcpTransport;
    network::sockets::ip::udp::Transport m_udpTransport;

    network::posix::Socket m_socket, m_socketAccept;
    network::posix::Sockets m_sockets;

    network::Location& (Derives::*m_clientLocation)();
    network::Location& (Derives::*m_serverLocation)();

    network::Endpoint& (Derives::*m_endpoint)();
    network::Transport& (Derives::*m_transport)();

    network::Interface& (Derives::*m_interface)();
    network::Interface& (Derives::*m_interfaceAccept)();
    network::InterfaceBase m_baseInterface, m_baseInterfaceAccept;
};
typedef  MainT<> Main;

} // namespace rete
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_RETE_MAIN_HPP 
