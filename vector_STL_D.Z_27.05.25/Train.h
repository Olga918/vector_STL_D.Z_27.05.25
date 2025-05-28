#pragma once



#include <string>

class Train {
private:
    int number;
    std::string departureTime;
    std::string destination;

public:
    Train(int num, const std::string& time, const std::string& dest);

    int getNumber() const;
    std::string getTime() const;
    std::string getDestination() const;

    void print() const;
};
