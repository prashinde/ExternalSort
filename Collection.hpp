#include<vector>
#include <iostream>
#include <queue>
#include <utility>

#include "KeyValue.hpp"
#include "Memory.hpp"

class Comp {
public:
    bool operator()(std::pair<KeyValue, int> &first, std::pair<KeyValue, int> &second) {
        return second.first < first.first;
    }
};

class Collection {
public:
    void sort();
    void write();
    void KWayMerge();
    int insert(const std::string &key, const std::string &value);
    void print() {
        std::cout << "*******************************" << std::endl;
        for(auto kv:collection) {
            std::cout << kv.getKey() << " " << kv.getValue() << std::endl;
        }
    }
private:
    int partnum = 0;
    std::priority_queue<std::pair<KeyValue, int>, std::vector<std::pair<KeyValue, int>>, Comp> pq;
    std::vector<KeyValue> collection;
};
