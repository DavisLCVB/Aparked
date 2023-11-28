#include <VehicleTypes.hpp>
VehicleType int_to_VehicleType(int cod){
    switch (cod){
        case 0:
            return VehicleType::CAR;
        case 1:
            return VehicleType::MOTORCYCLE;
        case 2:
            return VehicleType::TRUCK;
        case 3:
            return VehicleType::BUS;
        case 4:
            return VehicleType::TRAILER;
        case 5:
            return VehicleType::OTHER;
        default:
            return VehicleType::OTHER;
    }
}