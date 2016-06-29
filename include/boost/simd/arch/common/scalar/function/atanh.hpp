//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATANH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATANH_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/bitofsign.hpp>
#include <boost/simd/function/scalar/bitwise_xor.hpp>
#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/function/scalar/log1p.hpp>
#include <boost/simd/function/scalar/oneminus.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/function/scalar/dec.hpp>
#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/fast.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( atanh_
                          , (typename A0)
                             , bd::cpu_
                            , bd::scalar_< bd::floating_<A0> >
                            )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0) const BOOST_NOEXCEPT
    {
      A0 absa0 = bs::abs(a0);
      A0 t =  absa0+absa0;
      A0 z1 = oneminus(absa0);
      return bitwise_xor(bitofsign(a0),
                         Half<A0>()*bs::log1p((absa0 < Half<A0>())
                                              ? fma(t, absa0/z1, t)
                                              : t/z1)
                        );
    }
  };
  BOOST_DISPATCH_OVERLOAD ( atanh_
                          , (typename A0)
                          , bd::cpu_
                          , bs::std_tag
                          , bd::scalar_< bd::floating_<A0> >
                         )
  {
    BOOST_FORCEINLINE A0 operator() (const std_tag &,  A0  a0) const BOOST_NOEXCEPT
    {
      return std::atanh(a0);
    }
  };


   BOOST_DISPATCH_OVERLOAD( atanh_
                          , (typename A0)
                          , bd::cpu_
                          , bs::fast_tag
                          , bd::scalar_<bd::floating_<A0>>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(const fast_tag&, A0 a0) const BOOST_NOEXCEPT
      {
        A0 absa0 = bs::abs(a0);
        return bitwise_xor(bitofsign(a0), Half<A0>()*bs::log1p((absa0+absa0)/oneminus(absa0)));
      }
   };

} } }


#endif
