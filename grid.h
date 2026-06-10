#pragma once
#include <vector>

class grid {
public:
grid(){}
grid(size_t length);

void SetLength(size_t length);
size_t size() const{ return body.size();}

std::vector<std::vector<bool>> GetBody() { return body;}

std::vector<bool>& operator[](size_t index){ return body[index];}
const std::vector<bool>& operator[](size_t index) const 
{ return body[index];}

private:
size_t mlength{0};
std::vector<std::vector<bool>> body;

void EmptyGrid();

};