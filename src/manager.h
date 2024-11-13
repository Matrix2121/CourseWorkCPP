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
        static void removePair(Car);
        static void getPairByCar(Car);
        static void getPairByRoute(Route);
        static void editPair(Car, Car, Route);
};