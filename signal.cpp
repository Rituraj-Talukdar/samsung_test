#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;
        int a[n][m];
        map<vector<int>,int> mp;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < m; j++) {
                cin>>a[i][j];
                v.push_back(a[i][j]);
            }
            mp[v]++;
        }
        int ans =0;
        for (auto i : mp) {
            vector<int> v = i.first;
            int cnt =0;
            for (int j = 0; j < m; j++) {
                if (v[i]==0) cnt++;
            }
            if (k<cnt) continue;
            int left = k -cnt;
            if(left%2 ==0){ans = max(ans,i.second);}
        }
        std::cout << ans << std::endl;
    }
 
}