#pragma once

#include "ComponentBase.hpp"
#include <SFML/Graphics.hpp>

class GraphicsComponent : public ComponentBase, public sf::Drawable {
public:
  sf::Image image;
  sf::Texture texture;
  sf::Sprite sprite;

  GraphicsComponent() {
    if (image.loadFromFile("./Sprites/Fireball.png")) {
      texture.loadFromImage(image);
      sprite.setTexture(texture);
    }
  }

  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const override {
    target.draw(sprite, states);
  }
};