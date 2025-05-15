#include <iostream>
#include <string>
using namespace std;

string CaesarEnc (string msg , int key);

string CaesarDec (string dec , int key);

int main () {

}



















// Caeser Cipher Encryption
string CaesarEnc (string msg , int key) {
    for (int i = 0; i < msg.length(); i++) {
        if (isupper(msg[i])) {
            msg[i] = (( msg[i] - 'A' + key ) % 26) + 'A' ;
        }
        else if (islower(msg[i])) {
            msg[i] = (( msg[i] - 'a' + key ) % 26) + 'a';
        }

    }
    return msg;
}

// Caeser Cipher Decryption
string CaesarDec (string dec , int key) {
    for (int i = 0; i < dec.length(); i++) {
        if (isupper(dec[i])) {
            dec[i] = (( dec[i] - 'A' - key) % 26) + 'A' ;
        }
        else if (islower(dec[i])) {
            dec[i] = (( dec[i] - 'a' - key) % 26) + 'a' ;
        }
    }
    return dec;
}