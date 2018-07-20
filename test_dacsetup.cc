extern "C" {
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <errno.h>
#include <inttypes.h>
};
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <cinttypes>

#include <dacsetup.h>
#include <json.hpp>

//using namespace std;
using json = nlohmann::json;

I2C* dacsetup;

int main() {

  std::ifstream i;
  json j;

  //--Configure DACs from config file

  //Read in DAC settings from config file (optional)
/*
  printf("\nReading DAC settings from file...\n");
  i.open("ptb_config.json");
  std::cout << "Parsing document" << std::endl;
  i >> j;

  std::cout << "JSON object filled..." << std::endl;
  //Dig down to the DAC level settings
  json ctbconf = j.at("ctb");
  json subsys = ctbconf.at("subsystems");
  json ssp = subsys.at("ssp");
  json ssptrig = ssp.at("triggers");
  std::cout << "Testing ID " << ssptrig[0].at("id") << std::endl;
  std::cout << "Testing Mask " << ssptrig[0].at("mask") << std::endl;

  std::vector<uint32_t> dacv = ssp.at("dac_thresholds"); //1879 ticks = 1.51V 
*/
  std::vector<uint32_t> dacv(24,0);

  //Configure DACs with values set in the vector above
  if (dacsetup->ConfigureDacs(dacv, false)) {
     printf("Failed R/W test. \n");
     return 1;
  }
    //Writes random values and compares those to the values read back
//  if (!dacsetup->dac_test()) {
//     printf("Failed R/W test. \n");
//     return 1;
//  }


  return 0;
}
