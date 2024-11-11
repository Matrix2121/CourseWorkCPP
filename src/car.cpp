#include "car.h"

Car::Car(){}

Car::Car(std::string make, std::string model, int year, int seats, double load_capacity, double fuelConsumption){
    this->make = make;
    this->model = model;
    this->year = year;
    this->seats = seats;
    this->loadCapacity = loadCapacity;
    this->fuelConsumption  = fuelConsumption;
}

void Car::setMake(std::string make){
    this->make = make;
}
std::string Car::getMake(){
    return this->make;
}

void Car::setModel(std::string model){
    this->model  = model;
}
std::string Car::getModel(){
    return this->model;
}

void Car::setYear(int year){
    this->year = year;
}
int Car::getYear(){
    return this->year;
}

void Car::setSeats(int seats){
    this->seats = seats;
}
int Car::getSeats(){
    return this->seats;
}

void Car::setLoadCapacity(double loadCapacity){
    this->loadCapacity = loadCapacity;
}
double Car::getLoadCapacity(){
    return this->loadCapacity;
}

void Car::setFuelConsumption(double fuelConsumption){
    this->fuelConsumption = fuelConsumption;
}
double Car::getFuelConsumption(){
    return this->fuelConsumption;
}


