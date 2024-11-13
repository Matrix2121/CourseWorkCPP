#include <sstream>
#include <iomanip>
#include "route.h"

Route::Route(){}

Route::Route(int ID, std::vector<std::string> connectingPoints, double length, int repetitions){
    this->ID = ID;
    this->connectingPoints = connectingPoints;
    this->length = length;
    this->repetitions  = repetitions;
}

void Route::setId(int id){
    this->ID = id;    
}

int Route::getId(){
    return this->ID;
}

void Route::setConnectingPoints(std::vector<std::string>  connectingPoints){
    this->connectingPoints = connectingPoints;
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

std::string Route::toString(){
    std::stringstream ss;
    ss << std::fixed  << std::setprecision(2);
    ss << this->ID << ", ";

    for(std::string& s : this->connectingPoints){
        ss << s << ", ";
    }

    ss << length << ", " << repetitions;

    return ss.str();
}

bool Route::compare(Route r1){
    if (this->ID != r1.ID){
        return 0;
    } else if (this->connectingPoints != r1.connectingPoints){
        return 0;
    } else if (this->length != r1.length){
        return 0;
    } else if (this->repetitions != r1.repetitions){
        return 0;
    } else {
        return 1;
    } 
}