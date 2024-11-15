#pragma once
#include <string>
#include <sstream>
#include <iomanip>

class Car{
    private: 
        static int counter;
        int ID;
        std::string make;
        std::string model;
        int year;
        int seats;
        int loadCapacity;
        double fuelConsumption;
        std::string status;
    
    public:
        Car();
        Car(int, std::string, std::string, int, int, double, double);

        void IDDeclaration();

        void setID(int);
        int getID() const;

        void setMake(std::string make);
        std::string getMake();

        void setModel(std::string model);
        std::string getModel();

        void setYear(int year);
        int getYear();

        void setSeats(int seats);
        int getSeats();

        void setLoadCapacity(int loadCapacity);
        int getLoadCapacity();

        void setFuelConsumption(double fuelConsumption);
        double getFuelConsumption();

        void setStatus(std::string);
        std::string getStatus();

        bool operator<(const Car&) const;
        bool operator==(const Car&) const;

        friend std::ostream& operator<<(std::ostream&, const Car&);
};