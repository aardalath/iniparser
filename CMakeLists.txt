#=============================================================================
# CMakeLists.txt
#
# Copyright (C) 2015, J C Gonzalez
#
# This file is part of IniParser v. 0.1 
# 
# IniParser is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your
# option) any later version.
# 
# IniParser is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
# License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with iniparser.  If not, see <http://www.gnu.org/licenses/>
#=============================================================================
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(INIPARSER)

SET(PROJECT_NAME INIPARSER)

SET(INIPARSER_MAJOR 0)
SET(INIPARSER_MINOR 1)
SET(INIPARSER_PATCH 0)

SET(INIPARSER_VERSION ${INIPARSER_MAJOR}.${INIPARSER_MINOR}.${INIPARSER_PATCH})

MESSAGE(STATUS "Building iniparser version ${INIPARSER_VERSION}")

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(examples/iniex1)

SET(CPACK_PACKAGE_VERSION_MAJOR ${INIPARSER_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${INIPARSER_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH ${INIPARSER_PATCH})
SET(CPACK_GENERATOR "TGZ")
SET(CPACK_PACKAGING_INSTALL_PREFIX "")

INCLUDE(CPack)

