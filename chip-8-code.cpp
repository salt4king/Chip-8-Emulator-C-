#include <iostream>
#include <string>
#include <cstdint>
#include <fstream>

using namespace std;

class CHIP8 {
public:
    uint8_t V[16]{};            // registers from V0 - VF
    uint8_t memory[4096]{};     // 4096 bits of memory
    uint16_t PC = 0x200;        // Pointer counter registed to 0x200
    uint16_t stack[16]{};       // Stack
    uint16_t I{};               // Index register
    uint8_t SP{};               // Stack Pointer
    uint8_t display[64 *32]{};  // 64 by 32 bit display
    uint8_t delay_timer = 60;   // 60 Hz delay timer
    uint8_t sound_timer = 60;   // Buzzer sound
};


void loadROM(const string& fileName, CHIP8& chip8);

int main() {
    CHIP8 chip8;
    
    string fileName = "Insert ROM here";
    
    loadROM(fileName, chip8);  //This file will load the ROM data onto memory from 0x200 and up.
    
    return 0;
}




void loadROM(const string& fileName, CHIP8& chip8)
{
    uint16_t fileSize{};
    ifstream inFile(fileName, ios::binary | ios::ate);
  
    if (inFile.fail()) // Fail safe
    {
        cout << "File failed to load" << endl;
        return;
    }

    
    
    fileSize = inFile.tellg(); // reads ROM file size
    inFile.seekg(0, ios::beg);

    vector<char> buffer(fileSize);

    for (int i = 0; i < fileSize && (chip8.PC + i) < 4096; i++) //loads data onto memory
    {
        chip8.memory[chip8.PC + i] = static_cast<uint8_t>(buffer[i]);
    }
    
}

