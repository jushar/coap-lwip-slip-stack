set(LWIP_DIR "3rd_party/lwip" CACHE STRING "")
set(LWIP_CONTRIB_DIR "${LWIP_DIR}/contrib" CACHE STRING "")
set(LWIP_INCLUDE_DIRS
    "${LWIP_DIR}/src/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/lwip_config"
    "${LWIP_DIR}/contrib/ports/unix/port/include"
    CACHE STRING "")

set(LWIP_EXCLUDE_SLIPIF FALSE CACHE BOOL "")

include("3rd_party/lwip/src/Filelists.cmake")
include("3rd_party/lwip/contrib/ports/unix/Filelists.cmake")

add_library(lwip INTERFACE)
target_include_directories(lwip INTERFACE ${LWIP_INCLUDE_DIRS})
target_link_libraries(lwip INTERFACE lwipcore lwipcontribportunix)
