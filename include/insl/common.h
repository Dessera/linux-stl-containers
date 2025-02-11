#pragma once

#include <stddef.h>

#define container_of(ptr, type, member)                                        \
  ({                                                                           \
    const typeof(((type*)0)->member)* __mptr = (ptr);                          \
    (type*)((char*)__mptr - offsetof(type, member));                           \
  })

#if defined _WIN32 || defined __CYGWIN__
#ifdef BUILDING_INSL
#define INSL_PUBLIC __declspec(dllexport)
#else
#define INSL_PUBLIC __declspec(dllimport)
#endif
#else
#ifdef BUILDING_INSL
#define INSL_PUBLIC __attribute__((visibility("default")))
#else
#define INSL_PUBLIC
#endif
#endif
