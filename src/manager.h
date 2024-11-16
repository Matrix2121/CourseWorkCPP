#pragma once
#include <iostream>
#include <map>
#include <set>
#include "core/car.h"
#include "core/route.h"
#include "regex/regex.h"

class Manager{
    private:
        static std::vector<Car> storageAllCars;
        static std::set<Route> storageAllRoutes;
        static std::map<Car, Route> storageAllPairs;
        
    public:
        static void displayAllCars();
        static void displayAllRoutes();
        static void displayAllPairs();

        static void addCar(Car);
        static void addRoute(Route);

        static Car findCar(int);
        static Route findRoute(int);

        static void takeCar(int);
        static void untakeCar(int);
        static void addCarToRoute(int);
        static void removeCarFromRoute(int);

        static void assignPair(Car, Route);

        static void unassignPair(int);

        static void editCar(Car, Car);
        static void editRoute(Route, Route);

        static void deleteCar(int); //fix ids
        static void deleteRoute(int); //fix ids
};