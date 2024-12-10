#include "createmenu.h"

void CreateMenu::createVehicle(){
    std::string createObjectInput;
    Vehicle c1 = Vehicle();

    while(true){
        std::cout << "Enter the vehicle's make: ";
        std::cin >> createObjectInput;
        
        if (createObjectInput == "STOP"){
            return;
        } else {
            c1.setMake(createObjectInput);
            break;
        }
    }

    while(true){
        std::cout << "Enter the vehicle's model: ";
        std::cin >> createObjectInput;

        if (createObjectInput == "STOP"){
            return;
        } else {
            c1.setModel(createObjectInput);
            break;
        }
    }
    
    while(true){
        std::cout << "Enter the vehicle's year (in numbers, between 1886 and 2024): ";
        std::cin >> createObjectInput;

        if(Regex::yearRegex(createObjectInput)){
            c1.setYear(stoi(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort the creation!!";
        }
    }
    
    while(true){
        std::cout << "Enter the vehicle's seats (in numbers, up to 99): ";
        std::cin >> createObjectInput;

        if(Regex::seatsRegex(createObjectInput)){
            c1.setSeats(stoi(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort the creation!!";
        }
    }

    while(true){
        std::cout << "Enter the vehicle's load capacity in kg (in numbers, up to 49999): ";
        std::cin >> createObjectInput;

        if(Regex::loadCapacityRegex(createObjectInput)){
            c1.setLoadCapacity(stoi(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort the creation!!\n";
        }
    }
    
    while(true){
        std::cout << "Enter the vehicle's fuel consumption (l/100km) (in numbers, up to 99.9): ";
        std::cin >> createObjectInput;

        if(Regex::fuelConsumptionRegex(createObjectInput)){
            c1.setFuelConsumption(stod(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort the creation!!";
        }
    }

    std::cout << std::flush;
    c1.IDDeclaration();
    Manager::addVehicle(c1);
}

void CreateMenu::createRoute(){
    std::string createObjectInput;
    Route r1 = Route();

    std::cout << "Add connection points, write \"CONTINUE\" to continue or write \"STOP\" to abort the creation\n";
    int counter;

    while(true){
        counter++;

        std::cout<< "Connection point #" << counter << ": ";
        std::cin >> createObjectInput;

        if(createObjectInput == "CONTINUE"){
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            r1.addConnectingPoints(createObjectInput);
        }

    }

    while(true){
        std::cout << std::endl << "Enter route's length in km (in numbers, up to 10000): ";
        std::cin >> createObjectInput;

        if(Regex::lengthRegex(createObjectInput)){
            r1.setLength(stod(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort the creation!";
        }
    }

    while(true){
        std::cout << std::endl << "Enter route's repetitions (in numbers, up to 999): ";
        std::cin >> createObjectInput;

        if(Regex::repetitionsRegex(createObjectInput)){
            r1.setRepetitions(stoi(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort the creation!";
        }
    }

    std::cout << std::flush;
    r1.IDDeclaration();
    Manager::addRoute(r1);
}