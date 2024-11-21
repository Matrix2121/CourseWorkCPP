#include "car.h"

int Car::counter = 1;

Car::Car(){
    this->ID = -1;
    this->status = "untaken";
}

Car::Car(std::string make, std::string model, int year, int seats, int loadCapacity, double fuelConsumption){
    this->ID = Car::counter;
    this->make = make;
    this->model = model;
    this->year = year;
    this->seats = seats;
    this->loadCapacity = loadCapacity;
    this->fuelConsumption  = fuelConsumption;
    this->status = "untaken";
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

void Car::setStatusTaken(){
    status = "taken";
}
void Car::setStatusUntaken(){
    status = "untaken";
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
    if(is.peek() != '['){
        return is;
    }

    car = Car();

    char ch;
    is >> ch >> car.ID;
    is.ignore(2);
    std::getline(is, car.make, ',');
    is.ignore(1);
    std::getline(is, car.model, ',');
    is.ignore(1);
    is >> car.year;
    is.ignore(2);
    is >> car.seats;
    is.ignore(8);
    is >> car.loadCapacity;
    is.ignore(5);
    is >> car.fuelConsumption;
    is.ignore(10);
    std::getline(is, car.status, ']');
    return is;
}

bool Car::isEmpty() const {
    return make.empty() && model.empty() && year == 0 && seats == 0 && loadCapacity == 0 && fuelConsumption == 0.0 && status.empty();
}
