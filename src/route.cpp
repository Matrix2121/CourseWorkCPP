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