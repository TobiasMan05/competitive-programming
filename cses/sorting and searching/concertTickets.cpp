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


// Crear archivos: for x in {a..m}; do cp -n template.cpp $x.cpp; touch $x.in; done
// Pegar al empezar: c(){ g++ -std=c++20 -D_GLIBCXX_DEBUG -g -O2 -Wshadow -Wall -Wextra -o $1 $1.cpp && for f in $1*.in; do echo "== $f"; ./$1 < "$f"; done; }
// Usar: c nombreArchivo
//                       (sin el .cpp)


// for x in "%e"*.in; do echo $x; time "./%e" < "$x"; echo "=================================="; done
int main() { IOS

    ll n,m,a;
    
    while(cin >> n >> m){
        ll people;
        multiset<ll> tickets;
        forn(i,n){ 
            cin >> a; 
            tickets.insert(a);
        }
        forn(i,m){ 
            cin >> people;
            auto it = tickets.upper_bound(people);

            if(it == tickets.begin()){
                cout << -1 << ln;
            }else{
                cout << *--it << ln;
                tickets.erase(it);
            }
        }
    }

    return 0;
}