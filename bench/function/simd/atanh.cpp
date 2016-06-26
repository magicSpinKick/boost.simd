// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/atanh.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
DEFINE_SIMD_BENCH(simd_atanh, boost::simd::atanh);
DEFINE_SCALAR_BENCH(scalar_atanh, boost::simd::atanh);
DEFINE_SCALAR_BENCH(std_atanh, bs::std_(boost::simd::atanh));
DEFINE_SIMD_BENCH(fast_simd_atanh, bs::fast_(boost::simd::atanh));
DEFINE_SCALAR_BENCH(fast_scalar_atanh, bs::fast_(boost::simd::atanh));


int main(int argc, char** argv) {
  nsb::parse_args(argc, argv);
  nsb::for_each<simd_atanh, NS_BENCH_IEEE_TYPES>(-1, 1);
  nsb::for_each<scalar_atanh, NS_BENCH_IEEE_TYPES>(-1, 1);
  nsb::for_each<std_atanh, NS_BENCH_IEEE_TYPES>(-1, 1);
  nsb::for_each<fast_simd_atanh, NS_BENCH_IEEE_TYPES>(-1, 1);
  nsb::for_each<fast_scalar_atanh, NS_BENCH_IEEE_TYPES>(-1, 1);
  print_results();
  return 0;
}
