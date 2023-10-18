#pragma once
#include "ComponentBase.hpp"
#include <algorithm>
#include <vector>

class ComponentAcceptor {
public:
  void addComponent(ComponentBase *component) {
    components.push_back(component);
  }

  template <typename ComponentType>
  const ComponentType *getComponentOfType() const {
    for (auto &&component : components) {
      auto *p = dynamic_cast<const ComponentType *>(component);
      if (p != nullptr) {
        return p;
      }
    }
    return nullptr;
  }

  std::vector<ComponentBase *> components = {};

protected:
};