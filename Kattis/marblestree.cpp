#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, marbles [10010], parents [10010], ret;
set<int> children [10010], leaves, nextLeaves;

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(true){
        cin >> N;
        if(N == 0) break;
        leaves.clear(); ret = 0;
        for(int i = 0; i < N; i++){
            int id, m, numChildren; cin >> id >> m >> numChildren;
            marbles[id] = m;
            for(int j = 0; j < numChildren; j++){ 
                int x; cin >> x; 
                children[id].insert(x); parents[x] = id;
            }
            if(numChildren == 0) leaves.insert(id);
        }
        while(leaves.size() != 1){
            nextLeaves.clear();
            for(auto it = leaves.begin(); it != leaves.end(); it++){
                ret += abs(marbles[*it]-1);
                marbles[parents[*it]] += marbles[*it]-1;
                children[parents[*it]].erase(*it);
                if(children[parents[*it]].size() == 0) nextLeaves.insert(parents[*it]);
            }
            leaves = nextLeaves;
        }
        cout << ret << '\n';
    }
    return 0;
}
