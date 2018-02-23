/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 1)
            return "/";
        stack<string> pathStack;
        pathStack.push("/");
        for(int i = 1;i < path.size();)
        {
            if(path[i] == '/')
                i++;
            else
            {
                int j = i + 1;
                while(j < path.size() &&path[j] != '/')
                    j++;
                string p = path[j] != '/' ? path.substr(i, j - i + 1) : path.substr(i, j - i);
                if(p == "..")
                {
                    if(pathStack.size() > 1)
                        pathStack.pop();
                }
                else
                {
                    if(p != ".")
                    pathStack.push(p + "/");
                }
                i = j + 1;
            }
        }       
        string results;
        while(!pathStack.empty())
        {
            results = pathStack.top() + results;
            pathStack.pop();
        }
        if(results == "/" )
            return "/";
        else
            return results.substr(0, results.size() - 1);
    }
};