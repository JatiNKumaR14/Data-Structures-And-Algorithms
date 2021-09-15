// Find the maximum and minimum element in an array Solution
#include <iostream>
#include <string>
#include<vector>
#include<climits>

using namespace std;

int main(){
    int n;
    cin >> n;
    int max = INT_MIN;
    int min = INT_MAX;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
            cin >> arr[i];
            if(arr[i]>max) max = arr[i];
            if(arr[i]<min) min = arr[i];
    }
    cout << "Max : " << max <<"\n";
    cout << "Min : " << min <<"\n";
    
    return 0;
}