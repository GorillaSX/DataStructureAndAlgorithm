/*
318. Maximum Product of Word Lengths
DescriptionHintsSubmissionsDiscussSolution
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.
*/
class Solution {
public:
    int GenerateRepresentation(string word)
    {
        int result = 0;
        for(int i = 0;i < word.size();i++)
        {
            result |= (1 << (word[i] - 'a'));
        }
        return result;
    }
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mapFromRepToWord;
        for(auto word : words)
        {
            int rep = GenerateRepresentation(word);
            mapFromRepToWord[rep] = max(mapFromRepToWord[rep], int(word.size()));
        }
        int result = 0;
        for(auto left : mapFromRepToWord)
        {
            for(auto right : mapFromRepToWord)
            {
                if((left.first & right.first) == 0)
                {
                    result = max(result, left.second * right.second);
                }
            }
        }
        return result;
    }
};