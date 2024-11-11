#include "src/route.h"
#include "src/car.h"
#include <iostream>

int main(){
    Route r1 = Route(2, {}, 10.1, 3);
    std::cout << r1.getId();
}