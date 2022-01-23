#include <iostream>
#include <string>

using namespace std;

int test_case;
int T, exChange, answer;
string numPlate;

void DFS(int idx, int cnt)
{
    if (cnt == exChange) {
        answer = max(answer, stoi(numPlate));
        return;
    }

    for (int i = idx; i < numPlate.length()-1; ++i) {
        for (int j = i+1; j < numPlate.length(); ++j) {
            swap(numPlate[i], numPlate[j]);
            DFS(i, cnt+1);
            swap(numPlate[i], numPlate[j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
        answer = 0;
        cin >> numPlate >> exChange;

        // 불필요한 중복계산을 막는 조건
        if (exChange > numPlate.size())
            exChange = numPlate.size();

        DFS(0, 0);
        cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;
}