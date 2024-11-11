#include "src/taxi.h"
#include <iostream>

int main(){
    Route r1 = Route(2, {}, 10.1, 3);
    std::cout << r1.getId() << std::endl;
    Route r2 = Route();
    std::cout << r2.getId();
}