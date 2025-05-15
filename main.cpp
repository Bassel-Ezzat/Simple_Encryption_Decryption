#include <iostream>
#include <string>
using namespace std;

string CaesarEnc (string msg , int key);

string CaesarDec (string dec , int key);

int main () {
    int EncorDec;
    cout << "1- Encrypt" << endl << "2- Decrypt" << endl;
    cin >> EncorDec;
    if (EncorDec == 1) {
        int Enc_choice;
        cout << "Choose The Encryption method :" << endl
        << "1- Caesar Cipher" << endl << "2- XOR Cipher" << endl
        << "3- Vigenere Cipher" << endl;
        cin >> Enc_choice;
        cin.ignore();
        if (Enc_choice == 1) {
            string msg ;
            int key;
            cout << "Enter the text you want to encrypt:" ;
            getline(cin , msg);
            cout << "Enter the encryption key:";
            cin >> key;
            cout << CaesarEnc(msg , key);
        }
    }
    else if (EncorDec == 2) {
        int Dec_choice;
        cout << "Choose Which Cipher You Want To Decrypt:" << endl
        <<"1- Caesar Cipher" << endl << "2- XOR Cipher" << endl
        << "3- Vigenere Cipher" << endl;
        cin >> Dec_choice;
        cin.ignore();
        if (Dec_choice == 1) {
            int key ;
            string msg;
            cout << "Enter the text you want to Decrypt:" ;
            getline(cin , msg);
            cout << "Enter the Decryption key:";
            cin >> key;
            cout << CaesarDec(msg , key);
        }
    }

}



















// Caesar Cipher Encryption
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

// Caesar Cipher Decryption
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