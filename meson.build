project(
  'insl',
  'c',
  version: '0.1',
  default_options: ['warning_level=3', 'c_std=gnu23'],
)

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_INSL']

insl_inc = include_directories('include')
insl_src = ['src/list_head.c', 'src/hlist_head.c']
insl_shared = shared_library(
  'insl',
  sources: insl_src,
  install: true,
  c_args: lib_args,
  gnu_symbol_visibility: 'hidden',
  include_directories: insl_inc,
)

insl_dep = declare_dependency(
  include_directories: insl_inc,
  link_with: insl_shared,
)

install_subdir('include/insl', install_dir: 'include')

subdir('tests')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name: 'insl',
  filebase: 'insl',
  description: 'Some data structures implemented out of kernel tree',
  subdirs: 'insl',
  libraries: insl_shared,
  version: '0.1',
)