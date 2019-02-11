/*
411. Minimum Unique Word Abbreviation
DescriptionHintsSubmissionsDiscussSolution
A string such as "word" contains the following abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.

Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.

Note:
In the case of multiple answers as shown in the second example below, you may return any one of them.
Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
Examples:
"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")

"apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").
*/
class Solution {
public:
    int GenerateDifferent(string source, string target)
    {
        int len = source.size() - 1;
        int result = 0;
        for(int i = 0;i < source.size();i++)
        {
            if(source[i] != target[i])
            {
                result += (1 << (len - i)); 
            } 
        }
        return result;
    }
    
    int abbLen(int mask, int len)
    {
       int length = 0; 
       int zero = 0; 
       for(int i = 0;i < len;i++)
       {
          if(((mask  >> i) & 1) != 0) 
          {
              if(zero)
              {
                length = length + to_string(zero).size();
                zero = 0;
              }
              length++;
          }
          else 
          {
              zero++;
          }
       } 
        if(zero)
            length = length + to_string(zero).size();
        
       return length;
    }
    
    string reconstruct(int mask, int len, string source)
    {
        int zeros = 0;
        string result = "";
        for(int i = len-1; i >= 0;i--)
        {
            if(((mask >> i) & 1) != 0)
            {
                if(zeros)
                {
                    result.append(to_string(zeros));
                    zeros = 0;
                }
                result.push_back(source[len - 1 - i]);
            }
            else 
                zeros++;
        }
        if(zeros)
            result.append(to_string(zeros));
        
        return result;
    }
    void dfs(unordered_set<int>& differences, int len, int masks, int index, int mask, int& result)
    {
        int tmp = mask;
        bool find = true;
        for(auto& diff : differences)
        {
            if((diff & tmp) == 0 )
            {
                find = false;
                break;
            }
        }
        if(find)
        {
            if(abbLen(tmp, len) < abbLen(result, len))
            {
                result = tmp;
            }
        }
        else 
        {
               for(int i = index;i <= 21;i++)
               {
                   if((masks >> i) & 1 != 0)
                   {
                       dfs(differences, len, masks, i + 1, mask + (1 << i), result);
                   }
               }  
        }
    }
    
    
    string minAbbreviation(string target, vector<string>& dictionary) {
        unordered_set<int> differences;
        int masks = 0;
        for(auto word : dictionary)
        {
            if(word.size() == target.size())
            {
                int diff = GenerateDifferent(target, word);
                masks |= diff;
                differences.insert(diff);
            }
        } 
        int result = masks;
        cout << masks << endl;
        dfs(differences, target.size(), masks, 0, 0, result);
        
        return reconstruct(result, target.size(), target);
    }
    
};