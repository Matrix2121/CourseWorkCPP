#pragma once
#include <iostream>
#include <map>
#include <set>
#include "core/vehicle.h"
#include "core/route.h"
#include "regex/regex.h"
#include "fileManager.h"

class Manager{
    private:
        static std::vector<Vehicle> storageAllVehicles;
        static std::set<Route> storageAllRoutes;
        static std::map<Vehicle, Route> storageAllPairs;
        
    public:
        static void displayAllVehicles();
        static void displayAllRoutes();
        static void displayAllPairs();

        static void addVehicle(Vehicle);
        static void addRoute(Route);

        static Vehicle findVehicle(int);
        static Route findRoute(int);

        static void takeVehicle(int);
        static void untakeVehicle(int);
        // static void addVehicleToRoute(int);
        // static void removeVehicleFromRoute(int);

        static void assignPair(Vehicle, Route);

        static void unassignPair(int);

        static void editVehicle(Vehicle, Vehicle);
        static void editRoute(Route, Route);

        static void deleteVehicle(int);
        static void deleteRoute(int);

        static void saveVehiclesToFile();
        static void saveRoutesToFile();
        static void savePairsToFile();
};