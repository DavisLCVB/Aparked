#pragma once
#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <Person.hpp>
#include <Vehicle.hpp>
#include <ParkingSpace.hpp>
#include <memory>

class Customer : public Person {
    private:
    std::unique_ptr<Vehicle> vehicle;
    std::unique_ptr<ParkingSpace> parking_space;
    public:
    Customer();
    void set_vehicle(Vehicle *vehicle);
    void set_parking_space(ParkingSpace *parking_space);
    Vehicle *get_vehicle();
    ParkingSpace *get_parking_space();
    std::string to_string();
};

#endif // CLIENTE_HPP