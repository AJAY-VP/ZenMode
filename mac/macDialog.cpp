#include <bits/stdc++.h>
#include "../common/choice.cpp"
using namespace std;
// Version 1
// bool get_user_confirmation(const string& question) {
//     string script = "display dialog \"" + question + "\" buttons {\"Yes\", \"No\"} default button \"Yes\" with title \"Zen Mode\"";

//     // Use osascript to execute the AppleScript and capture the result
//     string result = "";
//     FILE* pipe = popen(("osascript -e '" + script + "'").c_str(), "r");
//     if (!pipe) {
//         cout << "Error executing AppleScript." << endl;
//         return false;
//     }

//     char buffer[128];
//     while (!feof(pipe)) {
//         if (fgets(buffer, 128, pipe) != nullptr)
//             result += buffer;
//     }
//     pclose(pipe);

//     // Check if the user clicked "Yes" or "No"
//     return (result.find("button returned:Yes") != string::npos);
// }

// Version 2
UserChoice get_user_confirmation(const std::string& question) {
    // Change the buttons list to include three options: "Yes", "No", and "Cancel"
    std::string script = "display dialog \"" + question + "\" buttons {\"Yes\", \"No\", \"Shutdown\"} default button \"Yes\" with title \"Zen Mode\"";

    // Use osascript to execute the AppleScript and capture the result
    std::string result = "";
    FILE* pipe = popen(("osascript -e '" + script + "'").c_str(), "r");
    if (!pipe) {
        std::cout << "Error executing AppleScript." << std::endl;
        return CHOICE_NO; // Return CHOICE_NO to indicate an error or cancellation
    }

    char buffer[128];
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr)
            result += buffer;
    }
    pclose(pipe);

    // Check if the user clicked "Yes", "No", or "Cancel"
    if (result.find("button returned:Yes") != std::string::npos) {
        return CHOICE_YES;
    } else if (result.find("button returned:No") != std::string::npos) {
        return CHOICE_NO;
    } else {
        return CHOICE_SHUTDOWN;
    }
}
