#pragma once

#include <vector>
#include <cstddef>
#include <string>
#include <bitset>

// Convert a standard string into a vector of bytes.
// Each character becomes one std::byte element.
std::vector<std::byte> message_to_byte(const std::string &message);

// Read a line from stdin, encode it, and print each byte as bits.
void encode_message_to_bytes();