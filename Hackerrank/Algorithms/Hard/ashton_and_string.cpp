/*
    Website: Hackerank
    Difficulty: Hard
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/ashton-and-string/problem
*/


#include <bits/stdc++.h>

using namespace std;

// Structure to store information of a suffix
struct suffix
{
    long index; // To store original index
    long rank[2]; // To store ranks and next rank pair
};
 
// A comparison function used by sort() to compare two suffixes
// Compares two pairs, returns 1 if first pair is smaller
long cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
               (a.rank[0] < b.rank[0] ?1: 0);
}
 
// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
vector<long> buildSuffixArray(string txt) {
    
    long n = txt.size();
    
    // A structure to store suffixes and their indexes
    struct suffix *suffixes = new suffix[n];
 
    // Store suffixes and their indexes in an array of structures.
    // The structure is needed to sort the suffixes alphabetically
    // and malongain their old indexes while sorting
    for (long i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
    }
 
    // Sort the suffixes using the comparison function
    // defined above.
    sort(suffixes, suffixes+n, cmp);
 
    // At this polong, all suffixes are sorted according to first
    // 2 characters.  Let us sort suffixes according to first 4
    // characters, then first 8 and so on.
    // This array is needed to get the index in suffixes[]
    // from original index.  This mapping is needed to get
    // next suffix.
    long *ind = new long[n];  
    for (long k = 4; k < 2*n; k = k*2)
    {
        // Assigning rank and index values to first suffix
        long rank = 0;
        long prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
 
        // Assigning rank to suffixes
        for (long i = 1; i < n; i++)
        {
            // If first rank and next ranks are same as that of previous
            // suffix in array, assign the same new rank to this suffix
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else // Otherwise increment rank and assign
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
 
        // Assign next rank to every suffix
        for (long i = 0; i < n; i++)
        {
            long nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                                  suffixes[ind[nextindex]].rank[0]: -1;
        }
 
        // Sort the suffixes according to first k characters
        sort(suffixes, suffixes+n, cmp);
    }
 
    // Store indexes of all sorted suffixes in the suffix array
    vector<long> suffixArr(n);
    for (long i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
 
    // Return the suffix array
    return  suffixArr;
}

// Constructs the Longest Common Prefix (LCP) Array
// This is an array that shows the longest common prefix (substring starting
// at the beginning of a string) between consecutive substrings in the
// suffix array. Each element is the number of characters in common between
// suffix[i] and suffix[i+1].
// Uses Kasai algorithm.
std::vector<long> constructLCPArray(std::string txt, std::vector<long>& suffixArr) {
    long n = suffixArr.size();

    // To store LCP array
    std::vector<long> lcp(n, 0);

    // An auxiliary array to store the inverse of suffix array
    // elements. For example, if suffixArr[0] is 5, invSuff[5] would store 0.
    // This is used to get the next suffix string from the suffix array.
    std::vector<long> invSuff(n, 0);

    // Fill values in invSuff[]
    for (long i = 0; i < n; i++)
        invSuff[suffixArr[i]] = i;

    // Initialize the length of the previous LCP
    long k = 0;

    // Process all suffixes one by one starting from
    // the first suffix in txt[]
    for (long i = 0; i < n; i++)
    {
        // If the current suffix is at n-1, then we don't
        // have the next substring to consider. So the LCP is not
        // defined for this substring; we put zero.
        if (invSuff[i] == n - 1)
        {
            k = 0;
            continue;
        }

        // j contains the index of the next substring to
        // be considered to compare with the present
        // substring, i.e., the next string in the suffix array
        long j = suffixArr[invSuff[i] + 1];

        // Directly start matching from the k'th index as
        // at least k-1 characters will match
        while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
            k++;

        // LCP for the present suffix
        lcp[invSuff[i]] = k;

        // Deleting the starting character from the string
        if (k > 0)
            k--;
    }

    // Return the constructed LCP array
    return lcp;
}

int main() {
    long t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long k;
        cin >> k;

        // Memoize the sum up to n for later use (long linear time)
        // where sum[i] = sum of 1 to i
        vector<long long> sumOf(s.size() + 1);
        sumOf[0] = 0;
        for(long i = 1; i <= s.size(); i++){
            sumOf[i] = sumOf[i-1] + i;
        }

        // Our strategy will be to go over all susbtrings by using the
        // suffix array. Each suffix array of length n will contain n of
        // strings susbtrings (all starting at the beginning of the suffix
        // in the suffix array, and incrementing in length until they hit
        // the end of the string). We can continuoysly append this length
        // and skip over large swaths of substrings until we reach one
        // that exceeds k's size, at which polong we iterate through it until
        // we reach the kth character.
        
        // But one problem remains, and that is, repeating substrings.
        // Since all substrings start at the start of a certain suffixes,
        // we can just check for the common prefixes between consectuive
        // suffixes in the array (since they are sorted already, if two
        // consecutive share a common prefix, we can guarantee a susbtring
        // further in the suffix array will have as much, or less in common,
        // otherwise it would be earlier in the arrat). That means we only
        // need to worry about common prefixes between consectuive arrays.
        // When we find common prefixes, we can ignore the substrings up to 
        // the end of the common prefix in the second substring, either by
        // subtracting it from the added sum, or by starting to count substrings
        // that surpass this prefix:
        // For example: for abcde and abcfh, we count a, ab, abc, abcd, abcde,
        // and then, we count only abcf and abcfh.
        // If we have a third suffix after that, it is a guarantee that it will
        // have at most as much in common with the first suffix as the second,
        // otherwise it would have been lexicographically smaller than it,
        // so for example, abckl comes after, and we don't need to compare
        // its prefix with any of the substrings that came before its
        // predecessor, as we have already ensured that it will at most have
        // with them as much in common as it does with its predecessor.

        vector<long> suffixArray = buildSuffixArray(s);
        vector<long> LCPArray = constructLCPArray(s, suffixArray);
        
        // Records how many characters we've passed at this polong
        long long sum{}; 
        
        // Suffix that will contain our kth character
        string correctSuffix;
        
        // Explained later
        long indecesToSkip{};
    
        for(long i = 0; i < s.size(); i++){
            long index = suffixArray[i];
            // Number of substrings in this suffix starting at its beginning.
            long numberOfSubstrings = s.size() - index;
            long charactersInSubstrings = sumOf[numberOfSubstrings];
            
            long numberOfSubstringsToCountOut{};
            if(i > 0){
                numberOfSubstringsToCountOut = LCPArray[i-1];
            } 
            long charactersToCountOut = sumOf[numberOfSubstringsToCountOut];
            
            long numberToAdd = charactersInSubstrings - charactersToCountOut;
        
            // If these substrings don't reach the threhsold
            if(sum + numberToAdd < k){
                sum += numberToAdd;
            }
            // Else, the correct character is in this susbtring
            else{
                correctSuffix = s.substr(index);
                
                // When we reach the correct suffix with out character 
                // (correctSuffix), we have to count the characters
                // in all the susbtrings starting at the start of this 
                // suffix to reach our index k, but we don't count from
                // the first susbstring with size 1 necessarily, since
                // it may not be unique, and may hav been passed already.
                // Instead, we count only starting with a size that exceeds
                // the common prefix with the last suffix, which is
                // what this vairbale does. 
                indecesToSkip = numberOfSubstringsToCountOut;
                break;
            }
        }

        // We then search through it, each iteration i is the subtring of
        // te suffix of length i+1, all beginning at the start of the suffix.
        // Note that we start couting substrings tarting from "indeces to
        // skip", since we skip substrings in common with the last suffix,
        // which are already counted (out).
        for(long i = indecesToSkip; i < correctSuffix.size(); i++){
            long size = i + 1;
            // If this whole susbtring is in this suffix +                 
            // the sum we have doesn't reach the threshhold.
            if(sum + size < k){
                sum += size;
            }
            else{
                long indexOfCharacter = k - sum;
                // -1 since we're counting starting at 0
                cout << correctSuffix[indexOfCharacter-1] << "\n";
                break;
            }
        }
    }

    return 0;
}
