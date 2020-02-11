########################################################################
# Copyright (c) 1988-2020 $organization$
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
#   File: ethernet.pri
#
# Author: $author$
#   Date: 2/9/2020
#
# QtCreator .pri file for rete executable ethernet
########################################################################

########################################################################
# ethernet

# ethernet TARGET
#
ethernet_TARGET = ethernet

# ethernet INCLUDEPATH
#
ethernet_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# ethernet DEFINES
#
ethernet_DEFINES += \
$${rete_DEFINES} \

########################################################################
# ethernet OBJECTIVE_HEADERS
#
#ethernet_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/rete/base/Base.hh \

# ethernet OBJECTIVE_SOURCES
#
#ethernet_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/rete/base/Base.mm \

########################################################################
# ethernet HEADERS
#
ethernet_HEADERS += \
$${RETE_SRC}/rete/network/ethernet/Address.hpp \
$${RETE_SRC}/rete/network/ethernet/posix/Address.hpp \
\
$${RETE_SRC}/rete/app/console/ethernet/MainOpt.hpp \
$${RETE_SRC}/rete/app/console/ethernet/Main.hpp \

# ethernet SOURCES
#
ethernet_SOURCES += \
$${RETE_SRC}/rete/network/ethernet/posix/Address.cpp \
\
$${RETE_SRC}/rete/app/console/ethernet/MainOpt.cpp \
$${RETE_SRC}/rete/app/console/ethernet/Main.cpp \
\
$${RETE_SRC}/rete/console/Main_main.cpp \

########################################################################
# ethernet FRAMEWORKS
#
ethernet_FRAMEWORKS += \
$${rete_FRAMEWORKS} \

# ethernet LIBS
#
ethernet_LIBS += \
$${rete_LIBS} \


