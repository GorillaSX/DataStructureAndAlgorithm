/*
Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
Explanation: 
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
*/
class STreeNode
{
    public:
    STreeNode(int left, int right, int count):m_left(left), m_right(right),m_leftNode(NULL), m_count(count),m_rightNode(NULL){}
    bool insertToTree(STreeNode* & root)
    {
        if(Check(root))
        {
            insert(root);
            return true;
        }
        return false;
    }
    void insert(STreeNode* & root)
    {
        if(root == NULL)
        {
            root = this;
        }
        else 
        {
           if(m_left >= root->m_right)
               insert(root->m_rightNode);
           else if(m_right <= root->m_left)
               insert(root->m_leftNode);
           else 
           {
                   if(m_left < root->m_left)
                   {
                       STreeNode* left = new STreeNode(m_left, root->m_left, m_count);
                       left->insert(root->m_leftNode);
                   }
                   else if(m_left > root->m_left)
                   {
                       STreeNode* left = new STreeNode(root->m_left, m_left, root->m_count);
                       left->m_leftNode = root->m_leftNode;
                       root->m_left = m_left;
                       root->m_leftNode = left;
                   }

                   if(m_right > root->m_right)
                   {
                       STreeNode* right = new STreeNode(root->m_right, m_right, m_count);
                       right->insertToTree(root->m_rightNode);
                   }
                   else if(m_right < root->m_right)
                   {
                       STreeNode* right = new STreeNode(m_right, root->m_right, root->m_count);
                       right->m_rightNode = root->m_rightNode;
                       root->m_right = m_right;
                       root->m_rightNode = right;
                   }
                   root->m_count += m_count;
               }                
           }
    }
    bool Check(STreeNode* & root)
    {
        if(root == NULL)
        {
            return true;
        }
        else 
        {
           if(m_left >= root->m_right)
              return Check(root->m_rightNode);
           else if(m_right <= root->m_left)
              return Check(root->m_leftNode);
           else 
           {
               if(root->m_count == 2 || m_count == 2)
                    return false;
               else 
               {
                   if(m_left < root->m_left)
                   {
                       STreeNode* left = new STreeNode(m_left, root->m_left, m_count);
                       if(!left->Check(root->m_leftNode))
                            return false;
                       delete left;   
                   }
                   if(m_right > root->m_right)
                   {
                       STreeNode* right = new STreeNode(root->m_right, m_right, m_count);
                       if(!right->Check(root->m_rightNode))
                            return false;
                       delete right;
                   }
                   return true;
               }                
           }
        }
    }
    int m_left;
    int m_right;
    int m_count;
    STreeNode* m_leftNode;
    STreeNode* m_rightNode;
};
class MyCalendarTwo {
public:
    STreeNode* root = NULL;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
       STreeNode* node = new STreeNode(start, end, 1); 
       return node->insertToTree(root);
    }
};