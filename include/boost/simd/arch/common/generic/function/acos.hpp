//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ACOS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ACOS_HPP_INCLUDED

#include <boost/simd/function/fast.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_2lo.hpp>
#include <boost/simd/function/simd/asin.hpp>
#include <boost/simd/arch/common/detail/generic/invtrig.hpp>
#include <boost/simd/meta/is_not_scalar.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( acos_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {

    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return detail::invtrig_base<A0,tag::radian_tag,is_not_scalar_t<A0>>::acos(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( acos_
                          , (typename A0)
                          , bd::cpu_
                          , bs::fast_tag
                          , bd::generic_< bd::floating_<A0> >
                          )
  {

    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 z = Pio_2<A0>()-bs::asin(a0);
      return z+Real<A0, 0x3c91a62633145c00ull, 0xb42eef48ul>(); //Pio_2lo<A0>();
    }
  };
} } }


#endif
