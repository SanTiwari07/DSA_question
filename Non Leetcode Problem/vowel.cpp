#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void countVowelsAndConsonants(const string& s) {
    int vowels = 0;
    int consonants = 0;

    for (char c : s) {
     
        char lower_c = tolower(c);

        if (lower_c >= 'a' && lower_c <= 'z') {
           
            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    cout << "Total Vowels: " << vowels << endl;
    cout << "Total Consonants: " << consonants << endl;
}

int main() {
    cout << "--- Find out the no of vowels and consonant ---" << endl;

    string text = "Programming Statements are fun!";
    cout << "Original String: " << text << endl;

    countVowelsAndConsonants(text);

    return 0;
}
