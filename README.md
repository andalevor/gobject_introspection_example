# gobject_introspection_example

Example how to create a gobject class and use it in python with help of gobject introspection.

To build example with make run:
*  make
*  LD_LIBRARY_PATH=\`pwd\`:$LD_LIBRARY_PATH GI_TYPELIB_PATH=\`pwd\` python3

To build example with meson run:
*  meson build
*  ninja -C build
*  LD_LIBRARY_PATH=\`pwd\`/build:$LD_LIBRARY_PATH GI_TYPELIB_PATH=\`pwd\`/build python3

In python:
*  import gi
*  gi.require_version('Girtest', '0.1')
*  from gi.repository import Girtest
*  test = Girtest.Object(name = "Python")
*  test.greet()