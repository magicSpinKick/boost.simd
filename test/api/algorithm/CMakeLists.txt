##==================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

SET( SOURCES
    reduce.cpp
    transform.cpp
   )

make_unit( "api.algorithm" ${SOURCES})
