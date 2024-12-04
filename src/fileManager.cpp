#include "FileManager.h"

std::fstream FileManager::vehiclesFile;
std::fstream FileManager::routesFile;
std::fstream FileManager::pairsFile;

bool FileManager::initializeFiles() {
    if (!std::filesystem::exists("data/vehicles.txt")) {
        vehiclesFile.open("data/vehicles.txt", std::ios::out);
        vehiclesFile.close();
    }
    vehiclesFile.open("data/vehicles.txt", std::ios::in);
    if (!vehiclesFile.is_open()) {
        std::cerr << "Error opening vehicles.txt" << std::endl;
        return false;
    }

    if (!std::filesystem::exists("data/routes.txt")) {
        routesFile.open("data/routes.txt", std::ios::out);
        routesFile.close();
    }
    routesFile.open("data/routes.txt", std::ios::in);
    if (!routesFile.is_open()) {
        std::cerr << "Error opening routes.txt" << std::endl;
        return false;
    }

    if (!std::filesystem::exists("data/pairs.txt")) {
        pairsFile.open("data/pairs.txt", std::ios::out);
        pairsFile.close();
    }
    pairsFile.open("data/pairs.txt", std::ios::in);
    if (!pairsFile.is_open()) {
        std::cerr << "Error opening pairs.txt" << std::endl;
        return false;
    }

    std::cout << "All files initialized successfully." << std::endl;
    return true;
}

void FileManager::loadData() {
    char delimiter;
    int counter;
    Vehicle vehicle;
    Route route;

    int vehicleID = 0, routeID = 0;

    vehiclesFile.clear();
    vehiclesFile.seekg(0);

    routesFile.clear();
    routesFile.seekg(0);

    pairsFile.clear();
    pairsFile.seekg(0);

    if (std::filesystem::file_size("data/vehicles.txt") > 0) {
        while (vehiclesFile >> vehicle) {
            if (vehiclesFile.eof()) {
                break;
            }
            if (!vehicle.isEmpty()) {
                Manager::addVehicle(vehicle);
                if(vehicleID < vehicle.getID()){
                    vehicleID = vehicle.getID();
                }
            } else {
                std::cout << "Empty vehicle encountered!" << std::endl;
                break;
            }
        }
    } else {
        std::cout << "vehicles.txt is empty." << std::endl;
    }

    Vehicle::setCounter(vehicleID + 1);

    if (std::filesystem::file_size("data/routes.txt") > 0) {
        while (routesFile >> route) {
            if (routesFile.eof()) {
                break;
            }
            if (!route.isEmpty()) {
                Manager::addRoute(route);
                if(routeID < route.getID()){
                    routeID = route.getID();
                }
            } else {
                std::cout << "Empty route encountered!" << std::endl;
                break;
            }
        }
    } else {
        std::cout << "routes.txt is empty." << std::endl;
    }

    Route::setCounter(routeID + 1);

    if (std::filesystem::file_size("data/pairs.txt") > 0) {
        while (pairsFile >> vehicle >> delimiter >> route) {
            if (pairsFile.eof()) {
                break;
            }
            Manager::assignPair(vehicle, route);
        }
    } else {
        std::cout << "pairs.txt is empty." << std::endl;
    }

    vehiclesFile.close();
    routesFile.close();
    pairsFile.close();
}

void FileManager::saveVehicleToFile(const Vehicle& vehicle){
    vehiclesFile << vehicle;
}
void FileManager::saveRouteToFile(const Route& route){
    routesFile << route;
}
void FileManager::savePairToFile(const Vehicle& vehicle, const Route& route){
    char delimiter = '-';
    pairsFile << vehicle << delimiter << route;
}

void FileManager::closeFiles() {
    vehiclesFile.open("data/vehicles.txt", std::ios::out | std::ios::trunc);
    routesFile.open("data/routes.txt", std::ios::out | std::ios::trunc);
    pairsFile.open("data/pairs.txt", std::ios::out | std::ios::trunc);
    Manager::saveVehiclesToFile();
    Manager::saveRoutesToFile();
    Manager::savePairsToFile();
    vehiclesFile.close();
    routesFile.close();
    pairsFile.close();
}
