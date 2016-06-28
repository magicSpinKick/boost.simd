## -------------------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------

set(SOURCES
  abs.cpp
  acos.cpp
  acosd.cpp
  acospi.cpp
  acot.cpp
  acotd.cpp
  acoth.cpp
  acotpi.cpp
  asin.cpp
  atan.cpp
  atanh.cpp
##  asin.cpp
##  atan.cpp
##  exp.cpp
##  exp10.cpp
##  exp2.cpp
##  expm1.cpp
  fast_acos.cpp
  fast_acosd.cpp
  fast_acospi.cpp
  fast_atanh.cpp
  log.cpp
  log1p.cpp
  log10.cpp
  log2.cpp
  std_acos.cpp
 )

make_exhaustive("function.simd" ${SOURCES})

















