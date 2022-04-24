class UndergroundSystem {
private:
    unordered_map<string, vector<int>> database;
    unordered_map<int, pair<string, int>> calculation;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        calculation[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> data = calculation[id];
        database[data.first + "-" + stationName].push_back(t - data.second);
        calculation.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> time = database[startStation + "-" + endStation];
        int sum = accumulate(time.begin(), time.end(), 0);
        int num = time.size();
        double avTime = sum*1.0 / num;
        return avTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */