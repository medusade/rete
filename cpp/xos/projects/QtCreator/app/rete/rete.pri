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
#   File: rete.pri
#
# Author: $author$
#   Date: 9/5/2017
#
# QtCreator .pri file for rete executable rete
########################################################################

rete_exe_TARGET = rete

########################################################################
rete_exe_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

rete_exe_DEFINES += \
$${rete_DEFINES} \
XOS_APP_CONSOLE_RETE_THE_MAIN \

########################################################################
# rete
rete_exe_HEADERS += \
$${FILA_SRC}/xos/console/mt/Main_main.hpp \

rete_exe_SOURCES += \
$${FILA_SRC}/xos/console/mt/Main_main.cpp \

########################################################################
# rete
rete_exe_HEADERS += \
$${RETE_SRC}/xos/app/console/rete/Main.hpp \
$${RETE_SRC}/xos/app/console/rete/MainOpt.hpp \

rete_exe_SOURCES += \
$${RETE_SRC}/xos/app/console/rete/Main.cpp \
$${RETE_SRC}/xos/app/console/rete/MainOpt.cpp \

########################################################################
rete_exe_LIBS += \
$${rete_LIBS} \



