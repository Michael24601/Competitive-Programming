
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

// Constructs a Suffix Array data structure:
// It is an array containing the indeces of the suffix substings of a string
// input (meaning substrings that end at the end of the string but can begin
// anywhere) in lexicographic order of the strings.

// There are many algorithms for building a suffix array, but this is among
// the most efficient, called the Kärkkäinen-Sanders Algorithm.
vector<long> buildSuffixArray(string txt) {
    
    long n = txt.size();
    
    // A structure to store suffixes and their indexes
    struct suffix* suffixes = new suffix[n];
 
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
    // characters, then first 8 and so on
    // This array is needed to get the index in suffixes[]
    // from original index.  This mapping is needed to get the next suffix.
    long* ind =  new long[n];
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
