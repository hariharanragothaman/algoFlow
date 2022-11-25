#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;


class Sleeper
{
public:
    Sleeper(int& i_):i{i_}{};
    void operator() (int k)
    {
        for (unsigned int j= 0; j <= 5; ++j)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            i += k;
        }
        std::cout << std::this_thread::get_id() << std::endl;
    }
private:
    int& i;
};

int main()
{

    std::cout << std::endl;

    int valSleeper= 1000;

    // Pass an argument here for sleep time variation
    std::thread t(Sleeper(valSleeper), 5);

    // detach thread after each execution to run independently
    t.join();
    std::cout << "valSleeper = " << valSleeper << std::endl;

    std::cout << std::endl;

}
