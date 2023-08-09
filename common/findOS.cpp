#include "../mac/macScript.cpp"
using namespace std;
void findOperatingSystem(){
    #if defined(_WIN32) || defined(_WIN64)
        cout << "Running on Windows" << std::endl;
    #elif defined(__APPLE__)
        call_MAC_Script();
    #elif defined(__linux__)
        cout << "Running on Linux" << std::endl;
    #elif defined(__FreeBSD__)
        cout << "Running on FreeBSD" << std::endl;
    #elif defined(__unix__)
        cout << "Running on Unix-like OS (other than macOS and Linux)" << std::endl;
    #else
        cout << "Unknown operating system" << std::endl;
    #endif
}