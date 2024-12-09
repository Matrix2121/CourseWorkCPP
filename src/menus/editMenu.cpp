#include "editMenu.h"

void EditMenu::editVehicle(){
    int vehicleID;
    std::string editMenuInput;
    Vehicle oldVehicle = Vehicle();
    Vehicle newVehicle = Vehicle();

    std::cout << "Which vehicle do you want to edit (by ID): ";
    DisplayMenu::displayAllVehicles();
    std::cin >> vehicleID;
    oldVehicle = Manager::findVehicle(vehicleID);
    newVehicle = oldVehicle;

    
    while(true){
        std::cout << "What do you want to edit (make/model/year/seats/loadCapacity/fuelConsumption) or type \"STOP\" to finish editing: ";
        std::cin >> editMenuInput;

        if(editMenuInput == "STOP"){
            break;
        } else if(editMenuInput == "make"){
            std::cout << "Enter new make: ";
            std::cin >> editMenuInput;
            newVehicle.setMake(editMenuInput);

        } else if(editMenuInput == "model"){
            std::cout << "Enter new model: ";
            std::cin >> editMenuInput;
            newVehicle.setModel(editMenuInput);

        } else if(editMenuInput == "year"){
            while(true){
                std::cout << "Enter new year (in numbers, between 1886 and 2024): ";
                std::cin >> editMenuInput;

                if(Regex::yearRegex(editMenuInput)){
                    newVehicle.setYear(stoi(editMenuInput));
                    break;
                } else if (editMenuInput == "STOP"){
                    return;
                } else {
                    std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
                }
            }

        } else if(editMenuInput == "seats"){
            while(true){
                std::cout << "Enter new seats: ";
                std::cin >> editMenuInput;

                if(Regex::seatsRegex(editMenuInput)){
                    newVehicle.setSeats(stoi(editMenuInput));
                    break;
                } else if (editMenuInput == "STOP"){
                    return;
                } else {
                    std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
                }
            }

        } else if(editMenuInput == "loadCapacity"){
            while(true){
                std::cout << "Enter new load capacity: ";
                std::cin >> editMenuInput;

                if(Regex::loadCapacityRegex(editMenuInput)){
                    newVehicle.setLoadCapacity(stoi(editMenuInput));
                    break;
                } else if (editMenuInput == "STOP"){
                    return;
                } else {
                    std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
                }
            }

        } else if(editMenuInput == "fuelConsumption"){
            while(true){
                std::cout << "Enter new fuel consumption: ";
                std::cin >> editMenuInput;

                if(Regex::fuelConsumptionRegex(editMenuInput)){
                    newVehicle.setFuelConsumption(stod(editMenuInput));
                    break;
                } else if (editMenuInput == "STOP"){
                    return;
                } else {
                    std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
                }
            }

        } else {
            std::cout << "Invalid input! Try again: ";
        }
    }

    Manager::editVehicle(oldVehicle, newVehicle);
}

void EditMenu::editRoute(){
    int routeID;
    std::string editMenuInput;
    Route oldRoute = Route();
    Route newRoute = Route();

    std::cout << "Which route do you want to edit (by ID): ";
    DisplayMenu::displayAllRoutes();
    std::cin >> routeID;
    oldRoute = Manager::findRoute(routeID);
    newRoute = oldRoute;

    
    while(true){
        std::cout << "What do you want to edit (connectionPoints/lenght/repetitions) or type \"STOP\" to finish editing: ";
        std::cin >> editMenuInput;

        if(editMenuInput == "STOP"){
            break;
        } else if(editMenuInput == "connectionPoints"){
            std::cout << "Add connection points or write \"STOP\" to stop inputting\n";
            newRoute.clearConnectionPoints();
            int counter;

            while(true){
                counter++;

                std::cout<< "Connection point #" << counter << ": ";
                std::cin >> editMenuInput;

                if(editMenuInput == "STOP"){
                    break;
                } else {
                    newRoute.addConnectingPoints(editMenuInput);
                }

            }

        } else if(editMenuInput == "lenght"){
            while(true){
                std::cout << "Enter new length in km (in numbers, up to 999.9): ";
                std::cin >> editMenuInput;

                if(Regex::lengthRegex(editMenuInput)){
                    newRoute.setLength(stod(editMenuInput));
                    break;
                } else if (editMenuInput == "STOP"){
                    return;
                } else {
                    std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
                }
            }

        } else if(editMenuInput == "repetitions"){
            while(true){
                std::cout << "Enter new repetitions (in numbers, up to 999): ";
                std::cin >> editMenuInput;

                if(Regex::repetitionsRegex(editMenuInput)){
                    newRoute.setRepetitions(stoi(editMenuInput));
                    break;
                } else if (editMenuInput == "STOP"){
                    return;
                } else {
                    std::cout << "Invalid input! Try again or type \"STOP\" to abort inputting!";
                }
            }
        
        } else {
            std::cout << "Invalid input! Try again: ";
        }
    }
    
    Manager::editRoute(oldRoute, newRoute);
}