/*
380. Insert Delete GetRandom O(1)
DescriptionHintsSubmissionsDiscussSolution
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
       m_count = 0; 
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m_map.count(val) == 0)
        {
            m_dataArray.push_back(val);
            m_map[val] = m_count;
            m_count++;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
       if(m_map.count(val) == 0)
           return false;
       m_map[m_dataArray.back()] = m_map[val];
       m_dataArray[m_map[val]] = m_dataArray.back(); 
       m_dataArray.pop_back();  
       m_map.erase(val);
       m_count--;
       return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
       int index = rand() % m_count;
       return m_dataArray[index]; 
    }
private:
    vector<int> m_dataArray;
    int m_count;
    unordered_map<int, int> m_map;
};
