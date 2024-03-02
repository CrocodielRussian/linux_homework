project(
    'myproject',                   
    'cpp',                          
    version: '0.1.0',                
    meson_version: '>=0.50',          
    default_options: ['cpp_std=c++20'] 
)

myproject_src = files([
    'main.cc' # список исходных файлов
])
zlib = dependency('zlib')

#Для библиотеки
myproject_lib = library(
    'myproject',              # название исполняемого файла
    include_directories: [],
    sources: myproject_src,   # список исходный файлов
    dependencies: [zlib],         # зависимости проекта (если имеются)
    install: true             # устанавливать ли файл
)
#Для файла
#executable(
#    'myproject',              # название исполняемого файла
#    include_directories: [], # где ищутся заголовочные файлы
#    sources: myproject_src,   # список исходный файлов
#    dependencies: [zlib],         # зависимости проекта (если имеются)
#    install: true             # устанавливать ли файл
#)
pkgconfig = import('pkgconfig')
pkgconfig.generate(
  myproject_lib,
  version: meson.project_version(),
  name: 'namelib',
  description: 'My lib',
  )
