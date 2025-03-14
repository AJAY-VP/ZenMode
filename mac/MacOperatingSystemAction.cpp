#include <bits/stdc++.h>
#include "macDialog.cpp"
#include "../common/closeApp.cpp"
#include "../common/OsInterface.cpp"
using namespace std;

class MacOperatingSystemAction : public OperatingSystemAction
{
public:
    void execute() override
    {
        cout << "Running on macOS" << endl;
        UserChoice choice = get_user_confirmation("Do you want to go to Zen mode?");

        switch (choice)
        {
        case CHOICE_YES:
        {
            cout << "User chose 'Yes'." << endl;
            system("pmset sleepnow");
            cout << "pmset sleepnow executed successfully." << endl;
            break;
        }
        case CHOICE_NO:
        {
            cout << "User chose 'No'." << endl;
            // Perform the action for 'No'
            break;
        }
        case CHOICE_CLOSE:
        {
            cout << "User chose 'ShutDown'." << endl;
            // Perform the action for 'Cancel'
            close_app_running_in_background();
            break;
        }
        }
    }
    bool isScreenLocked() override{
        FILE* pipe = popen("ioreg -n Root -d1 | grep 'CGSSessionScreenIsLocked'", "r");
        if (!pipe) return false;

        char buffer[128];
        string result = "";
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
        int status = pclose(pipe);

        // cout << "Command output: " << result << endl; // Debugging line
        // cout << "Status: " << status << endl;
        bool res = result.find("Yes") != string::npos;
        return res;
    }
    pair<string,string> licensePopup() override{
        pair<string, string> licenseInfo = get_license_info();
        return licenseInfo;
    }
};
