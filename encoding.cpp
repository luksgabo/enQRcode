#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

#include "encoding.h"

// Message to byte: get text string and return bytes strings
std::vector<std::byte> message_to_byte(const std::string &message){

std::vector<std::byte> byte_message;
byte_message.reserve(message.size());

for (unsigned char ch : message){
    byte_message.push_back(static_cast<std::byte>(ch));
}

return byte_message;
}

// Encode message to bytes: using previous function,
// wait for a input of text string and display the
// bytes code of each character
void encode_message_to_bytes(){
    std::string message;
    std::getline(std::cin, message);
    auto encoded_message = message_to_byte(message);

    // wait input message and output it encoded in bytes
    std::cout << std::endl;
    for (size_t i{0}; i< message.size(); i++){
        auto bit = encoded_message[i];
        auto ch = message[i];
        unsigned value = std::to_integer<unsigned>(bit);
        std::cout << ch << ": " << std::bitset<8>(value) << '\n';
    }
    std::cout << std::endl;
}