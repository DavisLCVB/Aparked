#pragma once
#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <string>

class Person {
protected:
    std::string name;
    int age;
    bool member;
public:
    Person() = default;
    Person(std::string name, int age, bool member);
    void set_name(std::string name);
    void set_age(int edad);
    void set_member(bool member);
    std::string get_name();
    int get_age();
    bool is_member();
    std::string to_string();
};

#endif // PERSONA_HPP