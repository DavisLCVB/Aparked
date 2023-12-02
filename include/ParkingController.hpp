#pragma once
#ifndef PARKINGCONTROLLER_HPP
#define PARKINGCONTROLLER_HPP

#include <string>
#include <vector>
#include <ControlConsole>
#include <CustomerManager.hpp>

class ParkingController{
private:
    const int X_COORD = 41;
    const int Y_COORD = 2;
    const int PARKING_WIDTH = 36;
    const int PARKING_HEIGHT = 15;
    std::vector<std::vector<std::string>> parking;
    ConsolePrinter<std::string> *printer;
public:
    ParkingController()=default;
    ParkingController(ConsolePrinter<std::string> *printer);
    void init_parking();
    void fill_parking();
    void print_parking();    
};

#endif // PARKINGCONTROLLER_HPP