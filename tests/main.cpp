#include "TestComponentSystem.hpp"
#include <QTest>

int main(int argc, char *argv[]) {
  auto runTest = [&argc, &argv](QObject *test) {
    return QTest::qExec(test, argc, argv);
  };

  int status = 0;
  status |= runTest(new TestComponentSystem);

  return status;
}