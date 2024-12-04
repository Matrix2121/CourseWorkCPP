#include "manager.h"

std::vector<Vehicle> Manager::storageAllVehicles;
std::set<Route> Manager::storageAllRoutes;
std::map<Vehicle, Route> Manager::storageAllPairs;

void Manager::displayAllVehicles(){
    for(const Vehicle& c1 : storageAllVehicles){
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
        std::cout << "\nRoute #" << ++counter << ":\n" << "Vehicle: " << pair.first << "\nRoute: " << pair.second << std::endl;
    }
}


void Manager::addVehicle(Vehicle c1){
    storageAllVehicles.push_back(c1);
}

void Manager::addRoute(Route r1){
    storageAllRoutes.insert(r1);
}


Vehicle Manager::findVehicle(int ID){
    for(const Vehicle& c1 : storageAllVehicles){
        if(c1.getID() == ID){
            return c1;
        }
    }

    return Vehicle();
}

Route Manager::findRoute(int ID){
    for(const Route& r1 : storageAllRoutes){
        if(r1.getID() == ID){
            return r1;
        }
    }

    return Route();
}

void Manager::takeVehicle(int ID){
    Vehicle newVehicle;
    Route route;
    for(Vehicle& c1 : storageAllVehicles){
        if(c1.getID() == ID){
            c1.setStatusTaken();
        }
    }

    for(auto pair : storageAllPairs){
        if(pair.first.getID() == ID){
            newVehicle = pair.first;
            route = pair.second;
            newVehicle.setStatusTaken();
            storageAllPairs.erase(pair.first);
            storageAllPairs.insert({newVehicle, route});
        }
    }
}

void Manager::untakeVehicle(int ID){
    Vehicle newVehicle;
    Route route;
    for(Vehicle& c1 : storageAllVehicles){
        if(c1.getID() == ID){
            c1.setStatusUntaken();
        }
    }

    for(auto pair : storageAllPairs){
        if(pair.first.getID() == ID){
            newVehicle = pair.first;
            newVehicle.setStatusUntaken();
            storageAllPairs.erase(pair.first);
            storageAllPairs.insert({newVehicle, route});
        }
    }
}

// void Manager::addVehicleToRoute(int ID){
//     Route newRoute;
//     for(Route r1 : storageAllRoutes){
//         if(r1.getID() == ID){
//             newRoute = r1;
//             std::cout << r1;
//             storageAllRoutes.erase(r1);
//             newRoute.addVehicleToRoute();
//             storageAllRoutes.insert(newRoute);
//             std::cout << r1;
//         }
//     }

//     for(auto pair : storageAllPairs){
//         if(pair.second.getID() == ID){
//             pair.second.addVehicleToRoute();
//             break;
//         }
//     }
// }

// void Manager::removeVehicleFromRoute(int ID){
//     Route newRoute;
//     for(Route r1 : storageAllRoutes){
//         if(r1.getID() == ID){
//             newRoute = r1;
//             storageAllRoutes.erase(r1);
//             newRoute.removeVehicleFromRoute();
//             storageAllRoutes.insert(newRoute);
//         }
//     }

//     for(auto pair : storageAllPairs){
//         if(pair.second.getID() == ID){
//             pair.second.removeVehicleFromRoute();
//             break;
//         }
//     }
// }

void Manager::assignPair(Vehicle c1, Route r1){  
    storageAllPairs.insert({c1, r1});
}


void Manager::unassignPair(int vehicleID){
    auto vehicleIt = findVehicle(vehicleID);
    int routeID = storageAllPairs[vehicleIt].getID();

    // removeVehicleFromRoute(routeID);
    untakeVehicle(vehicleID);

    storageAllPairs.erase(vehicleIt);
}


void Manager::editVehicle(Vehicle oldVehicle, Vehicle newVehicle){
    if(oldVehicle.getStatus() == "Taken"){
        Route r1 = Route();
        for(auto& pair : storageAllPairs){
            if(pair.first == oldVehicle){
                r1 = pair.second;
                storageAllPairs.erase(pair.first);
                storageAllPairs.insert({newVehicle, r1});
            }
        }
    }

    for(Vehicle& c1 : storageAllVehicles){
        if(c1 == oldVehicle){
            c1 = newVehicle;
            break;
        }
    }
}

void Manager::editRoute(Route oldRoute, Route newRoute){
    // if(oldRoute.getVehiclesOnRoute() >= 1){
        Vehicle c1 = Vehicle();
        for(auto& pair : storageAllPairs){
            if(pair.second == oldRoute){
                c1 = pair.first;
                storageAllPairs.erase(pair.first);
                storageAllPairs.insert({c1, newRoute});
                break;
            }
        }
    // }

    auto r1 = storageAllRoutes.find(oldRoute);
    if (r1 != storageAllRoutes.end()) {
        storageAllRoutes.erase(r1);
        storageAllRoutes.insert(newRoute);
    }

}


void Manager::deleteVehicle(int vehicleID){
    Vehicle c1 = Manager::findVehicle(vehicleID);

    for(auto& pair : storageAllPairs){
        if(pair.first == c1){
            storageAllPairs.erase(pair.first);
            break;
        }
    }

    for (std::vector<Vehicle>::iterator it = storageAllVehicles.begin(); it != storageAllVehicles.end(); ++it) {
    if (it->getID() == vehicleID) {
        storageAllVehicles.erase(it);
        break;
    }
    }
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


void Manager::saveVehiclesToFile(){
    for(Vehicle vehicle : Manager::storageAllVehicles){
        FileManager::saveVehicleToFile(vehicle);
    }
}

void Manager::saveRoutesToFile(){
    for(Route route : Manager::storageAllRoutes){
        FileManager::saveRouteToFile(route);
    }
}

void Manager::savePairsToFile(){
    for(auto pair : storageAllPairs){
        FileManager::savePairToFile(pair.first, pair.second);
    }
}