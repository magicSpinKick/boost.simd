//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ULP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ULP_HPP_INCLUDED

#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/simd/function/scalar/is_eqz.hpp>
#include <boost/simd/function/scalar/is_invalid.hpp>
#include <boost/simd/function/scalar/min.hpp>
#include <boost/simd/function/scalar/prev.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
 BOOST_DISPATCH_OVERLOAD ( ulp_
                         , (typename A0)
                         , bd::cpu_
                         , bd::scalar_< bd::arithmetic_<A0> >
                         )
 {
   BOOST_FORCEINLINE A0 operator() ( A0 const &) const BOOST_NOEXCEPT
   {
     return One<A0>();
   }
 };

  BOOST_DISPATCH_OVERLOAD ( ulp_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      using i_t = bd::as_integer_t<A0,unsigned>;
      if (is_eqz(a0)) return Mindenormal<A0>();
      if (is_invalid(a0)) return Nan<A0>();
      const A0 x = boost::simd::abs(a0);
      i_t aa = bitwise_cast<i_t>(x);
      i_t bb = aa;
      --bb;
      ++aa;
      return boost::simd::min(x-bitwise_cast<A0>(bb), bitwise_cast<A0>(aa)-x);
    }
  };
} } }


#endif
