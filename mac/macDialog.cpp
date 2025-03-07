#include <bits/stdc++.h>
#include "../common/choice.cpp"
using namespace std;

// Version 2
UserChoice get_user_confirmation(const string& question) {
    // Change the buttons list to include three options: "Yes", "No", and "Cancel"
    string script = "display dialog \"" + question + "\" buttons {\"Yes\", \"No\", \"Close\"} default button \"Yes\" with title \"Zen Mode\"";

    // Use osascript to execute the AppleScript and capture the result
    string result = "";
    FILE* pipe = popen(("osascript -e '" + script + "'").c_str(), "r");
    if (!pipe) {
        cout << "Error executing AppleScript." << endl;
        return CHOICE_NO; // Return CHOICE_NO to indicate an error or cancellation
    }

    char buffer[128];
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr)
            result += buffer;
    }
    pclose(pipe);

    // Check if the user clicked "Yes", "No", or "Cancel"
    if (result.find("button returned:Yes") != string::npos) {
        return CHOICE_YES;
    } else if (result.find("button returned:No") != string::npos) {
        return CHOICE_NO;
    } else {
        return CHOICE_CLOSE;
    }
}
