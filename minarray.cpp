#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits> 
using namespace std;

int main() {
    vector<int> arr = {3, 2, 3, 4, 1, 2, 4};

    unordered_map<int, int> frequency;

    for (int num : arr) {
        frequency[num]++;
    }

    int minFreq = INT_MAX;
    int minFreqElement = -1;
    for (auto &entry : frequency) {
        if (entry.second < minFreq) {
            minFreq = entry.second;
            minFreqElement = entry.first;
        }
    }

    cout << "Element with minimum frequency: " << minFreqElement << endl;
    cout << "Frequency: " << minFreq << endl;

    return 0;
}
