// maximum  frequency of an element in a given array consisting numbers 3,2,3,4,1
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
   
    vector<int> arr = {3, 2, 3, 4, 1};

    unordered_map<int, int> frequency;

    for (int num : arr) {
        frequency[num]++;
    }

    int maxFreq = 0;
    int maxFreqElement = -1;
    for (auto &entry : frequency) {
        if (entry.second > maxFreq) {
            maxFreq = entry.second;
            maxFreqElement = entry.first;
        }
    }

    cout << "Element with maximum frequency: " << maxFreqElement << endl;
    cout << "Frequency: " << maxFreq << endl;

    return 0;
}
