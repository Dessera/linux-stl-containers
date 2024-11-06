project(
  'linux-stl-containers',
  'c',
  version: '0.1',
  default_options: ['warning_level=3', 'c_std=gnu11'],
)

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_LINUX_STL_CONTAINERS']

linux_stl_containers_inc = include_directories('include')
linux_stl_containers_src = ['src/list_head.c']
linux_stl_containers = shared_library(
  'linux_stl_containers',
  sources: linux_stl_containers_src,
  install: true,
  c_args: lib_args,
  gnu_symbol_visibility: 'hidden',
  include_directories: linux_stl_containers_inc,
)

# Make this library usable as a Meson subproject.
linux_stl_containers_dep = declare_dependency(
  include_directories: linux_stl_containers_inc,
  link_with: linux_stl_containers,
)

# Make this library usable from the system's
# package manager.
install_subdir(
  'include',
  install_dir: 'include/linux_stl_containers',
  strip_directory: true,
)

subdir('tests')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name: 'linux-stl-containers',
  filebase: 'linux_stl_containers',
  description: 'Implementation of stl containers from linux-2.6.24',
  subdirs: 'linux_stl_containers',
  libraries: linux_stl_containers,
  version: '0.1',
)