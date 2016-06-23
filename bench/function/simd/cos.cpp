// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/cos.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
DEFINE_SIMD_BENCH(simd_cos, bs::cos);
DEFINE_SCALAR_BENCH(scalar_cos, bs::cos);
DEFINE_SCALAR_BENCH(scalar_std_cos, bs::std_(bs::cos));
DEFINE_SCALAR_BENCH(scalar_rcos, bs::restricted_(bs::cos));
DEFINE_SIMD_BENCH(simd_rcos, bs::restricted_(bs::cos));


struct cos1
{
  template <typename T>
  T operator()(const T & x) const
  {
     return std::cos(x);
   }
};
DEFINE_SCALAR_BENCH(scalar_std_cos1, cos1( ));



int main(int argc, char** argv) {
  nsb::parse_args(argc, argv);
  nsb::for_each<simd_cos, NS_BENCH_IEEE_TYPES>(-60, 60);
  nsb::for_each<scalar_cos, NS_BENCH_IEEE_TYPES>(-60, 60);
  nsb::for_each<scalar_std_cos, NS_BENCH_IEEE_TYPES>(-60, 60);
  nsb::for_each<scalar_std_cos1, NS_BENCH_IEEE_TYPES>(-60, 60);
  nsb::for_each<simd_cos, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  nsb::for_each<scalar_cos, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  nsb::for_each<scalar_std_cos, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  nsb::for_each<scalar_std_cos1, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  nsb::for_each<simd_rcos, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  nsb::for_each<scalar_rcos, NS_BENCH_IEEE_TYPES>(-bs::Pio_4<double>(), bs::Pio_4<double>());
  print_results();
  return 0;

}
