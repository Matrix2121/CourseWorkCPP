#include "unassignMenu.h"

void UnassignMenu::unassign(){
    int vehicleID;
    Manager::displayAllVehicles();

    std::cout << "Select the ID of the vehicle you want to unassign: ";
    std::cin >> vehicleID;

    Manager::unassignPair(vehicleID);
}