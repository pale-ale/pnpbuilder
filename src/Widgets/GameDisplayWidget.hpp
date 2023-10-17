#pragma once

#include <QWidget>
#include <SFML/Graphics.hpp>
#include <iostream>

class SFMLWidget : public QWidget, public sf::RenderWindow {
public:
  SFMLWidget(QWidget *parent = nullptr, const sf::Drawable *target = nullptr)
      : QWidget(parent), target{target} {
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    sf::Window::create(winId());
  }

  virtual void paintEvent(QPaintEvent *) override {
    if (target) {
      draw(*target);
      display();
    }
  }

  QPaintEngine *paintEngine() const override { return 0; }

  const sf::Drawable *target;
};