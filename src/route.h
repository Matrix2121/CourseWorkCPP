#pragma once
#include <string>
#include <vector>

class Route{
    private:
        int ID;
        std::vector<std::string> connectingPoints;
        double length;
        int repetitions;

    public:
        Route(int, std::vector<std::string>, double, int);

        void setId(int);
        int getId();

        void setConnectingPoints(std::vector<std::string>);
        std::vector<std::string> getConnectingPoints();

        void setLength(double);
        double getLength();

        void setRepetitions(int);
        int getRepetitions();
};