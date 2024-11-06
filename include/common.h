#pragma once

#define container_of(ptr, type, member)                                        \
  ({                                                                           \
    const typeof(((type*)0)->member)* __mptr = (ptr);                          \
    (type*)((char*)__mptr - offsetof(type, member));                           \
  })

#if defined _WIN32 || defined __CYGWIN__
#ifdef BUILDING_LINUX_STL_CONTAINERS
#define LINUX_STL_CONTAINERS_PUBLIC __declspec(dllexport)
#else
#define LINUX_STL_CONTAINERS_PUBLIC __declspec(dllimport)
#endif
#else
#ifdef BUILDING_LINUX_STL_CONTAINERS
#define LINUX_STL_CONTAINERS_PUBLIC __attribute__((visibility("default")))
#else
#define LINUX_STL_CONTAINERS_PUBLIC
#endif
#endif
