#pragma once

#include "cis_stack/iserial_port.hpp"

namespace cis_stack {

class CoapServer final {
 public:
  explicit CoapServer(ISerialPort& serial_port);

 private:
  ISerialPort& serial_port_;
};

}  // namespace cis_stack
