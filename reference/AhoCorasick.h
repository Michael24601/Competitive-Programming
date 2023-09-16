#ifndef AHO_CORASICK
#define AHO_CORASICK

#include <bits/stdc++.h>

using namespace std;

// A modified trie data structure with "fail links".
// Used for matching a text and the patterns in it or vice versa
// Note that in this version, we allow for the same pattern to be repeated
// twice if it is associated with different values (or even if it is associated
// with the same value twice or more, since we include in each end of pattern
// node an array of properties that can be looped over to consider all
// repeated instances of the same pattern). We can also not do that, and
// either include a single valued extra property (or more), or just not
// have extra properties for simple pattern matching. We can modify the
// add function to possibly take properties and either set them if unique,
// or add them to a vector if the pattern can exist more than once.
// We can also make it so if the same pattern and property are added,
// it can consider them distinct and push the property to the vector again,
// or search the vector first and add nothing if found. It's up to us.
// We can then moedify the match function to return the patterns, or number
// of patterns, or loop over the property vectors of each patterns in case
// our domain considers them different, or return something related to these
// properties... etc.
// If we want to consider the same pattern added more than once different,
// but not associate it with multiple properties, we can add a counter to
// the trieNode and increment it in the add function, and process that number
// in the match (like adding the macthed pattern to the vector or count the
// counter number of times to reflect repetition).
// In other words, we can modify it to do as we will, so long as we are
// matching text with patterns.
class AhoCorasick {

public:

    AhoCorasick() {
        root = new TrieNode();
    }

    // Adds pattern.
    // We can send the string pattern along with any other property we want,
    // and these properties are then appended to the patterns. Since not
    // all nodes signify the end of a word, only those that do are appended
    // with the property. Usually, if the same pattern is sent twice, nothing
    // is added, but if the same pattern can be associated with 2 different
    // property values, then we may create an array/vector in the node
    // of each pattern to allow the pattern to functionally act as two or more.
    void addPattern(const string& pattern, int property) {
        TrieNode* current = root;
        for (char c : pattern) {
            if (!current->children[c - 'a']) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEndOfPattern = true;
        current->addedProperty.push_back(property);
        current->pattern = pattern;
    }

    // Builds failure links for all nodes in the trie
    void buildFailureLinks() {
        queue<TrieNode*> q;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (root->children[c - 'a']) {
                root->children[c - 'a']->fail = root;
                q.push(root->children[c - 'a']);
            }
        }

        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();

            for (char c = 'a'; c <= 'z'; ++c) {
                TrieNode* child = current->children[c - 'a'];
                if (child) {
                    TrieNode* failure = current->fail;
                    while (failure && !failure->children[c - 'a']) {
                        failure = failure->fail;
                    }
                    child->fail = failure ? failure->children[c - 'a'] : root;
                    q.push(child);
                }
            }
        }
    }

    // Matches patterns to the input text and the patterns in the trie.
    // The returned patterns are either within the text, or the text in the
    // patterns that are returned. We can modify the function to return 
    // the count of these patterns, or some either added property in the
    // trieNode struct.
    vector<string> match(const string& text, int start, int end) {
        TrieNode* current = root;
        vector<string> matches;

        for (size_t i = 0; i < text.length(); ++i) {
            char c = text[i];
            while (current != root && !current->children[c - 'a']) {
                current = current->fail;
            }
            current = current->children[c - 'a'] ? current->children[c - 'a'] : root;

            // Traverse failure links and collect H values
            TrieNode* temp = current;
            while (temp != root) {
                if (temp->isEndOfPattern) {

                    // Note that even if a pattern is associated with multiple
                    // other values, effectively making it more than one node,
                    // the matches vector only includes one instance of it.
                    // To include multiple instances in the case where we want
                    // to treat patterns differently based on some other
                    // property, we can loop over temp->addedProperty and
                    // do as we will. The vector addedProperty's length is
                    // based on how many of the same pattern we have with
                    // each with possibly different values. So we can include
                    // the match temp->addedProperty.size() times in order
                    // to allow for repetition in case they're considered 
                    // different.
                    matches.push_back(temp->pattern);

                    // We can also loop over all the property values of a node
                    // in case a single node represents more than one pattern
                    // each with its own properties. Otherwise, it's enough to 
                    // just process the node once. We can here add logic to
                    // return something other than the matches, and add 
                    // conditions on which patterns we consider.
                }
                temp = temp->fail;
            }
        }

        return matches;
    }

private:
    // Allows lowercase alphabet letters (a to z). We can moedify the class
    // to accept other ASCII characters though, in the add and search 
    // functions.
    static const int ALPHABET_SIZE = 26;

    // Each node contains these values, plus any properties we decide to add.
    // If a pattern can apepear more than once by having different properties,
    // the properties need to be an array, and must be appended.
    struct TrieNode {
        TrieNode* children[ALPHABET_SIZE];
        TrieNode* fail;

        // Some nodes dont represent words, but rather, a prefix letter to 
        // a word (or pattern). Only if it is the end of the pattern do we
        // consider the node to be that of a pattern, and add in it the
        // string pattern and sometimes, other properties to be processed
        // in the match function.
        bool isEndOfPattern;

        // We store the pattern in the trieNode in case this is the end
        // of teh pattern and we want to easily access it. This value is
        // set in the insert process.
        string pattern;

        // Vector of some property in case the same pattern can have different
        // properties. Can be a single value otherwise.
        vector<int> addedProperty;

        TrieNode() {
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                children[i] = nullptr;
            }
            fail = nullptr;
            isEndOfPattern = false;
        }
    };

    TrieNode* root;
};

#endif