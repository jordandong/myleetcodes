/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
  
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

//cannot deal with dup points, need to improve later, slope is not a good idea, O(n^2)
#if 0
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
