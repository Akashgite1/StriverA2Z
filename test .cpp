#include <bits/stdc++.h>
using namespace std;

// Function to calculate total distance
int getDistance(string word) {
    // Edge case: If the word contains only one letter, return 0
    if (word.size() == 1) return 0;

    // Define the 2D grid layout of the keyboard
    vector<string> keyboard = {
        "QWERTYUIOP",
        "ASDFGHJKL",
        "ZXCVBNM"
    };

    // Map to store the position of each letter (optimized with unordered_map for O(1) access)
    unordered_map<char, pair<int, int>> pos = {
        {'Q', {0, 0}}, {'W', {0, 1}}, {'E', {0, 2}}, {'R', {0, 3}}, {'T', {0, 4}}, 
        {'Y', {0, 5}}, {'U', {0, 6}}, {'I', {0, 7}}, {'O', {0, 8}}, {'P', {0, 9}},
        {'A', {1, 0}}, {'S', {1, 1}}, {'D', {1, 2}}, {'F', {1, 3}}, {'G', {1, 4}}, 
        {'H', {1, 5}}, {'J', {1, 6}}, {'K', {1, 7}}, {'L', {1, 8}}, 
        {'Z', {2, 0}}, {'X', {2, 1}}, {'C', {2, 2}}, {'V', {2, 3}}, {'B', {2, 4}}, 
        {'N', {2, 5}}, {'M', {2, 6}}
    };

    int totalDistance = 0;

    // Starting position at 'Q'
    int prevRow = pos['Q'].first;
    int prevCol = pos['Q'].second;

    // Traverse each letter in the word
    for (char c : word) {
        int currRow = pos[c].first;
        int currCol = pos[c].second;

        // Calculate Manhattan distance and add to total distance
        totalDistance += abs(currRow - prevRow) + abs(currCol - prevCol);

        // Update the previous position to the current position
        prevRow = currRow;
        prevCol = currCol;
    }

    return totalDistance;
}

int main() {
    string word = "QTHEQUICKBROWNFOXJUMPSOVERTHELAZYD";
    cout << "Total Distance: " << getDistance(word) << endl;
    return 0;
}
