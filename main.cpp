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
    if (cin.fail()) { // in case the user inputs a letter for example
        cin.clear();  // To clear the error
        cin.ignore(10000, '\n');  // To clear the input and avoid an endless loop
        cout << "Enter a valid number: ";
        goto EncorDec_input;
    }
    if (EncorDec == 1) { //Encryption
        int Enc_choice;
        cout << "Choose The Encryption method :" << endl
        << "1- Caesar Cipher" << endl << "2- XOR Cipher" << endl
        << "3- Vigenère Cipher" << endl << "4- Atbash Cipher" << endl;
        Enc_input:
        cin >> Enc_choice;
        if (cin.fail()) { // in case the user inputs a letter for example
            cin.clear();  // To clear the error
            cin.ignore(10000, '\n');  // To clear the input and avoid an endless loop
            cout << "Enter a valid number: ";
            goto Enc_input;
        }
        cin.ignore(); //to avoid the additional /n
        if (Enc_choice == 1) { // Caesar
            int key;
            cout << "[CAESAR CIPHER]" << endl;
            cout << "Enter the text you want to encrypt:" ;
            getline(cin , msg); // To let the user input more than one word
            cout << "(Note : The key must be a number)" << endl;
            cout << "Enter the encryption key:";
            Enc_key1_input:
            cin >> key;
            if (cin.fail()) { // in case the user inputs a letter for example
                cin.clear();  // To clear the error
                cin.ignore(10000, '\n');  // To clear the input and avoid an endless loop
                cout << "Enter a valid number: ";
                goto Enc_key1_input;
            }
            cout << CaesarEnc(msg , key);
        }
        else if (Enc_choice == 2) { // XOR
            string line;
            int key;
            cout << "[XOR CIPHER]" << endl;
            cout << "Enter the text you want to encrypt:" ;
            getline(cin , msg); // To let the user input more than one word
            cout << "(Note : The key must be a number)" << endl;;
            cout << "Enter the encryption key:";
            Enc_key2_input:
            cin >> key;
            if (cin.fail()) { // in case the user inputs a letter for example
                cin.clear();  // To clear the error
                cin.ignore(10000, '\n');  // To clear the input and avoid an endless loop
                cout << "Enter a valid number: ";
                goto Enc_key2_input;
            }
            cout << XOREncDec(msg, key);
        }
        else if (Enc_choice == 3) { //Vigenère
            string key;
            cout << "[VIGENERE CIPHER]" << endl;
            cout << "Enter the text you want to encrypt:" ;
            getline(cin , msg); // To let the user input more than one word
            cout << "(Note : The key must consist of letters)" << endl;
            cout << "Enter the encryption key:";
            Enc_key3_input:
            getline(cin , key); // To let the user input more than one word
            for (int i = 0 ; i < key.size() ; i++) { // To make sure that the key only consists of letters
                if (!(key[i] <= 'z' && key[i] >= 'a' ) && !(key[i] <= 'Z' && key[i] >= 'A' ) && (key[i] != ' ')) {
                    cout << "Key must only consist of letters , try again :";
                    goto Enc_key3_input;
                }
            }
            cout << VigenèreEnc(msg , key);
        }
        else if (Enc_choice == 4) { //Atbash
            cout << "[ATBASH CIPHER]" << endl;
            cout << "Enter the text you want to encrypt:";
            getline(cin , msg); // To let the user input more than one word
            cout << AtbashEncDec (msg);
        }
        else {
            cout << "Enter a valid number :";
            goto Enc_input;
        }
}
    else if (EncorDec == 2) { //Decryption
        int Dec_choice;
        cout << "Choose Which Cipher You Want To Decrypt:" << endl
        <<"1- Caesar Cipher" << endl << "2- XOR Cipher" << endl
        << "3- Vigenere Cipher" << endl << "4- Atbash Cipher" << endl;
        Dec_input:
        cin >> Dec_choice;
        if (cin.fail()) { // in case the user inputs a letter for example
            cin.clear();  // To clear the error
            cin.ignore(10000, '\n');  // To clear the input and avoid an endless loop
            cout << "Enter a valid number: ";
            goto Dec_input;
        }
        cin.ignore(); // To avoid an additional /n
        if (Dec_choice == 1) { // Caesar
            int key ;
            cout << "[CAESAR CIPHER]" << endl;
            cout << "Enter the message you want to decrypt:" ;
            getline(cin , msg); // To let the user input more than one word
            cout << "(Note : The key must be a number)" << endl;
            cout << "Enter the decryption key:";
            Dec_key1_input:
            cin >> key;
            if (cin.fail()) { // in case the user inputs a letter for example
                cin.clear();  // To clear the error
                cin.ignore(10000, '\n');  // To clear the input and avoid an endless loop
                cout << "Enter a valid number: ";
                goto Dec_key1_input;
            }
            cout << CaesarDec(msg , key);
        }
        else if (Dec_choice == 2) { //XOR
            string line;
            int key;
            cout << "[XOR CIPHER]" << endl;
            cout << "(Note : Enter an additional new line to confirm that the message ended)" << endl;;
            cout << "Enter the message you want to decrypt:" ;
            while (getline(cin, line) && !line.empty()) { // takes from the user till he clicks enter twice
                msg += line + '\n';
            }
            if (!msg.empty() && msg.back() == '\n') { // deletes the useless new line at the end
                msg.pop_back();
            }
            cout << "(Note : The key must be a number)" << endl;
            cout << "Enter the decryption key:";
            Dec_key2_input:
            cin >> key;
            if (cin.fail()) { // in case the user inputs a letter for example
                cin.clear();  // To clear the error
                cin.ignore(10000, '\n');  // To clear the input and avoid an endless loop
                cout << "Enter a valid number: ";
                goto Dec_key2_input;
            }
            cout << XOREncDec(msg, key);
        }
        else if (Dec_choice == 3) { // Vigenère
            string key;
            cout << "[VIGENERE CIPHER]" << endl;
            cout << "Enter the text you want to decrypt:" ;
            getline(cin , msg); // To let the user input more than one word
            cout << "(Note : The key must consist of letters)" << endl;
            cout << "Enter the decryption key:";
            Dec_key3_input:
            getline(cin , key); // To let the user input more than one word
            for (int i = 0 ; i < key.size() ; i++) { // To make sure that the key only consists of letters
                if (!(key[i] <= 'z' && key[i] >= 'a' ) && !(key[i] <= 'Z' && key[i] >= 'A' )) {
                    cout << "Key must only consist of letters , try again :";
                    goto Dec_key3_input;
                }
            }
            cout << VigenèreDec(msg , key);
        }
        else if (Dec_choice == 4) { // Atbash
            cout << "[ATBASH CIPHER]" << endl;
            cout << "Enter the text you want to decrypt:";
            getline(cin , msg); // To let the user input more than one word
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
// Shifts every letter by the number the user inputs
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


// XOR Encryption and Decryption
// Uses the ascii value of each letter in its binary form to perform XOR operation on it
string XOREncDec (string msg , int key) {

    for (int i = 0 ; i < msg.size() ; i++) {
        msg[i] = msg[i] ^ key;
    }
    return msg;
}


// Vigenere Encryption
// Shifts each letter based on the opposite letter in the key
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


// Vigenere Decryption
string VigenèreDec (string msg , string key) {

    for (int i = 0 ; i < key.size() ; i++) { // makes the key all uppercase
        if (key[i] >= 'a' && key[i] <= 'z') {
            key[i] = toupper(key[i]);
        }
    }
    int j = 0;
    for (int i = 0 ; i < msg.size() ; i++) {
        char k = key[j % key.size()]; // to repeat the key in case it wasn't the same size as the msg
        if (msg[i] >= 'A' && msg[i] <= 'Z' ) {
            msg[i] = ((msg[i] - 'A' - (k - 'A') + 26) % 26) + 'A'; // add 26 in case the result was -ve.
            j++;
        }
        else if (msg[i] >= 'a' && msg[i] <= 'z' ){
            msg[i] = ((msg[i] - 'a' - (k - 'A') + 26) % 26) + 'a';
            j++;
        }
    }
    return msg;
}


// Atbash Encryption and Decryption
// Replaces each letter with the opposite one on the 2 row table
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
