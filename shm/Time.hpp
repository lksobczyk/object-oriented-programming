#pragma once

#include <vector>

class Time {
public:
    Time& operator++();
    size_t GetTimeElpased() const { return _time_elapsed; }

private:
    size_t _time_elapsed;
    std::vector<Observer*> _observers;
};
