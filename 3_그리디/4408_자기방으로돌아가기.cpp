#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct moveInfo {
	int start;
	int end;
};

int T, N;
bool visited[400];
moveInfo moving[400];

int myCompare(const moveInfo& A, const moveInfo& B)
{
	return A.start < B.start;
}

int solve()
{
	sort(moving, moving + N, myCompare);
	fill(visited, visited + 400, false);
	int answer = 0, cnt = 0;
	while (cnt < N) {
		int lastEnd = 0;
		for (int i = 0; i < N; ++i) {
			if (visited[i]) continue;
			if (moving[i].start < lastEnd) continue;
			
			lastEnd = moving[i].end;
			visited[i] = true;
			++cnt;
		}
		++answer;
	}
	return answer;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
	int test_case;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N;
		memset(moving, 0, sizeof(moving));
		for (int i = 0; i < N; ++i) {
			cin >> moving[i].start >> moving[i].end;
			
			if (moving[i].start % 2 == 0)
				moving[i].start--;
			
			if (moving[i].end % 2 == 1)
				moving[i].end++;

			if (moving[i].start > moving[i].end) {
				int tmp = moving[i].start;
				moving[i].start = moving[i].end;
				moving[i].end = tmp;
			}
		}
		cout << "#" << test_case << " " << solve() << '\n';
	}
	return 0;
}