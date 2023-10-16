#pragma once

#include <SFML/Graphics.hpp>
#include "ComponentBase.hpp"

class GraphicsComponent: public ComponentBase, public sf::Drawable{
  public:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    int oof = -123;

    GraphicsComponent(){
      if (image.loadFromFile("/home/alba/projects/pnpbuilder/Fireball.png")){
        texture.loadFromImage(image);
        sprite.setTexture(texture);
      }
      std::cout << "teststset" << oof << this << std::endl;
    }

    void doooo() const {std::cout << "soooooo" << std::endl;}
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
      target.draw(sprite, states);
    }
};