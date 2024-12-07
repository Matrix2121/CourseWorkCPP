#include "FileManager.h"

std::fstream FileManager::carsFile;
std::fstream FileManager::routesFile;
std::fstream FileManager::pairsFile;

bool FileManager::initializeFiles() {
    if (!std::filesystem::exists("data/cars.txt")) {
        carsFile.open("data/cars.txt", std::ios::out);
        carsFile.close();
    }
    carsFile.open("data/cars.txt", std::ios::in);
    if (!carsFile.is_open()) {
        std::cerr << "Error opening cars.txt" << std::endl;
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
    std::string delimiter;
    int counter;
    Car car;
    Route route;

    int carID = 0, routeID = 0;

    carsFile.clear();
    carsFile.seekg(0);

    routesFile.clear();
    routesFile.seekg(0);

    pairsFile.clear();
    pairsFile.seekg(0);

    if (std::filesystem::file_size("data/cars.txt") > 0) {
        while (carsFile >> car) {
            if (carsFile.eof()) {
                break;
            }
            if (!car.isEmpty()) {
                Manager::addCar(car);
                if(carID < car.getID()){
                    carID = car.getID();
                }
            } else {
                std::cout << "Empty car encountered!" << std::endl;
                break;
            }
        }
    } else {
        std::cout << "cars.txt is empty." << std::endl;
    }

    Car::setCounter(carID + 1);

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
        while (pairsFile >> car >> delimiter >> route) {
            if (pairsFile.eof()) {
                break;
            }
            Manager::assignPair(car, route);
        }
    } else {
        std::cout << "pairs.txt is empty." << std::endl;
    }

    carsFile.close();
    routesFile.close();
    pairsFile.close();
}

void FileManager::saveCarToFile(const Car& car){
    carsFile << car;
}
void FileManager::saveRouteToFile(const Route& route){
    routesFile << route;
}
void FileManager::savePairToFile(const Car& car, const Route& route){
    char delimiter = '-';
    pairsFile << car << delimiter << route;
}

void FileManager::closeFiles() {
    carsFile.open("data/cars.txt", std::ios::out | std::ios::trunc);
    routesFile.open("data/routes.txt", std::ios::out | std::ios::trunc);
    pairsFile.open("data/pairs.txt", std::ios::out | std::ios::trunc);
    Manager::saveCarsToFile();
    Manager::saveRoutesToFile();
    Manager::savePairsToFile();
    carsFile.close();
    routesFile.close();
    pairsFile.close();
}
