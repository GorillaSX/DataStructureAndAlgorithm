
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

struct DLinkedNode
{
    int key;
    int val;
    int freq; 
    DLinkedNode* next;
    DLinkedNode* prev;   
    DLinkedNode(int k, int v, int f):key(k), val(v), freq(f){}
};

class DLinkedList
{
    public:
        DLinkedList():m_count(0), m_tail(NULL), m_head(NULL){};
        int getSize(void)
        {
            return m_count;
        }
        DLinkedNode* RemoveTail(void)
        {
           if(m_count == 1)
           {
               DLinkedNode* tmp = m_tail;
               m_tail = NULL;
               m_head = NULL;
               m_count = 0;
               return tmp;  
           } 
           else 
           {
               DLinkedNode* tmp = m_tail;
               m_tail = m_tail->prev;
               m_tail->next = NULL;
               m_count--;  
               return tmp;
           } 
        } 
        void RemoveNode(DLinkedNode* node)
        {
           if(node == m_head && node == m_tail)
           {
               m_head = NULL, m_tail = NULL;
           } 
           else if(node == m_head && node != m_tail)
           {
               m_head = m_head->next;
               m_head->prev = NULL;
           } 
           else if(node == m_tail && node != m_head)
           {
               m_tail = m_tail->prev;
               m_tail->next = NULL;
           } 
           else 
           {
               node->prev->next = node->next;
               node->next->prev = node->prev;
           } 
            m_count--;
        }
        void insertAtFront(DLinkedNode* node)
        {
           if(m_head != NULL)
                m_head->prev = node;
           node->next = m_head;
           node->prev = NULL;
           m_head = node;
           if(m_count == 0)
           {
               m_tail = node;
           }
           m_count++;   
        }
    private:
        DLinkedNode* m_head;
        DLinkedNode* m_tail;
        int m_count;  
};
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
       if(cap == 0 || values.count(key) == 0)
            return -1;
       int value = values[key]->val;
       int freq = values[key]->freq;
       frequences[freq].RemoveNode(values[key]);
       (values[key]->freq)++; 
       frequences[values[key]->freq].insertAtFront(values[key]);  
       if(freq == minFreq && frequences[freq].getSize() == 0)
       {
           minFreq = freq + 1;
       } 
       return value;  
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return ;
        if(values.count(key) != 0)