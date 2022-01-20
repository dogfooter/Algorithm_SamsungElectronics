#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int T, N;
int dp[MAX][MAX];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
	int test_case;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		string str1, str2;
        cin >> str1 >> str2;

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= str1.size(); i++) {
            for (int j = 1; j <= str2.size(); j++) { 
                if (str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
		cout << "#" << test_case << " " << dp[str1.size()][str2.size()] << '\n';
	}
	return 0;
}