#pragma once
#ifndef VEHICLE_TYPES_HPP
#define VEHICLE_TYPES_HPP

enum class VehicleType {
    CAR = 0,
    MOTORCYCLE = 1,
    TRUCK = 2,
    BUS = 3,
    TRAILER = 4,
    OTHER = 5
};

VehicleType int_to_VehicleType(int cod);

#endif // VEHICLE_TYPES_HPP