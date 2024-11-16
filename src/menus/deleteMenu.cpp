#include "deleteMenu.h"

void DeleteMenu::deleteCar(){
    int carID;
    
    Manager::displayAllCars();
    std::cout << "Enter the car's ID you'd like to delete: ";
    std::cin >> carID;

    Manager::deleteCar(carID);
}

void DeleteMenu::deleteRoute(){
    int routeID;
    
    Manager::displayAllRoutes();
    std::cout << "Enter the route's ID you'd like to delete: ";
    std::cin >> routeID;

    Manager::deleteRoute(routeID);
}