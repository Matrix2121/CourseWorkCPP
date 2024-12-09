#include "route.h"

int Route::counter = 1;

Route::Route(){
    this->ID = -1;
    // this->vehiclesOnRoute = 0;
}

Route::Route(std::vector<std::string> connectingPoints, double length, int repetitions){
    this->ID = counter;
    this->connectingPoints = connectingPoints;
    this->length = length;
    this->repetitions  = repetitions;
    // this->vehiclesOnRoute = 0;
    Route::counter++;
}

void Route::setCounter(int i){
    Route::counter = i;
}

int Route::getCounter(){
    return Route::counter;
}


void Route::IDDeclaration(){
    this->ID = Route::counter;
    Route::counter++;
}

void Route::setID(int id){
    this->ID = id;    
}
int Route::getID() const{
    return this->ID;
}

void Route::addConnectingPoints(std::string s1){
    this->connectingPoints.push_back(s1);
}
void Route::clearConnectionPoints(){
    this->connectingPoints.clear();
}
std::vector<std::string> Route::getConnectingPoints(){
    return this->connectingPoints;
}

void Route::setLength(double length){
    this->length = length; 
}
double Route::getLength(){
    return this->length;
}

void Route::setRepetitions(int repetitions){
    this->repetitions = repetitions; 
}
int Route::getRepetitions(){
    return this->repetitions;
}

// void Route::addVehicleToRoute(){
//     ++vehiclesOnRoute;
// }
// void Route::removeVehicleFromRoute(){
//     --vehiclesOnRoute;
// }
// int Route::getVehiclesOnRoute(){
//     return this->vehiclesOnRoute;
// }

bool Route::operator<(const Route& other) const {
    return this->ID < other.ID;
}

bool Route::operator==(Route& r1) const{
    return this->ID == r1.ID;
}

std::ostream& operator<<(std::ostream& os, const Route& route){
    os << "[" << route.ID << ", {";
    
    if(!route.connectingPoints.empty())
    {
        std::copy(route.connectingPoints.begin(), route.connectingPoints.end()-1, std::ostream_iterator<std::string>(os, ", "));
        os << route.connectingPoints.back();
    }

    os << "}, " << route.length << " km, " << route.repetitions << " repetitions]"/* << route.vehiclesOnRoute << " vehicle(s)]"*/;

    return os;
}

std::istream& operator>>(std::istream& is, Route& route) {
    if(is.peek() != '['){
        return is;
    }

    route = Route();

    char ch;
    std::string point;
    
    is >> ch >> route.ID;
    is.ignore(3);

    while(true){
        std::getline(is, point, ',');
        if(point.find('}') < point.length()){
            point.pop_back();
            route.addConnectingPoints(point);
            break;
        }
        route.addConnectingPoints(point);
        is.ignore(1);
    }

    is.ignore(1);
    is >> route.length;
    is.ignore(5);
    is >> route.repetitions;
    is.ignore(13);
    // is >> route.vehiclesOnRoute;
    // is.ignore(8);
    return is;
}

bool Route::isEmpty() const{
    return connectingPoints.empty() && length == 0 && repetitions == 0;
}