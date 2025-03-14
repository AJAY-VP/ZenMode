// #include <bits/stdc++.h>
// #include <sodium.h>
// #include "encryptionStrategy.cpp"
// using namespace std;

// class AESEncryptionStrategy : public EncryptionStrategy {
// public:
//     const unsigned char AES_KEY[crypto_secretbox_KEYBYTES] =  "omde321Zenekt414"; // Must be exactly 16 bytes for AES-128

//     string encrypt(const string& data) override {
//         unsigned char nonce[crypto_secretbox_NONCEBYTES];
//         randombytes_buf(nonce, sizeof nonce);

//         string encrypted(data.size() + crypto_secretbox_MACBYTES, '\0');
//         crypto_secretbox_easy(reinterpret_cast<unsigned char*>(&encrypted[0]),
//                           reinterpret_cast<const unsigned char*>(data.data()),
//                           data.size(),
//                           nonce,
//                           AES_KEY);

//         return string(reinterpret_cast<char*>(nonce), crypto_secretbox_NONCEBYTES) + encrypted;
//     }

//     string decrypt(const string& data) override {
//         if (data.size() < crypto_secretbox_NONCEBYTES + crypto_secretbox_MACBYTES) {
//             throw runtime_error("Encrypted data too short");
//         }
    
//         const unsigned char* nonce = reinterpret_cast<const unsigned char*>(data.data());
//         const unsigned char* ciphertext = reinterpret_cast<const unsigned char*>(data.data() + crypto_secretbox_NONCEBYTES);
//         size_t ciphertext_len = data.size() - crypto_secretbox_NONCEBYTES;
    
//         string decrypted(ciphertext_len - crypto_secretbox_MACBYTES, '\0');
//         if (crypto_secretbox_open_easy(reinterpret_cast<unsigned char*>(&decrypted[0]),
//                                        ciphertext,
//                                        ciphertext_len,
//                                        nonce,
//                                        AES_KEY) != 0) {
//             throw runtime_error("Decryption failed");
//         }
    
//         return decrypted;
//     }
// };
