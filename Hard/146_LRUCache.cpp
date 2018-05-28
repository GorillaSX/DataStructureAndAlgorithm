/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

struct DLNode
{
   int key;
   int val;
   DLNode* prev, *next;
   DLNode(int k, int v):key(k), val(v), prev(NULL), next(NULL){}
};
class LRUCache {
public:
    LRUCache(int capacity):m_size(0), m_capacity(capacity),begin(NULL), end(NULL) {
    }
    
    int get(int key) {
       if(mapping.count(key) != 0)
       {
           DLNode* tmp = mapping[key];
           if((tmp == begin && tmp == end) or (tmp == begin))
                return tmp->val;
           else
           {
               tmp->prev->next = tmp->next;
               if(tmp == end)
                    end = tmp->prev;
               else 
                    tmp->next->prev = tmp->prev;
               tmp->next = begin;
               tmp->prev = NULL;
               begin = tmp;
               begin->next->prev = begin;
               return begin->val;
           }
       }
       else
            return -1;
    }
    
    void put(int key, int value) {
        if(m_capacity == 0)
            return;
        else 
        {
            if(m_size == m_capacity && mapping.count(key) == 0)
            {
                m_size--;
                mapping.erase(end->key);
                end = end->prev;
                if(end != NULL)
                {
                    end->next = NULL;
                }
                else 
                {
                    begin = NULL;
                }
            }
            if(mapping.count(key) == 0)
            {
                DLNode* tmp = new DLNode(key, value);
                tmp->next = begin;
                begin = tmp;
                if(begin->next != NULL)
                {
                    begin->next->prev = begin;
                }
                else
                {
                    end = begin;
                }
                mapping[key] = tmp;
                m_size++;
            }
            else
            {
                DLNode* tmp = mapping[key];
                if((tmp == begin && tmp == end) || tmp == begin)
                {
                    tmp->val = value;
                }
                else
                {
                    tmp->prev->next = tmp->next;
                    if(tmp->next != NULL)
                        tmp->next->prev = tmp->prev;
                    else
                        end = tmp->prev;
                    tmp->next = begin;
                    tmp->prev = NULL;
                    tmp->next->prev = tmp;
                    begin = tmp;
                    begin->val = value;
                }
            }
        }
    }
private:
    int m_size;
    int m_capacity;
    DLNode* begin;
    DLNode* end;
    unordered_map<int, DLNode*> mapping;
};