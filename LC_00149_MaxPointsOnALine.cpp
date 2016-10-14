/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Hide Tags Hash Table Math
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
//T : O(N^2) S : O(N), slope version
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int maxNum = 0;
        for (int i = 0; i< points.size(); i++){
            unordered_map<float, int> statistic;
            int duplicate = 0;
            for(int j = 0; j<points.size(); j++){
                if (points[j].x == points[i].x && points[j].y == points[i].y){// count duplicate
                    duplicate++;
                    continue;
                }
                float key = (points[j].x - points[i].x) == 0 ?
                            INT_MAX : // key for vertical line
                            (float) (points[j].y - points[i].y) / (points[j].x - points[i].x);
                statistic[key]++;
            }
            maxNum = max(maxNum, duplicate);
            for(auto it = statistic.begin(); it != statistic.end(); ++it)
                maxNum = max(maxNum, it->second + duplicate);
        } 
        return maxNum;
    }
};
 
//T : O(N^2), S : O(N), hash line
class pairHash{
public:
    size_t operator()(const pair<int, int> &k) const{
        return k.first<<4 ^ k.second>>4;
    }
};

class Solution { 
public:
    int gcd(int a, int b){
        return a ? gcd(b%a, a) : b;
    }
    int maxPoints(vector<Point> &points) {
        int res=0;
        for(auto& p1 : points){
            unordered_map<pair<int, int>, int, pairHash> slope;
            int cnt_same = 0, cnt_slope = 0;
            for(auto& p2 : points){
                int dx = p1.x - p2.x;
                int dy = p1.y - p2.y;
                int g = gcd(dx,dy);
                if(!g){
                    cnt_same++;
                    continue;
                }
                //if the ratio is the same, no matter what dx and dy are
                //- - return -  ; -n*A +n*B may always return + or -  ;  +n*A -n*B may always return - or +
                //So dx/g always has the same sign if dx/dy is the same
                dx /= g;
                dy /= g;
                cnt_slope = max(cnt_slope, ++slope[make_pair(dx,dy)]);
            }
            res = max(res, cnt_slope + cnt_same);
        }
        return res;
    }
};
 
//T : O(N^2 / 2 + N), S : O(N^2), hash line
/*hash func can be used eariler, then use the hash value as Key
we only need to declare unordered_map<int, int or set> map,
int value = hashfunc(Line or point);
map[value] = int or set;
Here I practise to add customized hash func to unordered_map, then Equal is necessary
*/
class Line{
public:	
	int a;
	int b;
	int c;
	Line(int a, int b, int c){
		int g = GCD(a,b);
		this->a = a/g;
		this->b = b/g;
		this->c = c/g;
	}
	int GCD(int a, int b){
		return a ? GCD(b%a, a):b;
	}
};  

class pointHash{
public:
    size_t operator()(const Point &k) const{
        return k.x<<4 ^ k.y>>4;
    }
};

class pointEqual{
public:
    bool operator()(const Point &a, const Point &b) const{
        return a.x == b.x && a.y == b.y;
    }
};

class lineHash{
public:
    size_t operator()(const Line &k) const{
        return k.a<<4 ^ k.b<<8 ^ k.c>>4;
    }
};

class lineEqual{
public:
    bool operator()(const Line &x, const Line &y) const{
        return x.a == y.a && x.b == y.b && x.c == y.c;
    }
};

class Solution {
public:
    int maxPoints(vector<Point> & points) {
        
        int res = 0;
        unordered_map<Point, int , pointHash, pointEqual> pts;
        for(auto & a : points) {
            pts[a] += 1;
            res = max(res, pts[a]);
        }

        unordered_map<Line, unordered_set<int>, lineHash, lineEqual> le;
        int n = points.size();
        for (int i = 0; i< n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = points[j].y - points[i].y;
                int b = points[i].x - points[j].x;
                if (a == 0 && b == 0)//same points
                    continue;
                int c = -a*points[i].x - b*points[i].y;
                Line l(a, b, c);
                le[l].insert(i);
                le[l].insert(j);
                if(le[l].size() > res)
                    res = le[l].size();
            }
        }
        return res;
    }
};

//T : O((NlgN + 2N)*N), S : O(N), sort slope
#define FLT_MAX float(1e36)
#define SAME_PT float(-1e36)
class Solution {
public:
    bool allSamePoints(vector<Point> &points){
        int i = 0;
        while(i < points.size()){
            if(points[i].x != points[0].x || points[i].y != points[0].y)
                break;
            ++i;
        }
        return i == points.size();
    }
    
    bool Equal(float x, float y){
        return abs(x - y) <= 0.00000001 || abs(x - SAME_PT) <= 0.00000001 || abs(y - SAME_PT) <= 0.00000001;
    };

    int Cal_One_Point(int &cur, vector<Point> &pts) {
        vector<float> slope;
        for (int i = 0; i < pts.size(); i++) {
            if(cur == i)
                continue;
            if(pts[cur].x == pts[i].x){
                if(pts[cur].y == pts[i].y)
                    slope.push_back(SAME_PT);
                else
                    slope.push_back(FLT_MAX);
            }else{
                float k = float((pts[i].y - pts[cur].y))/float((pts[i].x - pts[cur].x));
                slope.push_back(k);
            }
        }
        sort(slope.begin(), slope.end());
        int cnt = 0;
        int maxcnt = 0;
        for(int i = 0; i < slope.size() - 1; i++){
            if(Equal(slope[i], slope[i + 1])){
                cnt++;
            }else{
                maxcnt = max(cnt, maxcnt);
                cnt = 0;
            }
        }
        return (cnt > maxcnt ? cnt : maxcnt) + 2;
    };

    int maxPoints(vector<Point> &points) {
        if(allSamePoints(points) || points.size() <= 1)
            return points.size();
        int res = 2;    
        for(int i=0; i<points.size(); i++){
            res = max(res, Cal_One_Point(i, points));
        }
        return res;
    };
};

//T : O(N*N*N/2 + N), S : O(1), but easy
class Solution {
public:
    //Check if three points, i, j and k, are collinear
    bool sameLine(Point i, Point j, Point k){
        return (j.y - i.y)*(k.x - j.x) - (k.y - j.y)*(j.x - i.x) == 0;
    }
    //Check if all points are the same
    bool allSamePoints(vector<Point> &points){
        int i = 0;
        while(i < points.size()){
            if(points[i].x != points[0].x || points[i].y != points[0].y)
                break;
            ++i;
        }
        return i == points.size();
    }
    int maxPoints(vector<Point> &points) {
        if(points.size() <= 1 || allSamePoints(points))
            return points.size();
        int maxPoints = 2;
        for(int i = 0; i < points.size(); ++i){
            for(int j = i + 1; j < points.size(); ++j){
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    continue;
                int count = 2;
                for(int k = 0; k < points.size(); ++k){
                    if(k != i && k != j && sameLine(points[i], points[j], points[k]))
                        count++;
                }
                maxPoints = max(maxPoints, count);
            }
        }
        return maxPoints;
    }
};
