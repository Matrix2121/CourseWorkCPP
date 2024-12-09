#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include "manager.h"

class FileManager {
    private:
        static std::fstream vehiclesFile;
        static std::fstream routesFile;
        static std::fstream pairsFile;

    public:
        static bool initializeFiles();
        static void loadData();

        static void saveVehicleToFile(const Vehicle&);
        static void saveRouteToFile(const Route&);
        static void savePairToFile(const Vehicle&, const Route&);

        static void closeFiles();
};

