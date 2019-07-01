#include "ExternalSort.hpp"
#include <iostream>
#include <string>

int main() {
    int64_t memory_limit = 0;
    // Get the memory limit from STDIN.
    std::string line;
    std::getline(std::cin, line);
    memory_limit = std::stoll(line);

    ExternalSort externalSort(memory_limit);
    externalSort.sort(std::cin, std::cout);
    return 0;
}
