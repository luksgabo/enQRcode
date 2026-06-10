#include "vec.h"

vec::vec(size_t length){
    mlength = length;
    EmptyVector();
}
void vec::SetLength(size_t length){
        mlength = length;
    EmptyVector();
}


void vec::EmptyVector(){
    body.resize(mlength);
    for (size_t j{0}; j<mlength; ++j){
            body[j] = 0;
    };
}
