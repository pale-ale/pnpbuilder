#include "../src/Components/GraphicsComponent.hpp"
#include "../src/Entities/Entity.hpp"
#include <QTest>

class TestComponentSystem : public QObject {
  Q_OBJECT
private slots:
  void testComponentCreation() {
    Entity *entity = new Entity("testEntity");
    auto componentCount = [entity]() { return entity->components.size(); };
    QVERIFY(componentCount() == 0);

    entity->addComponent(new ComponentBase());
    QVERIFY(componentCount() == 1);

    entity->addComponent(new GraphicsComponent());
    QVERIFY(componentCount() == 2);
  }

  void testComponentAccess() {
    Entity *entity = new Entity("abc123");
    {
      auto component = entity->getComponentOfType<ComponentBase>();
      QVERIFY(component == nullptr);
      component = entity->getComponentOfType<GraphicsComponent>();
      QVERIFY(component == nullptr);
    }
    entity->addComponent(new ComponentBase());
    {
      auto component = entity->getComponentOfType<ComponentBase>();
      QVERIFY(component != nullptr);
      component = entity->getComponentOfType<GraphicsComponent>();
      QVERIFY(component == nullptr);
    }
    entity->addComponent(new GraphicsComponent());
    {
      auto component = entity->getComponentOfType<ComponentBase>();
      QVERIFY(component != nullptr);
      component = entity->getComponentOfType<GraphicsComponent>();
      QVERIFY(component != nullptr);
    }
    QVERIFY(typeid(*entity->components[0]) == typeid(ComponentBase));
    QVERIFY(typeid(*entity->components[0]) != typeid(GraphicsComponent));
    QVERIFY(typeid(*entity->components[1]) != typeid(ComponentBase));
    QVERIFY(typeid(*entity->components[1]) == typeid(GraphicsComponent));
  }
};
