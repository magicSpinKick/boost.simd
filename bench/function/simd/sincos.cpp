// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/sincos.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
DEFINE_SIMD_BENCH(simd_sincos, bs::sincos);
DEFINE_SCALAR_BENCH(scalar_sincos, bs::sincos);
DEFINE_SCALAR_BENCH(scalar_rsincos, bs::restricted_(bs::sincos));
DEFINE_SIMD_BENCH(simd_rsincos, bs::restricted_(bs::sincos));


int main(int argc, char** argv) {
  nsb::parse_args(argc, argv);
  nsb::for_each<simd_sincos, NS_BENCH_IEEE_TYPES>(-60, 60);
  nsb::for_each<scalar_sincos, NS_BENCH_IEEE_TYPES>(-60, 60);
  nsb::for_each<simd_sincos, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  nsb::for_each<scalar_sincos, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  nsb::for_each<simd_rsincos, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  nsb::for_each<scalar_rsincos, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  print_results();
  return 0;
}
