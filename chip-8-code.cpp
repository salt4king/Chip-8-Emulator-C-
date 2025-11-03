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

    for (int i = 0; i < 80; i++)
    {
        chip8.memory[0x50 +i] = fonset[i];
    }

 
    
    string fileName = "Insert ROM here";
    
    loadROM(fileName, chip8);  //This file will load the ROM data onto memory from 0x200 and up.
    
    return 0;
}

uint8_t fontset[80] =
{
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};


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
     inFile.read(buffer.data(), fileSize); // read the file bytes into the buffer

    for (int i = 0; i < fileSize && (chip8.PC + i) < 4096; i++) //loads data onto memory
    {
        chip8.memory[chip8.PC + i] = static_cast<uint8_t>(buffer[i]);
    }
    
}

