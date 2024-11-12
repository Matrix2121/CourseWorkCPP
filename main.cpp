#include "src/taxi.h"
#include <iostream>

int main(){
    Route r1 = Route(2, {}, 10.1, 3);
    std::cout << r1.getId() << std::endl;
    r1.setId(1);
    std::cout << r1.getId() << std::endl;
    Car c1 = Car("Ford", "Fiesta", 2005, 5, 1300, 7.1);
    std::cout << c1.toString() << std::endl;
}