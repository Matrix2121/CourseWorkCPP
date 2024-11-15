#include "createmenu.h"
#include "car.h"
#include "manager.h"
#include "regex.h"

void createMenu::createCar(){
    std::string createObjectInput;
    Car c1 = Car();

    std::cout << "Enter the car's make: ";
    std::cin >> createObjectInput;
    c1.setMake(createObjectInput);

    std::cout << "Enter the car's model: ";
    std::cin >> createObjectInput;
    c1.setModel(createObjectInput);
    
    while(true){
        std::cout << "Enter the car's year (in numbers, between 1886 and 2024): ";
        std::cin >> createObjectInput;

        if(Regex::yearRegex(createObjectInput)){
            c1.setYear(stoi(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
        }
    }
    
    while(true){
        std::cout << "Enter the car's seats (in numbers, up to 99): ";
        std::cin >> createObjectInput;

        if(Regex::seatsRegex(createObjectInput)){
            c1.setSeats(stoi(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
        }
    }

    while(true){
        std::cout << "Enter the car's load capacity in kg (in numbers, up to 49999): ";
        std::cin >> createObjectInput;

        if(Regex::loadCapacityRegex(createObjectInput)){
            c1.setLoadCapacity(stoi(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!\n";
        }
    }
    
    while(true){
        std::cout << "Enter the car's fuel consumption (l/100km) (in numbers, up to 99.9): ";
        std::cin >> createObjectInput;

        if(Regex::fuelConsumptionRegex(createObjectInput)){
            c1.setFuelConsumption(stod(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
        }
    }

    std::cout << std::flush;
    c1.IDDeclaration();
    Manager::addCar(c1);
}

void createMenu::createRoute(){
    std::string createObjectInput;
    Route r1 = Route();

    std::cout << "Add connection points or write \"STOP\" to continue\n";
    int counter;

    while(true){
        counter++;

        std::cout<< "Connection point #" << counter << ": ";
        std::cin >> createObjectInput;

        if(createObjectInput == "STOP"){
            break;
        } else {
            r1.addConnectingPoints(createObjectInput);
        }

    }

    while(true){
        std::cout << std::endl << "Enter route's length in km (in numbers, up to 999.9): ";
        std::cin >> createObjectInput;

        if(Regex::seatsRegex(createObjectInput)){
            r1.setLength(stod(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
        }
    }

    while(true){
        std::cout << std::endl << "Enter route's repetitions (in numbers, up to 999): ";
        std::cin >> createObjectInput;

        if(Regex::seatsRegex(createObjectInput)){
            r1.setRepetitions(stoi(createObjectInput));
            break;
        } else if (createObjectInput == "STOP"){
            return;
        } else {
            std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
        }
    }

    std::cout << std::flush;
    r1.IDDeclaration();
    Manager::addRoute(r1);
}