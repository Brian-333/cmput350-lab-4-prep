#include <cstddef>  // size_t
#include <random>
#include <iostream>
#include <list>
#include <vector>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    // test here...
    // --- List ---
    std::list<uint64_t> random_list = std::list<uint64_t>();
    std::mt19937_64 rng(0);
    Timer timer = Timer();
    for (size_t i = 0; i < SIZE; ++i) {
        random_list.push_back(rng());
    }
    uint64_t time_taken = timer.glance<Timer::Micros>();
    std::cout << "Time taken to push_back " << SIZE << " elements to list: " << time_taken << " us" << "\n";
    
    // --- Vector (reserved) ---
    rng.seed(0);
    std::vector<uint64_t> random_vector_reserved = std::vector<uint64_t>();
    random_vector_reserved.reserve(SIZE);
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        random_vector_reserved.push_back(rng());
    }
    time_taken = timer.glance<Timer::Micros>();
    std::cout << "Time taken to push_back " << SIZE << " elements to vector (reserved): " << time_taken << " us" << "\n";
    
    // --- Vector (unreserved) ---
    rng.seed(0);
    std::vector<uint64_t> random_vector_unreserved = std::vector<uint64_t>();
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        random_vector_unreserved.push_back(rng());
    }
    time_taken = timer.glance<Timer::Micros>();
    std::cout << "Time taken to push_back " << SIZE << " elements to vector (unreserved): " << time_taken << " us" << "\n";

    // --- Sum List ---
    uint64_t list_sum = 0;
    timer.restart();
    for (auto num : random_list) {
        list_sum += num;
    }
    time_taken = timer.glance<Timer::Micros>();
    std::cout << "Time taken to sum " << SIZE << " elements from list: " << time_taken << " us" << "\n";
    std::cout << "List sum: " << list_sum << "\n";

    // --- Sum Vector (reserved) ---
    uint64_t vector_reserved_sum = 0;
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        vector_reserved_sum += random_vector_reserved[i];
    }
    time_taken = timer.glance<Timer::Micros>();
    std::cout << "Time taken to sum " << SIZE << " elements from vector (reserved): " << time_taken << " us" << "\n";
    std::cout << "Vector reserved sum: " << vector_reserved_sum << "\n";

    // --- Sum Vector (unreserved) ---
    uint64_t vector_unreserved_sum = 0;
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        vector_unreserved_sum += random_vector_unreserved[i];
    }
    time_taken = timer.glance<Timer::Micros>();
    std::cout << "Time taken to sum " << SIZE << " elements from vector (unreserved): " << time_taken << " us" << "\n";
    std::cout << "Vector unreserved sum: " << vector_unreserved_sum << "\n";

    return 0;
}
