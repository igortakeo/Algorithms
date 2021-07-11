#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Referencia: https://github.com/icmcgema/gema/blob/master/13-Geometria_Computacional.ipynb

struct Point{
    ll x, y;

    Point(ll x, ll y){
        this->x = x;
        this->y = y;
    }

    Point operator+(const Point& b) const{
        return Point(x+b.x, y+b.y);
    }

    Point operator-(const Point& b) const{
        return Point(x-b.x, y-b.y);
    }

    //dot - produto escalar
    ll operator*(const Point& b) const{
        return x*b.x + y*b.y; 
    }

    //cross - produto vetorial
    // o modulo do produto vetorial entre a e b nos da area do paralelogramo 
    // definido entre estes dois pontos.
    ll operator^(const Point &b) const{
        return x*b.y - y*b.x;
    }

    ll norm(){
        return sqrt(x*x+y*y);
    }

};

//Menor distancia entre ponto e reta
double MinDist(Point a, Point b, Point point){
    Point BA = b-a, CA = point-a, CB = point-b, AB = a-b; 
    if(BA*CA >= 0 && CB*AB >= 0){
        ll area = BA^CA;
        ll h = area/BA.norm();
        return h;
    }
    else{
        return min(CA.norm(), CB.norm());
    }
}

//Verifica se um ponto esta dentro de um poligono convexo
//Complexidade: O(n)
bool isInside(vector<Point>polygon, Point x){
    int n = polygon.size();
    bool ans = true;

    for(int i=0; i<n; i++){
        Point seg1 = polygon[(i+1)%n] - polygon[i];
        Point seg2 = x - polygon[i];
        if((seg1^seg2) < 0){
            ans = false; 
            break;
        }
    }

    return ans;
}

bool isInsideTriangle(Point a, Point b, Point c, Point x){
    Point BA = b-a, XA = x-a, CB = c-b, XB = x-b, AC = a-c, XC = x-c;

    if((BA^XA) < 0) return false;
    else if((CB^XB) < 0) return false;
    else if((AC^XC) < 0) return false;

    return true;
}

//Verifica se um ponto esta dentro de um poligono convexo
//Complexidade: O(logn)
bool isInsideOptimization(vector<Point>polygon, Point x){
    int n = polygon.size();
    int l = 1, r = n-2;
    int i=1;
    
    while(l <= r){
        int mid = (l+r)/2;
        Point v = polygon[mid] - polygon[0];
        Point w = x - polygon[0];
        
        if((v^w) >= 0){
            i = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    bool ans = isInsideTriangle(polygon[0], polygon[i], polygon[i+1], x);
    return ans;
}

int axis(Point v){
    if(v.y > 0) return 1;
    else if(v.y < 0) return 2;
    else if(v.x >= 0) return 1;
    else return 2;
}

bool cmp(const Point& u, const Point& v){
    if(axis(u) == axis(v)){
        return ((u^v) > 0);
    }
    return axis(u) < axis(v);
}

//Ordena os angulos em ordem decrescente].
void SortAngles(vector<Point>&points){
    sort(points.begin(), points.end(), cmp);
}


int main(){
    Point a(-1,-1);
    Point b(1,3);
    Point c(-3,2);
    Point d(2,1);


    //Teste

    vector<Point>v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

    SortAngles(v);

    for(auto it : v){
        cout << it.x << ' ' << it.y << endl;
    }

    return 0;
}