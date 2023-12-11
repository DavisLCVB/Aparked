#include <CustomerManager.hpp>

int CustomerManager::customer_count = 0;
std::vector<std::unique_ptr<Customer>> CustomerManager::customers;

void CustomerManager::add_customer(std::unique_ptr<Customer> customer) {
    CustomerManager::customers.push_back(std::move(customer));
    CustomerManager::customer_count = static_cast<int>(CustomerManager::customers.size());
}

void CustomerManager::remove_customer(int index) {
    CustomerManager::customers.erase(CustomerManager::customers.begin() + index);
    CustomerManager::customer_count = static_cast<int>(CustomerManager::customers.size());
}

void CustomerManager::save_customers() {
    FileManager::write("customers.txt", std::to_string(CustomerManager::customer_count) + "\n");
    for (auto &customer : customers) {
        FileManager::write("customers.txt", customer->to_string() + "\n");
    }
}

void CustomerManager::load_customers() {
    std::vector<std::string> lines = FileManager::read("customers.txt");
    if (lines.empty()) {
        printf("No customers found, creating new file...\n");
        save_customers();
        return;
    }
    CustomerManager::customer_count = std::stoi(lines.at(0));
    for (int i = 0; i < CustomerManager::customer_count; i++) {
        std::unique_ptr<Customer> customer = std::make_unique<Customer>();
        customer->set_name(lines.at(i * CustomerManager::SIZE_DATA + 1));
        customer->set_age(std::stoi(lines.at(i * CustomerManager::SIZE_DATA + 2)));
        customer->set_member(std::stoi(lines.at(i * CustomerManager::SIZE_DATA + 3)));
        customer->get_vehicle()->set_plate(lines.at(i * CustomerManager::SIZE_DATA + 4));
        Color _color = static_cast<Color>(std::stoi(lines.at(i * CustomerManager::SIZE_DATA + 5)));
        customer->get_vehicle()->set_color(_color);
        VehicleType _type = static_cast<VehicleType>(std::stoi(lines.at(i * CustomerManager::SIZE_DATA + 6)));
        customer->get_vehicle()->set_type(_type);
        customer->get_parking_space()->set_x(std::stoi(lines.at(i * CustomerManager::SIZE_DATA + 7)));
        customer->get_parking_space()->set_y(std::stoi(lines.at(i * CustomerManager::SIZE_DATA + 8)));
        CustomerManager::add_customer(std::move(customer));
    }
}

void CustomerManager::get_info_customer() {
    
}

int CustomerManager::get_customer_count() {
    return CustomerManager::customer_count;
}

Customer *CustomerManager::get_customer(int index) {
    return CustomerManager::customers.at(index).get();
}