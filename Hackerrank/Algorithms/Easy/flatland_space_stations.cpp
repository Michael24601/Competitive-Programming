/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/flatland-space-stations/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    long n, m;
    cin >> n >> m;
    long* arr = new long[m];
    for(long i = 0; i< m; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+m);

    // If a city is on the edge of the line, its closet station is the distance
    // to the next station, while if a city is in the middle between two
    // stations, its the floor of the distance between the two stations divided
    // by two, so we keeo track of the max in the middle and the max between
    // the two edges.
    long max{};
    long maxedge;
    
    long last = -1;
    for(long i = 0; i < m; i++){
        long temp = arr[i];
        if(last != -1){
            if(max < temp - last){
                max = temp - last;
            }
        }
        else{
            maxedge = temp;
        }
        last = temp;
    }
    if(n - last - 1 > maxedge)
        maxedge = n - last - 1;
    
    
    cout << std::max((max/2), maxedge);
    
    return 0;
}