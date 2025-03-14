#pragma once
#include <bits/stdc++.h>
#include <sys/stat.h>
// #include "./encryptionStrategy.cpp"
using namespace std;

const string APP_SUPPORT_DIR = string(getenv("HOME")) + "/Library/Application Support/ZenMode/";
const string LICENSE_FILE = APP_SUPPORT_DIR + "license.txt";


class LicenseManager {
    private:
        // EncryptionStrategy* encryptionStrategy;
    
        void ensure_app_support_dir() {
            struct stat info;
            if (stat(APP_SUPPORT_DIR.c_str(), &info) != 0) {
                mkdir(APP_SUPPORT_DIR.c_str(), 0777);
            }
        }
    
    public:
        // explicit LicenseManager(EncryptionStrategy* strategy) : encryptionStrategy(strategy) {}
    
        void write_license(const string& uuid, time_t expiry) {
            ensure_app_support_dir();
            ofstream outFile(LICENSE_FILE);
            if (outFile.is_open()) {
                string data = uuid + "\n" + to_string(expiry);
                // string encrypted_data = encryptionStrategy->encrypt(data);
                outFile << data;
                outFile.close();
                cout << "License saved successfully." << endl;
            } else {
                cerr << "Error: Unable to open license file for writing." << endl;
            }
        }
    
        bool read_license(string& uuid, time_t& expiry) {
            ifstream inFile(LICENSE_FILE);
            if (inFile.is_open()) {
                string data((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
                // string decrypted_data = encryptionStrategy->decrypt(data);
    
                istringstream iss(data);
                getline(iss, uuid);
                string expiry_str;
                getline(iss, expiry_str);
                expiry = stol(expiry_str);
    
                inFile.close();
                return true;
            } else {
                cerr << "Error: Unable to open license file for reading." << endl;
                return false;
            }
        }
    
        bool is_license_expired(time_t expiry) {
            time_t now = time(nullptr);
            return now > expiry;
        }
    };
