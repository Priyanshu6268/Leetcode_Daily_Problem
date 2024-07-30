//    https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/

class Solution {
public:
    int minimumDeletions(string s){
       stack<char> stack;
        int deletions = 0;
        for(auto&c : s){
            if(c == 'b'){
                // Push 'b' onto the stack
                stack.push(c);
            }else if(c == 'a'){
                if (!stack.empty()) {
                    // We have a 'b' before 'a', which is unbalanced
                    // Remove one 'b' from the stack ( delete it)
                    stack.pop();
                    deletions++;
                }
            }
        }
        return deletions;
    }
};
