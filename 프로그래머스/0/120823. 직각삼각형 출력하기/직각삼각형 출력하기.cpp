#include <iostream>

using namespace std;

int main(void) {
    int n;
    int count = 1;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<count; j++){
            cout << "*";
        }
        count++;
        cout << endl;
    }
    return 0;
}