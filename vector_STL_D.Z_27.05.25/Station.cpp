#include "station.h"
#include <iostream>

void RailwayStation::addTrain(const Train& train) {
    schedule.push_back(train);
}

void RailwayStation::showAllTrains() const {
    if (schedule.empty()) {
        std::cout << "There are no trains in the schedule.\n";
        return;
    }
    for (const auto& train : schedule) {
        train.print();
    }
}

void RailwayStation::findTrainByNumber(int number) const {
    for (const auto& train : schedule) {
        if (train.getNumber() == number) {
            std::cout << "Train found:\n";
            train.print();
            return;
        }
    }
    std::cout << "Train with number " << number << " Not found.\n";
}

void RailwayStation::showTrainsAfterTime(const std::string& time) const {
    std::cout << "Trains after " << time << ":\n";
    for (const auto& train : schedule) {
        if (train.getTime() > time) {
            train.print();
        }
    }
}