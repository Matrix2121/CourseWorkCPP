#pragma once
#include <iostream>
#include <fstream>
#include "manager.h"

class FileManager{
    private:
        static std::fstream carsFile;
        static std::fstream routesFile;
        static std::fstream pairsFile;
        static std::fstream deletedFile;

    public:
        static bool createFiles();

        static std::vector<Car> loadCarsFromFile();
        static void saveCarToFile(Car);
        static void deleteCarFromFile(Car);

        static std::set<Route> loadRoutesFromFile();
        static void saveRouteToFile(Route);
        static void deleteRouteFromFile(Route);

        static std::map<Car, Route> loadPairsFromFile();
        static void savePairToFile(Car);
        static void deletePairFromFile(Car);
};
