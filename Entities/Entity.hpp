#include <SFML/Graphics.hpp>
#include "../Components/ComponentAcceptor.hpp"

class Entity: public ComponentAcceptor {
  public:
    Entity(const std::string &name):name{name}{}

    void setName(const std::string& name){Entity::name = name;}
    const std::string& getName(){return name;}

  
  private:
    std::string name;
};