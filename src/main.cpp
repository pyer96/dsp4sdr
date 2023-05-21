#include <iostream>
#include "../utils/useful_code/utils.h"
#include "../utils/useful_code/colors.h"
#include "../libs/inc/SDR/HackRF.h"
int main(int argc, char** argv){

    utils::print_banner();
    printf(green ">" reset "\tHi dsp4sdr!\n");
    printf(green ">" reset "\tCreating HackRF device\n");
    sdr::HackRF radio = sdr::HackRF();
    return 0;
}