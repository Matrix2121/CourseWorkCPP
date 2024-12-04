#include "vehicle.h"

int Vehicle::counter = 1;

Vehicle::Vehicle(){
    this->ID = -1;
    this->status = "untaken";
}

Vehicle::Vehicle(std::string make, std::string model, int year, int seats, int loadCapacity, double fuelConsumption){
    this->ID = Vehicle::counter;
    this->make = make;
    this->model = model;
    this->year = year;
    this->seats = seats;
    this->loadCapacity = loadCapacity;
    this->fuelConsumption  = fuelConsumption;
    this->status = "untaken";
    Vehicle::counter++;
}

void Vehicle::setCounter(int i){
    Vehicle::counter = i;
}

int Vehicle::getCounter(){
    return Vehicle::counter;
}

void Vehicle::IDDeclaration(){
    this->ID = Vehicle::counter;
    Vehicle::counter++;
}

void Vehicle::setID(int ID){
    this->ID = ID;
}

int Vehicle::getID() const{
    return this->ID;
}

void Vehicle::setMake(std::string make){
    this->make = make;
}
std::string Vehicle::getMake(){
    return this->make;
}

void Vehicle::setModel(std::string model){
    this->model  = model;
}
std::string Vehicle::getModel(){
    return this->model;
}

void Vehicle::setYear(int year){
    this->year = year;
}
int Vehicle::getYear(){
    return this->year;
}

void Vehicle::setSeats(int seats){
    this->seats = seats;
}
int Vehicle::getSeats(){
    return this->seats;
}

void Vehicle::setLoadCapacity(int loadCapacity){
    this->loadCapacity = loadCapacity;
}
int Vehicle::getLoadCapacity(){
    return this->loadCapacity;
}

void Vehicle::setFuelConsumption(double fuelConsumption){
    this->fuelConsumption = fuelConsumption;
}
double Vehicle::getFuelConsumption(){
    return this->fuelConsumption;
}

void Vehicle::setStatusTaken(){
    status = "taken";
}
void Vehicle::setStatusUntaken(){
    status = "untaken";
}
std::string Vehicle::getStatus(){
    return this->status;
}

bool Vehicle::operator<(const Vehicle& other) const {
    return this->ID < other.ID;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return this->ID == other.ID;
}


std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle){
    os << "[" << vehicle.ID << ", " << vehicle.make << ", " << vehicle.model << ", " << vehicle.year << ", " 
    << vehicle.seats << " seats, " << vehicle.loadCapacity << " kg, " << vehicle.fuelConsumption  << " l/100km, " << vehicle.status << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Vehicle& vehicle) {
    if(is.peek() != '['){
        return is;
    }

    vehicle = Vehicle();

    char ch;
    is >> ch >> vehicle.ID;
    is.ignore(2);
    std::getline(is, vehicle.make, ',');
    is.ignore(1);
    std::getline(is, vehicle.model, ',');
    is.ignore(1);
    is >> vehicle.year;
    is.ignore(2);
    is >> vehicle.seats;
    is.ignore(8);
    is >> vehicle.loadCapacity;
    is.ignore(5);
    is >> vehicle.fuelConsumption;
    is.ignore(10);
    std::getline(is, vehicle.status, ']');
    return is;
}

bool Vehicle::isEmpty() const {
    return make.empty() && model.empty() && year == 0 && seats == 0 && loadCapacity == 0 && fuelConsumption == 0.0 && status.empty();
}
