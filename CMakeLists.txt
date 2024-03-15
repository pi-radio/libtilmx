cmake_minimum_required (VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++20 -g")

include_directories(./include)

project(libtilmx VERSION 0.1.0 DESCRIPTION "TI LMXxxxx programming library")
set(LIBTILMX_SOURCES src/lmx2594.cxx src/lmx2594_config.cxx)

set(LIBTILMX_HEADERS
  include/piradio/lmx2594.hpp
  include/piradio/lmx2594_config.hpp
  include/piradio/lmx2595_config.hpp
  include/piradio/lmx2820_config.hpp
  )

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(tilmx STATIC ${LIBTILMX_SOURCES})

set_target_properties(tilmx PROPERTIES PUBLIC_HEADER "${LIBTILMX_HEADERS}")

install(TARGETS tilmx PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/piradio/ COMPONENT LIBTILMX)

add_executable(test-tilmx src/test-tilmx.cxx)
target_link_libraries(test-tilmx tilmx piradio)

set(CPACK_SET_DESTDIR true)
set(CPACK_INSTALL_PREFIX /)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME "piradio")
set(CPACK_PACKAGE_VENDOR "Pi Radio Inc.")
set(CPACK_PACKAGE_CONTACT "Michael Zappe <zapman@pi-rad.io>")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Michael Zappe <zapman@pi-rad.io>")
set(CPACK_DEBIAN_PACKAGE_VERSION 0.1.2)
set(CPACK_DEBIAN_PACKAGE_RELEASE 7)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "piradio-libpiradio")
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/deb/postinst")
set(CPACK_COMPONENTS_GROUPING ONE_PER_GROUP)
set(CPACK_DEB_PACKAGE_COMPONENT ON)
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")
set(CPACK_DEBIAN_ENABLE_COMPONENT_DEPENDS ON)
set(CPACK_DEBIAN_DEBUGINFO_PACKAGE ON)

set(CPACK_DEBIAN_PACKAGE_DEBUG ON)
  
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Global Pi Radio Description")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Global Pi Radio Description Summary")

set(CPACK_COMPONENTS_ALL LIBTILMX)

set(CPACK_COMPONENT_LIBTILMX_DISPLAY_NAME "piradio-libtilmx")
set(CPACK_COMPONENT_LIBTILMX_DESCRIPTION "Base ultility library for Pi Radio software")

include(CPack)


