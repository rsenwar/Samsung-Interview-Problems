#include <bits/stdc++.h>
using namespace std;

string getPoint(int x, int y) {
    return to_string(x)+to_string(y);
}

int getCost(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    
    int t, n, sx, sy, dx, dy, px, py, qx, qy, c;
    cin>>t;
    while(t--){
        cin>>n;
        map<string, vector<pair<string, int>>> adj;
        cin>>sx>>sy>>dx>>dy;
        string source = getPoint(sx, sy);
        string dest = getPoint(dx, dy);
        adj[source].push_back({dest, getCost(sx, sy, dx, dy)});
        adj[dest].push_back({source, getCost(dx, dy, sx, sy)});
        set<pair<string, vector<int>>> points;
        for(int i=0;i<n;i++){
            cin>>px>>py>>qx>>qy>>c; 
            string start = getPoint(px, py);
            string end = getPoint(qx, qy);
            for(auto currPoint: points) {
                int p1x = currPoint.second[0], p1y = currPoint.second[1];
                adj[start].push_back({currPoint.first, getCost(px, py, p1x, p1y)});
                adj[currPoint.first].push_back({start, getCost(px, py, p1x, p1y)});
                adj[end].push_back({currPoint.first, getCost(qx, qy, p1x, p1y)});
                adj[currPoint.first].push_back({end, getCost(qx, qy, p1x, p1y)});
            }
            points.insert({start, {px, py}});
            points.insert({end, {qx, qy}});
            adj[start].push_back({end, c});
            adj[end].push_back({start, c});
            adj[source].push_back({start, getCost(sx, sy, px, py)});
            adj[start].push_back({dest, getCost(px, py, dx, dy)});
            adj[source].push_back({end, getCost(sx, sy, qx, qy)});
            adj[end].push_back({dest, getCost(qx, qy, dx, dy)});
        }
        priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;
        map<string, bool> isVisited;
        string curr = source;
        int minCost = 0;
        while(curr!=dest) {
            isVisited[curr] = true;
            for(int i=0;i<(int)adj[curr].size();i++) {
                int cost = adj[curr][i].second;
                string endNode = adj[curr][i].first;
                if(isVisited[endNode]) continue;
                pq.push({minCost + cost, endNode});
            }
            auto topNode = pq.top();
            pq.pop();
            curr = topNode.second;
            minCost = topNode.first; 
        }
        cout<<minCost<<endl;
    }
    
    
    return 0;
}
