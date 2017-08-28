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
///   Date: 8/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_MT_HELLO_MAIN_HPP
#define _XOS_APP_CONSOLE_MT_HELLO_MAIN_HPP

#include "rete/app/console/mt/hello/Main.hpp"
#include "xos/network/posix/Sockets.hpp"
#include "xos/network/sockets/Location.hpp"
#include "xos/network/sockets/ip/v6/Endpoint.hpp"
#include "xos/network/sockets/ip/v4/Endpoint.hpp"
#include "xos/network/sockets/ip/tcp/Transport.hpp"
#include "xos/network/sockets/ip/udp/Transport.hpp"
#include "xos/network/Transport.hpp"

namespace xos {
namespace app {
namespace console {
namespace mt {
namespace hello {

typedef rete::app::console::mt::hello::MainOpt MainOpt;
typedef rete::app::console::mt::hello::MainImplements MainImplements;
typedef rete::app::console::mt::hello::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main
: virtual public MainOpt, virtual public MainImplements, public MainExtends {
public:
    typedef MainOpt OptImplements;
    typedef MainImplements Implements;
    typedef MainExtends Extends;
    typedef Main Derives;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: Main
    ///////////////////////////////////////////////////////////////////////
    Main()
    : m_runHello(0),
      m_runSocketsHello(0),
      m_runNetworkHello(0),
      m_clientPort(80), m_serverPort(8080),
      m_clientHost("localhost"), m_serverHost(""),
      m_clientSocketLocation(m_clientHost, m_clientPort),
      m_serverSocketLocation(m_serverHost, m_serverPort),
      m_socketEndpoint(0), m_socketTransport(0),
      m_clientLocation(0), m_serverLocation(0),
      m_endpoint(0), m_transport(0),
      m_interface(0), m_interfaceAccept(0) {
    }

protected:
    int (Derives::*m_runHello)(int argc, char_t**argv, char_t** env);
    ///////////////////////////////////////////////////////////////////////
    /// Function: RunHello
    ///////////////////////////////////////////////////////////////////////
    virtual int RunHello(int argc, char_t**argv, char_t** env) {
        int err = 0;
        if ((m_runHello)) {
            err = (this->*m_runHello)(argc, argv, env);
        } else {
            err = RunNetworkHello(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunNetworkHello(int argc, char_t**argv, char_t** env) {
        int err = 0;
        network::Library& nl = Library();

        if ((nl.Startup())) {
            network::Interface& in = Interface();
            network::Transport& tp = Transport();
            network::Endpoint& ep = Endpoint();

            if ((in.Open(tp))) {

                err = RunNetworkHello(in, ep, tp, argc, argv, env);
                in.Close();
            }
            nl.Cleanup();
        }
        return err;
    }

    int (Derives::*m_runNetworkHello)
    (network::Interface& in, network::Endpoint& ep,
     network::Transport& tp, int argc, char_t**argv, char_t** env);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunNetworkHello
    (network::Interface& in, network::Endpoint& ep,
     network::Transport& tp, int argc, char_t**argv, char_t** env) {
        int err = 0;
        if ((m_runNetworkHello)) {
            err = (this->*m_runNetworkHello)(in, ep, tp, argc, argv, env);
        } else {
            err = RunClientHello(in, ep, tp, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunClientHello
    (network::Interface& in, network::Endpoint& ep,
     network::Transport& tp, int argc, char_t**argv, char_t** env) {
        int err = 0;
        network::Location& _lc = ClientLocation();
        network::Location* _lp = 0;

        if (_lp = (ep.Attach(_lc))) {

            if ((in.Connect(ep))) {

                SendHello(in, argc, argv, env);
                in.Shutdown();
            }
            ep.Detach(*_lp);
        }
        return err;
    }
    virtual int RunServerHello
    (network::Interface& in, network::Endpoint& ep,
     network::Transport& tp, int argc, char_t**argv, char_t** env) {
        int err = 0;
        network::Location& _lc = ServerLocation();
        network::Location* _lp = 0;

        if ((_lp = ep.Attach(_lc))) {

            if ((in.Listen(ep))) {
                network::Interface& _cn = InterfaceAccept();

                if ((in.Accept(_cn, ep))) {

                    RecvHello(_cn, argc, argv, env);
                    _cn.Close();
                }
            }
            ep.Detach(*_lp);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendHello
    (network::Interface& in, int argc, char_t**argv, char_t** env) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;
        String r, s;

        MakeHelloHttpRequest(r, argc, argv, env);

        if (0 < (count = SendRequest(in, s, r))) {
            if ((chars = s.HasChars(length))) {
                this ->Out(chars, length);
            }
        }
        return count;
    }
    virtual ssize_t RecvHello
    (network::Interface& in, int argc, char_t**argv, char_t** env) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;
        String r, s;

        MakeHelloHttpResponse(s, argc, argv, env);

        if (0 < (count = SendResponse(in, r, s))) {
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
            amount = RecvResponse(in, rs);
        }
        return count;
    }
    virtual ssize_t SendResponse
    (network::Interface& in, String& rq, const String& rs) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;

        if ((chars = rs.HasChars(length))) {

            if ((amount = RecvRequest(in, rq))) {

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
    virtual ssize_t RecvRequest
    (network::Interface& in, String& rq) {
        ssize_t count = 0;
        count = RecvHttp(in, rq);
        return count;
    }
    virtual ssize_t RecvResponse
    (network::Interface& in, String& rs) {
        ssize_t count = 0;
        count = RecvHttp(in, rs);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t RecvHttp
    (network::Interface& in, String& rs) {
        ssize_t count = 0, amount = 0;
        enum { C, CR, CRLF, CRLFCR, CONTENT } s = C;
        char c = 0;

        if (0 < (amount = in.Recv(&c, 1))) {
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
            } while (0 < (amount = in.Recv(&c, 1)));
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunSocketsHello(int argc, char_t**argv, char_t** env) {
        int err = 0;
        network::Sockets& sks = Sockets();

        if ((sks.Startup())) {
            network::sockets::Interface& sk = Socket();
            network::sockets::Endpoint& ep = SocketEndpoint();
            network::sockets::Transport& tp = SocketTransport();

            if ((sk.Open(tp))) {

                err = RunSocketsHello(sk, ep, tp, argc, argv, env);
                sk.Close();
            }
            sks.Cleanup();
        }
        return err;
    }

    int (Derives::*m_runSocketsHello)
    (network::sockets::Interface& sk, network::sockets::Endpoint& ep,
     network::sockets::Transport& tp, int argc, char_t**argv, char_t** env);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunSocketsHello
    (network::sockets::Interface& sk, network::sockets::Endpoint& ep,
     network::sockets::Transport& tp, int argc, char_t**argv, char_t** env) {
        int err = 0;
        if ((m_runSocketsHello)) {
            err = (this->*m_runSocketsHello)(sk, ep, tp, argc, argv, env);
        } else {
            err = RunSocketsClientHello(sk, ep, tp, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunSocketsClientHello
    (network::sockets::Interface& sk, network::sockets::Endpoint& ep,
     network::sockets::Transport& tp, int argc, char_t**argv, char_t** env) {
        int err = 0;

        if ((ep.Attach(m_clientHost, m_clientPort))) {

            if ((sk.Connect(ep))) {

                SocketsSendHello(sk, argc, argv, env);
                sk.Shutdown();
            }
            ep.Detach();
        }
        return err;
    }
    virtual int RunSocketsServerHello
    (network::sockets::Interface& sk, network::sockets::Endpoint& ep,
     network::sockets::Transport& tp, int argc, char_t**argv, char_t** env) {
        int err = 0;

        if ((ep.Attach(m_serverHost, m_serverPort))) {

            if ((sk.Listen(ep))) {
                network::sockets::Interface& cn = SocketAccept();

                if ((sk.Accept(cn, ep))) {

                    SocketsRecvHello(cn, argc, argv, env);
                    cn.Close();
                }
            }
            ep.Detach();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SocketsSendHello
    (network::sockets::Interface& sk, int argc, char_t**argv, char_t** env) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;
        String r, s;

        MakeHelloHttpRequest(r, argc, argv, env);

        if (0 < (count = SocketsSendRequest(sk, s, r))) {
            if ((chars = s.HasChars(length))) {
                this ->Out(chars, length);
            }
        }
        return count;
    }
    virtual ssize_t SocketsRecvHello
    (network::sockets::Interface& sk, int argc, char_t**argv, char_t** env) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;
        String r, s;

        MakeHelloHttpResponse(s, argc, argv, env);

        if (0 < (count = SocketsSendResponse(sk, r, s))) {
            if ((chars = r.HasChars(length))) {
                this ->Out(chars, length);
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SocketsSendRequest
    (network::sockets::Interface& sk, String& rs, const String& rq) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;

        if ((chars = rq.HasChars(length))) {

            XOS_LOG_DEBUG("sk.Send(chars = \"" << chars << "\", length = " << length << ")...")
            if (0 < (amount = sk.Send(chars, length))) {
                count += amount;
            }
            amount = SocketsRecvResponse(sk, rs);
        }
        return count;
    }
    virtual ssize_t SocketsSendResponse
    (network::sockets::Interface& sk, String& rq, const String& rs) {
        ssize_t count = 0, amount = 0;
        const char* chars = 0;
        size_t length = 0;

        if ((chars = rs.HasChars(length))) {

            if ((amount = SocketsRecvRequest(sk, rq))) {

                XOS_LOG_DEBUG("sk.Send(chars = \"" << chars << "\", length = " << length << ")...")
                if (0 < (amount = sk.Send(chars, length))) {
                    count += amount;
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SocketsRecvRequest
    (network::sockets::Interface& sk, String& rq) {
        ssize_t count = 0;
        count = RecvHttp(sk, rq);
        return count;
    }
    virtual ssize_t SocketsRecvResponse
    (network::sockets::Interface& sk, String& rs) {
        ssize_t count = 0;
        count = RecvHttp(sk, rs);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual String& MakeHelloHttpRequest
    (String& r, int argc, char_t**argv, char_t** env) {
        const char* chars = 0;
        size_t length = 0;

        r.Assign("POST /");

        if ((chars = this->m_message.HasChars(length))) {
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
    virtual String& MakeHelloHttpResponse
    (String& s, int argc, char_t**argv, char_t** env) {
        const char* chars = 0;
        size_t length = 0;

        s.Assign("HTTP/1.0 200 Ok\r\n\r\n");

        if ((chars = this->m_message.HasChars(length))) {
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
        //return m_baseInterface;
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
        m_runNetworkHello = &Derives::RunClientHello;
        m_runSocketsHello = &Derives::RunSocketsClientHello;
    }
    virtual void OnServerOption() {
        m_runNetworkHello = &Derives::RunServerHello;
        m_runSocketsHello = &Derives::RunSocketsServerHello;
    }
    virtual void OnSocketsOption() {
        m_runHello = &Derives::RunSocketsHello;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
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

} // namespace hello
} // namespace mt 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_MT_HELLO_MAIN_HPP 
