#include <iostream>
#include <string>

using namespace std;

// Caesar Cipher function (used for both encryption and decryption)
string caesar(const string& text, int shift) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift + 26) % 26 + base; 
        }
        result += c;
    }

    return result;
}

int main() {
    string text;

    cout << "Enter the text: ";
    getline(cin, text);

    int shift = 4; 
    string encryptedText = caesar(text, shift);
    cout << "Encrypted text: " << encryptedText << endl;

    string decryptedText = caesar(encryptedText, -shift);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
