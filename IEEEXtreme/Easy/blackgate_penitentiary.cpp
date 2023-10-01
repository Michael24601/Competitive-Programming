/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/8761fb7efefcf1d890df1d8d91cae241/
*/


#include <bits/stdc++.h>

using namespace std;

struct person{
    string name;
    int h;
};

int main() {
    int n;
    cin >> n;
    vector<person> v(n);
    for(int i = 0; i < n; i++){
        string name;
        int h;
        cin >> name >> h;
        v[i] = {name, h};
    }
    sort(v.begin(), v.end(), [](const person& p1, const person& p2)->bool{
       if(p1.h < p2.h) return true;
       else if(p1.h > p2.h) return false;
       else return p1.name < p2.name;
    });
    
    for(int i = 0; i < n; ){
        int j  = i;
        while(j < n && v[i].h == v[j].h){
            cout << v[j].name << " ";
            j++;
        }
        cout << i+1 << " " << j << "\n";
        i = j; 
    }
    
    return 0;
}