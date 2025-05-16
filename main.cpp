#include <iostream>
#include <string>
using namespace std;

string CaesarEnc (string msg , int key);

string CaesarDec (string dec , int key);

string XOREncDec (string msg , int key);

string VigenèreEnc (string msg , string key);

string VigenèreDec (string msg , string key);

string AtbashEncDec (string msg);

int main () {
    int EncorDec;
    cout << "1- Encrypt" << endl << "2- Decrypt" << endl;
    cin >> EncorDec;
    if (EncorDec == 1) {
        int Enc_choice;
        cout << "Choose The Encryption method :" << endl
        << "1- Caesar Cipher" << endl << "2- XOR Cipher" << endl
        << "3- Vigenere Cipher" << endl << "4- Atbash Cipher" << endl;
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
        else if (Enc_choice == 2) {
            string msg, line;
            int key;
            cout << "Enter the text you want to encrypt:" ;
            getline(cin , msg);
            cout << "Enter the encryption key:";
            cin >> key;
            cout << XOREncDec(msg, key);
        }
        else if (Enc_choice == 3) {
            string msg , key;
            cout << "Enter the text you want to encrypt:" ;
            getline(cin , msg);
            cout << "(Note : The key must be consisting of letters)" << endl;
            cout << "Enter the encryption key:";
            getline(cin , key);
            cout << VigenèreEnc(msg , key);
        }
        else if (Enc_choice == 4) {
            string msg;
            cout << "Enter the text you want to encrypt:";
            getline(cin , msg);
            cout << AtbashEncDec (msg);
        }
    }
    else if (EncorDec == 2) {
        int Dec_choice;
        cout << "Choose Which Cipher You Want To Decrypt:" << endl
        <<"1- Caesar Cipher" << endl << "2- XOR Cipher" << endl
        << "3- Vigenere Cipher" << endl << "4- Atbash Cipher" << endl;
        cin >> Dec_choice;
        cin.ignore();
        if (Dec_choice == 1) {
            int key ;
            string msg;
            cout << "Enter the message you want to decrypt:" ;
            getline(cin , msg);
            cout << "Enter the decryption key:";
            cin >> key;
            cout << CaesarDec(msg , key);
        }
        else if (Dec_choice == 2) {
            string msg, line;
            int key;
            cout << "(Note : Enter an additional space to confirm that the message ended)" << endl;;
            cout << "Enter the message you want to decrypt:" ;
            while (getline(cin, line) && !line.empty()) {
                msg += line + '\n';
            }
            if (!msg.empty() && msg.back() == '\n') {
                msg.pop_back();
            }
            cout << "Enter the decryption key:";
            cin >> key;
            cout << XOREncDec(msg, key);
        }
        else if (Dec_choice == 3) {
            string msg , key;
            cout << "Enter the text you want to decrypt:" ;
            getline(cin , msg);
            cout << "(Note : The key must be consisting of letters)" << endl;
            cout << "Enter the decryption key:";
            getline(cin , key);
            cout << VigenèreDec(msg , key);
        }
        else if (Dec_choice == 4) {
            string msg;
            cout << "Enter the text you want to decrypt:";
            getline(cin , msg);
            cout << AtbashEncDec (msg);
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


//XOR Encryption and Decryption
string XOREncDec (string msg , int key) {

    for (int i = 0 ; i < msg.size() ; i++) {
        msg[i] = msg[i] ^ key;
    }
    return msg;
}


//Vigernere Encryption
string VigenèreEnc (string msg , string key) {

    for (int i = 0 ; i < key.size() ; i++) {
        if (key[i] >= 'a' && key[i] <= 'z') {
            key[i] = toupper(key[i]);
        }
    }
    int j = 0;
    for (int i = 0 ; i < msg.size() ; i++) {
        char k = key[j % key.size()];
        if (msg[i] >= 'A' && msg[i] <= 'Z' ) {
            msg[i] = ((msg[i] - 'A' + (k - 'A')) % 26) + 'A';
            j++;
        }
        else if (msg[i] >= 'a' && msg[i] <= 'z' ){
            msg[i] = ((msg[i] - 'a' + (k - 'A')) % 26) + 'a';
            j++;
        }
    }
    return msg;
}


//Vigernere Encryption
string VigenèreDec (string msg , string key) {

    for (int i = 0 ; i < key.size() ; i++) {
        if (key[i] >= 'a' && key[i] <= 'z') {
            key[i] = toupper(key[i]);
        }
    }
    int j = 0;
    for (int i = 0 ; i < msg.size() ; i++) {
        char k = key[j % key.size()];
        if (msg[i] >= 'A' && msg[i] <= 'Z' ) {
            msg[i] = ((msg[i] - 'A' - (k - 'A') + 26) % 26) + 'A';
            j++;
        }
        else if (msg[i] >= 'a' && msg[i] <= 'z' ){
            msg[i] = ((msg[i] - 'a' - (k - 'A') + 26) % 26) + 'a';
            j++;
        }
    }
    return msg;
}


//Atbash Encryption and Decryption
string AtbashEncDec (string msg) {

    for (int i = 0 ; i < msg.size() ; i++) {
        if (msg[i] >= 'A' && msg[i] <= 'Z' ) {
            msg[i] = 'Z' - msg[i] + 'A';
        }
        else if (msg[i] >= 'a' && msg[i] <= 'z' ) {
            msg[i] = 'z' - msg[i] + 'a';
        }
    }
    return msg;
}
