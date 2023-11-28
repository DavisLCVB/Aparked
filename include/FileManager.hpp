#pragma once
#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

class FileManager {
private:
    static const std::string dir;
public:
    static void write(std::string file_name, std::string data);
    static std::vector<std::string> read(std::string file_name);
};

#endif // FILE_MANAGER_HPP