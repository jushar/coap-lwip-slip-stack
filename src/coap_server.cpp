#include "cis_stack/coap_server.hpp"

namespace cis_stack {

CoapServer::CoapServer(ISerialPort& serial_port) : serial_port_{serial_port} {}

}  // namespace cis_stack
