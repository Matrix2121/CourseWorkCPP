#include "manager.h"

void Manager::displayAllPairs(){
    for(auto pair : storagePairs){
        std::cout << "Car: " << pair.first.toString() << "\nRoute: " << pair.second.toString() << std::endl;
    }
}

void Manager::addPair(Car c1, Route r1){
    storagePairs.insert({c1, r1});
}

void Manager::removePair(Car c1){
    storagePairs.erase(c1);
}

void Manager::getPairByCar(Car c1){
    std::cout << "Car: " << c1.toString() << "\nRoute: " << storagePairs.at(c1).toString();
}

void Manager::getPairByRoute(Route r1){
    for(auto pair : storagePairs){
        if(pair.second.compare(r1)){
             std::cout << "Car: " << pair.first.toString() << "\nRoute: " << pair.second.toString() << std::endl;
        }
    }
}

void Manager::editPair(Car c1, Car c2, Route r2){
    storagePairs.erase(c1);
    storagePairs.insert({c2, r2});
}


