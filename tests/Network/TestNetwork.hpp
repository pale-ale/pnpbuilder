#include "../../3rdparty/zpp_bits.h"
#include "../../src/Network/PnPClient.hpp"
#include "../../src/Network/PnPServer.hpp"
#include <QTest>
#include <string>

class TestNetwork : public QObject {
  Q_OBJECT
private slots:
  void testConnection() {
    const char *clientToServerMsg = "c->s12äüABC";
    const char *serverToClientMsg = "s->c12äüABC";
    const char *hostAddress = "127.0.0.1";
    const qint16 port(12345);

    bool clientConnected = false;
    bool serverConnected = false;
    bool clientMsgReceived = false;
    bool serverMsgReceived = false;

    PnPServer server;
    PnPPClient client;
    QTcpSocket *serverSocket = nullptr;
    server.setParent(this);
    client.setParent(this);

    server.listen(QHostAddress(hostAddress), port);
    server.connect(&server, &PnPServer::newConnection, [&]() {
      serverConnected = true;
      serverSocket = server.nextPendingConnection();
    });
    client.joinSession(hostAddress, port, [&]() { clientConnected = true; });
    server.waitForNewConnection(100);
    client.socket->waitForConnected(100);

    client.connect(client.socket, &QTcpSocket::readyRead, [&]() {
      clientMsgReceived = client.socket->readAll() == serverToClientMsg;
    });
    serverSocket->connect(serverSocket, &QTcpSocket::readyRead, [&]() {
      serverMsgReceived = serverSocket->readAll() == clientToServerMsg;
    });
    serverSocket->write(serverToClientMsg);
    serverSocket->flush();
    client.send(clientToServerMsg);

    client.socket->waitForReadyRead(100);
    serverSocket->waitForReadyRead(100);
    QVERIFY(clientConnected);
    QVERIFY(serverConnected);
    QVERIFY(clientMsgReceived);
    QVERIFY(serverMsgReceived);
  }
};
