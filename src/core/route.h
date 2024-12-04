#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iterator>

class Route{
    private:
        static int counter;
        int ID;
        mutable std::vector<std::string> connectingPoints;
        double length;
        int repetitions;
        // int vehiclesOnRoute;

    public:
        Route();
        Route(std::vector<std::string>, double, int);

        static void setCounter(int);
        static int getCounter();

        void IDDeclaration();

        void setID(int);
        int getID() const;

        void addConnectingPoints(std::string);
        void clearConnectionPoints();
        std::vector<std::string> getConnectingPoints();

        void setLength(double);
        double getLength();

        void setRepetitions(int);
        int getRepetitions();

        // void addVehicleToRoute();
        // void removeVehicleFromRoute();
        // int getVehiclesOnRoute();

        bool operator==(Route&) const;
        bool operator<(const Route&) const;

        friend std::ostream& operator<<(std::ostream&, const Route&);
        friend std::istream& operator>>(std::istream&, Route&);

        bool isEmpty() const;
};