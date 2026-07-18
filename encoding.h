#pragma once

#include <vector>
#include <cstddef>
#include <string>
#include <bitset>

// function to parse message to byte
std::vector<std::byte> message_to_byte(const std::string &message);

// convert input text to bytes
void encode_message_to_bytes();