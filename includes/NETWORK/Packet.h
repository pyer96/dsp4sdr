#include <cstdint>
#include <memory>

namespace network{

class Packet{   
    public:
    Packet(uint32_t initial_lenght);
    ~Packet(){ delete data_; }

    uint8_t* data(){
        return data_;
    };
    uint32_t len(){
        return len_; 
    };

    void resize(uint32_t uhduwhd);

    static std::shared_ptr<Packet> make_packet(uint32_t pkt_length); 

    private:
    uint8_t* data_;
    uint32_t initial_len_;
    uint32_t len_;

};

}//  namespace network