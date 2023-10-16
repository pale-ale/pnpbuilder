#pragma once
#include <vector>
#include "ComponentBase.hpp"
#include <algorithm>

class ComponentAcceptor{
  public:
    void addComponent(ComponentBase* component){components.push_back(component);}

    template<typename ComponentType>
    const ComponentType* getComponentOfType() const {
      for (auto&& component : components) {
          auto* p = static_cast<const ComponentType*>(component);
          if (p != nullptr) {
              return p;
          }
      }
      return nullptr;
    }

  std::vector<ComponentBase*> components = {};
  protected:
};