cmake_minimum_required(VERSION 3.21)
project(coap-lwip-slip-stack)

include("3rd_party/libcoap.cmake")
include("3rd_party/lwip.cmake")

add_library(cis_stack
	"src/coap_server.cpp"
	"src/ip_stack.cpp"
	"src/slip_net_if.cpp"
)
target_include_directories(cis_stack PUBLIC "include")
target_link_libraries(cis_stack PUBLIC lwip)

add_subdirectory("examples")
