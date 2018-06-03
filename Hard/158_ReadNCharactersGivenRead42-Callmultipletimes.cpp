/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.

Example 1: 

Given buf = "abc"
read("abc", 1) // returns "a"
read("abc", 2); // returns "bc"
read("abc", 1); // returns ""
Example 2: 

Given buf = "abc"
read("abc", 4) // returns "abc"
read("abc", 1); // returns ""
*/
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
       int count = 0;
       while(n > 0)
       {
           while(!more.empty() && n > 0)
           {
               buf[count++] = more.top();
               more.pop();
               n--;
           }
           if(n == 0)
               return count;
           int readed = read4(&buf[count]);
           count += readed;
           if(n < readed)
           {
               int k = readed - n;
               while(k != 0)
               {
                   --count;
                   more.push(buf[count]);
                   buf[count] = '\0';
                   k--;
               }
               return count;
           }
           else if(readed < 4)
           {
               return count;
           }
           n -= 4;
       } 
       return count;
    }
    stack<char> more;
};