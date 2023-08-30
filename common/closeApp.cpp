#include <bits/stdc++.h>
#include "../common/main.h"
using namespace std;
void close_app_running_in_background()
{
    string appName = "ZenMode";
    shouldStop = true;
    cout << appName << " has been requested to quit." << endl;
}