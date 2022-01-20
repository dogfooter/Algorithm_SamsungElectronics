#include <iostream>

using namespace std;

int charge[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
int cnt[8];

void solve(int N)
{
    for (int i = 0; i < 8; i++) {
        if (N >= charge[i]) {
            cnt[i] = (N / charge[i]);
            N %= charge[i];
        }
    }

    for (int i = 0; i < 8; i++)
        cout << cnt[i] << ' ';
    cout << '\n';
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T, N;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
        fill(cnt, cnt+8, 0);
        cin >> N;
        cout << "#" << test_case << '\n';
        solve(N);
	}
	return 0;
}