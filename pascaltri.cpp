#include <iostream>
#include <vector>
using namespace std;

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

void printPascal(int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << factorial(i) / (factorial(j) * factorial(i - j)) << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> rows;
    
    printPascal(rows);
    
    return 0;
}
