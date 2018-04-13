// 2018. 4. 13. (Fri)
// SW Expert Academy #1953 탈주범 검거

#include<stdio.h>

void func(int, int, int);
int isInside(int, int);

int T, test = 0, N, M, R, C, L, cnt;
int map[50][50] = { 0 };
int visit[50][50] = { 0 };
int pipe[8][4] = { 
	{0, 0, 0, 0}, {1, 1, 1, 1}, 
	{1, 0, 1, 0}, {0, 1, 0 ,1}, 
	{1, 1, 0, 0}, {0, 1, 1, 0}, 
	{0, 0, 1, 1}, {1, 0, 0, 1} 
};
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main(void) {

	int i, j;

	scanf("%d", &T);

	while (test < T) {
		test++;
		cnt = 0; // 맨홀뚜껑 위치 포함
	
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (i = 0; i < N; i++) 
			for (j = 0; j < M; j++) {
				visit[i][j] = 0; // init
				scanf("%d", &map[i][j]);
			}

		func(R, C, 1);
		printf("#%d %d\n", test, cnt);

	} // while()

	return 0;
} // main()

void func(int x, int y, int t) {

	int i, j, dx, dy, p;
	
	if (isInside(x, y) == 0) return; // 범위 밖
	if (t > L || (visit[x][y] < t && visit[x][y] > 0) || map[x][y] == 0) return; // escape condition

	if (visit[x][y] == 0) { cnt++; visit[x][y] = t;	} 
	else { if (visit[x][y] > t) visit[x][y] = t; }

	for (i = 0; i < 4; i++) {
		p = pipe[map[x][y]][i]; // 파이프 방향

		if (p == 1) {
			dx = x + dir[i][0]; dy = y + dir[i][1];
			if (isInside(dx, dy) == 0 || (visit[dx][dy] < t + 1 && visit[dx][dy] > 0)) continue;
			if (pipe[map[dx][dy]][(i + 2) % 4] == 1) func(dx, dy, t + 1);
		} // if
	} // for(i)	
} // func()

int isInside(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M) return 1;
	else return 0;
}