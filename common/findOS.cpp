#include "./OsInterface.cpp"
#include "../mac/MacOperatingSystemAction.cpp"
using namespace std;

OperatingSystemAction* findOperatingSystem() {
    // Your OS detection logic
    #if defined(_WIN32) || defined(_WIN64)
        // cout << "Running on Windows" << endl;
    #elif defined(__APPLE__)
        // call_MAC_Script();
        return new MacOperatingSystemAction();
    #elif defined(__linux__)
        // cout << "Running on Linux" << endl;
    #elif defined(__FreeBSD__)
        // cout << "Running on FreeBSD" << endl;
    #elif defined(__unix__)
        // cout << "Running on Unix-like OS (other than macOS and Linux)" << endl;
    #else
        cout << "Unknown operating system" << endl;
        return NULL;
    #endif
}