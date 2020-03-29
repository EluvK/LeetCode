class UndergroundSystem {
public:
    map<string,int> mp;
    map<pair<int,int>,pair<int,double>> cal;
    map<int,pair<int,int>> id2stime;
    int ind=1;
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        if(mp[stationName]==0) mp[stationName]=ind++;
        id2stime[id]=make_pair(mp[stationName],t);
    }

    void checkOut(int id, string stationName, int t) {
        if(mp[stationName]==0) mp[stationName]=ind++;
        double caltime=t-id2stime[id].second;
        pair<int,int> p=make_pair(id2stime[id].first,mp[stationName]);
        cal[p].first++;
        cal[p].second+=caltime;
    }

    double getAverageTime(string startStation, string endStation) {
        pair<int,int> p=make_pair(mp[startStation],mp[endStation]);
        return cal[p].second/cal[p].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
