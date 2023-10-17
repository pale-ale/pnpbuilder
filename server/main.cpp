#include "../src/Entities/World.hpp"
#include "../src/Widgets/GameDisplayWidget.hpp"
#include <QApplication>
#include <QPushButton>
#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char **argv) {
  World world;
  QApplication app(argc, argv);
  QWidget container;
  QPushButton button("Test", &container);
  SFMLWidget gameDisplayWidget(&container, &world);

  gameDisplayWidget.setView(sf::View({0, 0, 600, 600}));
  gameDisplayWidget.setSize({100, 50});

  container.show();
  return app.exec();
}