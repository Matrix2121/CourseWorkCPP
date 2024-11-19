#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include "manager.h"

class FileManager {
    public:
        static std::fstream carsFile;
        static std::fstream routesFile;
        static std::fstream pairsFile;
        static std::fstream deletedCarsFile;
        static std::fstream deletedRoutesFile;

    public:
        static bool initializeFiles();

        static void loadData();

        static void saveCarToFile(const Car& car);
        static void deleteCarFromFile(Car);

        static void saveRouteToFile(const Route&);
        static void deleteRouteFromFile(Route);
        
        static void savePairToFile(const Car&, const Route&);
        static void deletePairFromFile(Car, Route);

        static void addDeletedCarToFile(Car);

        static bool addDeletedRouteToFile(Route);

        static void closeFiles();
};

