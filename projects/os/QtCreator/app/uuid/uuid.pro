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
#   File: uuid.pro
#
# Author: $author$
#   Date: 2/9/2020
#
# QtCreator .pro file for rete executable uuid
########################################################################
include(../../../../../build/QtCreator/rete.pri)
include(../../../../QtCreator/rete.pri)
include(../../rete.pri)
include(../../../../QtCreator/app/uuid/uuid.pri)

TARGET = $${uuid_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${uuid_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${uuid_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${uuid_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${uuid_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${uuid_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${uuid_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${uuid_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${uuid_LIBS} \
$${FRAMEWORKS} \


