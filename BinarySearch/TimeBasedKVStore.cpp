// LC 981
// Design a time-based key-value data structure that can store multiple values for the same key 
// at different time stamps and retrieve the key's value at a certain timestamp.

// Implement the TimeMap class:

// TimeMap() Initializes the object of the data structure.
// 
// void set(String key, String value, int timestamp) 
// Stores the key key with the value value at the given time timestamp.
// 
// String get(String key, int timestamp) 
// Returns a value such that set was called previously, with timestamp_prev <= timestamp. 
// If there are multiple such values, it returns the value associated with the largest timestamp_prev. 
// If there are no values, it returns "".

#include <iterator>
#include <string>
#include <map>
#include <unordered_map>

class TimeMap {
public:
    TimeMap() = default;

    void set(std::string key, std::string value, int timestamp) {
        _tsMap[key].emplace(timestamp, value);
    }

    std::string get(std::string key, int timestamp) {
        if (_tsMap.find(key) == _tsMap.end()) {
            return {};
        }

        auto iter = _tsMap[key].upper_bound(timestamp);
        if (iter == _tsMap[key].begin()) {
            return {};
        }

        return std::prev(iter)->second;
    }

private:
    std::unordered_map<std::string, std::map<int, std::string>> _tsMap;
};