import java.util.Scanner;

class pair {
    int x, y;
    pair(int x, int y) { this.x = x; this.y = y; }
}

class Solution {
    private static int T, N, size, answer;
    private static int [][] graph;
    private static int [] dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    private static pair [] core;
    private static boolean [] isVisit;

	public static void combination(int idx, int cnt, int R) {
		if (cnt == R) {
			dfs(0, 0);
			return;
		}

		for (int i = idx; i < size; i++) {
			isVisit[i] = true;
			combination(i + 1, cnt + 1, R);
			isVisit[i] = false;
		}
	}
	
	public static void dfs(int idx, int cnt) {
		if (idx == size) {
			answer = Math.min(answer, cnt); // 배열 끝까지 돌렸으면 이때의 최솟값 갱신
			return;
		}
		if (!isVisit[idx]) { // 부분 집합에 포함되는 애들만 다음 단계로 넘어갈 수 있다.
			dfs(idx + 1, cnt);
			return;
		}
		for (int i = 0; i < 4; i++) {
			int x = core[idx].x, y = core[idx].y, tmp = 0;
			boolean success = false;
			while (true) {
				x += dx[i]; y += dy[i];
				if (x < 0 || x >= N || y < 0 || y >= N) { // 범위 끝까지 갔으면 성공
					success = true;
					break;
				}
				if (graph[x][y] != 0) break; // 전선이나 코어를 만나면 실패
				graph[x][y] = 2; // 전선 표시
				tmp++; // 전선 길이 합
			}
			if (success) dfs(idx + 1, cnt + tmp);
			while (true) { // 원 상태로 돌려놓기
				x -= dx[i]; y -= dy[i];
				if (x == core[idx].x && y == core[idx].y) break;
				graph[x][y] = 0;
			}
		}
	}

	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++) {
            N = sc.nextInt();
		    graph = new int[N][N];
            core = new pair[12];
            isVisit = new boolean[12];
            answer = Integer.MAX_VALUE;
            size = 0;

            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    graph[i][j] = sc.nextInt();
            
            for (int i = 1; i < N-1; ++i)
                for (int j = 1; j < N-1; ++j)
                    if (graph[i][j] == 1)
                        core[size++] = new pair(i, j);
            
            for (int i = size; i >= 0; --i) {
                combination(0, 0, i);
                if (answer < Integer.MAX_VALUE)
                    break;
            }
            System.out.println("#" + test_case + " " + answer);
		}
        sc.close();
	}
}