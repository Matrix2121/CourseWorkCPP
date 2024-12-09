#include "deleteMenu.h"

void DeleteMenu::deleteVehicle(){
    int vehicleID;
    
    Manager::displayAllVehicles();
    std::cout << "Enter the vehicle's ID you'd like to delete: ";
    std::cin >> vehicleID;

    Manager::deleteVehicle(vehicleID);
}

void DeleteMenu::deleteRoute(){
    int routeID;
    
    Manager::displayAllRoutes();
    std::cout << "Enter the route's ID you'd like to delete: ";
    std::cin >> routeID;

    Manager::deleteRoute(routeID);
}