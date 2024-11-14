#include "manager.h"

std::vector<Car> Manager::storageCars;
std::set<Route> Manager::storageRoutes;
std::map<Car, Route> Manager::storagePairs;

void Manager::displayAllPairs(){
    for(auto pair : storagePairs){
        std::cout << "Car: " << pair.first << "\nRoute: " << pair.second << std::endl;
    }
}

void Manager::addPair(Car c1, Route r1){
    storagePairs.insert({c1, r1});
}

void Manager::removePair(Car c1){
    storagePairs.erase(c1);
}

void Manager::getPairByCar(Car c1){
    std::cout << "Car: " << c1 << "\nRoute: " << storagePairs.at(c1);
}

void Manager::getPairByRoute(Route r1){
    for(auto pair : storagePairs){
        if(pair.second == r1){
             std::cout << "Car: " << pair.first << "\nRoute: " << pair.second << std::endl;
        }
    }
}

void Manager::editPair(Car c1, Car c2, Route r2){
    storagePairs.erase(c1);
    storagePairs.insert({c2, r2});
}
