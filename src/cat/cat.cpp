#include <iostream>
#include <fstream>
#include <set>
#include <string>

struct Cat {
    std::string flag;
    std::string directory;
};

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

/*
Обработка флагов: b, e, n, s, t;
    -b - нумеровать только непустые строки;
    -e - показывать символ $ в конце каждой строки;
    -n - нумеровать все строки;
    -s - удалять пустые повторяющиеся строки;
    -t - отображать табуляции в виде ^I;
*/
void BFlag(std::ifstream& file) {
    std::string line;
    int i = 1;
    while (!file.eof()) {
        getline (file, line);
        if (!line.empty()) {
            std::cout << i << " " << line << std::endl; 
        }
        i++;
    }
}

void EFlag(std::ifstream& file) {
    std::string line;
    while (!file.eof()) {
        getline (file, line);
        std::cout << line << "$" << std::endl;
    }
}

void NFlag(std::ifstream& file) {
    std::string line;
    int i = 1;
    while (!file.eof()) {
        getline (file, line);
        std::cout << i << " " << line << std::endl;
        i++;
    }
}

void SFlag(std::ifstream& file) {
    std::set<std::string> lines;
    std::string line;
    while (!file.eof()) {
        getline (file, line);
        if (!line.empty() && !lines.count(line)) {
            std::cout << line << std::endl;
            lines.insert(line);  
        }
    }
}

void TFlag(std::ifstream& file) {
    std::string line;
    while (!file.eof()) {
        int tab = 0;
        getline (file, line);
        for (char c : line) {
            if (c = ' ') {
                tab++;
            }
        }
        if (tab > 1) {
            std::cout << "^I" << line << std::endl;
            continue;
        }
        std::cout << line << std::endl;
    }
}

void ChooseFlag(const std::string& flag, std::ifstream& file) {
    if (flag == "b") {
        BFlag(file);
    } else if (flag == "e") {
        EFlag(file);
    } else if (flag == "n") {
        NFlag(file);
    } else if (flag == "s") {
        SFlag(file);
    } else if (flag == "t") {
        TFlag(file);
    } else {
        PrintFile(file);
    }
}

int main() {
    std::string query = ReadLine();
    Cat cat = {HookFlag(query), ParseQuery(query)};
    std::ifstream file;
    file.open(cat.directory);

    if (file) {
        std::cout << "Flag - " << cat.flag << std::endl;
        std::cout << "Directory - " << cat.directory << std::endl;
        ChooseFlag(cat.flag, file);
        file.close();
        return 0;
    }
    std::cout << "File not open" << std::endl;
}