#include "assignMenu.h"

void AssignMenu::assign(){
    int carID, routeID;
    std::string assignInput;
    Car c1;
    Route r1;

    DisplayMenu::displayFreeCars();
    while(true){
        std::cout << "Select which car you want to assign (by ID): ";
        std::cin >> assignInput;

        if(assignInput == "STOP"){
            return;
        } else if(!Regex::IDRegex(assignInput)){
            std::cout << "Invalid input! Try again ot type \"STOP\" to return to main menu!\n";
            continue;
        }

        c1 = Manager::findCar(stoi(assignInput));
        if(c1.getID() == -1){
            std::cout << "Invalid input! Try again ot type \"STOP\" to return to main menu!\n";
            continue;
        } else {
            carID = stoi(assignInput);
            break;
        }
    }
    
    DisplayMenu::displayAllRoutes();
    while(true){
        std::cout << "Select which route you want to assign to that car (by ID): ";
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

    Manager::addPair(c1, r1);

    Manager::removeCar(carID);
    std::cout << "flag3";

}