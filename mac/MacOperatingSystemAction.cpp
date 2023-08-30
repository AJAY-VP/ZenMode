#include <bits/stdc++.h>
#include "macDialog.cpp"
#include "../common/closeApp.cpp"
#include "../common/OsInterface.cpp"
using namespace std;

class MacOperatingSystemAction : public OperatingSystemAction
{
public:
    void execute()
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
};
