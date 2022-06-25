#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

struct Event
{
    double t;
    int u,v; this point in time u is shorter 
    bool operator < (const Event& r) const {
        return t < r.t;
    }
};

vector<Event> events;
#define PB push_back
const int maxn = 51;
const int maxl = maxn*(maxn-1)>>1;

struct Point
{
    double x,y,z,dx,dy,dz;
    void read(){ scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&z,&dx,&dy,&dz); }
    Point operator - (const Point&r) { return {x-r.x, y-r.y, z-r.z, dx-r.dx, dy-r.dy, dz-r.dz}; }
}P[maxn];

#define squ(x)  ((x)*(x))

struct Seg
{
    double a,b,c;
    int u,v;
    void cal(int i,int j){
        u = i; v = j;
        Point t = P[i]-P[j];
        a = squ(t.dx) + squ(t.dy) + squ(t.dz);
        b = 2*(t.dx*t.x + t.dy*t.y + t.dz*t.z);
        c = squ(t.x) + squ(t.y) + squ(t.z);
    }
}L[maxl];

bool operator < (const Seg&x, const Seg&y) { return x.c < y.c; }

int lcnt;
int n;

if equation has two roots, r1 < r2
int solveEqu(double a,double b,double c,double &r1,double &r2)
{
    if(fabs(a)<eps){
        if(fabs(b)<eps) return 0;
        r1 = -c/b;
        return 1;
    }
    double delta = b*b-4.*a*c;
    if(delta<eps) return 0;
    delta = sqrt(delta);
    if(a>0){
        r1 = (-b-delta)/(2.*a);
        r2 = (-b+delta)/(2.*a);
    }else {
        r1 = (-b+delta)/(2.*a);
        r2 = (-b-delta)/(2.*a);
    }
    return 2;
}


int pa[maxl];

int pos[maxl]; map: Edge  to MST
int e[maxn]; map: MST to Edge

void initUFS() { for(int i = 0; i < n; i++) pa[i] = i; }
int Find(int x) { return x == pa[x]?x:pa[x]=Find(pa[x]); }


int main()
{
    freopen("in.txt","r",stdin);
    int kas = 0;
    while(~scanf("%d",&n)){
        for(int i = 0; i < n; i++) P[i].read();
        events.clear(); lcnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                L[lcnt++].cal(i,j);
            }
        }
        sort(L,L+lcnt);ascending order

        for(int i = 0; i < lcnt; i++){
            for(int j = i+1; j < lcnt; j++){
                double r[2];
                double a = L[j].a - L[i].aThe length of j relative to i
                , b = L[j].b - L[i].b
                , c = L[j].c - L[i].c;

                int rcnt = solveEqu(a,b,c,r[0],r[1]);
                if(rcnt == 1){
                    if(r[0]>0) events.PB({r[0],j,i});
                }else if(rcnt == 2){
                    if(a<0){
                        if(r[1]>0) events.PB({r[1],j,i});
                    }else {
                        if(r[0]>0) events.PB({r[0],j,i});
                        if(r[1]>0) events.PB({r[1],i,j});
                    }

                }
            }
        }
        sort(events.begin(),events.end());
        DeBugEv
        initUFS();
        memset(pos,0,sizeof(int)*lcnt);

        int idx = 0;
        for(int i = 0; i < lcnt; i++){
            int s1 = Find(L[i].u), s2 = Find(L[i].v);
            if(s1 != s2){
                pa[s1] = s2;
                e[pos[i] = ++idx] = i; e[] subscripts start from 1. 0 table is not in MST 
                if(idx == n-1) break;
            }
        }

        int ans = 1;
        for(int i = 0; i < events.size(); i++){
            Event &ev = events[i];
            if(pos[ev.v]&&!pos[ev.u]){
                initUFS();
                int old = pos[ev.v];
                for(int j = 1; j <= idx; j++){
                    if(j == old) continue;
                    int s1 = Find(L[e[j]].u), s2 = Find(L[e[j]].v);
                    if(s1 != s2){ pa[s1] = s2; }
                }
                int s1 = Find(L[ev.u].u), s2 = Find(L[ev.u].v);
                if(s1 != s2){
                    ans++;
                    pos[ev.u] = old;
                    pos[ev.v] = 0;
                    e[old] = ev.u;
                }
            }
        }
        printf("Case %d: %d\n",++kas,ans);
    }
    return 0;
}