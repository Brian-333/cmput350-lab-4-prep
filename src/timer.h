#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <cstdint>

class Timer {
public:
    using Nanos = std::chrono::nanoseconds;
    using Micros = std::chrono::microseconds;
    using Millis = std::chrono::milliseconds;
    using Seconds = std::chrono::seconds;
    using Minutes = std::chrono::minutes;
    using Hours = std::chrono::hours;

    Timer() : start(std::chrono::steady_clock::now()) {}

    void restart() {
        start = std::chrono::steady_clock::now();
    }

    template <typename T>
    std::uint64_t click() {
        auto now = std::chrono::steady_clock::now();
        // Cast the duration to the template type
        auto duration = std::chrono::duration_cast<T>(now - start);
        restart();
        return duration.count();
    }

    template <typename T>
    std::uint64_t glance() const {
        auto now = std::chrono::steady_clock::now();
        // Cast the duration to the template type
        auto duration = std::chrono::duration_cast<T>(now - start);
        return duration.count();
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> start;
};

#endif  // TIMER_H
