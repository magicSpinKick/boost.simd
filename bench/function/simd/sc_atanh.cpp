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
namespace bs = boost::simd;
#define LIST float
//#define LIST double
//#define LIST NS_BENCH_IEEE_TYPES
DEFINE_SCALAR_BENCH(scalar_atanh, bs::atanh);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_atanh, LIST>(0.5,10.0);
  nsb::for_each<scalar_atanh, LIST>(0.5,10.0);
  nsb::for_each<scalar_atanh, LIST>(0.5,10.0);
  nsb::for_each<scalar_atanh, LIST>(0.5,10.0);

}
