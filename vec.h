#pragma once
#include <vector>

class vec{
public:
vec(){}
vec(size_t length);
void SetLength(size_t length);

size_t size() const { return body.size();}

std::vector<bool>::reference operator[](size_t index) 
{ return body[index]; }

bool operator[](size_t index) const 
{ return body[index]; }

private:
size_t mlength{0};
std::vector<bool> body;

void EmptyVector();
};