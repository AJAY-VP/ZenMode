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
         bool screenLocked = osAction->isScreenLocked();
         while(!shouldStop){
            // this_thread::sleep_for(chrono::milliseconds(20 * 60 * 1000));
            screenLocked = osAction->isScreenLocked();
            cout<<"Running : "<<screenLocked<<endl;
            if(!screenLocked){
                this_thread::sleep_for(chrono::seconds(10));
                screenLocked = osAction->isScreenLocked();
                if(!screenLocked){
                    osAction->execute();
                    this_thread::sleep_for(chrono::seconds(1));
                }
            } else{
                this_thread::sleep_for(chrono::seconds(5));
            }
        }
    }
    delete osAction;
    return 0;
}
