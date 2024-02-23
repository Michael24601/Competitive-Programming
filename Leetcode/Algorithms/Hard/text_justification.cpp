/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/text-justification/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        // Where we are in the words vector
        int index{};
        // Lines
        vector<string> lines;

        if(words.size() == 1){
            int spaces = maxWidth - words[0].size();
            string space(spaces, ' ');
            words[0] += space;
            lines.push_back(words[0]);
            return lines;
        }

        // Each time we need to check to make sure that the
        // words fit in a line, we need to check first by adding
        // n-1 spaces, the minimum number of spaces. After that, if
        // the space is less than the capacity, we pad spaces accordingly.

        while(index < words.size()){
            string text;
            // At least one word is added
            int addIndex = 1;
            int widthThusFar = words[index].size();
            while(widthThusFar <= maxWidth && addIndex + index-1 < words.size()){
                // Each time we add a word after the first, we add a space
                // (1) and a the word length

                // Note that we add this check just in case we reach the end
                // of the word length (we can't add it to the while loop
                // as a whole since that causes infinite looping when we have
                // only a single word left in a line).
                if(addIndex + index < words.size())
                    widthThusFar += 1 + words[index + addIndex].size();
                cout << addIndex + index-1 << " " <<  words.size() << "\n";
                addIndex++;
            }

            // Remove width that made it overflow
            // We check that there is extra width first however in case we
            // left thew while loop not because the width overflowed but
            // because we are out of words.
            if(widthThusFar > maxWidth)
                widthThusFar -= (1 + words[index + addIndex - 1].size());
            addIndex--;
            int spacesToAdd = maxWidth - widthThusFar;
            // Width added to all spaces
            int minWidthToAdd 
                = (addIndex-1 == 0 ? 0 : spacesToAdd/(addIndex-1));
            int firstSpacesWithExtraWidth 
                = (addIndex-1 == 0 ? 0 : spacesToAdd % (addIndex-1));

            // If this isnt the last line
            if (index + addIndex < words.size()){
                for(int i = 0; i < addIndex; i++){
                    text += words[index + i];
                    int numberOfSpaces;
                    // If there is only one word in the line, just add all spaces
                    // after it.
                    if(i == addIndex-1 && i == 0){
                        numberOfSpaces = spacesToAdd;
                    }
                    // Otherwise if it's the last, but not only word,
                    // we add no spaces.
                    else if (i == addIndex-1){
                        numberOfSpaces = 0;
                    }
                    else if(i < firstSpacesWithExtraWidth){
                        // First + 1 is regular space second + 1 is the left over
                        // spaces after distributing them
                        numberOfSpaces = minWidthToAdd + 1 + 1;
                    }
                    else{
                        // + 1 is the regular space
                        numberOfSpaces = minWidthToAdd + 1;
                    }
                    string charactersToAdd(numberOfSpaces, ' ');
                    text += charactersToAdd;
                }
            }
            // If it's the last word however, we simply add 1 space per,
            // then add the rest of the needed spaces.
            else{
                for(int i = 0; i < addIndex; i++){
                        text += words[index + i];
                        int numberOfSpaces;
                        // Last word in line
                        if(i == addIndex-1){
                            numberOfSpaces = spacesToAdd;
                        }
                        else{
                            // + 1 is the regular space
                            numberOfSpaces = 1;
                        }
                        string charactersToAdd(numberOfSpaces, ' ');
                        text += charactersToAdd;
                    }
            }
            index += addIndex;
            lines.push_back(text);
            cout << text <<" " <<  addIndex << "\n";
        }
        return lines;
    }
};