#include <iostream>
#include <string>
#include <cstdint>
#include <fstream>

using namespace std;

class CHIP8 {
public:
    //0x000 to 0x1FF
    uint8_t V[16]{};
    uint8_t memory[4096]{};
    //PC 0x200 and up reerved for ROM
    uint16_t PC = 0x200;
    //uint16_t PC{};
    uint16_t stack[16]{};
    uint16_t I{};
    uint8_t SP{};
    uint8_t display[64 *32]{};
    uint8_t delay_timer = 60;
    uint8_t sound_timer = 60;
};




int main() {

    
return 0;
}




void loadROM(fileName)
{
  ifstream inFile(fileName);
  
  if (inFile.fail())
  {
    cout << "File failed to load" << endl;
    return 1;
  }
  
}
