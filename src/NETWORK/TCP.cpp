#include "../../includes/NETWORK/TCP.h"

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

namespace network{

TCP::TCP(){
    serverSocket_ = 0;
    clientSocket_  = 0;
}; 


bool TCP::startServer(uint16_t port){
        serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket_ == -1) {
            std::cerr << "Error creating socket." << std::endl;
            return false;
        }

        sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = INADDR_ANY;
        serverAddress.sin_port = htons(port);

        if (bind(serverSocket_, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
            std::cerr << "Error binding socket." << std::endl;
            close(serverSocket_);
            return false;
        }

        if (listen(serverSocket_, 1) == -1) {
            std::cerr << "Error listening on socket." << std::endl;
            close(serverSocket_);
            return false;
        }

        std::cout << "Server started on port " << port << std::endl;
        return true;
}

bool TCP::acceptConnection(){
    sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        clientSocket_ = accept(serverSocket_, (struct sockaddr*)&clientAddress, &clientAddressLength);

        if (clientSocket_ == -1) {
            std::cerr << "Error accepting client connection." << std::endl;
            return false;
        }

        char clientIp[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddress.sin_addr), clientIp, INET_ADDRSTRLEN);
        std::cout << "Accepted connection from: " << clientIp << std::endl;
        return true;
}

bool TCP::sendPacket(const std::shared_ptr<Packet> pkt){
     ssize_t bytesSent = send(clientSocket_, pkt->data(), pkt->len(), 0);
        if (bytesSent == -1) {
            std::cerr << "Error sending data." << std::endl;
            return false;
        }
    return true;
}

std::shared_ptr<Packet> TCP::receivePacket(){
    auto pkt = Packet::make_packet(TCP_PKT_SIZE);
    ssize_t bytesRead = recv(clientSocket_, pkt->data(), pkt->len(), 0);
    if (bytesRead <= 0) {
        std::cerr << "Error receiving data." << std::endl;
        return nullptr;
    }
    return pkt;
}

void TCP::closeConnection() {
    close(clientSocket_);
    clientSocket_ = 0;
}

void TCP::stopServer() {
    close(clientSocket_);
    close(serverSocket_);
    clientSocket_ = 0;
    serverSocket_ = 0;
}


}// namespace network
