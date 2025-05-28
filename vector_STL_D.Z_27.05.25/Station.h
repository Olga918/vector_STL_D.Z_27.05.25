#pragma once



#include "train.h"
#include <vector>
#include <string>

class RailwayStation {
private:
    std::vector<Train> schedule;

public:
    void addTrain(const Train& train);
    void showAllTrains() const;
    void findTrainByNumber(int number) const;
    void showTrainsAfterTime(const std::string& time) const;
};