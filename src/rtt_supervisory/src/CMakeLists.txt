#
# Components, types and plugins.
#
# The CMake 'target' names are identical to the first argument of the
# macros below, except for orocos_typegen_headers, where the target is fully
# controlled by generated code of 'typegen'.
#

# Creates a component library librtt_supervisory-<target>.so
# and installs in the directory lib/orocos/rtt_supervisory/
#
# -------------------------------------------
# orocos_component(rtt_supervisory rtt_supervisory-component.hpp rtt_supervisory-component.cpp) # ...you may add multiple source files
# -------------------------------------------
#
# You may add multiple orocos_component statements.

#
# Additional headers:
#
# Installs in the include/orocos/rtt_supervisory/ directory
#
# -------------------------------------------
# orocos_install_headers(rtt_supervisory-component.hpp) # ...you may add multiple header files
# -------------------------------------------
#
# You may add multiple orocos_install_headers statements.

#
# Building a Plugin
#
# Creates a plugin library librtt_supervisory-plugin-<target>.so
# and installs in the directory lib/orocos/rtt_supervisory/plugins/
#
# Be aware that a plugin may only have the loadRTTPlugin() function once defined in a .cpp file.
# This function is defined by the plugin and service CPP macros.
#
# -------------------------------------------
# orocos_plugin(rtt_supervisory-plugin rtt_supervisory-plugin.cpp) # ...only one plugin function per library !
# -------------------------------------------
#
# You may add multiple orocos_plugin statements.


#
# Building a Service:
#
# Creates a plugin library librtt_supervisory-service-<target>.so
# and installs in the directory lib/orocos/rtt_supervisory/plugins/
#
# -------------------------------------------
# orocos_service(rtt_supervisory-service rtt_supervisory-service.cpp) # ...only one service per library !
# -------------------------------------------
#
# You may add multiple orocos_service statements.


#
# Building a normal library (optional):
#
# Creates a library librtt_supervisory-support-<target>.so and installs it in
# lib/
#
# -------------------------------------------
# orocos_library(rtt_supervisory-support support.cpp) # ...you may add multiple source files
# -------------------------------------------
#
# You may add multiple orocos_library statements.


