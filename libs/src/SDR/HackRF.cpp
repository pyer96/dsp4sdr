#include "../../inc/SDR/HackRF.h"
#include "../../../utils/useful_code/colors.h"
#include <iostream>
namespace sdr{

HackRF::HackRF(){
/*initialize libhackrf*/
_initialize_libhackrf(); 

/*detech hackrf devices*/
_handle_device_list();
}


/*#######################
    PRIVATE FUNCTIONS
########################*/ 
void HackRF::_initialize_libhackrf(){
    if(hackrf_init()==HACKRF_SUCCESS){
        dprintf(2, green ">" reset "\thackrf library initialized...\n");
    }else{
        dprintf(2,red ">" reset "\terror while initializing hackrf library...\n");
    };
}
void HackRF::_exit_libhackrf(){
    if(hackrf_exit()==HACKRF_SUCCESS){
        dprintf(2, green ">" reset"\tlibhackrf: libhackrf correctly closed...\n");
    }else{
        dprintf(2,red ">" reset"\tlibhackrf: not all devices correctly closed...\n");
    };
}
void HackRF::_handle_device_list(){
    hackrf_device_list_t* dev_list = hackrf_device_list();
    if(dev_list->devicecount>1){
        printf(green">" reset"\tSDR::HackRF # %d hackrfs detected, which one you want to open?\n", dev_list->usb_devicecount);
        for(int i = 0; i< dev_list->devicecount; i++){
            printf(green ">" reset"\t%d) SN: %s\n", i, dev_list->serial_numbers[i]);
        }
        int selection; 
        scanf("%d", &selection);
        if(selection>=0 && selection < dev_list->devicecount){
            printf(green">" reset"SDR::HackRF # %s has been selected!\n", dev_list->serial_numbers[selection]);

        }
        
    }else{
        printf(green ">" reset"\tSDR::HackRF # 1 hackrf detected, opening it...\n"); 
    }

}
}