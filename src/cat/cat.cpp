#include <iostream>
#include <fstream>
#include <string>

std::string ReadLine() {
    std::string s;
    getline(std::cin, s);
    return s;
}

std::string HookFlag(const std::string& query) {
    std::string flag;
    for (int i = 0; i < query.length(); i++) {
        if (query[i] == '-') {
            flag = query[i + 1];
            break;
        }
    }
    return flag;
}

std::string ParseQuery(const std::string& query) {
    std::string text = query;
    const char delims = '/';
    std::string::size_type pos{};
    pos = text.find_first_of(delims, pos);
    text.erase(0, pos);
    return text;
}

void PrintFile(std::ifstream& file) {
    std::string line;
    while (!file.eof()) {
      getline (file, line);
      std::cout << line << std::endl;
    }
}

int main() {
    std::string query = ReadLine();
    std::string flag = HookFlag(query);
    std::string directory = ParseQuery(query);
    std::string line;
    std::ifstream file;
    file.open(directory);

    if (file) {
        std::cout << "Flag - " << flag << std::endl;
        std::cout << "Directory - " << directory << std::endl;
        PrintFile(file);
        file.close();
        return 0;
    }
    std::cout << "File not open" << std::endl;
}