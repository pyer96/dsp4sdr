#include "../../includes/NETWORK/Packet.h"

namespace network{

Packet::Packet(uint32_t initial_len){
    data_ = new uint8_t[initial_len];
    initial_len_ = initial_len;
    len_  = initial_len;
}

void Packet::resize(uint32_t l){
    if(l > len_) return;

    len_ = l;
}

std::shared_ptr<Packet> Packet::make_packet(uint32_t pkt_len){
    return std::make_shared<Packet>(pkt_len);
}


}//namespace network