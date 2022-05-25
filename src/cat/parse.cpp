#include <iostream>
#include <string>

std::string ReadLine() {
    std::string s;
    getline(std::cin, s);
    return s;
}

std::string ParseQuery(const std::string& query) {
    std::string text = query;
    const char delims = '/';
    std::string::size_type pos{};
    pos = text.find_first_of(delims, pos);
    text.erase(0, pos);
    return text;
}

int main() {
    const std::string query = ReadLine();
    const std::string text = ParseQuery(query);

    std::cout << text << std::endl;
}
