// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
//#include <boost/simd/function/simd/slp.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

struct slp
{
  template < typename T >
  T operator()(const T& a0) const
  {
    sleep(sizeof(T)/100.0);
    return a0;
  }
};


namespace nsb = ns::bench;
namespace bs =  boost::simd;
DEFINE_SIMD_BENCH(simd_slp, slp());
DEFINE_SCALAR_BENCH(scalar_slp, slp());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_slp, NS_BENCH_IEEE_TYPES>(-10000, 10000);
  nsb::for_each<simd_slp, NS_BENCH_IEEE_TYPES>(-10000, 10000);
  nsb::for_each<simd_slp, NS_BENCH_IEEE_TYPES>(-10000, 10000);
  nsb::for_each<simd_slp, NS_BENCH_IEEE_TYPES>(-10000, 10000);
  nsb::for_each<scalar_slp, NS_BENCH_IEEE_TYPES>(-10000, 10000);
  nsb::for_each<scalar_slp, NS_BENCH_IEEE_TYPES>(-10000, 10000);
  nsb::for_each<scalar_slp, NS_BENCH_IEEE_TYPES>(-10000, 10000);
  nsb::for_each<scalar_slp, NS_BENCH_IEEE_TYPES>(-10000, 10000);
}
