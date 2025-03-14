#pragma once
#include <string>
using namespace std;
class EncryptionStrategy {
    public:
        virtual ~EncryptionStrategy() = default;
        virtual string encrypt(const string& data) = 0;
        virtual string decrypt(const string& data) = 0;
};
    