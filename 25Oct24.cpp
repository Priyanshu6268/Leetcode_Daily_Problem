//    https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;

        // Sorting so that we wont have problem in dealing test cases
        sort(folder.begin(),folder.end());

        // To compare with the last string we took
        stack<string>stk;
        stk.push(folder[0]);
        for(int i = 1; i<folder.size();i++)
        {
            string temp = stk.top() + '/';
            if(folder[i].compare(0,temp.size(),temp) == 0) // substring found 
                continue;
            else
                stk.push(folder[i]);
        }
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
