#include "createmenu.h"
#include "car.h"
#include "manager.h"

void createMenu::createCar(){
    std::string createObjectInput;
    Car c1 = Car();

    std::cout << "Enter the car's make: ";
    std::cin >> createObjectInput;
    c1.setMake(createObjectInput);

    std::cout << "Enter the car's model: ";
    std::cin >> createObjectInput;
    c1.setModel(createObjectInput);
    
    std::cout << "Enter the car's year: ";
    std::cin >> createObjectInput;
    c1.setYear(stoi(createObjectInput));
    
    std::cout << "Enter the car's seats: ";
    std::cin >> createObjectInput;
    c1.setSeats(stoi(createObjectInput));
    
    std::cout << "Enter the car's load capacity: ";
    std::cin >> createObjectInput;
    c1.setLoadCapacity(stod(createObjectInput));
    
    std::cout << "Enter the car's fuel consumption: ";
    std::cin >> createObjectInput;
    c1.setFuelConsumption(stod(createObjectInput));
    
    std::cout << std::flush;

    Manager::addCar(c1);
}

void createMenu::createRoute(){
    std::string createObjectInput;
    Route r1 = Route();

    std::cout << "Add connection points or write \"STOP\" to continue";
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

    std::cout << std::endl << "Enter route's length: ";
    std::cin >> createObjectInput;
    r1.setLength(stod(createObjectInput));

    std::cout << std::endl << "Enter route's repetitions: ";
    std::cin >> createObjectInput;
    r1.setRepetitions(stoi(createObjectInput));

    std::cout << std::flush;

    Manager::addRoute(r1);
}