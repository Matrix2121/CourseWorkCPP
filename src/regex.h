#include <regex>

class Regex{
    public:
        static bool IDRegex(std::string);

        static bool yearRegex(std::string);
        static bool seatsRegex(std::string);
        static bool loadCapacityRegex(std::string);
        static bool fuelConsumptionRegex(std::string);

        static bool lengthRegex(std::string);
        static bool repetitionsRegex(std::string);
};