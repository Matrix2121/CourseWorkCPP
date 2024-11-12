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
        void displayAllPairs();
        void addPair(Car, Route);
        void removePair(Car);
        void getPairByCar(Car);
        void getPairByRoute(Route);
        void editPair(Car, Car, Route);
};