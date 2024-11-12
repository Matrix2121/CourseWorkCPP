#pragma once
#include <string>

class Car{
    private: 
        std::string make;
        std::string model;
        int year;
        int seats;
        double loadCapacity;
        double fuelConsumption;
    
    public:
        Car();
        Car(std::string, std::string, int, int, double, double);

        void setMake(std::string make);
        std::string getMake();

        void setModel(std::string model);
        std::string getModel();

        void setYear(int year);
        int getYear();

        void setSeats(int seats);
        int getSeats();

        void setLoadCapacity(double loadCapacity);
        double getLoadCapacity();

        void setFuelConsumption(double fuelConsumption);
        double getFuelConsumption();

        std::string toString();
};