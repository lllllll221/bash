#include <iostream>
#include <fstream>
#include <string>

std::string ReadLine() {
    std::string s;
    getline(std::cin, s);
    return s;
}

void PrintFile(std::ifstream& file) {
    std::string line;
    while (!file.eof()) {
      getline (file, line);
      std::cout << line << std::endl;
    }
}

int main() {
    std::ifstream file;
    std::string directory = ReadLine();
    file.open(directory);
    if (file) {
        PrintFile(file);
        return 0;
    }
    std::cout << "File not open" << std::endl;
}