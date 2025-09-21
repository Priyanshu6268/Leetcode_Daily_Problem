//.  https://leetcode.com/problems/design-movie-rental-system/description/
class MovieRentingSystem {
public:
    struct PairHash {
        size_t operator()(const std::pair<int, int>& p) const {
            // Combine the hash values of individual elements
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
        }
    };
    unordered_map<int, set<pair<int,int>>> movie_map;
    unordered_map<pair<int,int>, int, PairHash> price_map;
    set<pair<pair<int, int>, int>> rented_movies;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {

        for(int i=0;i<entries.size();i++) {
            int shop = entries[i][0],movie = entries[i][1],price = entries[i][2];
            auto it = movie_map.find(movie);
            if(it == movie_map.end()) {
                set<pair<int, int>> st = {};
                movie_map.emplace(movie, st);
                it = movie_map.find(movie);
            }
            it->second.insert(make_pair(price, shop));
            price_map.emplace(make_pair(movie, shop), price);
        }
    }
    
    vector<int> search(int movie) {
        vector<int> cheapest = {};
        auto it = movie_map.find(movie);
        if(it == movie_map.end())return cheapest;
        auto set_it = it->second.begin();
        while(set_it!=it->second.end() && cheapest.size() < 5) {
            cheapest.push_back(set_it->second);
            set_it++;
        }
        return cheapest;
    }
    
    void rent(int shop, int movie) {
        int price = price_map[make_pair(movie, shop)];
        rented_movies.insert(make_pair(make_pair(price, shop), movie));

        auto it = movie_map.find(movie);
        it->second.erase(make_pair(price, shop));
    }
    
    void drop(int shop, int movie) {
        int price = price_map[make_pair(movie, shop)];
        auto it = movie_map.find(movie);
        it->second.insert(make_pair(price, shop));
        rented_movies.erase(make_pair(make_pair(price, shop), movie));
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans = {};
        auto it = rented_movies.begin();
        while(it!=rented_movies.end() && ans.size() < 5) {
            ans.push_back({it->first.second, it->second});
            it++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
