#include "cis_stack/ip_stack.hpp"

#include <lwip/init.h>

namespace cis_stack {

IpStack::IpStack() {
  lwip_init();
}

void IpStack::AddNetIf(cis_stack::INetIf& net_if) {
  net_ifs_.emplace_back(net_if);
}

void IpStack::Update() {
  for (auto& net_if : net_ifs_) {
    net_if.get().Update();
  }
}

}