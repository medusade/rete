########################################################################
# Copyright (c) 1988-2017 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: test.pri
#
# Author: $author$
#   Date: 8/14/2017
########################################################################

test_TARGET = test

test_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

test_DEFINES += \
$${rete_DEFINES} \

########################################################################
# nadir
test_HEADERS += \
$${NADIR_SRC}/xos/base/Base.hpp \

test_SOURCES += \
$${NADIR_SRC}/xos/base/Base.cpp \

########################################################################
# patrona
test_HEADERS += \
$${PATRONA_SRC}/xos/base/Opened.hpp \
$${PATRONA_SRC}/xos/base/Created.hpp \

test_SOURCES += \
$${PATRONA_SRC}/xos/base/Opened.cpp \
$${PATRONA_SRC}/xos/base/Created.cpp \

########################################################################
# fila
test_HEADERS += \
$${FILA_SRC}/xos/mt/os/Mutex.hpp \

test_SOURCES += \
$${FILA_SRC}/xos/mt/os/Mutex.cpp \

########################################################################
# crono
test_HEADERS += \
$${CRONO_SRC}/xos/mt/Logger.hpp \

test_SOURCES += \
$${CRONO_SRC}/xos/mt/Logger.cpp \

########################################################################
# rete
test_HEADERS += \
$${RETE_SRC}/xos/network/Library.hpp \
$${RETE_SRC}/xos/network/posix/Sockets.hpp \
$${RETE_SRC}/xos/network/posix/Socket.hpp \
$${RETE_SRC}/xos/network/sockets/posix/Interface.hpp \
$${RETE_SRC}/xos/network/sockets/Interface.hpp \
$${RETE_SRC}/xos/network/Interface.hpp \
$${RETE_SRC}/xos/network/sockets/ip/v6/Endpoint.hpp \
$${RETE_SRC}/xos/network/sockets/ip/v4/Endpoint.hpp \
$${RETE_SRC}/xos/network/sockets/ip/Endpoint.hpp \
$${RETE_SRC}/xos/network/sockets/Endpoint.hpp \
$${RETE_SRC}/xos/network/Endpoint.hpp \
$${RETE_SRC}/xos/network/sockets/Location.hpp \
$${RETE_SRC}/xos/network/Location.hpp \
$${RETE_SRC}/xos/network/Sockets.hpp \
$${RETE_SRC}/xos/network/sockets/ip/udp/Transport.hpp \
$${RETE_SRC}/xos/network/sockets/ip/tcp/Transport.hpp \
$${RETE_SRC}/xos/network/sockets/ip/Transport.hpp \
$${RETE_SRC}/xos/network/sockets/Transport.hpp \
$${RETE_SRC}/xos/network/Transport.hpp \
$${RETE_SRC}/xos/network/sockets/transport/Interface.hpp \
$${RETE_SRC}/xos/network/sockets/transport/Domain.hpp \
$${RETE_SRC}/xos/network/sockets/transport/Type.hpp \
$${RETE_SRC}/xos/network/sockets/transport/Protocol.hpp \
$${RETE_SRC}/xos/network/transport/Interface.hpp \
$${RETE_SRC}/xos/network/transport/Domain.hpp \
$${RETE_SRC}/xos/network/transport/Type.hpp \
$${RETE_SRC}/xos/network/transport/Protocol.hpp \
$${RETE_SRC}/xos/network/sockets/ip/v6/Address.hpp \
$${RETE_SRC}/xos/network/sockets/ip/v4/Address.hpp \
$${RETE_SRC}/xos/network/sockets/ip/Address.hpp \
$${RETE_SRC}/xos/network/sockets/Address.hpp \
$${RETE_SRC}/xos/network/sockets/address/Interface.hpp \
$${RETE_SRC}/xos/network/sockets/address/Family.hpp \
$${RETE_SRC}/xos/network/sockets/address/Version.hpp \
$${RETE_SRC}/xos/network/address/Interface.hpp \
$${RETE_SRC}/xos/network/address/Family.hpp \
$${RETE_SRC}/xos/network/address/Version.hpp \
$${RETE_SRC}/xos/app/console/mt/hello/Main.hpp \
$${RETE_SRC}/rete/app/console/mt/hello/Main.hpp \
$${RETE_SRC}/rete/app/console/mt/hello/MainOpt.hpp \
$${RETE_SRC}/rete/console/mt/getopt/Main.hpp \
$${RETE_SRC}/rete/console/mt/getopt/MainOpt.hpp \
$${RETE_SRC}/rete/console/getopt/Main.hpp \
$${RETE_SRC}/rete/console/getopt/MainOpt.hpp \

test_SOURCES += \
$${RETE_SRC}/xos/network/Library.cpp \
$${RETE_SRC}/xos/network/posix/Sockets.cpp \
$${RETE_SRC}/xos/network/posix/Socket.cpp \
$${RETE_SRC}/xos/network/sockets/posix/Interface.cpp \
$${RETE_SRC}/xos/network/sockets/ip/v6/Endpoint.cpp \
$${RETE_SRC}/xos/network/sockets/Location.cpp \
$${RETE_SRC}/xos/network/Transport.cpp \
$${RETE_SRC}/xos/network/sockets/transport/Domain.cpp \
$${RETE_SRC}/xos/network/sockets/transport/Type.cpp \
$${RETE_SRC}/xos/network/sockets/transport/Protocol.cpp \
$${RETE_SRC}/xos/network/sockets/Address.cpp \
$${RETE_SRC}/xos/network/sockets/address/Family.cpp \
$${RETE_SRC}/xos/network/sockets/address/Version.cpp \
$${RETE_SRC}/xos/app/console/mt/hello/Main.cpp \

########################################################################
test_HEADERS += \
$${CRONO_SRC}/xos/console/mt/Main_main.hpp \

test_SOURCES += \
$${CRONO_SRC}/xos/console/mt/Main_main.cpp \

########################################################################
test_LIBS += \
$${crono_LIBS} \

