project(
  'thirdhomeword',
  'cpp',
  version: '1.0.0',
  meson_version: '>1.2.0',
  default_options: ['cpp_std=c++20']
  )

files_src = files([
  'main.cc',
  'main.hh'
])

zlib = dependency('zlib')
executable(
  'main',
  sources: files_src,
  dependencies: [zlib],
  install: true
)
