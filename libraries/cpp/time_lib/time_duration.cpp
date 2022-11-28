#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

using namespace std::chrono;
template <class Rep, class Period = ratio<1>> class duration;

/*
 *
 * Time duration is the difference between the two time-points. Time duration is measured in the number of ticks.
 * If Rep is a floating-point number, the time duration supports fractions of ticks.
 * The most important time durations are predefined in the chrono library:
 *
 *  typedef duration<signed int, nano> nanoseconds;
    typedef duration<signed int, micro> microseconds;
    typedef duration<signed int, milli> milliseconds;
    typedef duration<signed int> seconds;
    typedef duration<signed int, ratio< 60>> minutes;
    typedef duration<signed int, ratio<3600>> hours;
 *
 */

/*
 *  CLOCK
 *  The clock consists of a starting point and a tick. So you can get the current time with the method now.
    std::chrono::system_clock: System time, which you can synchronize with the external clock.
    std::chrono::steady_clock: Clock, which can not be adjusted.
    std::chrono::high_resolution_clock: System time with the greatest accuracy.
    std::chrono::system_clock will refer typically to the 1.1.1970.
     You can not adjust std::steady_clock forward or backward in opposite to two other clocks.
     The methods to_time_t and from_time_t can be used to convert between std::chrono::system_clock and std::time_t objects.
 *
 */


int main()
{
    typedef std::chrono::duration<long long, std::ratio<1>> MySecondTick;
    MySecondTick aSecond(1);

    milliseconds milli(aSecond);
    std::cout << milli.count() << " ms\n";        // 1000 milli

    seconds seconds(aSecond);
    std::cout << seconds.count() << " sec\n";         // 1 sec

    minutes minutes(duration_cast<minutes>(aSecond));
    std::cout << minutes.count() << " min\n";         // 0 min

    typedef std::chrono::duration<double, std::ratio<2700>> MyLessonTick;
    MyLessonTick myLesson(aSecond);
    std::cout << myLesson.count() << " less\n";       // 0.00037037 less

    return 0;
}
