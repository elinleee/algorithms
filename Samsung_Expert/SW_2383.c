// 2018. 04. 14. (Sat)
// SW Expert Academy #2383 점심 식사시간
#include<stdio.h>

#define abs(a) (a>0)?(a):(-a);

void func();

int map[10][10] = { 0 };
int human[10][4] = { 0 }; // x좌표, y좌표, 0번 계단까지, 1번 계단까지
int stair[2][4] = { 0 }; // x좌표, y좌표, 시간, 인원수
int sList[2][3] = { 0 }; // 계단 사람 유무

int T, N, hCnt, sCnt;

int main(void) {
	
	int t;
	int i, j;

	scanf("%d", &T);

	while (t < T) {
		t++;
		hCnt = 0; sCnt = 0;
		scanf("%d", &N);

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) { // 사람
					human[hCnt][0] = i; human[hCnt][1] = j;
					hCnt++;
				}
				if (map[i][j] > 1) { // 계단
					stair[sCnt][0] = i; stair[sCnt][1] = j; stair[sCnt][2] = map[i][j];
					sCnt++;
				}
			} // for(j)
		} // for(i)

		for (i = 0; i < hCnt; i++) { // 거리 계산
			human[i][2] = abs(human[i][0] - stair[0][0]) + abs(human[i][1] - stair[0][1]);
			human[i][3] = abs(human[i][0] - stair[1][0]) + abs(human[i][1] - stair[1][1]);
		}

		func();

	} // while()

	return 0;
} // main()

void func() {
	
	int time = 0, arr[2][10]; // 몇번째 사람이 도착했나
	int i, j, max = 0, maxIndex;

	while (1) {
		time++;

		for (i = 0; i < hCnt; i++) {
			human[i][2]--;
			human[i][3]--;
			if (human[i][2] == 0) arr[0][i] = 1;
			if (human[i][3] == 0) arr[1][i] = 1;
		}

		for (i = 0; i < 3 - stair[0][3]; i++) {
			for (j = 0; j < hCnt; j++) {
				if (arr[0][j] == 1) {
					if (human[arr[0][j]][3] > max) {
						max = human[arr[0][j]][3];
						maxIndex = j;
					}
				}
				arr[0][maxIndex] = 0;

			} // for(j)
		} // for(i)


	} // while()


} // func()