// Reverse the array Solution
#include <iostream>
#include <string>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
            cin >> arr[i];
    }
    for(int i=0;i<n/2;i++){
        int temp;
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;

    }

for (int i :arr) cout << i<< ' ';
    return 0;
}