########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   File: rete.pri
#
# Author: $author$
#   Date: 3/24/2018, 12/26/2020
#
# QtCreator .pri file for rete executable rete
########################################################################

########################################################################
# rete

# rete_exe TARGET
#
rete_exe_TARGET = rete

# rete_exe INCLUDEPATH
#
rete_exe_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# rete_exe DEFINES
#
rete_exe_DEFINES += \
$${rete_DEFINES} \
XOS_DEFAULT_LOG_ERROR \

########################################################################
# rete_exe OBJECTIVE_HEADERS
#
#rete_exe_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/rete/base/Base.hh \

# rete_exe OBJECTIVE_SOURCES
#
#rete_exe_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/rete/base/Base.mm \

########################################################################
# rete_exe HEADERS
#
rete_exe_HEADERS += \
$${CIFRA_SRC}/cifra/crypto/random/generator.hpp \
$${CIFRA_SRC}/cifra/crypto/random/pseudo/generator.hpp \
\
$${RETE_SRC}/rete/network/Sockets.hpp \
$${RETE_SRC}/rete/network/Address.hpp \
$${RETE_SRC}/rete/network/ethernet/Address.hpp \
$${RETE_SRC}/rete/network/unique/Identifier.hpp \
$${RETE_SRC}/rete/network/unique/posix/Identifier.hpp \
$${RETE_SRC}/rete/network/Addresses.hpp \
$${RETE_SRC}/rete/network/Location.hpp \
$${RETE_SRC}/rete/network/local/Location.hpp \
$${RETE_SRC}/rete/network/sockets/Location.hpp \
$${RETE_SRC}/rete/network/Locations.hpp \
$${RETE_SRC}/rete/network/Transports.hpp \
$${RETE_SRC}/rete/network/Endpoint.hpp \
$${RETE_SRC}/rete/network/local/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/v4/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/v6/Endpoint.hpp \
$${RETE_SRC}/rete/network/Endpoints.hpp \
$${RETE_SRC}/rete/network/Interface.hpp \
$${RETE_SRC}/rete/network/sockets/Interface.hpp \
$${RETE_SRC}/rete/network/Connection.hpp \
$${RETE_SRC}/rete/network/Connections.hpp \
$${RETE_SRC}/rete/network/Connector.hpp \
$${RETE_SRC}/rete/network/Connectors.hpp \
\
$${RETE_SRC}/rete/console/Main_main.hpp \
\
$${RETE_SRC}/rete/app/console/rete/MainOpt.hpp \
$${RETE_SRC}/rete/app/console/rete/Main.hpp \

# rete_exe SOURCES
#
rete_exe_SOURCES += \
$${CIFRA_SRC}/cifra/crypto/random/pseudo/generator.cpp \
\
$${RETE_SRC}/rete/network/ethernet/Address.cpp \
$${RETE_SRC}/rete/network/unique/posix/Identifier.cpp \
$${RETE_SRC}/rete/network/Addresses.cpp \
$${RETE_SRC}/rete/network/Location.cpp \
$${RETE_SRC}/rete/network/Locations.cpp \
$${RETE_SRC}/rete/network/Transports.cpp \
$${RETE_SRC}/rete/network/Endpoint.cpp \
$${RETE_SRC}/rete/network/Endpoints.cpp \
$${RETE_SRC}/rete/network/sockets/Interface.cpp \
$${RETE_SRC}/rete/network/Connection.cpp \
$${RETE_SRC}/rete/network/Connections.cpp \
$${RETE_SRC}/rete/network/Connector.cpp \
$${RETE_SRC}/rete/network/Connectors.cpp \
\
$${RETE_SRC}/rete/console/Main_main.cpp \
\
$${RETE_SRC}/rete/app/console/rete/MainOpt.cpp \
$${RETE_SRC}/rete/app/console/rete/Main.cpp \

########################################################################
# rete_exe FRAMEWORKS
#
rete_exe_FRAMEWORKS += \
$${rete_FRAMEWORKS} \

# rete_exe LIBS
#
rete_exe_LIBS += \
$${rete_LIBS} \

