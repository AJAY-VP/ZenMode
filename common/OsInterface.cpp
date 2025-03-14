#pragma once
#include <bits/stdc++.h>
using namespace std;
class OperatingSystemAction {
public:
    virtual ~OperatingSystemAction() {}
    virtual void execute() = 0;
    virtual bool isScreenLocked() = 0;
    virtual pair<string,string> licensePopup() = 0;
};