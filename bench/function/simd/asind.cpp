// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/asind.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
DEFINE_SIMD_BENCH(simd_asind, boost::simd::asind);
DEFINE_SCALAR_BENCH(scalar_asind, boost::simd::asind);
DEFINE_SCALAR_BENCH(std_scalar_asind, bs::std_(boost::simd::asind));

int main(int argc, char** argv) {
  nsb::parse_args(argc, argv);
  nsb::for_each<simd_asind, NS_BENCH_IEEE_TYPES>(-1, 1);
  nsb::for_each<scalar_asind, NS_BENCH_IEEE_TYPES>(-1, 1);
  nsb::for_each<std_scalar_asind, NS_BENCH_IEEE_TYPES>(-1, 1);
  print_results();
  return 0;
}
