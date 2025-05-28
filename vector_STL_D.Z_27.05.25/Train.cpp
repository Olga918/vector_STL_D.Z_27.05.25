#include "train.h"
#include <iostream>

Train::Train(int num, const std::string& time, const std::string& dest)
    : number(num), departureTime(time), destination(dest) {
}

int Train::getNumber() const {
    return number;
}

std::string Train::getTime() const {
    return departureTime;
}

std::string Train::getDestination() const {
    return destination;
}

void Train::print() const {
    std::cout << "Train " << number
        << ", Time: " << departureTime
        << ", Purpose: " << destination << std::endl;
}