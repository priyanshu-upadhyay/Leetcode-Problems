class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> t;
        for(auto i: ops){
            if(i=="D"){
                t.push_back(t.back()*2);
            }
            else if(i=="C"){
                t.pop_back();
            }
            else if(i=="+"){
                t.push_back(t[t.size()-1]+t[t.size()-2]);
            }
            else{
                t.push_back(stoi(i));
            }
        }
        int sum=0;
        for(auto i: t){
            sum+=i;
        }
        return sum;
    }
};