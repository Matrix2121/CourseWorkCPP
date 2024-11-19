#include "manager.h"

std::vector<Car> Manager::storageAllCars;
std::set<Route> Manager::storageAllRoutes;
std::map<Car, Route> Manager::storageAllPairs;

void Manager::displayAllCars(){
    for(const Car& c1 : storageAllCars){
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
    storageAllCars.push_back(c1);
}

void Manager::addRoute(Route r1){
    storageAllRoutes.insert(r1);
}


Car Manager::findCar(int ID){
    for(const Car& c1 : storageAllCars){
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

void Manager::takeCar(int ID){
    for(Car& c1 : storageAllCars){
        if(c1.getID() == ID){
            c1.setStatus("Taken");
        }
    }
}

void Manager::untakeCar(int ID){
    for(Car& c1 : storageAllCars){
        if(c1.getID() == ID){
            c1.setStatus("Untaken");
        }
    }
}

void Manager::addCarToRoute(int ID){
    for(Route r1 : storageAllRoutes){
        if(r1.getID() == ID){
            r1.addCarToRoute();
        }
    }
}

void Manager::removeCarFromRoute(int ID){
    for(Route r1 : storageAllRoutes){
        if(r1.getID() == ID){
            r1.removeCarFromRoute();
        }
    }
}

void Manager::assignPair(Car c1, Route r1){  
    storageAllPairs.insert({c1, r1});
}


void Manager::unassignPair(int carID){
    storageAllPairs.erase(Manager::findCar(carID));
}


void Manager::editCar(Car oldCar, Car newCar){
    if(oldCar.getStatus() == "Taken"){
        Route r1 = Route();
        for(auto& pair : storageAllPairs){
            if(pair.first == oldCar){
                r1 = pair.second;
                storageAllPairs.erase(pair.first);
                storageAllPairs.insert({newCar, r1});
                break;
            }
        }
    }

    for(Car& c1 : storageAllCars){
        if(c1 == oldCar){
            c1 = newCar;
            break;
        }
    }
}

void Manager::editRoute(Route oldRoute, Route newRoute){
    if(oldRoute.getCarsOnRoute() >= 1){
        Car c1 = Car();
        for(auto& pair : storageAllPairs){
            if(pair.second == oldRoute){
                c1 = pair.first;
                storageAllPairs.erase(pair.first);
                storageAllPairs.insert({c1, newRoute});
                break;
            }
        }
    }

    auto r1 = storageAllRoutes.find(oldRoute);
    if (r1 != storageAllRoutes.end()) {
        storageAllRoutes.erase(r1);
        storageAllRoutes.insert(newRoute);
    }

}


void Manager::deleteCar(int carID){
    Car c1 = Manager::findCar(carID);

    for(auto& pair : storageAllPairs){
        if(pair.first == c1){
            storageAllPairs.erase(pair.first);
            break;
        }
    }

    storageAllPairs.erase(c1);
}

void Manager::deleteRoute(int routeID){
    Route r1 = Manager::findRoute(routeID);

    storageAllRoutes.erase(r1);

    for(auto& pair : storageAllPairs){
        if(pair.second == r1){
            storageAllPairs.erase(pair.first);
            break;
        }
    }
}

int Manager::carCounter(){
    int counter = 0;
    for(Car car : storageAllCars){
        counter++;
    }
    return counter;
}

int Manager::routeCounter(){
    int counter = 0;
    for(Route car : storageAllRoutes){
        counter++;
    }
    return counter;
}

int Manager::pairCounter(){
    int counter = 0;
    for(auto pair : storageAllPairs){
        counter++;
    }
    return counter;
}
