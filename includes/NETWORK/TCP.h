#include <cstdint>

namespace network{


class TCP{
    public:
    TCP();
    ~TCP(){};

    bool startServer(uint16_t port);
    bool acceptConnection();
    bool sendData(const std::string& data);
    std::string receiveData(); 

    void closeConnection();
    void stopServer();

    
    int serverSocket_;
    int clientSocket_;


}; // tcp class
}// namespace network