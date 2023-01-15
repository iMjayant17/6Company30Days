class StockPrice {
public:
    map<int,int> mp;
    multiset<int> mset;
    //priority_queue<int> maxheap;
    //priority_queue<int,vector<int>,greater<int>> minheap;
    int time=0; int curr=0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (timestamp>=time){curr= price; time=timestamp;}
        if (mp.find(timestamp)== mp.end()){
            mp.insert({timestamp,price});
            mset.insert(price);
        }
        else{
            auto it= mset.find(mp[timestamp]);
            mset.erase(it);
            mp[timestamp]= price;
            mset.insert(price);
        }

    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        //return maxheap.top();
        return *(mset.rbegin());
    }
    
    int minimum() {
        //return minheap.top();
        return *(mset.begin());
    }
};