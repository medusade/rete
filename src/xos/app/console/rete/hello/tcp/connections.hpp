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
///   File: connections.hpp
///
/// Author: $author$
///   Date: 6/21/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_TCP_CONNECTIONS_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_TCP_CONNECTIONS_HPP

#include "xos/app/console/rete/hello/message.hpp"

#include "xos/network/ip/v4/tcp/transport.hpp"
#include "xos/network/ip/v4/endpoint.hpp"

#include "xos/network/ip/v6/tcp/transport.hpp"
#include "xos/network/ip/v6/endpoint.hpp"

#include "xos/network/os/socket.hpp"
#include "xos/mt/os/semaphore.hpp"
#include "xos/mt/os/mutex.hpp"
#include "xos/mt/lock.hpp"

#include <queue>

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {
namespace tcp {

/// class connectionst
template <class TExtends = extend, class TImplements = typename TExtends::implements>
class exported connectionst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef connectionst derives; 
    
    /// constructors / destructor
    connectionst(): cleared_(false) {
    }
    virtual ~connectionst() {
        clear();
    }
private:
    connectionst(const connectionst& copy): cleared_(false) {
    }

public:
    /// ...queue / clear
    virtual bool queue(network::os::socket& s) {
        mt::lock l(lock_);
        queue_.push(s);
        if (0 < (queue_.size())) {
            network::os::socket& qed = queue_.back();
            LOGGER_LOG_DEBUG("queued socket...");
            qed.set_is_open(s.is_open());
            s.set_is_open(false);
            signal_.release();
            return true;
        } else {
            LOGGER_LOG_ERROR("...queue empty");
        }
        return false;
    }
    virtual bool dequeue(network::os::socket& s) {
        LOGGER_LOG_DEBUG("wait signal...");
        if ((signal_.wait())) {
            mt::lock l(lock_);
            if (0 < (queue_.size())) {
                s = queue_.front();
                s.set_is_open(queue_.front().is_open());
                queue_.front().set_is_open(false);
                queue_.pop();
                LOGGER_LOG_DEBUG("...dequeued socket");
                return true;
            } else {
                LOGGER_LOG_DEBUG("...queue empty");
                if ((cleared_)) {
                    signal_.release();
                }
            }
        } else {
            LOGGER_LOG_ERROR("...failed on wait signal");
        }
        return false;
    }
    virtual void clear() {
        mt::lock l(lock_);
        while (0 < (queue_.size())) {
            network::os::socket s = queue_.front();
            s.closed();
            queue_.pop();
        }
        cleared_ = true;
    }

protected:
    bool cleared_;
    mt::os::mutex lock_;
    mt::os::semaphore signal_;
    std::queue<network::os::socket> queue_;
}; /// class connectionst
typedef connectionst<> connections;

} /// namespace tcp
} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_RETE_HELLO_TCP_CONNECTIONS_HPP
