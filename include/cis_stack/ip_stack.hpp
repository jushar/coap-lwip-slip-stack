#pragma once

#include <functional>
#include <vector>

#include "cis_stack/inet_if.h"

namespace cis_stack {

class IpStack final {
 public:
  IpStack();

  void AddNetIf(INetIf& net_if);

  void Update();

 private:
  std::vector<std::reference_wrapper<INetIf>> net_ifs_{};
};

}