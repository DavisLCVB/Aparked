#pragma once
#ifndef CUSTOMER_MANAGER_HPP
#define CUSTOMER_MANAGER_HPP

#include <Color.hpp>
#include <Customer.hpp>
#include <FileManager.hpp>
#include <VehicleTypes.hpp>
#include <memory>
#include <string>
#include <vector>

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
    static int get_customer_count();
    static Customer *get_customer(int index);
};

#endif // CUSTOMER_MANAGER_HPP