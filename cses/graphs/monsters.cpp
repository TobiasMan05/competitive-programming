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

*/
int MAXN = 1007;
int n, m;
vector<string> grid(MAXN);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

pii dirA;
string camino;
vector<vi> dist, dir;

bool valida(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}


int bfs(int i, int j){
    dist.assign(n, vi(m, -1));
    dir.assign(n, vi(m, -1));
    dist[i][j] = 0;
    int goal = -1;
    queue<pii> q;
    q.push({i, j});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        forn(d, 4) {
            int nx = x + dx[d], ny = y + dy[d];
            if (valida(nx, ny) && goal == -1 && dist[nx][ny] == -1) {
                if(grid[nx][ny] == '.'){
                    dist[nx][ny] = dist[x][y] + 1;
                    dir[nx][ny] = d;
                    q.push({nx, ny});
                }else if(grid[nx][ny] == 'M'){
                    dist[nx][ny] = dist[x][y] + 1;
                    dir[nx][ny] = d;
                    goal = 0;
                    break;
                }else if(grid[nx][ny] == 'A'){
                    dist[nx][ny] = dist[x][y] + 1;
                    dir[nx][ny] = d;
                    dirA = {nx, ny};
                    goal = 1;
                    break;
                }
            }
        }
    }
    if(goal == 1){
        string move = "UDLR";
        auto [x, y] = dirA;
        while (x != i || y != j) {
            int d = dir[x][y];
            camino.pb(move[d]);
            x -= dx[d];                  
            y -= dy[d];
        }
    }
    // reverse(all(camino));

    return goal;
}

int main() { IOS
    
    while(cin >> n >> m){
        forn(i,n){
            cin >> grid[i];
        }

        forn(i,n){
            forn(j,m){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == '.'){
                        if(bfs(i,j) == 1){                        
                            cout << "YES" << ln;
                            cout << dist[dirA.first][dirA.second] << ln;
                            for(char movimiento: camino) cout << movimiento;
                            return 0;
                        }
                    }
                }
                    
            }
        }
        cout << "NO" << ln;
    }

    return 0;
}