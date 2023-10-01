/*
    Website: IEEEXtreme
    Difficulty: Medium
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/f8d68dbb0c844910797ce64354c66143/
*/


#include <bits/stdc++.h>

using namespace std;

// Since most of the numbers we deal with will be consectuive, there is a
// formula for the xor of numbers from m to n, which is xor of numbers from
// 1 to m-1 xor the xor numbers from 1 to n.
// We can furthermore calculate the xor of 1 to a by using this handy chart:
// If a % 4 == 0, the XOR of all numbers from 1 to a is a.
// If a % 4 == 1, the XOR of all numbers from 1 to a is 1.
// If a % 4 == 2, the XOR of all numbers from 1 to a is a + 1.
// If a % 4 == 3, the XOR of all numbers from 1 to a is 0.

// XOR from 1 to a
long long xorValue(long long a){
    if (a%4 == 0) return a;
    else if (a%4 == 1) return 1;
    else if (a%4 == 2) return a+1;
    else return 0;
}

// The step after this is to count the number of consecutive lines of numbers
// we have. There will be a rectangle at the top, and one at the bottom
// sandwicihing the inner rectangle which are wholly consecutive.
// After that, there will be twice as many consecutive lines as the height
// of the inner rectangle (one line on each side of it).
// This of course, granted that the inner rectangle isn't at edge of the
// outer rectangle (we can check for that).

int main() {
    
    int t;
    cin >> t;
    while(t--){
        long long width, height;
        long long n;
        long long d1, d2;
        
        cin >> width >> height >> n >> d1 >> d2;
        
        // Get x and y of each diagonal
        long long y1 = (d1-n)/width; 
        long long x1 = (d1-n) % width; 
        long long y2 = (d2-n)/width; 
        long long x2 = (d2-n) % width;
        
        // top left x, bottom right x
        long long tlx =  min(x1, x2);
        long long brx =  max(x1, x2);
        // top left y, bottom right y
        long long tly =  min(y1, y2);
        long long bry =  max(y1, y2);

        long long xorNum = 0; 
        
        // top rectangle (if it exists)
        if(tly > 0){
            // It will span from n to (tly * width) + n - 1:
            long long one = xorValue(n-1); // we do -1 since lower bound
            long long two = xorValue(tly * width + n - 1);
            long long result = one ^ two;
            xorNum = xorNum ^ result;
        }
        
        // bottom rectangle (if it exists)
        if(bry < height-1){
            // It will span from ((bry + 1) * width + n) 
            // to (height * width) + n - 1 :
            // we do -1 since lower bound
            long long one = xorValue((bry + 1) * width + n -1);
            long long two = xorValue(width * height + n - 1);
            long long result = one ^ two;
            xorNum = xorNum ^ result;
        }
        
        // lines left of inner rectangle
        if(tlx > 0){
            // Lines start at tly and end at bry
            for(long long i = tly; i <= bry; i++){
                // The consective numbers here are i * width + n and 
                // that value + tlx - 1, which is i * width + tlx + n - 1
                // we do -1 since lower bound
                long long one = xorValue(i * width + n - 1);
                long long two = xorValue(i * width + tlx + n - 1);
                long long result = one ^ two;
                xorNum = xorNum ^ result;
            }  
        }
        
        // lines right of inner rectangle
        if(brx < width - 1){
            // Lines start at tly and end at bry
            for(long long i = tly; i <= bry; i++){
                // The consective numbers here are i * width + n + brx + 1 and 
                // (i+1) * width + n - 1 
                // we do -1 since lower bound
                long long one = xorValue(i * width + n + brx);
                long long two = xorValue((i+1) * width + n - 1);
                long long result = one ^ two;
                xorNum = xorNum ^ result;
            }  
        }
        
        cout << xorNum << "\n";
    }

    return 0;
}