#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    string answer;
	int test_case;
	int T, N, M;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M;
        
        string answer = "ON";
        int check = 0;
        for (int i = 0; i < N; ++i) {
            if (M % 2) {
                M >>= 1;
                continue;
            }

            answer = "OFF";
            break;
        }

        cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;
}