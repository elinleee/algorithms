// 2018. 04. 14. (Sat)
// SW Expert Academy #2382 미생물 격리

#include <stdio.h>

int isEdge(int, int);
void func();

int T, N, M, K;
int map[100][100][2] = { 0 }; // 각 좌표에 있는 미생물의 수 & 군집의 방향
int cell[1000][2] = { 0 }; // 군집들의 위치 좌표
int dir[4][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };

int main(void) {

	int i, j, tx, ty, sum;
	int t = 0;
	int k;

	scanf("%d", &T);

	while (t < T) {

		t++;
		sum = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				map[i][j][0] = 0; map[i][j][1] = 0;
			}
		}

		scanf("%d %d %d", &N, &M, &K); // 맵 크기, 시간, 군집 수
		for (i = 0; i < K; i++) {
			scanf("%d %d", &tx, &ty);
			scanf("%d %d", &map[tx][ty][0], &map[tx][ty][1]);
			cell[i][0] = tx; cell[i][1] = ty;
		} // for(i)

		for (i = 0; i < M; i++) func();

		for (i = 0; i < N; i++) for (j = 0; j < N; j++) sum += map[i][j][0];

		printf("#%d %d\n", t, sum);

	}// while()

	return 0;
} // main()

int isEdge(int x, int y) {
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1) return 1;
	else return 0;
} // isEdge()

void func() {

	int i, j;
	int x, y, c, d, sum, cnt = 0;
	int dx, dy, dc, dd, dmap[100][100][2] = { 0 }, max[100][100][2] = { 0 };

	for (i = 0; i < K; i++) {

		x = cell[i][0]; y = cell[i][1];
		c = map[x][y][0]; d = map[x][y][1];

		if (x == 0 && y == 0) continue;

		dx = x + dir[d - 1][0]; dy = y + dir[d - 1][1];
		dc = c; dd = d;

		// 가장자리
		if (isEdge(dx, dy) == 1) {
			dc /= 2;
			if (d == 1) dd = 2;
			else if (d == 2) dd = 1;
			else if (d == 3) dd = 4;
			else if (d == 4) dd = 3;
		} // if()

		  // 합쳐질 경우
		if (dmap[dx][dy][0] != 0) {
			if (c > max[dx][dy][0]) {
				max[dx][dy][0] = c;
				max[dx][dy][1] = d;
			} // if()
			dc += dmap[dx][dy][0];
			dd = max[dx][dy][1];
			cell[i][0] = 0; cell[i][1] = 0;
		} // if()
		else {
			max[dx][dy][0] = c;
			max[dx][dy][1] = d;
			cell[i][0] = dx; cell[i][1] = dy;
		}

		dmap[dx][dy][0] = dc; dmap[dx][dy][1] = dd;

	} // for(i)

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			map[i][j][0] = dmap[i][j][0];
			map[i][j][1] = dmap[i][j][1];
		}
	}

} // func()