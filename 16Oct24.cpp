//    https://leetcode.com/problems/longest-happy-string/description/
class Solution {
public:
    using int2 = pair<int, char>;
    string longestDiverseString(int a, int b, int c) {
        string ans;
        int2 x[3] = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (1) {
            nth_element(x, x+1, x+3);// partition equivalent to sort 3 elements
            // Get the freq and char
            auto& [f2, c2]= x[2];
            auto& [f1, c1]= x[1];
            int &f0 = x[0].first;

            if (f2==0) break; // No more characters to add

            // Add the most frequent character
            int len= ans.size();
            if (len>= 2 && ans[len-1] == c2 && ans[len-2] == c2) {
                if (f1==0) break; // No valid character to add
                ans+=c1;
                f1--;
            } 
            else {
                // Otherwise, add the most frequent character
                ans += c2;
                f2--;
            }
        }
        return ans;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
