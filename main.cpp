#include "src/menu.h"
#include "src/manager.h"
#include <iostream>

int main(){
    Menu::mainMenu();



    
    Route r1 = Route({"carigradsko", "luvov most", "zona b5"}, 10.1, 3);
    std::cout << r1 << std::endl;
    Car c1 = Car("Ford", "Fiesta", 2005, 5, 1300, 7.1);
    std::cout << c1 << std::endl;

    

}