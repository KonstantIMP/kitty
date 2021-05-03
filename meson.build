project('kitty', ['cpp'])

source_root = meson.source_root()
sources_dir = include_directories('source/')

kitty_sources = [
    'source/main.cpp',
    'source/kitty.cpp',
    'source/password_generator.cpp'
]

kitty_bin = executable('kitty',
    [kitty_sources], include_directories : [sources_dir]
)
