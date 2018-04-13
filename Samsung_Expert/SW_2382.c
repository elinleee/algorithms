// 2018. 04. 14. (Sat)
// SW Expert Academy #2382 미생물 격리

#include <stdio.h>

int isEdge(int, int);
void func();

int T, N, M, K;
int map[100][100][2] = { 0 }; // 각 좌표에 있는 미생물의 수와 방향
int dmap[100][100][2] = { 0 };
int cell[1000][2] = { 0 }; // 군집들의 위치 좌표
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main(void) {

	int i, j, t = 0, cnt;
	int k;

	scanf("%d", &T);

	while (t < T) {
		t++; cnt = 0;

		scanf("%d %d %d", &N, &M, &K);

		for (i = 0; i < K; i++) {
			scanf("%d %d", &cell[i][0], &cell[i][1]);
			scanf("%d %d", &map[cell[i][0]][cell[i][1]][0], &map[cell[i][0]][cell[i][1]][1]);
		} // for(i)

		for (i = 0; i < M; i++) {
			printf("=================\n");
			for (j = 0; j < N; j++) {
				for (k = 0; k < N; k++) {
					printf("(%2d, %2d) ", map[j][k][0], map[j][k][1]);
				}
				printf("\n");
			}
			func();
		}

		printf("=================\n");
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				printf("(%2d, %2d) ", map[j][k][0], map[j][k][1]);
			}
			printf("\n");
		}
		
		for (i = 0; i < N; i++) for (j = 0; j < N; j++) cnt += map[i][j][0];

		printf("#%d %d\n", t, cnt);

	} // while()

	return 0;
} // main()

int isEdge(int x, int y) {
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1) return 1;
	else return 0;
} // isEdge()

void func() {
	
	int i, j, x, y, c, d;
	int dx, dy, dc, dd;

	for (i = 0; i < K; i++) {

		x = cell[i][0]; y = cell[i][1];
		c = map[x][y][0]; d = map[x][y][1]; // 미생물 수, 방향

		if (map[x][y][0] == 0) continue; // 미생물이 없을 경우 pass
		if (x == 0 && y == 0) continue; 

		dx = x + dir[d - 1][0]; 
		dy = y + dir[d - 1][1];
		dc = c; dd = d;

		if (isEdge(dx, dy) == 1) { // 가장자리로 갔을 경우
			dc = c / 2; 
			if (d == 1) dd = 2;
			else if (d == 2) dd = 1;
			else if (d == 3) dd = 4;
			else if (d == 4) dd = 3;
		} 
		
		if (dmap[dx][dy][0] != 0) { // 다른 군집이랑 겹칠 경우
			dd = ((dc > dmap[dx][dy][0]) ? dd : dmap[dx][dy][1]);
			dc += dmap[dx][dy][0];
			cell[i][0] = 0; cell[i][1] = 0;
		}
		else 
			cell[i][0] = dx; cell[i][1] = dy;
		
		dmap[dx][dy][0] = dc;
		dmap[dx][dy][1] = dd;

	} // for(i)

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			map[i][j][0] = dmap[i][j][0]; map[i][j][1] = dmap[i][j][1];
			dmap[i][j][0] = 0; dmap[i][j][1] = 0;
		}
	}
	
} // func()