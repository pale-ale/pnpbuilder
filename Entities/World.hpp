#pragma once

#include "Entity.hpp"
#include <vector>
#include "Components/ComponentAcceptor.hpp"
#include "Components/GraphicsComponent.hpp"

class World : public sf::Drawable {
  public:
  World(){
    entities = {Entity("SomeEntity")};
    entities[0].addComponent(new GraphicsComponent());
  }

  std::vector<Entity> entities;
  
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
    for (const auto& entity : entities){
      auto* graphicsComponent = entity.getComponentOfType<GraphicsComponent>();
      if (graphicsComponent){
        graphicsComponent->draw(target, states);
      }
    }
  };
};