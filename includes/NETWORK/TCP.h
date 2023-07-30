#include <cstdint>
#include "Packet.h"

namespace network{

#define TCP_PKT_SIZE 4096

class TCP{
    public:
    TCP();
    ~TCP(){};

    bool startServer(uint16_t port);
    bool acceptConnection();
    bool sendPacket(const std::shared_ptr<Packet>);
    std::shared_ptr<Packet> receivePacket(); 

    void closeConnection();
    void stopServer();

    
    int serverSocket_;
    int clientSocket_;


}; // tcp class
}// namespace network