#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

string reverseCharWise(const string& s) {
    string reversed_s = s;
 
    reverse(reversed_s.begin(), reversed_s.end()); 
   
    return reversed_s;
}

int main() {
    cout << "--- Display String in Reverse Order Char Wise ---" << endl;

    string text = "DSA Problem";
    cout << "Original String: " << text << endl;

    string reversed_text = reverseCharWise(text);

    cout << "Reversed String (Char Wise): " << reversed_text << endl;

    return 0;
}
