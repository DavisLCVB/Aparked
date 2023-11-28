#include <FileManager.hpp>

const std::string FileManager::dir = "files\\";

void FileManager::write(std::string file_name, std::string data) {
    std::ofstream file;
    file.open(dir + file_name);
    file << data;
    file.close();
}

std::vector<std::string> FileManager::read(std::string file_name) {
    std::ifstream file(dir + file_name);
    std::vector<std::string> lines;
    if (!file.is_open()) {
        return lines;
    }
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}
