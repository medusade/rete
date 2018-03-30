########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   Date: 11/29/2016
########################################################################
RETE_PKG = ../../../../..
RETE_BLD = ../..

RETE_PRJ = $${RETE_PKG}
RETE_BIN = $${RETE_BLD}/bin
RETE_LIB = $${RETE_BLD}/lib
RETE_SRC = $${RETE_PKG}/src

CONFIG(debug, debug|release) {
RETE_CONFIG = Debug
rete_DEFINES += DEBUG_BUILD
} else {
RETE_CONFIG = Release
rete_DEFINES += RELEASE_BUILD
}
rete_DEFINES += BUILD_CONFIG=$${RETE_CONFIG}

########################################################################
# NO Qt
QT -= gui core

########################################################################
# patrona
PATRONA_PKG = $${RETE_PKG}/../patrona
PATRONA_PRJ = $${PATRONA_PKG}
PATRONA_SRC = $${PATRONA_PKG}/src

patrona_INCLUDEPATH += \
$${PATRONA_SRC} \

patrona_DEFINES += \

patrona_LIBS += \

########################################################################
# nadir
NADIR_PKG = $${RETE_PKG}/../nadir
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

nadir_LIBS += \

########################################################################
# crono
CRONO_PKG = $${RETE_PKG}/../crono
CRONO_PRJ = $${CRONO_PKG}
CRONO_SRC = $${CRONO_PKG}/src

crono_INCLUDEPATH += \
$${CRONO_SRC} \

crono_DEFINES += \

crono_LIBS += \

########################################################################
rete_INCLUDEPATH += \
$${RETE_SRC} \
$${crono_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \

rete_DEFINES += \

########################################################################
rete_LIBS += \
-L$${RETE_LIB}/librete \
-lrete \
