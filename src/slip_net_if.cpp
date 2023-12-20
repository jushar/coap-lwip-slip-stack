#include "cis_stack/slip_net_if.hpp"

#include <lwip/ip.h>
#include <netif/slipif.h>

namespace cis_stack {

SlipNetIf::SlipNetIf(ISerialPort& serial_port, std::string_view const& ip_addr,
                     std::string_view const& netmask,
                     std::string_view const& gateway_addr)
    : serial_port_{serial_port} {
  netif_add(&lwip_netif_, IP4_ADDR_ANY, IP4_ADDR_ANY, IP4_ADDR_ANY, nullptr,
            &slipif_init, &ip_input);

  lwip_netif_.name[0] = 'e';
  lwip_netif_.name[1] = '0';
  netif_set_default(&lwip_netif_);  // TODO
  netif_set_up(&lwip_netif_);
}

void SlipNetIf::Update() {
  slipif_poll(&lwip_netif_);
}

}  // namespace cis_stack
