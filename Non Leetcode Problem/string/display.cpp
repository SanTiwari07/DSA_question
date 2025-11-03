#include <iostream>
#include <string>

using namespace std;

void displayCharByChar(const string& s) {
    cout << "Characters: ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    cout << "--- Display String Value Char by Char ---" << endl;

    string text = "Hello World";
    cout << "Original String: \"" << text << "\"" << endl;

    displayCharByChar(text);

    return 0;
}
