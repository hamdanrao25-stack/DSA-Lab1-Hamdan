#include <iostream>
#include <string>

using namespace std;


int findSubstring(string text, string pattern) {                       // Function to find the starting index of the first pattern match

    if (pattern.empty()) {                     //edge case
        return 0;
    }

    int tLen = text.length();
    int pLen = pattern.length();

    for (int i = 0; i <= tLen - pLen; i++) {                       // Loop through the text, but stop where the pattern can no longer fit
        int j;
        
        for (j = 0; j < pLen; j++) {                                     // Check if the substring matches character by character
            if (text[i + j] != pattern[j]) {
                break;                                           // Mismatch found, jump to the next window
            }
        }

        if (j == pLen) {
            return i;
        }
    }

    return -1;
}

// Quick helper to format output cleanly
void testCase(string text, string pattern, string label) {
    cout << label << "\nText: \"" << text << "\" | Pattern: \"" << pattern << "\"\n";
    int index = findSubstring(text, pattern);
    cout << "Result index: " << index << endl;
}

int main() {
    // TC 1: Pattern is right at the start
    testCase("applepie", "apple", "Test Case 1: Pattern at the beginning");

    // TC 2: Pattern is right at the very end
    testCase("database", "base", "Test Case 2: Pattern at the end");

    // TC 3: Pattern isn't in the string at all
    testCase("structures", "algo", "Test Case 3: Pattern not present");

    // TC 4: Pattern is an empty string
    testCase("hello", "", "Test Case 4: Empty pattern");

    return 0;
}