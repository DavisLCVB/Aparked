#pragma once
#ifndef CUSTOMER_MANAGER_HPP
#define CUSTOMER_MANAGER_HPP

#include <Customer.hpp>
#include <Color.hpp>
#include <VehicleTypes.hpp>
#include <memory>
#include <vector>
#include <string>
#include <FileManager.hpp>

class CustomerManager {
private:
    const static int SIZE_DATA = 8;
    static int customer_count;
    static std::vector<std::unique_ptr<Customer>> customers;
public:
    static void add_customer(std::unique_ptr<Customer> customer);
    static void remove_customer(int index);
    static void save_customers();
    static void load_customers();
};

#endif // CUSTOMER_MANAGER_HPP