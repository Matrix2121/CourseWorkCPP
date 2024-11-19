#include "FileManager.h"
#include <iostream>

std::fstream FileManager::carsFile;
std::fstream FileManager::routesFile;
std::fstream FileManager::pairsFile;
std::fstream FileManager::deletedCarsFile;
std::fstream FileManager::deletedRoutesFile;

bool FileManager::initializeFiles() {
    if (!std::filesystem::exists("data/cars.txt")) {
        carsFile.open("data/cars.txt", std::ios::out);
        carsFile.close();
    }
    carsFile.open("data/cars.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!carsFile.is_open()) {
        std::cerr << "Error opening cars.txt" << std::endl;
        return false;
    }

    if (!std::filesystem::exists("data/routes.txt")) {
        routesFile.open("data/routes.txt", std::ios::out);
        routesFile.close();
    }
    routesFile.open("data/routes.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!routesFile.is_open()) {
        std::cerr << "Error opening routes.txt" << std::endl;
        return false;
    }

    if (!std::filesystem::exists("data/pairs.txt")) {
        pairsFile.open("data/pairs.txt", std::ios::out);
        pairsFile.close();
    }
    pairsFile.open("data/pairs.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!pairsFile.is_open()) {
        std::cerr << "Error opening pairs.txt" << std::endl;
        return false;
    }

    if (!std::filesystem::exists("data/deleted/cars.txt")) {
        deletedCarsFile.open("data/deleted/cars.txt", std::ios::out);
        deletedCarsFile.close();
    }
    deletedCarsFile.open("data/deleted/cars.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!deletedCarsFile.is_open()) {
        std::cerr << "Error opening deleted/cars.txt" << std::endl;
        return false;
    }

    if (!std::filesystem::exists("data/deleted/routes.txt")) {
        deletedRoutesFile.open("data/deleted/routes.txt", std::ios::out);
        deletedRoutesFile.close();
    }
    deletedRoutesFile.open("data/deleted/routes.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!deletedRoutesFile.is_open()) {
        std::cerr << "Error opening deleted/routes.txt" << std::endl;
        return false;
    }

    std::cout << "All files initialized successfully." << std::endl;
    return true;
}

void FileManager::loadData() { //bug
    int counter;
    Car car;
    Route route;
    char delimiter;


    carsFile.clear();
    carsFile.seekg(0);

    routesFile.clear();
    routesFile.seekg(0);

    pairsFile.clear();
    pairsFile.seekg(0);

    std::cout << "flag 0";

    while (carsFile >> car) { 
        if (!car.isEmpty()) {
            Manager::addCar(car); 
        } else {
            std::cout << "flag 1";
            break;
        }
    }

    while(routesFile >> route){
        if(!route.isEmpty()){
            Manager::addRoute(route);
        } else {
            std::cout << "flag 2";
            break;
        }
    }


    while(pairsFile >> car >> delimiter >> route){
        if (!(car.isEmpty() && route.isEmpty()))
        {
            Manager::assignPair(car, route);
        } else {
            std::cout << "flag 3";
            break;
        }
    }
}

void FileManager::saveCarToFile(const Car& car) {
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
    if (carsFile.is_open()) carsFile.close();
    if (routesFile.is_open()) routesFile.close();
    if (pairsFile.is_open()) pairsFile.close();
    if (deletedCarsFile.is_open()) deletedCarsFile.close();
    if (deletedRoutesFile.is_open()) deletedRoutesFile.close();
}
