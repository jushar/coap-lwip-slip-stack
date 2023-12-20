#include "cis_stack/ip_stack.hpp"
#include "cis_stack/slip_net_if.hpp"

#include <thread>

using namespace std::string_view_literals;

class DummySerialPort : public cis_stack::ISerialPort {};

int main() {
  cis_stack::IpStack ip_stack{};

  DummySerialPort serial_port{};
  cis_stack::SlipNetIf slip_net_if{serial_port, "192.0.2.0"sv,
                                   "255.255.255.252"sv, "0.0.0.0"sv};
  ip_stack.AddNetIf(slip_net_if);

  for (;;) {
    ip_stack.Update();

    std::this_thread::sleep_for(std::chrono::milliseconds{10});
  }
}