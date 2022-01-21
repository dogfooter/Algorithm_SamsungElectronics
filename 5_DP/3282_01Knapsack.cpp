#include <bits/stdc++.h>

#define MAXN 101
#define MAXK 1001

using namespace std;

struct Thing {
	int volume; // 물건의 볼륨
	int value;	// 물건의 가치
};

vector<Thing> item;
int DP[MAXN][MAXK];
int T, N, K;
int volume, value;

void init()
{
	item.clear();
	item.push_back({0, 0});
	memset(DP, 0, sizeof(DP));
}

int knapsack()
{
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			int wi = item[i].volume;
			int vi = item[i].value;
			
			if (wi > j) {
				DP[i][j] = DP[i-1][j];
			}
			else {
				DP[i][j] = max(DP[i-1][j], DP[i-1][j-wi] + vi);
			}
		}
	}
	
	return DP[N][K];
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
	int test_case;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		init();

		cin >> N >> K;
        for (int i = 1; i <= N; ++i) {
			cin >> volume >> value;
			item.push_back({volume, value});
		} 

		cout << "#" << test_case << " " << knapsack() << '\n';
	}
	return 0;
}