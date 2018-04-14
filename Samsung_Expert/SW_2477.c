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

struct line {
	int cusNum;
	int time;
	int remain;
} typedef line;

struct cus {
	int time;
	int numA;
	int numB;
} typedef cus;

void func();

line a[20] = { 0 }, b[20] = { 0 };
cus c[1000] = { 0 };
int T, N, M, K, A, B, end;

int main(void) {

	int i, j, t = 0, sum;

	scanf("%d", &T);

	while (t < T) {
		t++;
		sum = 0; end = 0;

		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);

		for (i = 0; i < N; i++) scanf("%d", &a[i].time);
		for (i = 0; i < M; i++) scanf("%d", &b[i].time);
		for (i = 0; i < K; i++) scanf("%d", &c[i].time);

		func();

		for (i = 0; i < K; i++) if (c[i].numA == A && c[i].numB == B) sum += i;
		printf("#%d %d\n", t, sum);

	} // while()

	return 0;
} // main()

void func() {
	
	int i = 0, j, k;
	int fi, fj;
	int wa = 0, wb = 0;
	int waiting[1000];

	while (1) {
		// 접수 창구 정리 - 끝난 사람 정리
		for (fi = 0; fi < N; fi++) { // 접수 창구 번호가 작은 순서
			if (a[fi].cusNum != 0 && a[fi].remain == 0) { // 접수 끝난 사람
				waiting[wb] = a[fi].cusNum; // 대기열에 손님 번호 저장
				wb++;
				a[fi].cusNum = 0;
			}
		} // for(fi)

		// 접수 창구 정리 - 대기 중인 사람 배정
		j = 0;
		while (c[i].time == 0) {
			while (j < N) {
				if (a[j].remain == 0) {
					a[j].cusNum = i + 1; // 손님 번호 저장
					a[j].remain = a[j].time; // 시간 할당
					c[i].numA = j; // 창구 번호 저장
					i++; // 손님 빠져나감
					break;
				}
				j++;
			} // while()
			if (j == N) break; // 빈 창구가 없을 경우
		}

		// 정비 창구 정리 - 끝난 사람 정리
		for (fi = 0; fi < M; fi++) {
			if (b[fi].cusNum != 0 && b[fi].remain == 0) {
				b[fi].cusNum = 0;
				end++;
				if (end == K) return;
			}
		}

		// 정비 창구 정리 - 대기 중인 사람 배정
		k = 0;
		while (wa < wb) {
			while (k < M) {
				if (b[k].remain == 0) {
					b[k].cusNum = waiting[wa]; // 손님 번호 저장
					b[k].remain = b[k].time; // 시간 할당
					c[waiting[wa]].numB = k; // 창구 번호 저장
					wa++; // 웨이팅 빠져나감
					break;
				}
				k++;
			} // while()
			if (k == M) break; // 빈 창구가 없을 경우
		}

		// 시간 흐르기
		for (fi = 0; fi < N; fi++) a[fi].remain--;
		for (fi = 0; fi < M; fi++) b[fi].remain--;
		for (fi = 0; fi < K; fi++) c[fi].time--;

	} // while()
} // func()
