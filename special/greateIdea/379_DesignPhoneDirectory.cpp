/*
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
*/
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers):maxnumber(maxNumbers) {
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(released.size() == 0)
        {
            if(used.size() == maxnumber)
                return -1;
            int res = used.size();
            used.insert(res);
            return res;
        }
        else
        {
            int res = *released.begin();
            released.erase(res);
            used.insert(res);
            return res;
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return used.count(number) == 0;   
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number >= used.size() + released.size())
            return ;
        used.erase(number);
        released.insert(number);
    }
private:
    unordered_set<int> used;
    unordered_set<int> released;
    int maxnumber = 0;
};
