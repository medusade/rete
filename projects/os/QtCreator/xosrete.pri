########################################################################
# Copyright (c) 1988-2021 $organization$
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
#   File: xosrete.pri
#
# Author: $author$
#   Date: 6/14/2021
#
# Os specific QtCreator .pri file for xosrete
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
XOSRETE_OS = macosx
} else {
contains(UNAME,Linux) {
XOSRETE_OS = linux
} else {
XOSRETE_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,XOSRETE_OS) {
XOSRETE_BUILD = $${XOSRETE_OS}
} else {
XOSRETE_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,XOSRETE_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(XOSRETE_OS,macosx) {
} else {
contains(XOSRETE_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(XOSRETE_OS,windows) {
} else {
} # contains(XOSRETE_OS,windows)
} # contains(XOSRETE_OS,linux)
} # contains(XOSRETE_OS,macosx)

########################################################################
# xosrostra
XOSROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${XOSROSTRA_THIRDPARTY_PKG}/build/$${XOSRETE_BUILD}/$${BUILD_CONFIG}
XOSROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${XOSROSTRA_THIRDPARTY_PRJ}/build/$${XOSRETE_BUILD}/$${BUILD_CONFIG}
XOSROSTRA_THIRDPARTY_PKG_BLD = $${XOSROSTRA_THIRDPARTY_PKG}/build/$${XOSRETE_BUILD}/QtCreator/$${BUILD_CONFIG}
XOSROSTRA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${XOSROSTRA_THIRDPARTY_PRJ}/build/$${XOSRETE_BUILD}/QtCreator/$${BUILD_CONFIG}
XOSROSTRA_PKG_BLD = $${OTHER_BLD}/$${XOSROSTRA_PKG}/build/$${XOSRETE_BUILD}/QtCreator/$${BUILD_CONFIG}
XOSROSTRA_PRJ_BLD = $${OTHER_BLD}/$${XOSROSTRA_PRJ}/build/$${XOSRETE_BUILD}/QtCreator/$${BUILD_CONFIG}
#XOSROSTRA_LIB = $${XOSROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#XOSROSTRA_LIB = $${XOSROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#XOSROSTRA_LIB = $${XOSROSTRA_THIRDPARTY_PKG_BLD}/lib
#XOSROSTRA_LIB = $${XOSROSTRA_THIRDPARTY_PRJ_BLD}/lib
XOSROSTRA_LIB = $${XOSROSTRA_PKG_BLD}/lib
#XOSROSTRA_LIB = $${XOSROSTRA_PRJ_BLD}/lib
#XOSROSTRA_LIB = $${XOSRETE_LIB}

# xosrostra LIBS
#
xosrostra_LIBS += \
-L$${XOSROSTRA_LIB}/lib$${XOSROSTRA_LIB_NAME} \
-l$${XOSROSTRA_LIB_NAME} \

########################################################################
# xosnadir
XOSNADIR_THIRDPARTY_PKG_MAKE_BLD = $${XOSNADIR_THIRDPARTY_PKG}/build/$${XOSRETE_BUILD}/$${BUILD_CONFIG}
XOSNADIR_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${XOSNADIR_THIRDPARTY_PRJ}/build/$${XOSRETE_BUILD}/$${BUILD_CONFIG}
XOSNADIR_THIRDPARTY_PKG_BLD = $${XOSNADIR_THIRDPARTY_PKG}/build/$${XOSRETE_BUILD}/QtCreator/$${BUILD_CONFIG}
XOSNADIR_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${XOSNADIR_THIRDPARTY_PRJ}/build/$${XOSRETE_BUILD}/QtCreator/$${BUILD_CONFIG}
XOSNADIR_PKG_BLD = $${OTHER_BLD}/$${XOSNADIR_PKG}/build/$${XOSRETE_BUILD}/QtCreator/$${BUILD_CONFIG}
XOSNADIR_PRJ_BLD = $${OTHER_BLD}/$${XOSNADIR_PRJ}/build/$${XOSRETE_BUILD}/QtCreator/$${BUILD_CONFIG}
#XOSNADIR_LIB = $${XOSNADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#XOSNADIR_LIB = $${XOSNADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#XOSNADIR_LIB = $${XOSNADIR_THIRDPARTY_PKG_BLD}/lib
#XOSNADIR_LIB = $${XOSNADIR_THIRDPARTY_PRJ_BLD}/lib
XOSNADIR_LIB = $${XOSNADIR_PKG_BLD}/lib
#XOSNADIR_LIB = $${XOSNADIR_PRJ_BLD}/lib
#XOSNADIR_LIB = $${XOSRETE_LIB}

# xosnadir LIBS
#
xosnadir_LIBS += \
-L$${XOSNADIR_LIB}/lib$${XOSNADIR_LIB_NAME} \
-l$${XOSNADIR_LIB_NAME} \

########################################################################
# xosrete

# xosrete INCLUDEPATH
#
xosrete_INCLUDEPATH += \

# xosrete DEFINES
#
xosrete_DEFINES += \

# xosrete LIBS
#
xosrete_LIBS += \
$${xosnadir_LIBS} \
$${xosrostra_LIBS} \
$${build_xosrete_LIBS} \

contains(XOSRETE_OS,macosx|linux) {
xosrete_LIBS += \
-lpthread \
-ldl
} else {
} # contains(XOSRETE_OS,macosx|linux)

contains(XOSRETE_OS,linux) {
xosrete_LIBS += \
-lrt
} else {
} # contains(XOSRETE_OS,linux)
