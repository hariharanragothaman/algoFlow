//
// Created by hariharanragothaman on 4/22/25.
//
#include <iostream>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>
using namespace std;

using Clock = std::chrono::steady_clock;
using ms = std::chrono::milliseconds;

inline auto make_log_file()
{
    FILE* f = fopen("timelog.txt", "w");
    if (!f) throw std::runtime_error("Cannot open timelog.txt");
    return unique_ptr<FILE, decltype(&std::fclose)>(f, &std::fclose);
}

class ScopedTimer
{
    Clock::time_point start_;
    std::string label_;
    static unique_ptr<FILE, decltype(&std::fclose)> log_;

public:
    explicit ScopedTimer(string lbl) : start_{Clock::now()}, label_{std::move(lbl)}
    {
        if (!log_)
            log_ = make_log_file();
    }

    // Make it non-copyable, but movable
    ScopedTimer(const ScopedTimer&) = delete;
    ScopedTimer& operator=(const ScopedTimer&) = delete;

    ScopedTimer(ScopedTimer&&) = default;
    ScopedTimer& operator=(ScopedTimer&&) = default;

    ~ScopedTimer()
    {
        auto end = Clock::now();
        auto diff = chrono::duration_cast<ms>(end - start_).count();
        fprintf(log_.get(), "%-20s took %lld ms \n", label_.c_str(), static_cast<long long>(diff));
    }

};
std::unique_ptr<FILE, decltype(&std::fclose)> ScopedTimer::log_{nullptr, &std::fclose};

int main()
{
    const int N = 1'000'000;
    vector<int> A(N);
    std::iota(A.begin(), A.end(), 0);

    ScopedTimer t{"shuffle"};

    random_shuffle(A.begin(), A.end());
}