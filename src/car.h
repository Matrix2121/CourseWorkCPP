#pragma once
#include <string>

class Car{
    private: 
        int ID;
        std::string make;
        std::string model;
        int year;
        int seats;
        double loadCapacity;
        double fuelConsumption;
    
    public:
        Car();
        Car(int, std::string, std::string, int, int, double, double);

        void setID(int);
        int getID();

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

        std::string toString() const;
        bool operator<(const Car&) const;
};