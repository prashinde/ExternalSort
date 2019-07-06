#include "ExternalSort.hpp"
#include "Collection.hpp"
#include <iostream>

Memory memory;

void ExternalSort::sort(std::istream& input, std::ostream& output) {
    // TODO: IMPLEMENT YOUR ALGORITHM.
    // output << "Implement Me!" << std::endl;
    Collection collections;
    memory.init(memory_limit);
    while(1) {
        std::string key;
        if(getline(input, key, ' ')) {
            std::string value;
            getline(input, value);
            //std::cout << key << " " << value << std::endl;
            int res = collections.insert(key, value);
            if(res != 0) {
                collections.sort();
                collections.write();
                collections.insert(key, value);
            }
        } else {
            collections.sort();
            collections.write();
            break;
        }
    }
    collections.KWayMerge();
}
