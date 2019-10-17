project('gobject_introspection_example', 'c')

sources = ['src/girtest_object.c']
headers = ['src/girtest_object.h']

gir_dep = dependency('gobject-introspection-1.0')

libgirtest = library(
  'girtest',
  sources : sources,
  version : '0.1',
  install : true,
  dependencies : gir_dep
)

gnome = import('gnome')
gnome.generate_gir(libgirtest,
  sources : sources + headers,
  nsversion : '0.1',
  namespace : 'Girtest',
  symbol_prefix : 'girtest_',
  identifier_prefix : 'Girtest',
  export_packages : 'girtest',
  includes : ['GObject-2.0'],
  install : true
)