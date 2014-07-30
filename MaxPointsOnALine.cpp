/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
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
 
//O(n^2) slope version
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int maxNum = 0;
        for (int i = 0; i< points.size(); i++){
            unordered_map<float, int> statistic;
            int duplicate = 1;
            for (int j = 0; j<points.size(); j++){
                if (j == i)
                    continue;
                if (points[j].x == points[i].x && points[j].y == points[i].y){// count duplicate
                    duplicate++;
                    continue;
                }
                float key = (points[j].x - points[i].x) == 0 ?
                            INT_MAX : // key for vertical line
                            (float) (points[j].y - points[i].y) / (points[j].x - points[i].x);
                statistic[key]++;
            }
            maxNum=max(maxNum, duplicate);
            for (unordered_map<float, int>::iterator it = statistic.begin(); it != statistic.end(); ++it)
                maxNum = max(maxNum, it->second + duplicate);
        } 
        return maxNum;
    }
};
 
//O(n^2), hash line
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
		this->a=a/g;
		this->b=b/g;
		this->c=c/g;
	}
	int GCD(int a, int b){
		return a?GCD(b%a,a):b;
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
        return a.x==b.x && a.y==b.y;
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
        return x.a==y.a && x.b==y.b && x.c == y.c;
    }
};

class Solution {
public:
    int maxPoints(vector<Point> & points) {
        
        int res = 0;
        unordered_map<Point, int , pointHash, pointEqual> pts;
        for(auto & a : points) {
            pts[a]+= 1;
            res = res>pts[a]?res:pts[a];
        }

        unordered_map<Line, unordered_set<int>, lineHash, lineEqual> le;
        int n = points.size();
        for (int i=0; i< n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int a = points[j].y-points[i].y;
                int b = points[i].x-points[j].x;
                if (a == 0 && b == 0)
					continue;
                int c = -a*points[i].x-b*points[i].y;
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

#if 0
//O(n^2) time, O(n) space, using space to save time based on last method, hash slope 
class pairHash{
public:
    size_t operator()(const pair<int, int> &k) const{
        return k.first<<4 ^ k.second>>4;
    }
};

class Solution { 
public:
    int gcd(int a, int b){
        return a?gcd(b%a, a):b;
    }
    int maxPoints(vector<Point> &points) {
        int res=0;
        for(auto& p1: points){
            unordered_map<pair<int, int>, int, pairHash> slope;
            int cnt_same=0, cnt_slope=0;
            for(auto& p2:points){
                int dx=p1.x-p2.x;
                int dy=p1.y-p2.y;
                int g=gcd(dx,dy);
                if(!g){
                    cnt_same++;
                    continue;
                }
                //if the ratio is the same, no matter what dx and dy are
                //- - return -  ; -n*A +n*B may always return + or -  ;  +n*A -n*B may always return - or +
                //So dx/g always has the same sign if dx/dy is the same
                dx/=g;
                dy/=g;
                cnt_slope=max(cnt_slope,++slope[make_pair(dx,dy)]);
            }
            res=max(res,cnt_slope+cnt_same);
        }
        return res;
    }
};
#endif
 
#if 0 
//O(n^2) time, O(n) space, using space to save time based on last method, hash slope here
class Solution { 
public:
    int gcd(int a, int b){
        return a?gcd(b%a, a):b;
    }
    int maxPoints(vector<Point> &points) {
        int res=0;
        for(auto& p1: points){
            unordered_map<string, int> slope;
            int cnt_same=0, cnt_slope=0;
            for(auto& p2:points){
                int dx=p1.x-p2.x;
                int dy=p1.y-p2.y;
                int g=gcd(dx,dy);
                if(!g){
                    cnt_same++;
                    continue;
                }
                //if the ratio is the same, no matter what dx and dy are
                //- - return -  ; -n*A +n*B may always return + or -  ;  +n*A -n*B may always return - or +
                //So dx/g always has the same sign if dx/dy is the same
                dx/=g;
                dy/=g;
                cnt_slope=max(cnt_slope,++slope[to_string(dx)+" "+to_string(dy)]);
            }
            res=max(res,cnt_slope+cnt_same);
        }
        return res;
    }
};
#endif

#if 0 
//O(lgn*n^2), sort slope
#define FLT_MAX float(1e36)
#define SAME_PT float(-1e36)
class Solution {
public:
    bool allSamePoints(vector<Point> &points){
        int i=0;
        while(i<points.size()){
            if(points[i].x!=points[0].x || points[i].y!=points[0].y)
                break;
            ++i;
        }
        return i==points.size();
    }
    
    bool Equal(float x, float y){
        return abs(x-y)<=0.00000001 || abs(x-SAME_PT)<=0.00000001 || abs(y-SAME_PT)<=0.00000001;
    };

    int Cal_One_Point(int &cur, vector<Point> &pts) {
        vector<float> slope;
        for (int i=0; i<pts.size(); i++) {
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
        int cnt =0;
        int maxcnt=0;
        for(int i=0;i<slope.size()-1;i++){
            if(Equal(slope[i],slope[i+1])){
                cnt++;
            }else{
                maxcnt=max(cnt, maxcnt);
                cnt=0;
            }
        }
        return (cnt>maxcnt?cnt:maxcnt)+2;
    };

    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(allSamePoints(points) || points.size()<=1)
            return points.size();
        int res = 2;    
        for(int i=0; i<points.size(); i++){
            res = max(res, Cal_One_Point(i, points));
        }
        return res;
    };
};
#endif

#if 0
//O(n^3), but easy
class Solution {
public:
    //Check if three points, i, j and k, are collinear
    bool sameLine(Point i, Point j, Point k){
        return (j.y-i.y)*(k.x-j.x)-(k.y-j.y)*(j.x-i.x)==0;
    }
    //Check if all points are the same
    bool allSamePoints(vector<Point> &points){
        int i=0;
        while(i<points.size()){
            if(points[i].x!=points[0].x || points[i].y!=points[0].y)
                break;
            ++i;
        }
        return i==points.size();
    }
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(points.size()<=1 || allSamePoints(points))
            return points.size();
        int maxPoints = 2;
        for(int i=0; i<points.size(); ++i){
            for(int j=i+1; j<points.size(); ++j){
                if(points[i].x==points[j].x && points[i].y==points[j].y)
                    continue;
                int count = 2;
                for(int k=0; k<points.size(); ++k){
                    if(k!=i && k!=j && sameLine(points[i], points[j], points[k]))
                        count++;
                }
                maxPoints = max(maxPoints, count);
            }
        }
        return maxPoints;
    }
};
#endif

#if 0
//cannot deal with dup points, need to improve later, slope is not a good idea, O(n^2)
class Solution {
public:
    struct LINE {
        bool bVertical;
        float k;
        float b;// y axle intersection if none vertical, x axle intersection if vertical line
    };
    
    bool Equal(float x, float y){
        return (x - y) >= -0.00000001 && (x - y) <= 0.00000001;
    };
    
    LINE findLine(vector<Point> &pts) {
        LINE line;
        int nMax = 0;
        int n = pts.size();

        for (int i = 0; i < n-1; i++) {
            unordered_map<float, int> map;
            int nVertical = 0;
            for (int j = i+1; j < n; j++) {
                if (pts[i].x == pts[j].x) {
                    nVertical++;
                    if (nVertical > nMax) {
                        line.bVertical = true;
                        line.b = pts[i].x;
                        nMax = nVertical;
                    }
                }
                else{
                    float k = float((pts[j].y - pts[i].y))/float((pts[j].x - pts[i].x));
                    if (map.find(k) != map.end())
                        map[k]++;
                    else
                        map[k] = 1;

                    if (map[k] > nMax) {
                        line.bVertical = false;
                        line.k = k;
                        line.b = pts[i].y - k * pts[i].x;
                        nMax = map[k];
                    }
                }
            }
        }
        return line;
    };

    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(points.size()<=1)
            return points.size();
        
        LINE l = findLine(points);
        int res = 0;
        for(int i=0; i<points.size(); i++){
            if(l.bVertical && Equal(l.b, points[i].x))
                res++;
            else{
                if(Equal(points[i].y, l.k*points[i].x+l.b))
                    res++;
            }
        }
        return res;
    };
};
#endif
