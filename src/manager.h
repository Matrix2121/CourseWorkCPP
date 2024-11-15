#pragma once
#include <iostream>
#include <map>
#include <set>
#include "core/car.h"
#include "core/route.h"
#include "regex/regex.h"

class Manager{
    private:
        static std::vector<Car> storageFreeCars;
        static std::set<Route> storageAllRoutes;
        static std::map<Car, Route> storageAllPairs;
        
    public:
        static void displayFreeCars();
        static void displayAllRoutes();
        static void displayAllPairs();

        static void addCar(Car);
        static void addRoute(Route);

        static Car findCar(int);
        static Route findRoute(int);
        static void addPair(Car, Route);





        static void editPair(Car, Car, Route); //rework
        static void removePair(Car); //rework
        static void getPairByCar(Car); //rework
        static void getPairByRoute(Route); //rework

        
        static void editCar(int); //to-do
        static void removeCar(int); //to-do

        
        static void editRoute(int); //to-do
        static void removeRoute(int); //to-do

        
};