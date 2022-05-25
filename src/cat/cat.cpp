#include <iostream>
#include <fstream>
#include <string>

std::string ReadLine() {
    std::string s;
    getline(std::cin, s);
    return s;
}
int main() {
    std::string line;
    std::ifstream file;
    file.open(ReadLine());

    if (file) {
        while (!file.eof()) {
          getline (file, line);
          std::cout << line << std::endl;
        }
        file.close();
        return 0;
    }
    std::cout << "File not open" << std::endl;
}