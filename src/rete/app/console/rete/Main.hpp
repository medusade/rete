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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_APP_CONSOLE_RETE_MAIN_HPP
#define _RETE_APP_CONSOLE_RETE_MAIN_HPP

#include "rete/app/console/rete/MainOpt.hpp"
#include "rete/network/Transports.hpp"
#include "rete/network/Locations.hpp"
#include "rete/network/Endpoints.hpp"
#include "rete/network/Connections.hpp"
#include "rete/network/os/Sockets.hpp"
#include "crono/io/Logger.hpp"

namespace rete {
namespace app {
namespace console {
namespace rete {

typedef MainOpt MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: public MainExtends {
public:
    typedef MainExtends Extends;
    typedef Main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main()
    : m_run(0), 
      m_clientRun(0), m_serverRun(0),
      m_clientLocation(0), m_serverLocation(0),
      m_clientHost("localhost"), m_serverHost("*"),
      m_clientPort(80), m_serverPort(8080),
      m_clientMessage("GET / HTTP/1.0\r\n\r\n"), 
      m_beforeClientMessage(""), m_afterClientMessage(""),
      m_serverMessage("HTTP/1.0 200 OK\r\n\r\nOK\r\n"), 
      m_beforeServerMessage(""), m_afterServerMessage(""),
      m_transport(0), m_endpoint(0), m_connection(0), m_accepted(0)
    {
    }
    virtual ~Main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef int (Derives::*RunT)(int argc, char_t **argv, char_t **env);
    RunT m_run;
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        if ((m_run)) {
            err = (this->*m_run)(argc, argv, env);
        } else {
            err = this->Usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int TcpClientRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        ::rete::network::Sockets& sockets = this->Sockets(argc, argv, env);

        LOG_DEBUG("sockets.Startup()...");
        if ((sockets.Startup())) {
            ::rete::network::Endpoint& endpoint = this->Endpoint(argc, argv, env);
            ::rete::network::Location& location = this->ClientLocation(argc, argv, env);

            LOG_DEBUG("endpoint.Attach(location)...");
            if ((endpoint.Attach(location))) {
                ::rete::network::Transport& transport = this->Transport(argc, argv, env);
                ::rete::network::Connection& connection = this->Connection(argc, argv, env);
                
                LOG_DEBUG("connection.Open(transport)...");
                if ((connection.Open(transport))) {
                    
                    LOG_DEBUG("connection.Connect(endpoint)...");
                    if ((connection.Connect(endpoint))) {
                        ssize_t count = 0;
                        
                        LOG_DEBUG("this->SendClientMessage(connection, argc, argv, env)...");
                        if (0 < (count = this->SendClientMessage(connection, argc, argv, env))) {
                            
                            LOG_DEBUG("this->RecvServerMessage(connection, argc, argv, env)...");
                            if (0 < (count = this->RecvServerMessage(connection, argc, argv, env))) {
                                const char* chars = 0;
                                
                                if ((chars = m_recvMessage.has_chars())) {
                                    this->OutLn(chars);
                                }
                            }
                        }
                    }
                    LOG_DEBUG("connection.Close()...");
                    connection.Close();
                }
                LOG_DEBUG("endpoint.Detach()...");
                endpoint.Detach();
            }
            LOG_DEBUG("sockets.Cleanup()...");
            sockets.Cleanup();
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int TcpServerRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        ::rete::network::Sockets& sockets = this->Sockets(argc, argv, env);

        LOG_DEBUG("sockets.Startup()...");
        if ((sockets.Startup())) {
            ::rete::network::Endpoint& endpoint = this->Endpoint(argc, argv, env);
            ::rete::network::Location& location = this->ServerLocation(argc, argv, env);

            LOG_DEBUG("endpoint.Attach(location)...");
            if ((endpoint.Attach(location))) {
                ::rete::network::Transport& transport = this->Transport(argc, argv, env);
                ::rete::network::Connection& connection = this->Connection(argc, argv, env);
                
                LOG_DEBUG("connection.Open(transport)...");
                if ((connection.Open(transport))) {
                    
                    LOG_DEBUG("connection.Listen(endpoint)...")
                    if ((connection.Listen(endpoint))) {
                        ::rete::network::Connection& accepted = this->Accepted(argc, argv, env);
                        
                        LOG_DEBUG("connection.Accept(accepted, endpoint)...");
                        if ((connection.Accept(accepted, endpoint))) {
                            ssize_t count = 0;
                            
                            LOG_DEBUG("this->RecvClientMessage(accepted, argc, argv, env)...");
                            if (0 < (count = this->RecvClientMessage(accepted, argc, argv, env))) {
                                const char* chars = 0;
                                
                                if ((chars = m_recvMessage.has_chars())) {
                                    this->OutLn(chars);
                                }
                                LOG_DEBUG("this->SendServerMessage(accepted, argc, argv, env)...");
                                if (0 < (count = this->SendServerMessage(accepted, argc, argv, env))) {
                                }
                            }
                            LOG_DEBUG("accepted.Close()...");
                            accepted.Close();
                        } else {
                            LOG_ERROR("...failed on connection.Accept(accepted, endpoint)");
                        }
                    }
                    LOG_DEBUG("connection.Close()...");
                    connection.Close();
                }
                LOG_DEBUG("endpoint.Detach()...");
                endpoint.Detach();
            }
            LOG_DEBUG("sockets.Cleanup()...");
            sockets.Cleanup();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef RunT (Derives::*WhichRunT)(int argc, char_t**argv, char_t**env);
    WhichRunT m_clientRun, m_serverRun;
    ///////////////////////////////////////////////////////////////////////
    virtual RunT ClientRun(int argc, char_t**argv, char_t**env) {
        RunT run = 0;
        if ((this->m_clientRun)) {
            run = (this->*m_clientRun)(argc, argv, env);
        } else {
            run = DefaultClientRun(argc, argv, env);
        }
        return run;
    }
    virtual RunT DefaultClientRun(int argc, char_t**argv, char_t**env) {
        return &Derives::TcpClientRun;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual RunT ServerRun(int argc, char_t**argv, char_t**env) {
        RunT run = 0;
        if ((this->m_serverRun)) {
            run  = (this->*m_serverRun)(argc, argv, env);
        } else {
            run = DefaultServerRun(argc, argv, env);
        }
        return run;
    }
    virtual RunT DefaultServerRun(int argc, char_t**argv, char_t**env) {
        return &Derives::TcpServerRun;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendServerMessage
    (::rete::network::Connection& connection, int argc, char_t**argv, char_t**env) {
        ssize_t count = 0, amount = 0;
        const char *chars = 0;
        size_t length = 0;
        m_sendMessage.clear();
        if ((chars = this->BeforeServerMessage(length, argc, argv, env))) {
            m_sendMessage.append(chars, length);
        }
        if ((chars = this->ServerMessage(length, argc, argv, env))) {
            m_sendMessage.append(chars, length);
        }
        if ((chars = this->AfterServerMessage(length, argc, argv, env))) {
            m_sendMessage.append(chars, length);
        }
        if ((chars = m_sendMessage.has_chars(length))) {
            if (0 < (amount = connection.Send(chars, length))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t RecvServerMessage
    (::rete::network::Connection& connection, int argc, char_t**argv, char_t**env) {
        ssize_t count = 0, amount = 0;
        char c = 0;
        m_recvMessage.clear();
        while (0 < (amount = connection.Recv(&c, sizeof(c)))) {
            if (!(c != '\r') || !(c != 'n')) {
                break;
            }
            m_recvMessage.append(&c, 1);
            count += amount;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendClientMessage
    (::rete::network::Connection& connection, int argc, char_t**argv, char_t**env) {
        ssize_t count = 0, amount = 0;
        const char *chars = 0;
        size_t length = 0;
        m_sendMessage.clear();
        if ((chars = this->BeforeClientMessage(length, argc, argv, env))) {
            m_sendMessage.append(chars, length);
        }
        if ((chars = this->ClientMessage(length, argc, argv, env))) {
            m_sendMessage.append(chars, length);
        }
        if ((chars = this->AfterClientMessage(length, argc, argv, env))) {
            m_sendMessage.append(chars, length);
        }
        if ((chars = m_sendMessage.has_chars(length))) {
            if (0 < (amount = connection.Send(chars, length))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t RecvClientMessage
    (::rete::network::Connection& connection, int argc, char_t**argv, char_t**env) {
        ssize_t count = 0, amount = 0;
        char c = 0;
        m_recvMessage.clear();
        while (0 < (amount = connection.Recv(&c, sizeof(c)))) {
            if (!(c != '\r') || !(c != 'n')) {
                break;
            }
            m_recvMessage.append(&c, 1);
            count += amount;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* ServerMessage(size_t& length, int argc, char_t**argv, char_t**env) {
        const char *chars = 0;
        int args = 0;
        chars = this->ServerMessage(length);
        if ((0 < (args = argc - optind)) && (argv)) {
            const char_t* arg = (args>2)?(argv[optind+1]):(argv[optind]);
            m_message.assign(arg);
            chars = m_message.has_chars(length);
        }
        return chars;
    }
    virtual const char* BeforeServerMessage(size_t& length, int argc, char_t**argv, char_t**env) {
        const char *chars = 0;
        chars = this->BeforeServerMessage(length);
        return chars;
    }
    virtual const char* AfterServerMessage(size_t& length, int argc, char_t**argv, char_t**env) {
        const char *chars = 0;
        int args = 0;
        chars = this->AfterServerMessage(length);
        if ((0 < (args = argc - optind)) && (argv)) {
            const char_t* arg = (args>2)?(argv[optind+2]):("\r\n");
            m_afterMessage.assign(arg);
            chars = m_afterMessage.has_chars(length);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* ClientMessage(size_t& length, int argc, char_t**argv, char_t**env) {
        const char *chars = 0;
        int args = 0;
        chars = this->ClientMessage(length);
        if ((0 < (args = argc - optind)) && (argv)) {
            const char_t* arg = (args>2)?(argv[optind+1]):(argv[optind]);
            m_message.assign(arg);
            chars = m_message.has_chars(length);
        }
        return chars;
    }
    virtual const char* BeforeClientMessage(size_t& length, int argc, char_t**argv, char_t**env) {
        const char *chars = 0;
        chars = this->BeforeClientMessage(length);
        return chars;
    }
    virtual const char* AfterClientMessage(size_t& length, int argc, char_t**argv, char_t**env) {
        const char *chars = 0;
        int args = 0;
        chars = this->AfterClientMessage(length);
        if ((0 < (args = argc - optind)) && (argv)) {
            const char_t* arg = (args>2)?(argv[optind+2]):("\r\n");
            m_afterMessage.assign(arg);
            chars = m_afterMessage.has_chars(length);
        }
        return chars;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef ::rete::network::Location& (Derives::*LocationT)(int argc, char_t**argv, char_t**env);
    LocationT m_clientLocation, m_serverLocation;
    ::rete::network::local::Location m_localLocation;
    ::rete::network::sockets::Location m_socketsLocation;
    ///////////////////////////////////////////////////////////////////////
    virtual ::rete::network::Location& ClientLocation(int argc, char_t**argv, char_t**env) {
        if ((this->m_clientLocation)) {
            return (this->*m_clientLocation)(argc, argv, env);
        }
        return this->DefaultClientLocation(argc, argv, env);
    }
    virtual ::rete::network::Location& LocalClientLocation(int argc, char_t**argv, char_t**env) {
        return m_localLocation;
    }
    virtual ::rete::network::Location& SocketsClientLocation(int argc, char_t**argv, char_t**env) {
        const char* host = 0;
        unsigned port = 0;
        if ((host = this->ClientHost())) {
            m_socketsLocation.SetHost(host);
        }
        if ((port = this->ClientPort())) {
            m_socketsLocation.SetPort(port);
        }
        return m_socketsLocation;
    }
    virtual ::rete::network::Location& DefaultClientLocation(int argc, char_t**argv, char_t**env) {
        return this->SocketsClientLocation(argc, argv, env);
    }
    ///////////////////////////////////////////////////////////////////////
    virtual ::rete::network::Location& ServerLocation(int argc, char_t**argv, char_t**env) {
        if ((this->m_serverLocation)) {
            return (this->*m_serverLocation)(argc, argv, env);
        }
        return this->DefaultServerLocation(argc, argv, env);
    }
    virtual ::rete::network::Location& LocalServerLocation(int argc, char_t**argv, char_t**env) {
        return m_localLocation;
    }
    virtual ::rete::network::Location& SocketsServerLocation(int argc, char_t**argv, char_t**env) {
        const char* host = 0;
        unsigned port = 0;
        if ((host = this->ServerHost())) {
            m_socketsLocation.SetHost(host);
        }
        if ((port = this->ServerPort())) {
            m_socketsLocation.SetPort(port);
        }
        return m_socketsLocation;
    }
    virtual ::rete::network::Location& DefaultServerLocation(int argc, char_t**argv, char_t**env) {
        return this->SocketsServerLocation(argc, argv, env);
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    String m_clientHost, m_serverHost;
    unsigned m_clientPort, m_serverPort;
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetClientHost(const char* to) {
        const char* chars = 0;
        m_clientHost.assign(to);
        chars = m_clientHost.has_chars();
        return chars;
    }
    virtual const char* ClientHost() const {
        const char* chars = m_clientHost.has_chars();
        return chars;
    }
    virtual unsigned SetClientPort(unsigned to) {
        unsigned port = 0;
        m_clientPort = to;
        port = m_clientPort;
        return port;
    }
    virtual unsigned ClientPort() const {
        unsigned port = m_clientPort;
        return port;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetServerHost(const char* to) {
        const char* chars = 0;
        m_serverHost.assign(to);
        chars = m_serverHost.has_chars();
        return chars;
    }
    virtual const char* ServerHost() const {
        const char* chars = m_serverHost.has_chars();
        return chars;
    }
    virtual unsigned SetServerPort(unsigned to) {
        unsigned port = 0;
        m_serverPort = to;
        port = m_serverPort;
        return port;
    }
    virtual unsigned ServerPort() const {
        unsigned port = m_serverPort;
        return port;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    String m_clientMessage, m_beforeClientMessage, m_afterClientMessage, 
           m_serverMessage, m_beforeServerMessage, m_afterServerMessage,
           m_message, m_beforeMessage, m_afterMessage, 
           m_sendMessage, m_recvMessage;
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetClientMessage(const char* to) {
        const char* chars = 0;
        m_clientMessage.assign(to);
        chars = m_clientMessage.has_chars();
        return chars;
    }
    virtual const char* ClientMessage(size_t& length) const {
        const char* chars = m_clientMessage.has_chars(length);
        return chars;
    }
    virtual const char* SetBeforeClientMessage(const char* to) {
        const char* chars = 0;
        m_beforeClientMessage.assign(to);
        chars = m_beforeClientMessage.has_chars();
        return chars;
    }
    virtual const char* BeforeClientMessage(size_t& length) const {
        const char* chars = m_beforeClientMessage.has_chars(length);
        return chars;
    }
    virtual const char* SetAfterClientMessage(const char* to) {
        const char* chars = 0;
        m_afterClientMessage.assign(to);
        chars = m_afterClientMessage.has_chars();
        return chars;
    }
    virtual const char* AfterClientMessage(size_t& length) const {
        const char* chars = m_afterClientMessage.has_chars(length);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* SetServerMessage(const char* to) {
        const char* chars = 0;
        m_serverMessage.assign(to);
        chars = m_serverMessage.has_chars();
        return chars;
    }
    virtual const char* ServerMessage(size_t& length) const {
        const char* chars = m_serverMessage.has_chars(length);
        return chars;
    }
    virtual const char* SetBeforeServerMessage(const char* to) {
        const char* chars = 0;
        m_beforeServerMessage.assign(to);
        chars = m_beforeServerMessage.has_chars();
        return chars;
    }
    virtual const char* BeforeServerMessage(size_t& length) const {
        const char* chars = m_beforeServerMessage.has_chars(length);
        return chars;
    }
    virtual const char* SetAfterServerMessage(const char* to) {
        const char* chars = 0;
        m_afterServerMessage.assign(to);
        chars = m_afterServerMessage.has_chars();
        return chars;
    }
    virtual const char* AfterServerMessage(size_t& length) const {
        const char* chars = m_afterServerMessage.has_chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef ::rete::network::Transport& (Derives::*TransportT)(int argc, char_t**argv, char_t**env);
    TransportT m_transport;
    ::rete::network::local::stream::Transport m_streamTransport;
    ::rete::network::local::dgram::Transport m_dgramTransport;
    ::rete::network::ip::tcp::Transport m_tcpTransport;
    ::rete::network::ip::udp::Transport m_udpTransport;
    ///////////////////////////////////////////////////////////////////////
    virtual ::rete::network::Transport& Transport(int argc, char_t**argv, char_t**env) {
        if ((m_transport)) {
            return (this->*m_transport)(argc, argv, env);
        }
        return DefaultTransport(argc, argv, env);
    }
    virtual ::rete::network::Transport& StreamTransport(int argc, char_t**argv, char_t**env) {
        return m_streamTransport;
    }
    virtual ::rete::network::Transport& DgramTransport(int argc, char_t**argv, char_t**env) {
        return m_dgramTransport;
    }
    virtual ::rete::network::Transport& TcpTransport(int argc, char_t**argv, char_t**env) {
        return m_tcpTransport;
    }
    virtual ::rete::network::Transport& UdpTransport(int argc, char_t**argv, char_t**env) {
        return m_udpTransport;
    }
    virtual ::rete::network::Transport& DefaultTransport(int argc, char_t**argv, char_t**env) {
        return m_tcpTransport;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef ::rete::network::Endpoint& (Derives::*EndpointT)(int argc, char_t**argv, char_t**env);
    EndpointT m_endpoint;
    ::rete::network::local::Endpoint m_localEndpoint;
    ::rete::network::ip::v4::Endpoint m_ipV4Endpoint;
    ::rete::network::ip::v6::Endpoint m_ipV6Endpoint;
    ///////////////////////////////////////////////////////////////////////
    virtual ::rete::network::Endpoint& Endpoint(int argc, char_t**argv, char_t**env) {
        if ((m_endpoint)) {
            return (this->*m_endpoint)(argc, argv, env);
        }
        return DefaultEndpoint(argc, argv, env);
    }
    virtual ::rete::network::Endpoint& LocalEndpoint(int argc, char_t**argv, char_t**env) {
        return m_localEndpoint;
    }
    virtual ::rete::network::Endpoint& IpV4Endpoint(int argc, char_t**argv, char_t**env) {
        return m_ipV4Endpoint;
    }
    virtual ::rete::network::Endpoint& IpV6Endpoint(int argc, char_t**argv, char_t**env) {
        return m_ipV6Endpoint;
    }
    virtual ::rete::network::Endpoint& DefaultEndpoint(int argc, char_t**argv, char_t**env) {
        return m_ipV4Endpoint;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef ::rete::network::Connection& (Derives::*ConnectionT)(int argc, char_t**argv, char_t**env);
    ConnectionT m_connection, m_accepted;
    ::rete::network::os::Socket m_socket, m_socket_accepted;
    ///////////////////////////////////////////////////////////////////////
    virtual ::rete::network::Connection& Connection(int argc, char_t**argv, char_t**env) {
        if ((this->m_connection)) {
            return (this->*m_connection)(argc, argv, env);
        }
        return this->DefaultConnection(argc, argv, env);
    }
    virtual ::rete::network::Connection& SocketConnection(int argc, char_t**argv, char_t**env) {
        return m_socket;
    }
    virtual ::rete::network::Connection& DefaultConnection(int argc, char_t**argv, char_t**env) {
        return this->SocketConnection(argc, argv, env);
    }
    ///////////////////////////////////////////////////////////////////////
    virtual ::rete::network::Connection& Accepted(int argc, char_t**argv, char_t**env) {
        if ((this->m_connection)) {
            return (this->*m_connection)(argc, argv, env);
        }
        return this->DefaultAccepted(argc, argv, env);
    }
    virtual ::rete::network::Connection& SocketAccepted(int argc, char_t**argv, char_t**env) {
        return m_socket_accepted;
    }
    virtual ::rete::network::Connection& DefaultAccepted(int argc, char_t**argv, char_t**env) {
        return this->SocketAccepted(argc, argv, env);
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ::rete::network::os::Sockets m_sockets;
    virtual ::rete::network::Sockets& Sockets(int argc, char_t**argv, char_t**env) {
        return m_sockets;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnClientOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = ClientRun(argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnServerOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = ServerRun(argc, argv, env);
        return err;
    }

    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->SetClientHost(optarg);
            this->SetServerHost(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnPortOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            unsigned port = String(optarg).to_unsigned();
            this->SetClientPort(port);
            this->SetServerPort(port);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
};

} // namespace rete 
} // namespace console 
} // namespace app 
} // namespace rete 

#endif // _RETE_APP_CONSOLE_RETE_MAIN_HPP 
