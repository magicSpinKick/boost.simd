//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/acos.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/std.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = i%2 ?T(i)/N : -T(i)/N ;
    b[i] = bs::acos(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::acos(aa1), bb, 0.5);
}

STF_CASE_TPL("Check acos on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
  std::cout <<  std::setprecision(20) << bs::ldexp(13176796.0f, -23) << std::endl;
  std::cout <<  bs::ldexp(-11464520.0f, -46) << std::endl;
  std::cout <<  std::setprecision(20) << bs::ldexp(7074237752028440.0, -52) << std::endl;
  std::cout <<  bs::ldexp(4967757600021504.0, -106) << std::endl;

}

// 13176796 2^-23   7074237752028440 2^-52

// -11464520 2^-46 4967757600021504 2^-106
