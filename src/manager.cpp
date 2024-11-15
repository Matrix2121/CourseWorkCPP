#include "manager.h"

std::vector<Car> Manager::storageFreeCars;
std::set<Route> Manager::storageAllRoutes;
std::map<Car, Route> Manager::storageAllPairs;

void Manager::displayFreeCars(){
    for(const Car& c1 : storageFreeCars){
        std::cout << c1 << "\n";
    }
    std::cout << std::flush;
}

void Manager::displayAllRoutes(){
    for(const Route& r1 : storageAllRoutes){
        std::cout << r1 << "\n";
    }
    std::cout << std::flush;
}

void Manager::displayAllPairs(){
    int counter = 0;
    for(auto pair : storageAllPairs){
        std::cout << "\nRoute #" << ++counter << ":\n" << "Car: " << pair.first << "\nRoute: " << pair.second << std::endl;
    }
}


void Manager::addCar(Car c1){
    storageFreeCars.push_back(c1);
}

void Manager::addRoute(Route r1){
    storageAllRoutes.insert(r1);
}


Car Manager::findCar(int ID){
    for(const Car& c1 : storageFreeCars){
        if(c1.getID() == ID){
            return c1;
        }
    }

    return Car();
}

Route Manager::findRoute(int ID){
    for(const Route& r1 : storageAllRoutes){
        if(r1.getID() == ID){
            return r1;
        }
    }

    return Route();
}

void Manager::addPair(Car c1, Route r1){  
    storageAllPairs.insert({c1, r1});
}







void Manager::editPair(Car c1, Car c2, Route r2){
    storageAllPairs.erase(c1);
    storageAllPairs.insert({c2, r2});
}

void Manager::removePair(Car c1){
    storageAllPairs.erase(c1);
}

void Manager::getPairByCar(Car c1){
    std::cout << "Car: " << c1 << "\nRoute: " << storageAllPairs.at(c1);
}

void Manager::getPairByRoute(Route r1){
    for(auto pair : storageAllPairs){
        if(pair.second == r1){
             std::cout << "Car: " << pair.first << "\nRoute: " << pair.second << std::endl;
        }
    }
}

void Manager::removeCar(int ID){
    for (auto it = storageFreeCars.begin(); it != storageFreeCars.end(); it++) {
        if (it->getID() == ID) {
            it = storageFreeCars.erase(it);
            return;
        }
    }
}
