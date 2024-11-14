#pragma once
#include <string>
#include <vector>

class Route{
    private:
        static int counter;
        int ID;
        mutable std::vector<std::string> connectingPoints;
        double length;
        int repetitions;

    public:
        Route();
        Route(std::vector<std::string>, double, int);

        void setId(int);
        int getId();

        void setConnectingPoints(std::vector<std::string>);
        std::vector<std::string> getConnectingPoints();

        void setLength(double);
        double getLength();

        void setRepetitions(int);
        int getRepetitions();

        bool operator==(Route&) const;

        friend std::ostream& operator<<(std::ostream&, const Route&);
};