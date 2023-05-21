#include <cstdint> 
#include <memory>

namespace dsp{

class LFSR {
    public:
    /**
     * @fn LFSR constructor
     * @brief It initializes a Linear Feedback Shift Register according to parameters 
    */
    LFSR(uint8_t len, uint8_t* feedbacks_bitmask, uint8_t* state_bitmask = nullptr);
    /**
     * @fn LFSR destructor
     * @brief Destroys the lfsr
    */
    ~LFSR(){};

    private:
    uint8_t                     _register_len;
    uint8_t                     _octets_needed;
    std::shared_ptr<uint8_t[]>   _register_state;       
    std::shared_ptr<uint8_t[]>   _register_feedbacks;  

};






} // namespace dsp
