#include "unassignMenu.h"

void UnassignMenu::unassign(){
    int carID;
    Manager::displayAllCars();

    std::cout << "Select the ID of the car you want to unassign: ";
    std::cin >> carID;

    Manager::unassignPair(carID);
}