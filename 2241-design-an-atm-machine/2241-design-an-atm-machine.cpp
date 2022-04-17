class ATM {
public:
    vector<long long> total;
    vector<long long> prices;
    ATM() {
        total = {0, 0, 0, 0, 0};
        prices = {20, 50, 100, 200, 500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++)
        {
            total[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        
        vector<long long> process(total.begin(), total.end());
        vector<int> weTaken(5);
        for(int i = 4; i >= 0; i--)
        {
            long long notesCanTaken = amount/prices[i];
            int toTake = min(notesCanTaken, process[i]);
            weTaken[i] = toTake;
            amount -= prices[i]*toTake;
            process[i] -= toTake;
        }
        
        
        if(amount == 0)
        {
            for(int i = 0; i < 5; i++)
            {
                total[i] = process[i];
            }
            
            return weTaken;
        }
        else
        {
            return {-1};
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */