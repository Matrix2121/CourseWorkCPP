#include "car.h"

int Car::counter = 1;

Car::Car(){
    this->ID = -1;
    this->status = "Untaken";
}

Car::Car(std::string make, std::string model, int year, int seats, int loadCapacity, double fuelConsumption){
    this->ID = Car::counter;
    this->make = make;
    this->model = model;
    this->year = year;
    this->seats = seats;
    this->loadCapacity = loadCapacity;
    this->fuelConsumption  = fuelConsumption;
    this->status = "Untaken";
    Car::counter++;
}

void Car::setCounter(int i){
    Car::counter = i;
}

int Car::getCounter(){
    return Car::counter;
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

void Car::setStatus(std::string taken){
    this->status = status;
}
std::string Car::getStatus(){
    return this->status;
}

bool Car::operator<(const Car& other) const {
    return this->ID < other.ID;
}

bool Car::operator==(const Car& other) const {
    return this->ID == other.ID;
}


std::ostream& operator<<(std::ostream& os, const Car& car){
    os << "[" << car.ID << ", " << car.make << ", " << car.model << ", " << car.year << ", " 
    << car.seats << " seats, " << car.loadCapacity << " kg, " << car.fuelConsumption  << " l/100km, " << car.status << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Car& car) {
    char ch;
    is >> ch >> car.ID >> ch;
    std::getline(is, car.make, ',');
    std::getline(is, car.model, ',');
    is >> car.year >> ch >> car.seats;
    is.ignore(7, ',');
    is >> car.loadCapacity;
    is.ignore(4, ',');
    is >> car.fuelConsumption;
    is.ignore(9, ',');
    std::getline(is, car.status, ']');
    return is;
}

bool Car::isEmpty() const {
    return make.empty() && model.empty() && year == 0 && seats == 0 && loadCapacity == 0 && fuelConsumption == 0.0 && status.empty();
}
