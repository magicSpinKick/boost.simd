//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAXNUMMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAXNUMMAG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing maxnummag capabilities

    Returns the input value which have the greatest absolute value, ignoring nan.

    @par Semantic:

    @code
    T r = maxnummag(x,y);
    @endcode

    is similar to:

    @code
    T r = isnan(x) ? y : (isnan(y) ? x : maxmag(x, y));
    @endcode

  **/
  Value maxnummag(Value const & x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/maxnummag.hpp>
#include <boost/simd/function/simd/maxnummag.hpp>

#endif
