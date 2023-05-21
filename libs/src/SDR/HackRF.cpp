#include "../../inc/SDR/HackRF.h"
#include <libhackrf/hackrf.h>
#include <iostream>
namespace sdr{

HackRF::HackRF(){
/*initialize libhackrf*/
_initialize_libhackrf(); 
}

void HackRF::_initialize_libhackrf(){
    if(hackrf_init()==HACKRF_SUCCESS){
        dprintf(2, "hackrf library initialized...\n");
    }else{
        dprintf(2,"error while initializing hackrf library...\n");
    };
}

void HackRF::_exit_libhackrf(){
    if(hackrf_exit()==HACKRF_SUCCESS){
        dprintf(2, "libhackrf: libhackrf correctly closed...\n");
    }else{
        dprintf(2,"libhackrf: not all devices correctly closed...\n");
    };
}

}