//    https://leetcode.com/problems/design-a-food-rating-system/description/
class FoodRatings {
    using pis = pair<int,string> ;
    unordered_map<string,string> food_to_cuisine_map ;
    unordered_map<string,multiset<pis>> cuisine_map ;
    unordered_map<string,multiset<pis>::iterator> food_to_iterator_map ;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0 ; i < foods.size() ; i++){
            food_to_cuisine_map[foods[i]] = cuisines[i] ;
            pis to_insert = {-1 * ratings[i], foods[i]} ;
            cuisine_map[cuisines[i]].insert(to_insert) ;
            food_to_iterator_map[foods[i]] = cuisine_map[cuisines[i]].find(to_insert) ;
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &m = cuisine_map[food_to_cuisine_map[food]] ;
        m.erase(food_to_iterator_map[food]) ;
        pis updated = {-1 * newRating, food} ;
        m.insert(updated) ;
        food_to_iterator_map[food] = m.find(updated) ;
    }
    
    string highestRated(string cuisine) {
        return (*cuisine_map[cuisine].begin()).second ;
    }
};
