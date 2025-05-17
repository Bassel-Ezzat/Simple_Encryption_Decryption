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
    string msg;
    cout << "1- Encrypt" << endl << "2- Decrypt" << endl;
    EncorDec_input:
    cin >> EncorDec;
    if (EncorDec == 1) {
        int Enc_choice;
        cout << "Choose The Encryption method :" << endl
        << "1- Caesar Cipher" << endl << "2- XOR Cipher" << endl
        << "3- Vigenère Cipher" << endl << "4- Atbash Cipher" << endl;
        Enc_input:
        cin >> Enc_choice;
        cin.ignore();
        if (Enc_choice == 1) {
            int key;
            cout << "[CAESAR CIPHER]" << endl;
            cout << "Enter the text you want to encrypt:" ;
            getline(cin , msg);
            cout << "(Note : The key must be a number)";
            cout << "Enter the encryption key:";
            Enc_key1_input:
            cin >> key;
            if (!cin >> key) {
                cout << "The key must be a number , try again :";
                goto Enc_key1_input;
            }
            cout << CaesarEnc(msg , key);
        }
        else if (Enc_choice == 2) {
            string line;
            int key;
            cout << "[XOR CIPHER]" << endl;
            cout << "Enter the text you want to encrypt:" ;
            getline(cin , msg);
            cout << "(Note : The key must be a number)";
            cout << "Enter the encryption key:";
            Enc_key2_input:
            cin >> key;
            if (!cin >> key) {
                cout << "The key must be a number , try again :";
                goto Enc_key2_input;
            }
            cout << XOREncDec(msg, key);
        }
        else if (Enc_choice == 3) {
            string key;
            cout << "[VIGENÈRE CIPHER]" << endl;
            cout << "Enter the text you want to encrypt:" ;
            getline(cin , msg);
            cout << "(Note : The key must consist of letters)" << endl;
            cout << "Enter the encryption key:";
            Enc_key3_input:
            getline(cin , key);
            for (int i = 0 ; i < key.size() ; i++) {
                if (!(key[i] <= 'z' && key[i] >= 'a' ) && !(key[i] <= 'Z' && key[i] >= 'A' ) && (key[i] != ' ')) {
                    goto Enc_key3_input;
                }
            }
            cout << VigenèreEnc(msg , key);
        }
        else if (Enc_choice == 4) {
            cout << "[ATBASH CIPHER]" << endl;
            cout << "Enter the text you want to encrypt:";
            getline(cin , msg);
            cout << AtbashEncDec (msg);
        }
        else {
            cout << "Enter a valid number :";
            goto Enc_input;
        }
}
    else if (EncorDec == 2) {
        int Dec_choice;
        cout << "Choose Which Cipher You Want To Decrypt:" << endl
        <<"1- Caesar Cipher" << endl << "2- XOR Cipher" << endl
        << "3- Vigenere Cipher" << endl << "4- Atbash Cipher" << endl;
        Dec_input:
        cin >> Dec_choice;
        cin.ignore();
        if (Dec_choice == 1) {
            int key ;
            cout << "[CAESAR CIPHER]" << endl;
            cout << "Enter the message you want to decrypt:" ;
            getline(cin , msg);
            cout << "(Note : The key must be a number)";
            cout << "Enter the decryption key:";
            Dec_key1_input:
            cin >> key;
            if (!cin >> key) {
                cout << "The key must be a number , try again :";
                goto Dec_key1_input;
            }
            cout << CaesarDec(msg , key);
        }
        else if (Dec_choice == 2) {
            string line;
            int key;
            cout << "[XOR CIPHER]" << endl;
            cout << "(Note : Enter an additional space to confirm that the message ended)" << endl;;
            cout << "Enter the message you want to decrypt:" ;
            while (getline(cin, line) && !line.empty()) {
                msg += line + '\n';
            }
            if (!msg.empty() && msg.back() == '\n') {
                msg.pop_back();
            }
            cout << "(Note : The key must be a number)";
            cout << "Enter the decryption key:";
            Dec_key2_input:
            cin >> key;
            if (!cin >> key) {
                cout << "The key must be a number , try again :";
                goto Dec_key2_input;
            }
            cout << XOREncDec(msg, key);
        }
        else if (Dec_choice == 3) {
            string key;
            cout << "[VIGENÈRE CIPHER]" << endl;
            cout << "Enter the text you want to decrypt:" ;
            getline(cin , msg);
            cout << "(Note : The key must consist of letters)" << endl;
            cout << "Enter the decryption key:";
            Dec_key3_input:
            getline(cin , key);
            for (int i = 0 ; i < key.size() ; i++) {
                if (!(key[i] <= 'z' && key[i] >= 'a' ) && !(key[i] <= 'Z' && key[i] >= 'A' )) {
                    goto Dec_key3_input;
                }
            }
            cout << VigenèreDec(msg , key);
        }
        else if (Dec_choice == 4) {
            cout << "[ATBASH CIPHER]" << endl;
            cout << "Enter the text you want to decrypt:";
            getline(cin , msg);
            cout << AtbashEncDec (msg);
        }
        else {
            cout << "Enter a valid number :";
            goto Dec_input;
        }
    }
    else {
        cout << "Enter a valid number :";
        goto EncorDec_input;
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
