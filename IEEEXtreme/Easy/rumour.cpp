/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/9ca8fafd184f553a903734761546a224/
*/


#include <iostream>

using namespace std;

int main() {
    // The trick is to find the smallest common ancestor, and to sum
    // the height difference between it and the two nodes (unless the node
    // is itself).
    long q;
    cin >> q;
    while(q--){
        
        long long a, b;
        cin >> a >> b;
        
        long long c = a, d = b;
        long depthA{}, depthB{};
        
        // To see wether an element is an ancestor of x, we devide x by 2
        // repeatedly until we either arrive at the node (ancestor) or pass
        // it (not an anestor). Note that we want the floor of the division by 2.
        while(true){
            if(c > d){
                c /= 2; 
                depthA++;
            }
            else if (c < d){
                d /= 2;
                depthB++;
            }
            else{
                break;
            }
        }
        
        // Smallest common ancestor is now in c and d.
        cout << depthA + depthB << "\n";
    }
    
}