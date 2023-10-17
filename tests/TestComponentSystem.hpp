#include <QTest>

class TestComponentSystem : public QObject {
  Q_OBJECT
private slots:
  void doStuff() { QVERIFY(1 == 2); }
};
