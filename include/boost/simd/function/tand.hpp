//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TAND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing tand capabilities

    tangent of the input in degrees.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = tand(x);
    @endcode

    is similar to:

    @code
    T r =  sind(x)/cosd(x);
    @endcode

    As most other trigonometric function tand can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see tan, tanpi

  **/
  Value tand(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/tand.hpp>
#include <boost/simd/function/simd/tand.hpp>

#endif
