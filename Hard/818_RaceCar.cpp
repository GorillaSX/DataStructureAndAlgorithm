/*
818. Race Car
DescriptionHintsSubmissionsDiscussSolution
Your car starts at position 0 and speed +1 on an infinite number line.  (Your car can go into negative positions.)

Your car drives automatically according to a sequence of instructions A (accelerate) and R (reverse).

When you get an instruction "A", your car does the following: position += speed, speed *= 2.

When you get an instruction "R", your car does the following: if your speed is positive then speed = -1 , otherwise speed = 1.  (Your position stays the same.)

For example, after commands "AAR", your car goes to positions 0->1->3->3, and your speed goes to 1->2->4->-1.

Now for some target position, say the length of the shortest sequence of instructions to get there.

Example 1:
Input: 
target = 3
Output: 2
Explanation: 
The shortest instruction sequence is "AA".
Your position goes from 0->1->3.
Example 2:
Input: 
target = 6
Output: 5
Explanation: 
The shortest instruction sequence is "AAARA".
Your position goes from 0->1->3->7->7->6.
 

Note:

1 <= target <= 10000.
*/
class State 
{
    public:
    State(int position, int speed)
    {
       m_position = position;
       m_speed = speed;
       m_name = to_string(position) + "," + to_string(speed); 
    }
    int m_position;
    int m_speed;
    int m_steps;
    string m_name;
};

class Solution {
public:
    int racecar(int target) {
        if(target == 0)
            return 0;
        State start(0, 1, 0);
        queue<State> states;
        unordered_set<string> visited;
        visited.insert(states.m_name);
        states.push(start);
        int miniStep = INT_MAX;
        while(!start.empty())
        {
            State s = states.front();
            states.pop();
            if(s.m_position + s.m_speed == target)
            {
                miniStep = min(miniStep, s.m_steps + 1);
                continue;
            }
            if((target - s.m_position) * (s.m_speed) < 0)
            {
                State next(s.m_position, s.m_speed > 0 ? -1 : 1, s.m_steps + 1);
                if(visited.count(next.m_name) == 0)
                {
                    visited.insert(next.m_name);
                    states.push(next);
                }
            }
            else if((target < s.m_position &&  s.m_position + 2 * s.m_speed >= target) && (target > s.m_position && s.m_position + s.m_speed <= target)
            {
                State next(s.m_position + s.m_speed, 2  * s.m_speed, m_steps + 1);
                if(visited.count(next.m_name) == 0)
                {
                    visited.insert(next.m_name);
                    states.push(next);
                }
            }
            else 
            {
                State next1(s.m_position + s.m_speed, 2  * s.m_speed, m_steps + 1);
                if(visited.count(next1.m_name) == 0)
                {
                    visited.insert(next1.m_name);
                    states.push(next1);
                }
                State next2(s.m_position, s.m_speed > 0 ? 1 : -1, s.m_steps + 2);
                if(visited.count(next2.m_name) == 0)
                {
                    visited.insert(next2.m_name);
                    states.push(next2);
                }
            }
        }
        return miniStep;
    }
};