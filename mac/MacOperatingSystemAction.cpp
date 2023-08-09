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
            std::cout << "User chose 'Yes'." << std::endl;
            system("pmset sleepnow");
            std::cout << "pmset sleepnow executed successfully." << std::endl;
            break;
        }
        case CHOICE_NO:
        {
            std::cout << "User chose 'No'." << std::endl;
            // Perform the action for 'No'
            break;
        }
        case CHOICE_SHUTDOWN:
        {
            std::cout << "User chose 'ShutDown'." << std::endl;
            // Perform the action for 'Cancel'
            close_app_running_in_background();
            break;
        }
        }
    }
};
