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

pair<string, string> get_license_info() {
    string script =
        "set keyInput to text returned of (display dialog \"Enter your license key:\" "
        "with title \"License Activation\" default answer \"\" with icon note)\n"
        "set emailInput to text returned of (display dialog \"Enter your email address:\" "
        "with title \"License Activation\" default answer \"\" with icon note)\n"
        "return keyInput & \"\\n\" & emailInput";

    string result = "";
    FILE* pipe = popen(("osascript -e '" + script + "'").c_str(), "r");
    if (!pipe) {
        cerr << "Error executing AppleScript." << endl;
        return make_pair("", "");
    }

    char buffer[256];
    while (!feof(pipe)) {
        if (fgets(buffer, sizeof(buffer), pipe) != nullptr)
            result += buffer;
    }
    pclose(pipe);

    size_t newlinePos = result.find('\n');
    if (newlinePos == string::npos) {
        cerr << "Invalid input format." << endl;
        return make_pair("", "");
    }

    string key = result.substr(0, newlinePos);
    string email = result.substr(newlinePos + 1);

    return make_pair(key, email);
}
