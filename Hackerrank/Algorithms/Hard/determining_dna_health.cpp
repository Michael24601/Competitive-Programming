/*
    Website: Hackerank
    Difficulty: Hard
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/determining-dna-health/problem
*/


#include <bits/stdc++.h>

using namespace std;

class AhoCorasick {
public:
    AhoCorasick() {
        root = new TrieNode();
    }

    // Add a pattern to the Aho-Corasick automaton
    void addPattern(const string& pattern, int h, int index) {
        TrieNode* current = root;
        for (char c : pattern) {
            if (!current->children[c - 'a']) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEndOfPattern = true;
        current->h_values.push_back(h);
        current->indeces.push_back(index);
        patterns.push_back(pattern);
    }

    // Build failure links for all nodes in the trie
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

    // Match patterns in the input string
    long long match(const string& text, int start, int end) {
        TrieNode* current = root;
        long long sum{};

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
                    for (int i = 0; i < temp->h_values.size(); i++) {
                        if (start <= temp->indeces[i] && temp->indeces[i] <= end) {
                            sum += temp->h_values[i];
                        }
                    }
                }
                temp = temp->fail;
            }
        }

        return sum;
    }

private:
    // Allows lowercase alphabet letters (a to z)
    static const int ALPHABET_SIZE = 26;

    struct TrieNode {
        TrieNode* children[ALPHABET_SIZE];
        TrieNode* fail;
        vector<int> h_values;
        vector<int> indeces;
        bool isEndOfPattern;

        TrieNode() {
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                children[i] = nullptr;
            }
            fail = nullptr;
            isEndOfPattern = false;
        }
    };

    TrieNode* root;
    vector<string> patterns;
};

int main() {
    AhoCorasick aho;

    long long n;
    cin >> n;
    vector<string> genes(n);

    for (long long i = 0; i < n; i++) {
        cin >> genes[i];
    }

    for (long long i = 0; i < n; i++) {
        long long health;
        cin >> health;
        aho.addPattern(genes[i], health, i);
    }

    // Build failure links and outputs in the Trie
    aho.buildFailureLinks();

    long long s;
    cin >> s;

    long long minHealth = 9999999999999, maxHealth = -1;

    for (long long i = 0; i < s; i++) {
        string dna;
        long long start, end;
        cin >> start >> end >> dna;

        // Checks which patterns are in it and sums them if they're in the range
        long long sum = aho.match(dna, start, end);

        if (maxHealth < sum) {
            maxHealth = sum;
        }
        if (minHealth > sum) {
            minHealth = sum;
        }
    }

    cout << minHealth << " " << maxHealth;

    return 0;
}