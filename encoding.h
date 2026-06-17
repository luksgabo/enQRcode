#pragma once

#include <vector>
#include <cstddef>
#include <string>

// function to parse message to byte
std::vector<std::byte> message_to_byte(const std::string &message);