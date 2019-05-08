#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int max2(const int &a, const int &b) {
	return a > b ? a : b;
}
int main() {
    struct drag{
        int t;  // time
        int n;  // value
    };
    int T, M;   // T == the weight of the 01 bag, M == the maximun value
    int tt, nn; // temp time and temp value for argument
    vector<drag> vec(M+1);
    cin >> T >> M;
    for(int i = 1; i <= M; i++) {
        cin >> tt >> nn;
        vec[i].t = tt;
        vec[i].n = nn;
    }
//	for(int i = 1; i <= M; i++)
//		cout << vec[i].t << " " << vec[i].n << endl;
    int dp[101][1010];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= M; i++) {
		for(int j = 0; j <= T; j++) {
			if(j >= vec[i].t)
				dp[i][j] = max2(dp[i-1][j], dp[i-1][j-vec[i].t] + vec[i].n);
			else
				dp[i][j] = dp[i-1][j];	
		}
	}
	cout << dp[M][T] << endl;
    return 0;
}
