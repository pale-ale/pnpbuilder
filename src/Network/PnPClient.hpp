#pragma once

#include <QtNetwork>
#include <functional>

class PnPPClient : public QObject {
public:
  QTcpSocket *socket = nullptr;
  PnPPClient() : socket{new QTcpSocket(this)} {}

  void joinSession(const char *hostname, qint16 port,
                   std::function<void()> func = nullptr) {
    socket->connect(socket, &QTcpSocket::connected, func);
    socket->connectToHost(hostname, port);
  }

  void send(const char *msg) {
    socket->write(msg);
    socket->flush();
  }
};