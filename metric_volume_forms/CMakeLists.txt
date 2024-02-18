# TODO
cmake_minimum_required( VERSION 3.0 )

project( metric_volume_forms )

add_library( metric_volume_forms SHARED 
    schwarchild_spherical.cpp)

target_include_directories( metric_volume_forms PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:.>) 

# Add more metric volume forms as needed
install( TARGETS metric_volume_forms DESTINATION ${CMAKE_INSTALL_LIBDIR} )
install( FILES metric_volume_forms.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )
install( FILES schwarchild_spherical.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )
