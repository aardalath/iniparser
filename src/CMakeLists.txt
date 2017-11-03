#=============================================================================
# CMakeLists.txt
# src directory
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

SET(INIPARSER_SOURCES
	iniparser.cpp
	)

SET(INIPARSER_HEADERS
	iniparser.h
	)

SET(INIPARSER_INTERNAL_HEADERS
	)

ADD_LIBRARY(iniparser SHARED ${INIPARSER_SOURCES} )

SET_TARGET_PROPERTIES(iniparser PROPERTIES 
                      SOVERSION ${INIPARSER_VERSION}
                      VERSION   ${INIPARSER_VERSION})

INSTALL(TARGETS iniparser
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

INSTALL(FILES ${INIPARSER_HEADERS}
	DESTINATION include)

