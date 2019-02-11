/*
756. Pyramid Transition Matrix
DescriptionHintsSubmissionsDiscussSolution
We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:
Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  D   E
 / \ / \
X   Y   Z

This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
Example 2:
Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
Note:
bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
*/
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<string>> choice;
        for(auto allow : allowed)
        {
            choice[allow.substr(0,2)].push_back(allow.substr(2));
        } 
        unordered_map<string, bool> memo;
        return canBuild("", bottom, 0, choice,  memo);
    }
    
    bool canBuild(string top, string bottom, int index, unordered_map<string, vector<string>>& choice, unordered_map<string, bool>& memo)
    {
        if(index == bottom.size() - 1)
        {
            bottom = top;
            index = 0;
            top = "";
            if(memo.count(bottom))
                return memo[bottom];
        }
        if(bottom.size() == 2)
            return choice.count(bottom) != 0;
        string key = bottom.substr(index, 2);
        if(choice.count(key) == 0)
            return false;
        for(auto cho : choice[key])
        {
              string tmp = top + cho;
              if(canBuild(tmp, bottom, index+1, choice,memo))
                    return true; 
        }
        memo[bottom] = false;
        return false;
    }
};