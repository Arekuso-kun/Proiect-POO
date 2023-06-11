#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Utility {
public:
    static vector<string> split(string str, char delimiter) {
        vector<string> tokens;
        char* token = strtok(&str[0], &delimiter);

        while (token != nullptr) {
            tokens.emplace_back(token);
            token = strtok(nullptr, &delimiter);
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

    static string encryptString(string input) {
        string encryptedString;

        for (char ch : input) {
            ch = 126 - (ch - 33) + 41;

//            ch = 167 - (ch - 33);

            encryptedString += ch;
        }

        return encryptedString;
    }

    static string decryptString(string input) {
        string decryptedString;

        for (char ch : input) {
            ch -= 41;
            ch = 126 - (ch - 33);

//            ch = 126 - (ch - 74);

            decryptedString += ch;
        }

        return decryptedString;
    }
};

#endif