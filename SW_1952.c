// 2018. 04. 13. (Fri)
// SW Expert Academy #1952 수영장

#include<stdio.h>

void func(int, int);

int T, price[4], plan[12], ground = 0;
int min = 0;
int mCost[12][3] = { 0 }; // mCost[i][0]: 1일 이용, [1]: 1달 이용, [2]: 3달 이용

int main(void) {

	int i;

	scanf("%d", &T);

	while (ground < T) {

		ground++;

		for (i = 0; i < 4; i++) scanf("%d", &price[i]);
		min = price[3]; // 1년 이용권의 요금을 min으로 잡아두기

		for (i = 0; i < 12; i++) {
			scanf("%d", &plan[i]);

			mCost[i][0] = plan[i] * price[0];
			mCost[i][1] = price[1];
			mCost[i][2] = price[2];
		}

		func(1, 0);
		func(1, 1);
		func(1, 2);

		printf("#%d %d\n", ground, min);

	} // while()

	return 0;
} // main()

void func(int m, int cost) {

	int month = m - 1;

	if (m > 12) {
		min = min < cost ? min : cost;
		return;
	}
	func(m + 1, cost + mCost[month][0]); // 1일권으로 끊었을 경우
	func(m + 1, cost + mCost[month][1]); // 1개월권으로 끊었을 경우
	if (m < 11) func(m + 3, cost + mCost[month][2]); // 3개월권으로 끊었을 경우

} // func()