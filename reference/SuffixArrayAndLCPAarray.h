
#include <bits/stdc++.h>

using namespace std;


// Constructs a Suffix Array data structure:
// It is an array containing the indeces of the suffix substings of a string
// input (meaning substrings that end at the end of the string but can begin
// anywhere) in lexicographic order of the strings.

// There are many algorithms for building a suffix array, but this is among
// the most efficient, called the Kärkkäinen-Sanders Algorithm.
// suffixRank is table hold the rank of each string on each iteration  
// suffixRank[i][j] denotes rank of jth suffix at ith iteration  

int suffixRank[20][int(1E6)];

// Example "abaab"  
// Suffix Array for this (2, 3, 0, 4, 1)  
// Create a tuple to store rank for each suffix  

struct myTuple {  
    int originalIndex;   // stores original index of suffix  
    int firstHalf;       // store rank for first half of suffix  
    int secondHalf;      // store rank for second half of suffix  
};


// function to compare two suffix in O(1)  
// first it checks whether first half chars of 'a' are equal to first half chars of b  
// if they compare second half  
// else compare decide on rank of first half  

int cmp(myTuple a, myTuple b) {  
    if(a.firstHalf == b.firstHalf) return a.secondHalf < b.secondHalf;  
    else return a.firstHalf < b.firstHalf;  
}

int main() {

    // Take input string
    // initialize size of string as N

    string s; cin >> s;
    int N = s.size();

    // Initialize suffix ranking on the basis of only single character
    // for single character ranks will be 'a' = 0, 'b' = 1, 'c' = 2 ... 'z' = 25

    for(int i = 0; i < N; ++i)
        suffixRank[0][i] = s[i] - 'a';

    // Create a tuple array for each suffix

    myTuple* L = new myTuple[N];

    // Iterate log(n) times i.e. till when all the suffixes are sorted
    // 'stp' keeps the track of number of iteration
    // 'cnt' store length of suffix which is going to be compared

    // On each iteration we initialize tuple for each suffix array
    // with values computed from previous iteration

    for(int cnt = 1, stp = 1; cnt < N; cnt *= 2, ++stp) {

        for(int i = 0; i < N; ++i) {
            L[i].firstHalf = suffixRank[stp - 1][i];
            L[i].secondHalf = i + cnt < N ? suffixRank[stp - 1][i + cnt] : -1;
            L[i].originalIndex = i;
        }

        // On the basis of tuples obtained sort the tuple array

        sort(L, L + N, cmp);

        // Initialize rank for rank 0 suffix after sorting to its original index
        // in suffixRank array

        suffixRank[stp][L[0].originalIndex] = 0;

        for(int i = 1, currRank = 0; i < N; ++i) {

            // compare ith ranked suffix ( after sorting ) to (i - 1)th ranked suffix
            // if they are equal till now assign same rank to ith as that of (i - 1)th
            // else rank for ith will be currRank ( i.e. rank of (i - 1)th ) plus 1, i.e ( currRank + 1 )

            if(L[i - 1].firstHalf != L[i].firstHalf || L[i - 1].secondHalf != L[i].secondHalf)
                ++currRank;

            suffixRank[stp][L[i].originalIndex] = currRank;
        }

    }

    // Print suffix array

    for(int i = 0; i < N; ++i) cout << L[i].originalIndex << endl;

    return 0;
} 

// Constructs the Longest Common Prefix (LCP) Array
// This is an array that shows the longest common prefix (substring starting
// at the beginning of a string) between consecutive substrings in the
// suffix array. Each element is the number of characters in common between
// suffix[i] and suffix[i+1].
// Uses Kasai algorithm.
vector<int> kasai(string s, vector<int> sa) {
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}

// We can use the substrings of a suffix array (substings of each suffix
// starting at its start and incrementing in length) to sort all the
// substrings of the string.
// One problem with suffix arrays is of repeating substrings.
// To solve this, since all substrings start at the start of a certain 
// suffixes, we can just check for the common prefixes between consecutive
// suffixes in the array (since they are sorted already, if two
// consecutive share a common prefix, we can guarantee a susbtring
// further in the suffix array will have as much, or less in common,
// otherwise it would be earlier in the array). That means we only
// need to worry about common prefixes between consectuive arrays.
// When we find common prefixes, we can ignore the substrings up to 
// the end of the common prefix in the second substring, either by
// subtracting it from the added sum, or by starting to count substrings
// that surpass this prefix:
// For example: for abcde and abcfh, we count a, ab, abc, abcd, abcde,
// as unique substrings and then, we count only abcf and abcfh.
// If we have a third suffix after that, it is a guarantee that it will
// have at most as much in common with the first suffix as the second,
// otherwise it would have been lexicographically smaller than it,
// so for example, abckl comes after, and we don't need to compare
// its prefix with any of the substrings that came before its
// predecessor, as we have already ensured that it will at most have
// with them as much in common as it does with its predecessor.
