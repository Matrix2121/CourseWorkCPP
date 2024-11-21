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

    public:
        static bool initializeFiles();
        static void loadData();

        static void saveCarToFile(const Car&);
        static void saveRouteToFile(const Route&);
        static void savePairToFile(const Car&, const Route&);

        static void closeFiles();
};

