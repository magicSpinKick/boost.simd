//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_AUXV_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_AUXV_HPP_INCLUDED

#include <boost/predef/os.hpp>

#if BOOST_OS_LINUX
#include <linux/auxvec.h>
#include <fcntl.h>
#include <unistd.h>
#include <boost/cstdint.hpp>

namespace boost { namespace simd { namespace detail
{
  inline std::uintptr_t auxv(std::uintptr_t type)
  {
    int fd;
    uintptr_t auxv[2];

    fd = open("/proc/self/auxv", O_RDONLY);
    if (fd >= 0)
    {
      while(read(fd, &auxv, sizeof(auxv)) == sizeof(auxv))
      {
        if (auxv[0] == type)
        {
          close(fd);
          return auxv[1];
        }
      }
      close(fd);
    }
    return 0;
  }

  inline unsigned int hwcap() { return auxv(AT_HWCAP); }
} } }

#endif

#endif
