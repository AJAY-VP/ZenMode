#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include "./common/findOS.cpp"
using namespace std;
bool shouldStop = false;
int main()
{
    while(!shouldStop)
    {
        findOperatingSystem();
        std::this_thread::sleep_for(std::chrono::milliseconds(20 * 60 * 1000));
        // std::this_thread::sleep_for(std::chrono::milliseconds(20000));
    }
    return 0;
}
