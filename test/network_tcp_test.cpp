#include "../includes/NETWORK/TCP.h"



int main(){
    static const uint16_t port = 7500;
    printf("creating tcp obj\n");
    network::TCP* tcp_srv = new network::TCP();
    printf("starting server\n");
    tcp_srv->startServer(port);
    printf("accepting connections\n");
    tcp_srv->acceptConnection();

    return 0;
}