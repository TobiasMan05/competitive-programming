#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define forr(i, a, b) for(int i = (int) (a); i < (int) (b); i++)
#define forn(i, n) forr(i,0,n)
#define ln '\n'
#define pb push_back
#define sz(c) ((int)c.size())
#define fst first
#define snd second
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define all(v) begin(v), end(v)
#define fore(e,c) for(const auto &e : (c))
#define db(v) cerr<<#v" = "<<(v)<<'\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int INF = 1e9;
// Crear archivos: for x in {a..m}; do cp -n template.cpp $x.cpp; touch $x.in; done
// Pegar al empezar: c(){ g++ -std=c++20 -D_GLIBCXX_DEBUG -g -O2 -Wshadow -Wall -Wextra -o $1 $1.cpp && for f in $1*.in; do echo "== $f"; ./$1 < "$f"; done; }
// Usar: c nombreArchivo
//                       (sin el .cpp)


/* 
    for (int i = 1; i <= n; i++) distance[i] = INF;
    distance[x] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            distance[b] = min(distance[b], distance[a]+w);
        }
    }
*/

int main() { IOS

    int n, m;
    
    while(cin >> n >> m){
        vector<tuple<int, int, int>> edges;
        int distance[n+1];
        bool ciclo = false;
        int a, b, w;
        forn(i,m){
            cin >> a >> b >> w;
            edges.push_back({a, b, w});
        }

        for (int i = 1; i <= n; i++) distance[i] = -INF;
        distance[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (auto e : edges) {
                int a, b, w;
                tie(a, b, w) = e;
                if(a == -INF) continue;
                if(i==n && b == n && distance[a] + w > distance[b]){
                    ciclo = true;
                }

                distance[b] = max(distance[b], distance[a]+w);
            }    
        }
        
        if(ciclo == true){
            cout << -1 << ln;
        }else{
           cout << distance[n] << ln;
        }
        }
    

    return 0;
}