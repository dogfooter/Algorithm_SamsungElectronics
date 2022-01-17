#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int test_case;
	int T, N;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
        int answer = 0;
		int check = 0;

        cin >> N;
		
        while (true) {
			answer += N;

			int temp = answer;
			while (temp > 0) {
				check |= 1 << (temp % 10);
				temp /= 10;
			}

			if (check == (1 << 10) - 1)
				break;
        }        

        cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;
}