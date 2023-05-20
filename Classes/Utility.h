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
    vector<string> split(string str, char delimiter) {
        vector<string> tokens;
        char* token = strtok(&str[0], &delimiter);

        while (token != NULL) {
            tokens.push_back(string(token));
            token = strtok(NULL, &delimiter);
        }

        return tokens;
    }
};

#endif