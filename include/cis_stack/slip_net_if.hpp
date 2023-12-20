#pragma once

#include <cstddef>
#include <string_view>

#include "../../3rd_party/lwip/src/include/lwip/netif.h" // TODO
#include "cis_stack/inet_if.h"
#include "cis_stack/iserial_port.hpp"

namespace cis_stack {

class SlipNetIf final : public INetIf {
 public:
  SlipNetIf(ISerialPort& serial_port, std::string_view const& ip_addr,
            std::string_view const& netmask,
            std::string_view const& gateway_addr);

  void Update() override;

 private:
  ISerialPort& serial_port_;

  netif lwip_netif_{};
};

}  // namespace cis_stack