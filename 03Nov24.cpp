//    https://leetcode.com/problems/rotate-string/description/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        string rotated = s;
        for (int i = 0; i < s.length(); i++) {
            if (rotated == goal)
                return true;
            
            char ch = rotated[0];
            rotated.erase(0, 1); 
            rotated.push_back(ch); 
        }
        return false;
    }
};
