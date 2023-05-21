#include "../../includes/DSP/lfsr.h"
#include "../../utils/useful_code/colors.h"
#include <cmath>
#include <cstdlib>

namespace dsp{  

    LFSR::LFSR(uint8_t register_length, uint8_t* feedbacks_bitmask, uint8_t* initial_state_bitmask = nullptr){
        if(register_length==0){
            dprintf(2,red ">" reset"\tLFSR: the register length must be in the range [1 255] included!\n");
            dprintf(2,red ">" reset"\tAborting...\n");
            exit(EXIT_FAILURE);
        }
        _register_len = register_length;
        _octets_needed = (uint8_t) std::ceil(((float)_register_len)/8);
        _register_state = std::make_shared<uint8_t[]>(_octets_needed);
        _register_feedbacks = std::make_shared<uint8_t[]>(_octets_needed); 

        /* INITIALIZE FEEDBACK TAPS */  
        for(int i = 0; i < _octets_needed; i++){
            _register_feedbacks.get()[i] = (uint8_t)feedbacks_bitmask[i];
        }

        /* INITIALIZE REGISTER STATE */
        if(initial_state_bitmask != nullptr){   // Uses user-provided state if available...
            for(int i = 0; i < _octets_needed; i++){
                _register_state.get()[i] = (uint8_t)initial_state_bitmask[i];
            }
        }else{                                  // ...all 1s otherwise
            for(int i = 0; i < _octets_needed; i++){
                _register_state.get()[i] = (uint8_t)0xFF; 
            } 
        }
        


        
    }





} // namespace dsp