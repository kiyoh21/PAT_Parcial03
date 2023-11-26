#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;
using std::pair;

class TimeMap {
public:
    TimeMap();

    void set(string key, string value, int timestamp);

    string get(string key, int timestamp);

private:
    unordered_map<string, vector<pair<int, string>>> data;
};


