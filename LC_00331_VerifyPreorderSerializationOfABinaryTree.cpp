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

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Tags Stack
*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int N = preorder.length();
        int i = 0;
        int child_num = 1;

        for (int i = 0; i <= N; i++) {
            if ('0' <= preorder[i] && preorder[i] <= '9') //avoid multiple check for more than one digits element
                continue;
            if (--child_num < 0) //when hit ',', it is the end of one element, conmsume one potential child expected before.
                return false;
            if (preorder[i] == ',' || i == N) { //expect two new children for normal element
                child_num += 2;
            } else { //for #, consume one potential child and bypass next ','
                i++;
            }
        }
        return child_num == 0;
    }
};
