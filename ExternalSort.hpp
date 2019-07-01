#include <iostream>
#include <sstream>

class ExternalSort {
    private:
        // The maximum amount of memory the algorithm should use in bytes.
        int64_t memory_limit;
    public:
        ExternalSort(int64_t _memory_limit): memory_limit(_memory_limit) {}
        ~ExternalSort() {}

        // This function reads all the key/value pairs from the given 'input'
        // stream, performs the external sort, and writes the sorted key/value
        // pairs to the 'output' stream.
        void sort(std::istream& input, std::ostream& output);
};
