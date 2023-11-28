#include <Customer.hpp>

Customer::Customer(){
    this->vehicle =  std::make_unique<Vehicle>();
    this->parking_space = std::make_unique<ParkingSpace>();
}

void Customer::set_vehicle(Vehicle *vehicle){
    this->vehicle.reset(vehicle);
}

void Customer::set_parking_space(ParkingSpace *parking_space){
    this->parking_space.reset(parking_space);
}

Vehicle *Customer::get_vehicle(){
    return this->vehicle.get();
}

ParkingSpace *Customer::get_parking_space(){
    return this->parking_space.get();
}

std::string Customer::to_string(){
    std::string buffer = "";
    buffer += Person::to_string();
    buffer += this->vehicle->to_string();
    buffer += this->parking_space->to_string();
    return buffer;
}