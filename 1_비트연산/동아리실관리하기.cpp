#include <iostream>
#include <string>
#include <cstring>

#define MAX 10000

using namespace std;

long long DP[MAX][16]; // A, B, C, D 경우의 수 2^4 - 1 = 15

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string str;
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
        cin >> str;
        
        memset(DP, 0, sizeof(DP));
        for (int day = 0; day < str.length(); ++day) {
            int admin = 1 << (str[day] - 'A');

            for (int i = 1; i < 16; ++i) {
                // 1일차에 관리자와 열쇠를 가진 A가 모두 포함된 경우
                if (day == 0) {
                    if ((i & admin) != 0 && (i & 1) != 0) {
                        DP[day][i] = 1;
                    }
                }
                // 2일차 이후
                else {
                    if (DP[day-1][i] != 0) {
                        for (int j = 1; j < 16; ++j) {
                            // 어제활동한사람(i)과 오늘활동한사람(j)이 최소한 한명은 겹침 && 오늘활동한사람 중에 관리자 포함
                            if ((i & j) != 0 && (j & admin) != 0) {
                                DP[day][j] += DP[day-1][i];
                                DP[day][j] %= 1000000007;
                            }
                        }
                    }
                }
            }
        }

        long long answer = 0;
        for (int i = 1; i < 16; ++i) {
            answer += DP[str.size()-1][i];
            answer %= 1000000007;
        }

        cout << "#" << test_case << " " << answer << '\n';
	}

	return 0;
}