/*
  Copyright 1999-2020 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.  You may
  obtain a copy of the License at
  
    https://imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  MagickCore random methods.
*/
#ifndef MAGICKCORE_RANDOM__H
#define MAGICKCORE_RANDOM__H

#include "MagickCore/string_.h"

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

/*
  Typedef declarations.
*/
typedef struct _RandomInfo
  RandomInfo;

/*
  Method declarations.
*/
extern MagickExport double
  GetRandomValue(RandomInfo *),
  GetPseudoRandomValue(RandomInfo *magick_restrict);

extern MagickExport RandomInfo
  *AcquireRandomInfo(void),
  *DestroyRandomInfo(RandomInfo *);

extern MagickExport StringInfo
  *GetRandomKey(RandomInfo *,const size_t);

extern MagickExport unsigned long
  GetRandomSecretKey(const RandomInfo *);

extern MagickExport void
  SetRandomKey(RandomInfo *,const size_t,unsigned char *),
  SetRandomSecretKey(const unsigned long),
  SetRandomTrueRandom(const MagickBooleanType);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
