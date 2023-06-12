#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <regex>
#include <ctime>
#include <chrono>

using namespace std;

class Utility {
public:
    static vector<string> split(string str, char delimiter) {
        vector<string> tokens;
        char delimiterStr[] = {delimiter, '\0'};  // Convert delimiter to C-style string

        char* token = strtok(&str[0], delimiterStr);

        while (token != nullptr) {
            tokens.emplace_back(token);
            token = strtok(nullptr, delimiterStr);
        }

        return tokens;
    }

    static string toLowercase(string str)
    {
        string result = str;
        for (char& c : result)
        {
            c = tolower(c);
        }
        return result;
    }

    static bool validareDoarCifre(string str) {
        for (char ch : str) {
            if (!isdigit(ch)) {
                return false;
            }
        }
        return true;
    }

    static bool validareEmail(string email) {
        regex pattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");

        return regex_match(email, pattern);
    }

    static bool validareDataCalendaristica(string data) {
        if (data.length() != 10) {
            return false;
        }

        if (data[2] != '/' || data[5] != '/') {
            return false;
        }

        string ziuaStr = data.substr(0, 2);
        string lunaStr = data.substr(3, 2);
        string anulStr = data.substr(6, 4);

        int ziua = 0, luna = 0, anul = 0;

        ziua = stoi(ziuaStr);
        luna = stoi(lunaStr);
        anul = stoi(anulStr);

        if (ziua < 1 || ziua > 31 || luna < 1 || luna > 12 || anul < 0) {
            return false;
        }

        bool februarie = (luna == 2);
        bool numarZileCorect = (ziua <= 28 + februarie + (luna + luna / 8) % 2);

        return numarZileCorect;
    }
};

#endif