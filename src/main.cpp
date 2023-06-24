#include <iostream>
#include <unistd.h>

#include "../utils/utils.h"
#include "../utils/colors.h"
#include "../includes/SDR/HackRF.h"
int main(int argc, char** argv){

    utils::print_banner();
    printf(green ">" reset "\tCreating HackRF device\n");
    sdr::HackRF radio = sdr::HackRF();
    sleep(10);
    return 0;
}