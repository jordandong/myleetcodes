/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
1. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
2. All airports are represented by three capital letters (IATA code).
3. You may assume all tickets may form at least one valid itinerary.

Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Tags Depth-first Search Graph
*/

//Greedy, backward
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, multiset<string>> src_dst;//multiset is sorted
        vector<string> route;

        for (auto ticket : tickets)
            src_dst[ticket.first].insert(ticket.second);
        findItineraryHelper("JFK", src_dst, route);
        return vector<string>(route.rbegin(), route.rend());
    }
    
    void findItineraryHelper(string src, map<string, multiset<string>> &src_dst, vector<string> &route) {
        while (src_dst[src].size()) {
            string dst = *src_dst[src].begin();
            src_dst[src].erase(src_dst[src].begin());
            findItineraryHelper(dst, src_dst, route);
        }
        route.push_back(src);
    }
};
