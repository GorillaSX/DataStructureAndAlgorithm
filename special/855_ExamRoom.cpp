/*
855. Exam Room
DescriptionHintsSubmissionsDiscussSolution
In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

 

Example 1:

Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
Output: [null,0,9,4,2,null,5]
Explanation:
ExamRoom(10) -> null
seat() -> 0, no one is in the room, then the student sits at seat number 0.
seat() -> 9, the student sits at the last seat number 9.
seat() -> 4, the student sits at the last seat number 4.
seat() -> 2, the student sits at the last seat number 2.
leave(4) -> null
seat() -> 5, the student​​​​​​​ sits at the last seat number 5.
​​​​​​​

Note:

1 <= N <= 10^9
ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.

*/
struct range
{
    int left;
    int right;   
    range(int l, int r):left(l), right(r){}
};
class comp
{
public:
    bool operator()(const range& lhs, const range& rhs)
    {
        int llen = (lhs.right - lhs.left - 1) % 2 == 0 ? (lhs.right - lhs.left - 1) / 2 - 1 : (lhs.right - lhs.left - 1) / 2 ;
        int rlen = (rhs.right - rhs.left - 1) % 2 == 0 ? (rhs.right - rhs.left - 1) / 2 - 1 : (rhs.right - rhs.left - 1) / 2 ;
        return llen < rlen || (llen == rlen && lhs.left > rhs.left);
    }   
};
typedef priority_queue<range, vector<range>, comp> rangePQ;

class ExamRoom {
public:
    ExamRoom(int N) {
       n = N;
    }
    
    int seat() {
       int llen = -1; 
       if(seated.count(0) == 0) 
       {
           if(seated.size() == 0)
           {
               seated.insert(0);
               return 0; 
           }
           llen = (*seated.begin()) - 1;
       }
       int rlen  = -1; 
       if(seated.count(n-1) == 0)
       {
          rlen = n - 1 -  (*(--seated.end())) - 1;
       } 
       if(nextSeat.size() != 0) 
       {
           auto r =  nextSeat.top();
           int rangelen = (r.right - r.left - 1) % 2 == 0 ? (r.right - r.left - 1) / 2 - 1 : (r.right - r.left - 1) / 2 ;
           int pos = r.left + rangelen + 1;
           while(seated.count(r.left) == 0 || seated.count(r.right) == 0 || seated.count(pos) != 0)
           {
                nextSeat.pop();
                if(nextSeat.size() == 0)
                    break;
                r = nextSeat.top();
                rangelen = (r.right - r.left - 1) % 2 == 0 ? (r.right - r.left - 1) / 2 - 1 : (r.right - r.left - 1) / 2 ;
                pos = r.left + rangelen + 1;
           }
           if(nextSeat.size() != 0)
           {
               if(rangelen > llen && rangelen >= rlen)
               {
                    nextSeat.pop();
                   seated.insert(pos);
                   if(pos - r.left > 1)
                   {
                       nextSeat.emplace(r.left, pos);
                   } 
                   if(r.right - pos > 1)
                   {
                       nextSeat.emplace(pos, r.right);
                   }
                   return pos;
               }
           }
        } 
       if(llen >= rlen)
       {
            nextSeat.emplace(0, *seated.begin());        
            seated.insert(0);
            return 0;
       }
       else 
       {
           nextSeat.emplace((*(--seated.end())), n-1);
           seated.insert(n-1);
           return n - 1; 
       }

    }
    
    void leave(int p) {
       if(p != 0 && p != n-1)
       { 
            auto it = seated.find(p); 
            if(it != seated.begin() && it != --seated.end())
            {
                 int left =  *(--it); 
                int right = *(++(++it)); 
                nextSeat.emplace(left, right); 
            }
       }
       seated.erase(p); 
    }
private:
    set<int> seated;
    rangePQ nextSeat;    
    int n;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */