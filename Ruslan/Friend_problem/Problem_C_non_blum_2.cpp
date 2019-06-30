// use one hash
// WA
# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
long long mood = 100000ll;
//, 14401, 28573, 13033, 23417, 29173, 15307, 26459, 13367, 929, 23663
//int prost[15] = {1000003, 1000033, 24859, 4889, 13553, 967, 26777, 31357, 3881, 18913, 20173, 18859, 10369, 28591, 12113};
vector< string > vrr[100000];
inline int get_hash(string s, int prost){
    if(sz(s) == 0) return 0;
    long long hash = 0ll;
    for(int i = 0, len = sz(s); i < len; i++) {
        hash = ((prost * 1ll * hash)%mood + abs(int(s[i]))) % mood;
    }
    return hash;
}
int check_prost(int n){
    for(int i = 2, k = int(sqrt(n)); i <= k; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int x = get_hash(s, 1000033) % mood;
        int sum = 0;
        for(string t : vrr[x]){
            if(t == s){
                sum = 1;
                break;
            }
        }
        if(sum == 0){
            ans++;
            vrr[x].push_back(s);
        }
    }
    cout << ans;
    return 0;
}
