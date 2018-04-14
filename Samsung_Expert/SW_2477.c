// 2018. 04. 14. (Sat)
// SW Expert Academy #2477 차량 정비소

/* 
# 접수 창구의 우선순위
1) 여러 고객이 기다리고 있는 경우 고객번호가 낮은 순서대로
2) 빈 창구가 여러 곳인 경우 접수 창구번호가 작은 곳으로

# 정비 창구의 우선순위
1) 먼저 기다리는 고객이 우선
2) 두 명 이상의 고객들이 접수 창고 접수 완료 >> 접수 창구번호가 작은 고객 우선
3) 빈 창구가 여러 곳인 경우 정비 창구번호가 작은 곳으로
*/

#include<stdio.h>

void func();

int T, N, M, K, A, B;
int a[20] = { 0 }, b[20] = { 0 }, c[1000] = { 0 }; // 접수 창구, 정비 창구, 손님 시간
int alist[20][2] = { 0 }, blist[20][2] = { 0 }; // 손님 번호, 창구 남은 시간
int num1[1000] = { 0 }, num2[1000] = { 0 }; // 손님 이용 창구 번호

int main(void) {

	int t = 0, i, j, cnt = 0;

	scanf("%d", &T);

	while (t < T) {

		t++;

		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);

		for (i = 0; i < N; i++)	scanf("%d", &a[i]);
		for (i = 0; i < M; i++) scanf("%d", &b[i]);
		for (i = 0; i < K; i++) scanf("%d", &c[i]);

		func();

		for (i = 0; i < K; i++) if (num1[i] == A && num2[i] == B) cnt += i;

		printf("#%d %d\n", t, cnt);

	} // while()

	return 0;
} // main()

void func() {

	int i, j, n1, n2;
	int num = 0, wa = 0, wb = 0, waiting[1000] = { 0 }; // 손님번호 0부터
	int end = 0;

	while (1) {

		n2 = 0; // 창구 번호

		// 정비 창구 정리
		for (i = wa; i < wb; i++) { // 기다리는 손님들 중에
			while (1) {
				if (blist[n2][1] == 0) { // 빈 창구가 있으면
					blist[n2][1] = b[n2]; // 시간 할당
					blist[n2][0] = waiting[wa] + 1; // 손님 번호 저장
					num2[waiting[wa]] = n2; // 이용 창구 번호 저장
					wa++;
					break;
				} // if()
				n2++;
				if (n2 == M) break; // 빈 창구가 하나도 없을 경우
			} // while()
			if (n2 == M) break; // 빈 창구가 하나도 없을 경우
		}

		n1 = 0; // 창구 번호

		// 접수 창구 정리
		for (i = num; i < K; i++) { // 손님들 중에
			if (c[i] != 0) break; // 대기하는 손님이 없으면
			else { // 대기하는 손님이 있으면
				while (1) {
					if (alist[n1][1] == 0) { // 낮은 창구 번호부터 자리가 있으면
						alist[n1][1] = a[n1]; // 시간 할당
						alist[n1][0] = i + 1; // 손님 번호 저장
						num1[num] = n1;
						num++;
						break;
					} // if()
					n1++;
					if (n1 == N) break; // 빈 창구가 하나도 없을 경우
				} // while()
			} // if()
			if (n1 == N) break; // 빈 창구가 하나도 없을 경우
		} // for(i)

		// 시간 흐르게 하기
		for (i = num; i < K; i++) c[i]--;
		for (i = 0; i < N; i++) { // 접수 창구 정리
			if (alist[i][1] - 1 == 0) { // 끝났을 경우
				waiting[wb] = alist[i][0] - 1; // 대기열로 보내기
				alist[i][0] = 0;
				wb++;
			}
			if (alist[i][1] != 0) alist[i][1]--; // 시간 감소
		} // for(i)
		for (i = 0; i < M; i++) { // 정비 창구 정리
			if (blist[i][1] - 1 == 0) { // 끝났을 경우
				blist[i][0] = 0;
				end++;
			}
			if (blist[i][1] != 0) blist[i][1]--; // 시간 감소
		} // for(i)

		if (end == K) break;
	} // while()

} // func()