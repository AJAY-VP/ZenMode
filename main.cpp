#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include "./common/findOS.cpp"
using namespace std;
bool shouldStop = false;
int main()
{
    OperatingSystemAction* osAction =  NULL;
    osAction = findOperatingSystem();
    if(osAction){
         while(!shouldStop)
        {
            osAction->execute();
            // this_thread::sleep_for(chrono::milliseconds(20 * 60 * 1000));
            this_thread::sleep_for(chrono::milliseconds(20000));
        }
    }
    delete osAction;
    return 0;
}
