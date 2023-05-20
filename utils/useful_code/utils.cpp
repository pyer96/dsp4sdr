#include "utils.h"
#include "colors.h"

#include <iostream>
#include <string>
#include <fstream>

namespace utils{

void print_banner() {
  std::string line;
  std::ifstream banner("../utils/useful_code/dsp4sdr_banner");
  if (banner.is_open()) {
    printf( GREEN"\n" );
    while (getline(banner, line)) {
      std::cout << line << std::endl;
    }
    printf(reset "\n");
    banner.close();
  } else {
    std::cout << "Unable to open the HackRf One banner\n";
  }
}


}



