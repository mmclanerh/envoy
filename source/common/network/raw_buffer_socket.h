#pragma once

#include "envoy/buffer/buffer.h"
#include "envoy/network/transport_socket.h"

#include "common/common/logger.h"

namespace Envoy {
namespace Network {

class RawBufferSocket : public TransportSocket, protected Logger::Loggable<Logger::Id::connection> {
public:
  // Network::TransportSocket
  void setTransportSocketCallbacks(TransportSocketCallbacks& callbacks) override;
  std::string protocol() const override;
  bool canFlushClose() override { return true; }
  void closeSocket(Network::ConnectionEvent) override {}
  void onConnected() override;
  IoResult doRead(Buffer::Instance& buffer) override;
  IoResult doWrite(Buffer::Instance& buffer) override;

private:
  TransportSocketCallbacks* callbacks_{};
};

} // namespace Network
} // namespace Envoy
