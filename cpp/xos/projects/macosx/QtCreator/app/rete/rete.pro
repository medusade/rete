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
#   File: rete.pro
#
# Author: $author$
#   Date: 9/5/2017
#
# QtCreator .pro file for rete executable rete
########################################################################
include(../../../../../build/QtCreator/rete.pri)
include(../../../../QtCreator/rete.pri)
include(../../rete.pri)
include(../../../../QtCreator/app/rete/rete.pri)

TARGET = $${rete_exe_TARGET}


########################################################################
INCLUDEPATH += \
$${rete_exe_INCLUDEPATH} \

DEFINES += \
$${rete_exe_DEFINES} \

########################################################################
HEADERS += \
$${rete_exe_HEADERS} \

SOURCES += \
$${rete_exe_SOURCES} \

########################################################################
LIBS += \
$${rete_exe_LIBS} \


