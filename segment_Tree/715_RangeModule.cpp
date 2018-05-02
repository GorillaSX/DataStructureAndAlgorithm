/*
A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
Example 1:
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
Note:

A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000.
*/
struct STNode
{
    STNode(int s, int e):start(s), end(e),left(NULL), right(NULL){}
     void insert(STNode*& root)
    {
        if(root == NULL)
            root = this;
        else if(start >= root->end)
            return this->insert(root->right);
        else if(end <= root->start)
            return this->insert(root->left);
        else 
        {
            if(start < root->start)
            {
                STNode* newleft = new STNode(start, root->start);
                newleft->insert(root->left);
            }
            if(end > root->end)
            {
                STNode* newright = new STNode(root->end, end);
                newright->insert(root->right);
            }
        }
    }
    bool find(STNode* root)
    {
        if(root == NULL)
            return false;
        else if(start >= root->end)
            return this->find(root->right);
        else if(end <= root->start)
            return this->find(root->left);
        else 
        {
            bool leftreturn = true, rightreturn = true;
            if(start < root->start)
            {
                STNode* newleft = new STNode(start, root->start);
                leftreturn = newleft->find(root->left);
            }

            if(end > root->end)
            {
                STNode* newright = new STNode(root->end, end);
                rightreturn = newright->find(root->right);
            }
            return leftreturn && rightreturn;
        }
    }

    void remove(STNode*& root)
    {
        if(root == NULL)
            return ;
        else if(start >= root->end)
            return this->remove(root->right);
        else if(end <= root->start)
            return this->remove(root->left);
        else 
        {

            if(start == root->start && end < root->end)
            {
                root->start = end;
                return;
            }
            
            if(start > root->start && end == root->end)
            {
                root->end = start;
                return ;
            }

            if(start > root->start && end < root->end)
            {
                
                STNode* node = new STNode(end, root->end);
                node->right = root->right;
                root->end = start;
                root->right = node; 
                return ;
            }

            if(start < root->start)
            {
                STNode* newleft = new STNode(start, root->start);
                newleft->remove(root->left);
                if(end < root->end)
                {
                    root->start = end;
                    return;
                }
            }
            
            if(end > root->end)
            {
                STNode* newright = new STNode(root->end, end);
                newright->remove(root->right);
                if(start > root->start)
                {
                    root->end = start;
                    return;
                }
            }

                if(root->left == NULL && root->right == NULL)
                {
                    root = NULL;
                    return;
                }
                else if(root->left == NULL && root->right != NULL)
                    root = root->right;
                else if(root->left != NULL && root->right == NULL)
                    root = root->left;
                else 
                {
                    if(root->left->right == NULL)
                    {
                        root->left->right = root->right;
                        root = root->left;
                        return ;
                    }
                    STNode* tmp = root->left;
                    while(tmp->right->right != NULL)
                        tmp = tmp->right;
                    STNode* an = tmp->right->left;
                    tmp->right->right = root->right;
                    tmp->right->left = root->left;
                    root = tmp->right;
                    tmp->right = an;
                    return;
                }
        }
    }
    int start, end;
    STNode *left, *right;
};
class RangeModule {
public:
    STNode* root;
    RangeModule():root(NULL) {
        
    }
    
    void addRange(int left, int right) {
       STNode* node = new STNode(left, right);
       node->insert(root); 
    }
    
    bool queryRange(int left, int right) {
       STNode* node = new STNode(left, right);
       return node->find(root); 
    }
    
    void removeRange(int left, int right) {
       STNode* node = new STNode(left, right);
       node->remove(root) ;
    }
};