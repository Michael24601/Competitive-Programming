/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/queens-attack-2/problem
*/


#include <bits/stdc++.h>

using namespace std;

struct point{
    int x; 
    int y;
};

int main(){
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    vector<point> v(k);
    long sum = 0;
    for(int i =0; i < k; i++){
        int a, b;
        cin >> a >> b;
        v[i].x = a;
        v[i].y = b;
    }
    
    // vertical
    int max = 0, min = n+1;
    for(int i = 0; i < k; i++){
        if(v[i].x == x && v[i].y > max && v[i].y < y){
            max = v[i].y;
        }
        if(v[i].x == x && v[i].y < min && v[i].y > y){
            min = v[i].y;
        }
    }
    sum += (y - max - 1) + (min - y - 1);
    
    // Horizontal
    max = 0, min = n+1;
    for(int i = 0; i < k; i++){
        if(v[i].y == y && v[i].x > max && v[i].x < x){
            max = v[i].x;
        }
        if(v[i].y == y && v[i].x < min && v[i].x > x){
            min = v[i].x;
        }
    }
    sum += (x - max - 1) + (min - x - 1);
    
    // Diagonal
    int maxY, maxX, minY, minX;
    if(n - x >= y){
        minX = 0;
        minY = x + y; 
        
        maxY = 0;
        maxX = x + y;
    }
    else{
        maxX = n+1;
        maxY = x+y - n-1;
        
        minY = n+1;
        minX= x+y - n-1;
    }
    for(int i = 0; i < k; i++){
        if(v[i].y + v[i].x == x+ y && v[i].y > maxY && v[i].y < y){
            maxY = v[i].y;
        }
        if(v[i].y + v[i].x == x+y && v[i].y < minY && v[i].y > y){
            minY = v[i].y;
        }
    }
    sum += (y - maxY - 1) + (minY - y - 1);
    
    // Second Diagonal
    if(x >= y){
        maxY = 0;
        maxX = x - y;
        
        minX = n+1;
        minY= y - x + n+1;
    }
    else{
        maxX = 0;
        maxY = y - x; 
        
        minY = n+1;
        minX = x - y + n+1;
    }
    for(int i = 0; i < k; i++){
        if(v[i].y - v[i].x == y- x && v[i].y > maxY && v[i].y < y){
            maxY = v[i].y;
        }
        if(v[i].y - v[i].x == y-x && v[i].y < minY && v[i].y > y){
            minY = v[i].y;
        }
    }
    sum += (y - maxY - 1) + (minY - y - 1);
    
    cout << sum;
    
    return 0;
}