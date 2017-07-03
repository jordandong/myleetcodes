/*
You are given several logs that each log contains a unique id and timestamp.
Timestamp is a string that has the following format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59.
All domains are zero-padded decimal numbers.

Design a log storage system to implement the following functions:

void Put(int id, string timestamp): Given a log's unique id and timestamp, store the log in your storage system.

int[] Retrieve(String start, String end, String granularity): Return the id of logs whose timestamps are within the range from start to end.
Start and end all have the same format as timestamp. However, granularity means the time level for consideration.
For example, start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", granularity = "Day", it means that we need to find the logs within the range from Jan. 1st 2017 to Jan. 2nd 2017.

Example 1:
put(1, "2017:01:01:23:59:59");
put(2, "2017:01:01:22:59:59");
put(3, "2016:01:01:00:00:00");
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // return [1,2,3], because you need to return all logs within 2016 and 2017.
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); // return [1,2], because you need to return all logs start from 2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.

Note:
1. There will be at most 300 operations of Put or Retrieve.
2. Year ranges from [2000,2017]. Hour ranges from [00,23].
3. Output for Retrieve has no order required.
*/

class LogSystem {
private:
    multimap<string, int> m;
    unordered_map<string, int> g;

public:
    LogSystem() {
        g["Year"] = 4;
        g["Month"] = 7;
        g["Day"] = 10;
        g["Hour"] = 13;
        g["Minute"] = 16;
        g["Second"] = 19;
    }
    
    void put(int id, string timestamp) {
        m.emplace(timestamp, id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        s = s.substr(0, g[gra]);
        e = e.substr(0, g[gra]);
        auto it = m.lower_bound(s);
        vector<int> ans;
        while (it != m.end()) {
            if (it->first.substr(0, g[gra]) <= e) {
                ans.push_back(it->second);
            } else {
                break;
            } 
            it++;
        }
        return ans;
    }
};

class LogSystem {
private:
    multimap<string, int> m;
public:
    LogSystem() {    
    }
    
    void put(int id, string timestamp) {
        m.emplace(timestamp, id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        if (gra == "Year") {
            s = s.substr(0, 4) + ":01:01:00:00:00";
            e = e.substr(0, 4) + ":12:31:23:59:59";
        }
        else if (gra == "Month") {
            s = s.substr(0, 7) + ":01:00:00:00";
            e = e.substr(0, 7) + ":31:23:59:59";
        }
        else if (gra == "Day") {
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        }
        else if (gra == "Hour") {
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        }
        else if (gra == "Minute") {
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }
        auto start = m.lower_bound(s), end = m.upper_bound(e);
        vector<int> ans;
        for (auto iter = start; iter != end; ++iter)
            ans.push_back(iter->second);
        return ans;
    }
};

class LogSystem {
private:
    unordered_map<string, int> m;
    unordered_map<string, int> g;

public:
    LogSystem() {
        g["Year"] = 4;
        g["Month"] = 7;
        g["Day"] = 10;
        g["Hour"] = 13;
        g["Minute"] = 16;
        g["Second"] = 19;
    }
    
    void put(int id, string timestamp) {
        m[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        s = s.substr(0, g[gra]);
        e = e.substr(0, g[gra]);
        vector<int> ans;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->first >= s && it->first.substr(0, g[gra]) <= e)
                ans.push_back(it->second);
        }
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
