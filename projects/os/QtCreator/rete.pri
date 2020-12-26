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
#   Date: 12/28/2018, 12/26/2020
#
# Os specific QtCreator .pri file for rete
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
RETE_OS = macosx
} else {
contains(UNAME,Linux) {
RETE_OS = linux
} else {
RETE_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,RETE_OS) {
RETE_BUILD = $${RETE_OS}
} else {
RETE_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,RETE_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(RETE_OS,macosx) {
} else {
contains(RETE_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(RETE_OS,windows) {
} else {
} # contains(RETE_OS,windows)
} # contains(RETE_OS,linux)
} # contains(RETE_OS,macosx)

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${RETE_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# nadir
NADIR_THIRDPARTY_PKG_MAKE_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_MAKE_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PKG_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_PKG_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_PRJ_BLD = $${OTHER_BLD}/$${NADIR_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_BLD}/lib
#NADIR_LIB = $${NADIR_PKG_BLD}/lib
NADIR_LIB = $${NADIR_PRJ_BLD}/lib
#NADIR_LIB = $${RETE_LIB}

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_NAME} \
-l$${NADIR_NAME} \

########################################################################
# patrona
PATRONA_THIRDPARTY_PKG_MAKE_BLD = $${PATRONA_THIRDPARTY_PKG}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PRJ_MAKE_BLD = $${PATRONA_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PKG_BLD = $${PATRONA_THIRDPARTY_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PRJ_BLD = $${PATRONA_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
PATRONA_PKG_BLD = $${OTHER_BLD}/$${PATRONA_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
PATRONA_PRJ_BLD = $${OTHER_BLD}/$${PATRONA_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PKG_MAKE_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PKG_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PRJ_BLD}/lib
#PATRONA_LIB = $${PATRONA_PKG_BLD}/lib
PATRONA_LIB = $${PATRONA_PRJ_BLD}/lib
#PATRONA_LIB = $${RETE_LIB}

# patrona LIBS
#
patrona_LIBS += \
-L$${PATRONA_LIB}/lib$${PATRONA_NAME} \
-l$${PATRONA_NAME} \

########################################################################
# crono
CRONO_THIRDPARTY_PKG_MAKE_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_MAKE_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PKG_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
CRONO_PKG_BLD = $${OTHER_BLD}/$${CRONO_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
CRONO_PRJ_BLD = $${OTHER_BLD}/$${CRONO_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_BLD}/lib
#CRONO_LIB = $${CRONO_PKG_BLD}/lib
CRONO_LIB = $${CRONO_PRJ_BLD}/lib
#CRONO_LIB = $${RETE_LIB}

# crono LIBS
#
crono_LIBS += \
-L$${CRONO_LIB}/lib$${CRONO_NAME} \
-l$${CRONO_NAME} \

########################################################################
# fila
FILA_THIRDPARTY_PKG_MAKE_BLD = $${FILA_THIRDPARTY_PKG}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_MAKE_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PKG_BLD = $${FILA_THIRDPARTY_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
FILA_PKG_BLD = $${OTHER_BLD}/$${FILA_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
FILA_PRJ_BLD = $${OTHER_BLD}/$${FILA_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
#FILA_LIB = $${FILA_THIRDPARTY_PKG_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PKG_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_BLD}/lib
#FILA_LIB = $${FILA_PKG_BLD}/lib
FILA_LIB = $${FILA_PRJ_BLD}/lib
#FILA_LIB = $${RETE_LIB}

# fila LIBS
#
fila_LIBS += \
-L$${FILA_LIB}/lib$${FILA_NAME} \
-l$${FILA_NAME} \

########################################################################
# cifra
CIFRA_THIRDPARTY_PKG_MAKE_BLD = $${CIFRA_THIRDPARTY_PKG}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
CIFRA_THIRDPARTY_PRJ_MAKE_BLD = $${CIFRA_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/$${BUILD_CONFIG}
CIFRA_THIRDPARTY_PKG_BLD = $${CIFRA_THIRDPARTY_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
CIFRA_THIRDPARTY_PRJ_BLD = $${CIFRA_THIRDPARTY_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
CIFRA_PKG_BLD = $${OTHER_BLD}/$${CIFRA_PKG}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
CIFRA_PRJ_BLD = $${OTHER_BLD}/$${CIFRA_PRJ}/build/$${RETE_BUILD}/QtCreator/$${BUILD_CONFIG}
#CIFRA_LIB = $${CIFRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#CIFRA_LIB = $${CIFRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#CIFRA_LIB = $${CIFRA_THIRDPARTY_PKG_BLD}/lib
#CIFRA_LIB = $${CIFRA_THIRDPARTY_PRJ_BLD}/lib
#CIFRA_LIB = $${CIFRA_PKG_BLD}/lib
CIFRA_LIB = $${CIFRA_PRJ_BLD}/lib
#CIFRA_LIB = $${RETE_LIB}

# cifra LIBS
#
cifra_LIBS += \
-L$${CIFRA_LIB}/lib$${CIFRA_NAME} \
-l$${CIFRA_NAME} \

########################################################################
# rete

# rete INCLUDEPATH
#
rete_INCLUDEPATH += \

# rete DEFINES
#
rete_DEFINES += \

# rete LIBS
#
rete_LIBS += \
$${fila_LIBS} \
$${crono_LIBS} \
$${patrona_LIBS} \
$${nadir_LIBS} \
$${rostra_LIBS} \
$${build_rete_LIBS} \
-lpthread \
-ldl \

contains(RETE_OS,linux) {
rete_LIBS += \
-lrt
} else {
}
