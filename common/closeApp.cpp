#include <bits/stdc++.h>
#include "../common/main.h"
using namespace std;
void close_app_running_in_background()
{
    std::string appName = "ZenMode";
    shouldStop = true;
    std::cout << appName << " has been requested to quit." << std::endl;
}