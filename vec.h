#pragma once
#include <vector>

class vec{
public:
    // Default empty vector.
    vec(){}
    // Create a vector of the requested length.
    vec(size_t length);
    // Resize the vector and reset all values to false.
    void SetLength(size_t length);

    // Return the current vector length.
    size_t size() const { return body.size();}

    // Mutable access to an element.
    std::vector<bool>::reference operator[](size_t index) 
    { return body[index]; }

    // Read-only access to an element.
    bool operator[](size_t index) const 
    { return body[index]; }

private:
    // number of elements in the vector
    size_t mlength{0};
    // linear sequence of module values: true = black, false = white
    std::vector<bool> body;

    // Set vector size and fill with false.
    void EmptyVector();
};