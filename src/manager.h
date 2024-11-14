#pragma once
#include <iostream>
#include <map>
#include <set>
#include "car.h"
#include "route.h"

class Manager{
    private:
        static std::vector<Car> storageCars;
        static std::set<Route> storageRoutes;
        static std::map<Car, Route> storagePairs;
        
    public:
        static void displayAllPairs();
        static void addPair(Car, Route);
        static void editPair(Car, Car, Route); //rework
        static void removePair(Car); //rework
        static void getPairByCar(Car); //rework
        static void getPairByRoute(Route); //rework

        static void addCar(Car);
        static void editCar(int); //to-do
        static void removeCar(int); //to-do

        static void addRoute(Route);
        static void editRoute(int); //to-do
        static void removeRoute(int); //to-do
};