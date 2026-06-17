#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

#include "encoding.h"

std::vector<std::byte> message_to_byte(const std::string &message){

std::vector<std::byte> byte_message;
byte_message.reserve(message.size());

for (unsigned char ch : message){
    byte_message.push_back(static_cast<std::byte>(ch));
}

return byte_message;
}