#include "car.h"
#include <string>
#include <sstream>
#include <iomanip>

int Car::counter = 1;

Car::Car(){
    this->ID = -1;
}

Car::Car(int ID, std::string make, std::string model, int year, int seats, double loadCapacity, double fuelConsumption){
    this->ID = Car::counter;
    this->make = make;
    this->model = model;
    this->year = year;
    this->seats = seats;
    this->loadCapacity = loadCapacity;
    this->fuelConsumption  = fuelConsumption;
    Car::counter++;
}

void Car::IDDeclaration(){
    this->ID = Car::counter;
    Car::counter++;
}

void Car::setID(int ID){
    this->ID = ID;
}

int Car::getID() const{
    return this->ID;
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

void Car::setLoadCapacity(int loadCapacity){
    this->loadCapacity = loadCapacity;
}
int Car::getLoadCapacity(){
    return this->loadCapacity;
}

void Car::setFuelConsumption(double fuelConsumption){
    this->fuelConsumption = fuelConsumption;
}
double Car::getFuelConsumption(){
    return this->fuelConsumption;
}

bool Car::operator<(const Car& other) const {
    return this->ID < other.ID;
}

std::ostream& operator<<(std::ostream& os, const Car& car){
    os << "[" << car.ID << ", " << car.make << ", " << car.model << ", " << car.year << ", " 
    << car.seats << " seats, " << car.loadCapacity << " kg, " << car.fuelConsumption  << " l/100km" << "]";
    return os;
}


