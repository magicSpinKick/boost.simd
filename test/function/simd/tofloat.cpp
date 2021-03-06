//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, int N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;
  using fT = bd::as_floating_t<T>;
  using f_t =bs::pack<fT, N>;

  T a1[N];
  fT b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::tofloat(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  f_t bb (&b[0], &b[0]+N);

  STF_IEEE_EQUAL(bs::tofloat(aa1), bb);
}

STF_CASE_TPL("Check tofloat on pack" , (std::uint32_t)(std::uint64_t)(std::int32_t)(std::int64_t))
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
