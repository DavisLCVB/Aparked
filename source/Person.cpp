#include <Person.hpp>

Person::Person(std::string name, int age, bool member) {
    this->name = name;
    this->age = age;
    this->member = member;
}

void Person::set_name(std::string name) {
    this->name = name;
}

void Person::set_age(int age) {
    this->age = age;
}

void Person::set_member(bool member) {
    this->member = member;
}

std::string Person::get_name() {
    return this->name;
}

int Person::get_age() {
    return this->age;
}

bool Person::is_member() {
    return this->member;
}

std::string Person::to_string(){
    std::string buffer = "";
    buffer += this->name + "\n";
    buffer += std::to_string(this->age) + "\n";
    buffer += std::to_string(this->member) + "\n";
    return buffer;
}