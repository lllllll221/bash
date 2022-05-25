#include <iostream>
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
    std::string 
}

int main() {
    const std::string query = ReadLine();
    const std::string flag = HookFlag(query);

    std::cout << flag << std::endl;
}