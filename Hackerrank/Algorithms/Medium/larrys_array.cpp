/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/larrys-array/problem
*/


#include <bits/stdc++.h>

using namespace std;

// Shift left (the given operation)
void shift(vector<int>& arr, int first){
    int temp = arr[first];
    arr[first] = arr[first+1];
    arr[first+1] = arr[first+2];
    arr[first+2] = temp;
}

// Determines wether we shoul shift once, twice, or none times,
// to get the smallest number on the left
void determineShift(vector<int>& arr, int first){
    if(arr[first] <= arr[first+1] && arr[first] <= arr[first+2]){
        return; // Do nothing
    }
    else{
        shift(arr, first);
    }
    
    // Check again after the shift if it is the smallest, otherwise
    // shift again
    if(arr[first] <= arr[first+1] && arr[first] <= arr[first+2]){
        return; // Do nothing
    }
    else{
        shift(arr, first);
    }
    
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        
        // Our startegy will be to try and sort the array by using a bubble
        // like sort (with 3 swaps instead of 2). If after we reach the last 
        // two items (which we can't swap since we swap 3 items at a time and
        // the previous element is already sorted), if they are sorted, we 
        // return yes, otherwise, it's impossible, as there is nothing we can do.
        for(int i = 0; i < n-2; i++){
            // We start at n-i because all those after it are sorted
            for(int j = n-3; j >= i; j--){
                determineShift(v, j);
            }
        }
        
        if(v[n-3] <= v[n-2] && v[n-2] <= v[n-1]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}