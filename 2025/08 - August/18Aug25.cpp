//    https://leetcode.com/problems/24-game/description/
class Solution {
public:
    vector<char> op = {'+','-','*','/'};
    bool check(vector<double> &card){
        bool flag = false;
        for(double &d : card){
            if(d != -1 && d != 24)return false;
            else if(d == 24)flag = true;
        }
        return flag;
    }
    double operation(double a, double b, char o){
        if(o == '+')return a+b;
        else if(o == '-')return a-b;
        else if(o == '*')return a*b;
        else return a/b;
    }
    bool solve(vector<double> &card){
        if(check(card))return true;
        for(int i = 0; i < card.size(); i++){
            if(card[i] == -1)continue;
            for(int j = 0; j < card.size(); j++){
                if(i == j)continue;
                if(card[j] == -1)continue;
                double a = card[i], b = card[j];
                for(char &o : op){
                    card[i] = operation(a,b,o);
                    card[j] = -1;
                    if(solve(card))return true;
                    card[i] = a;
                    card[j] = b;
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> card;
        for(int ele : cards)card.push_back((double)ele);
        return solve(card);
    }
};
