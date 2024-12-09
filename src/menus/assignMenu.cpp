#include "assignMenu.h"

void AssignMenu::assign(){
    int vehicleID, routeID;
    std::string assignInput;
    Vehicle c1 = Vehicle();
    Route r1 = Route();

    DisplayMenu::displayAllVehicles();
    while(true){
        std::cout << "\nSelect which vehicle you want to assign (by ID): ";
        std::cin >> assignInput;

        if(assignInput == "STOP"){
            return;
        } else if(!Regex::IDRegex(assignInput)){
            std::cout << "Invalid input! Try again ot type \"STOP\" to return to main menu!\n";
            continue;
        }

        c1 = Manager::findVehicle(stoi(assignInput));

        if(c1.getStatus() == "taken"){
            std::cout << "This vehicle is already assigned on a route! Chose another or abort assignment!";
            continue;
        }
    
        if(c1.getID() == -1){
            std::cout << "Invalid input! Try again ot type \"STOP\" to return to main menu!\n";
            continue;
        } else {
            vehicleID = stoi(assignInput);
            break;
        }
    }
        
    
    DisplayMenu::displayAllRoutes();
    while(true){
        std::cout << "\nSelect which route you want to assign to that vehicle (by ID): ";
        std::cin >> assignInput;

        if(assignInput == "STOP"){
            return;
        } else if(!Regex::IDRegex(assignInput)){
            std::cout << "Invalid input! Try again ot type \"STOP\" to return to main menu!\n";
            continue;
        }

        r1 = Manager::findRoute(stoi(assignInput));
        
        if(r1.getID() == -1){
            std::cout << "Invalid input! Try again ot type \"STOP\" to return to main menu!\n";
            continue;
        } else {
            routeID = stoi(assignInput);
            break;
        }
    }

    double consumption = r1.getLength() * r1.getRepetitions() * c1.getFuelConsumption() / 100;

    std::cout << "\nThe fuel needed for this route is: " << consumption << " liters!\nDo you want to assign\n" << c1 << "\nto\n" << r1 << " ?(y/n) ";

    while(true){
        std::cin >> assignInput;
        if(assignInput == "y"){
            Manager::assignPair(c1, r1);
            Manager::takeVehicle(vehicleID);
            //Manager::addVehicleToRoute(routeID);
            std::cout << std::flush;
            return;
        } else if(assignInput == "n"){
            std::cout << "The operation was aborted!";
            std::cout << std::flush;
            return;
        } else {
            std::cout << "Invalid input! Try again: ";
        }
    }
}