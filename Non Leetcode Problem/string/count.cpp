#include <iostream>
#include <string>
#include <map>

using namespace std;


void countCharacterFrequency(const string& s) {
    
    map<char, int> frequency_map;

    for (char c : s) {
      
        if (isalpha(c)) { 
         
            char lower_c = tolower(c);
            frequency_map[lower_c]++;
        }
    }

    cout << "Character Frequencies (Ignoring spaces and case):" << endl;
    for (const auto& pair : frequency_map) {
        cout << "'" << pair.first << "': " << pair.second << endl;
    }
}

int main() {
    cout << "--- Find out how many times char are occurred ---" << endl;

    string text = "Programming Statement";
    cout << "Original String: " << text << endl;

    countCharacterFrequency(text);

    return 0;
}
