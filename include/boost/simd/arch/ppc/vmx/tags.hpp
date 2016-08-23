//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_TAGS_HPP_INCLUDED

#include <boost/simd/arch/common/tags.hpp>

#if BOOST_OS_LINUX
#include <boost/simd/sdk/config/details/detector/linux_auxv.hpp>
#include <asm/cputable.h>
#elif BOOST_OS_MACOS
#include <Gestalt.h>
#endif

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief PowerPC VMX SIMD architecture hierarchy tag

    This tag represent architectures implementing the VMX SIMD instructions set.
  **/
  struct vmx_ : simd_
  {
    using parent = simd_;

    vmx_() : support(detect()) {}

    bool is_supported() const { return support; }

    static bool detect()
    {
      #if BOOST_ARCH_PPC
        #if BOOST_OS_LINUX
          return detail::hwcap() & PPC_FEATURE_HAS_ALTIVEC;
        #elif BOOST_OS_MACOS
          long cpuAttributes;
          bool hasAltiVec = false;
          OSErr err = Gestalt( gestaltPowerPCProcessorFeatures, &cpuAttributes );
          if( noErr == err )
          {
            hasAltiVec = ( 1 << gestaltPowerPCHasVectorInstructions) & cpuAttributes;
          }
          return hasAltiVec;
        #else
          return false;
        #endif
      #else
        return false;
      #endif
    }

    private:
    bool support;
  };

  /*!
    @ingroup  group-api
    Global object for accessing VMX support informations
  **/
  static vmx_ const vmx = {};
} }

#endif
