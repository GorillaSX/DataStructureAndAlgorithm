/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/

//Because we need to verify preorder serialization, we must need to utilize the property of preorder traversal, as a preorder sequence, the parent must appear first, then it's child behind, this order is very important, so when we walk through this sequence, meet a node, then it's parent must appeared before, every parent have two child, then every child will consume one spot of two, and this child will generate two spot as a parent node, which two spot will be consumed later. we follow this rules to walk through the sequence, then every time when a child want to consume a spot, there are must have at least one. Because its parent appear first, if this rule is not be obeyed , then it's not a valid preorder traversal. And in inorder traversal and postorder traversal, this rule is broken.  This rule will not apply to inorder sequence, because we will meet child node first, and no empty slot generate by it's parent. 
class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder += ",";
        int slot = 1;
        for(int i = 0;i < preorder.size();i++)
        {
            if(preorder[i] != ',')
                continue;
            if(slot == 0)
                return false;
            slot--;
            if(preorder[i-1] != '#')
                slot+=2;
        }
        return slot == 0;
    }
};