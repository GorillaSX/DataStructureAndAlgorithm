/*
 * Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.
 *
 * For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].
 *
 * Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.
 *
 * Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.
 *
 * Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.
 *
 * Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
 *
 */

//union find solution


class UnionFind
{
   public:
       UnionFind(vector<pair<string,string>>& pairs)
       {
          for(auto & p : pairs)
          {
             if(map.count(p.first) == 0)
             {
                map[p.first] = array.size();
                array.push_back(array.size());
             }
             if(map.count(p.second) == 0)
             {
                map[p.second] = array.size();
                array.push_back(array.size());
             }
          }
       }
       
       int find(int i)
       {
           while(array[i] != i)
           {
               i = array[i];
           }
           return i;
       }
       
       void connect(string left, string right)
       {
           int l = map[left];
           int r = map[right];
           int lr = find(l);
           int rr = find(r);
           if(lr != rr)
           {
              array[lr] = rr;
           }
       }

       bool checkSimilarity(string left, string right)
       {
           int l = map[left];
           int r = map[right];
           int lr = find(l);
           int rr = find(r);
           if(lr != rr)
               return false;
           else
               return true;

       }

       bool isIn(string word)
       {
           if(map.count(word) == 1)
                return true;
           else
                return false;
       }

   private:
       unordered_map<string, int> map;
       vector<int> array;
};
class Solution
{
    public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs)
    {
         if(words1.size() != words2.size())
         {
            return false;
         }
         UnionFind uf(pairs);
         for(auto& p : pairs)
         {
            uf.connect(p.first, p.second);
         }
         for(int i = 0;i < words1.size();i++)
         {
            if(words1[i] != words2[i])
            {
                if((!uf.isIn(words1[i]) || !uf.isIn(words2[i])) || !(uf.checkSimilarity(words1[i], words2[i])))
                    return false;
            }
         }
         return true;
    }
};