#include <iostream>
#include "../utils/useful_code/utils.h"
#include "../utils/useful_code/colors.h"
//#include "../includes/DSP/lfsr.h"
int main(int argc, char** argv){

    utils::print_banner();
    printf(green ">" reset "\tCreating HackRF device\n");
    uint8_t len = 5;
    uint8_t state = 0x01;
    uint8_t feed  = 0x10;
    //dsp::lfsr reg = dsp::LFSR(len, &feed,&state);
    return 0;
}