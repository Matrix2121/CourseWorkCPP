#include "regex.h"

bool Regex::IDRegex(std::string str){
    std::regex IDRegex(R"(\b\d+\b)"); 

    if (std::regex_match(str, IDRegex)) {
        return 1;
    } else {
        return 0;
    }
}

bool Regex::yearRegex(std::string str){
    std::regex yearRegex(R"(\b(188[6-9]|189[0-9]|19[0-9]{2}|200[0-9]|201[0-9]|202[0-4])\b)");

    if (std::regex_match(str, yearRegex)) {
        return 1;
    } else {
        return 0;
    }
}

bool Regex::seatsRegex(std::string str){
    std::regex seatsRegex(R"(\b(?:[1-9]|[1-9][0-9]|100)\b)");

    if (std::regex_match(str, seatsRegex)) {
        return 1;
    } else {
        return 0;
    }
}

bool Regex::loadCapacityRegex(std::string str){
    std::regex loadCapacityRegex(R"(\b(?:[1-9][0-9]{0,3}|[1-4][0-9]{4}|50000)\b)");

    if (std::regex_match(str, loadCapacityRegex)) {
        return 1;
    } else {
        return 0;
    }
}

bool Regex::fuelConsumptionRegex(std::string str){
    std::regex fuelConsumptionRegex(R"(\b\d{1,2}(\.\d+)?|100\b)");

    if (std::regex_match(str, fuelConsumptionRegex)) {
        return 1;
    } else {
        return 0;
    }
}

bool Regex::lengthRegex(std::string str){
    std::regex lengthRegex(R"(\b(?:[1-9][0-9]{0,3}|10000)(?:\.\d+)?\b)");

    if (std::regex_match(str, lengthRegex)) {
        return 1;
    } else {
        return 0;
    }
}

bool Regex::repetitionsRegex(std::string str){
    std::regex repetitionsRegex(R"(\b(?:[1-9]|[1-9][0-9]{1,2}|1000)\b)");

    if (std::regex_match(str, repetitionsRegex)) {
        return 1;
    } else {
        return 0;
    }
}