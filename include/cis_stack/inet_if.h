#pragma once

namespace cis_stack {

class INetIf {
 public:
  virtual ~INetIf() = default;

  virtual void Update() = 0;
};

}