#include "Ejercicio03.h"

TimeMap::TimeMap() {
}

void TimeMap::set(string key, string value, int timestamp) {
    data[key].emplace_back(timestamp, value);
}

string TimeMap::get(string key, int timestamp) {
    if (data.find(key) == data.end()) {
        return "";
    }

    const auto& values = data[key];
    int low = 0, high = values.size() - 1;

    // Búsqueda binaria para encontrar el valor con el timestamp más cercano y menor o igual
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (values[mid].first <= timestamp) {
            if (mid == values.size() - 1 || values[mid + 1].first > timestamp) {
                return values[mid].second;
            }
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return "";
}
