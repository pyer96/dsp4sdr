#include "utils.h"
#include "colors.h"

#include <iostream>
#include <string>
#include <fstream>

namespace utils{

void print_banner() {
  std::string line;
  std::ifstream banner("../resources/dsp4sdr_banner");
  if (banner.is_open()) {
    printf( GREEN"\n" );
    while (getline(banner, line)) {
//      std::cout << line << std::endl;
      for(int i = 0; i<line.length(); i++){
        if(line[i]!= '_'){
          printf(red"%c" green, line.c_str()[i]);
        }else{
          printf("%c",line[i]);
        }
      }
      printf("\n");
    }
    printf(reset "\n");
    banner.close();
  } else {
    std::cout << "Unable to open the HackRf One banner\n";
  }
}


}



