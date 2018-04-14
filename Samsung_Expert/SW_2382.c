// 2018. 04. 14. (Sat)
// SW Expert Academy #2382 미생물 격리

#include <stdio.h>

int isInside(int, int);
int isEdge(int, int);
void func();

int T, N, M, K;
int map[100][100][2] = { 0 }; // 각 좌표에 있는 미생물의 수 & 군집의 방향
int dir[4][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };

int main(void) {

	int i, j, tx, ty, total;
	int t = 0;
	int k;

	scanf("%d", &T);

	while (t < T) {

		t++;
		total = 0;
		for (i = 0; i < N; i++) for (j = 0; j < N; j++) { map[i][j][0] = 0; map[i][j][1] = 0; }

		scanf("%d %d %d", &N, &M, &K); // 맵 크기, 시간, 군집 수
		for (i = 0; i < K; i++) {
			scanf("%d %d", &tx, &ty);
			scanf("%d %d", &map[tx][ty][0], &map[tx][ty][1]);
		} // for(i)

		for (i = 0; i < M; i++) func();

		for (i = 0; i < N; i++) for (j = 0; j < N; j++) total += map[i][j][0];

		printf("#%d %d\n", t, total);

	}// while()

	return 0;
} // main()

int isInside(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N) return 1;
	else return 0;
} // isInside()

int isEdge(int x, int y) {
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1) return 1;
	else return 0;
} // isEdge()

void func() {

	int i, j, k;
	int x, y, c, d, sum, max, maxdir;
	int dmap[100][100][2] = { 0 };

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {

			sum = 0; max = 0; maxdir = 0;

			for (k = 0; k < 4; k++) {

				x = i + dir[k][0]; y = j + dir[k][1];
				if (isInside(x, y) == 0) continue;
				c = map[x][y][0]; d = map[x][y][1];

				if (c == 0 && d == 0) continue;

				if ((k == 0 && d == 2) || (k == 1 && d == 1) ||
					(k == 2 && d == 4) || (k == 3 && d == 3)) {

					sum += map[x][y][0];

					if (map[x][y][0] > max) {
						max = map[x][y][0];
						maxdir = map[x][y][1];
					} // if()
				} // if()
			} // for(k)

			if (isEdge(i, j) == 1) { // 가장자리
				dmap[i][j][0] = sum / 2;
				if (maxdir == 1) dmap[i][j][1] = 2;
				else if (maxdir == 2) dmap[i][j][1] = 1;
				else if (maxdir == 3) dmap[i][j][1] = 4;
				else if (maxdir == 4) dmap[i][j][1] = 3;
			}
			else {
				dmap[i][j][0] = sum;
				dmap[i][j][1] = maxdir;
			} // if ..  else

		} // for(j)
	} // for(i)

	for (i = 0; i < N; i++) for (j = 0; j < N; j++) {
		map[i][j][0] = dmap[i][j][0]; map[i][j][1] = dmap[i][j][1];
		dmap[i][j][0] = 0; dmap[i][j][1] = 0;
	}

} // func()