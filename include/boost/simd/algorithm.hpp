//==================================================================================================
/*!
  @file

  Convenience header for Boost.SIMD standard algorithms

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-api
    @defgroup group-std Algorithms and Ranges

    SIMD-aware Range adaptors and implementation of standard algorithms;
  **/
} }

#include <boost/simd/algorithm/reduce.hpp>
#include <boost/simd/algorithm/transform.hpp>

#endif
