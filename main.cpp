#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include "./common/findOS.cpp"
#include "./common/license.cpp"
#include "./common/utils.cpp"
// #include "./common/aesEncryptionStrategy.cpp"
using namespace std;
bool shouldStop = false;
int main()
{
    string uuid, key;
    time_t expiry;
    bool isLicenseFound = false;
    OperatingSystemAction* osAction =  NULL;
    LicenseManager *license = new LicenseManager();
    osAction = findOperatingSystem();
    if(osAction){
        // LicenseManager *license = new LicenseManager(new AESEncryptionStrategy());
        LicenseManager *license = new LicenseManager();
        if (license->read_license(uuid,expiry)) {
            cout << "License Found." << endl;
            isLicenseFound = true;
        } else {
            cout << "No license found. Please enter a new license key and email." << endl;
            pair<string, string> licenseInfo = osAction->licensePopup();
            cout<<"License Key : "<<licenseInfo.first<<endl;
            cout<<"Email : "<<licenseInfo.second<<endl;
            string newUuid = generate_uuid();
            time_t newExpiry = get_expiry_time();
            expiry = newExpiry;
            license->write_license(newUuid,newExpiry);
            isLicenseFound = true;
        }
        cout << "Current license expires on: " << format_expiry_time(expiry) << endl;
        while(!shouldStop && isLicenseFound && !license->is_license_expired(expiry))
        {
            bool screenLocked = osAction->isScreenLocked();
             cout<<"Is Screen Locked : "<<screenLocked<<endl;
             if(!screenLocked){
                 this_thread::sleep_for(chrono::seconds(10));
                 screenLocked = osAction->isScreenLocked();
                 if(!screenLocked){
                     osAction->execute();
                     this_thread::sleep_for(chrono::seconds(1));
                 }
             } else{
                 this_thread::sleep_for(chrono::seconds(5));
             }
        }
    }
    delete license;
    delete osAction;
    return 0;
}
