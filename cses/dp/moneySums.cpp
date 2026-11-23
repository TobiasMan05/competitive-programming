#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i = (int) a; i < (int) b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int)b-1; i>=(int)a;--i)
#define dforn(i,n) for(int i = (int)n-1; i>=0; i--)
#define fore(e,c) for(const auto &e: (c))
#define pb push_back
#define ln '\n'
#define sz(c) ((int)c.size())
#define zero(v) memset(v,0,sizeof(v))
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int INF = 1e8;
const int MAXX= 1e5 + 7;
int memo[MAXX];
int n, coins[100], total = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    forn(i,n){
        cin >> coins[i];
    }

    memo[0] = 1;
    
    for(auto c: coins){
        dforn(x,MAXX){
            if(memo[x] != 1 && x - c >= 0){
                memo[x] = memo[x - c];
            }
        }
    }

    forn(i,MAXX){
        if(memo[i] == 1){
            total++;
        }
    }
   
    cout << total - 1 << ln;
    forr(i, 1,MAXX){
        if(memo[i] == 1){
            cout << i << " ";
        }
    }

    return 0;
}