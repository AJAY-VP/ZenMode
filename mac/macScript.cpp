#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include "macDialog.cpp"
#include "../common/main.h"
#include "../common/closeApp.cpp"
#include <filesystem>
using namespace std;
void call_MAC_Script()
{
    cout << "Running on macOS" << endl;
    // Version 1
    // if (get_user_confirmation("Do you want to go to Zen mode?")) {
    //     std::cout << "User chose 'Yes'." << std::endl;
    //     // Use AppleScript to send the keyboard shortcut "Cmd + Ctrl + Q"
    //     std::string applescriptCode = "tell application \"System Events\" to keystroke \"q\" using {control down, command down}";
    //     // Execute the AppleScript code using osascript
    //     std::string osascriptCommand = "osascript -e '" + applescriptCode + "'";
    //     system(osascriptCommand.c_str());
    //     system("pmset sleepnow");
    //     std::cout << "pmset sleepnow executed successfully." << std::endl;
    // } else {
    //     std::cout << "User chose 'No'." << std::endl;
    // }
    // Version 2
    UserChoice choice = get_user_confirmation("Do you want to go to Zen mode?");

    switch (choice){
    case CHOICE_YES:{
        std::cout << "User chose 'Yes'." << std::endl;
        // Perform the action for 'Yes'
        // Use AppleScript to send the keyboard shortcut "Cmd + Ctrl + Q"
        // std::string applescriptCode = "tell application \"System Events\" to keystroke \"q\" using {control down, command down}";
        // Execute the AppleScript code using osascript
        // std::string osascriptCommand = "osascript -e '" + applescriptCode + "'";
        // system(osascriptCommand.c_str());
        system("pmset sleepnow");
        std::cout << "pmset sleepnow executed successfully." << std::endl;
        break;
    }
    case CHOICE_NO:{
        std::cout << "User chose 'No'." << std::endl;
        // Perform the action for 'No'
        break;
    }
    case CHOICE_SHUTDOWN:{
        std::cout << "User chose 'ShutDown'." << std::endl;
        // Perform the action for 'Cancel'
        close_app_running_in_background();
        break;
    }
    }
}