// 2018. 04. 14. (Sat)
// SW Expert Academy #2477 ���� �����

/* 
# ���� â���� �켱����
1) ���� ���� ��ٸ��� �ִ� ��� ����ȣ�� ���� �������
2) �� â���� ���� ���� ��� ���� â����ȣ�� ���� ������

# ���� â���� �켱����
1) ���� ��ٸ��� ���� �켱
2) �� �� �̻��� ������ ���� â�� ���� �Ϸ� >> ���� â����ȣ�� ���� �� �켱
3) �� â���� ���� ���� ��� ���� â����ȣ�� ���� ������
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
		// ���� â�� ���� - ���� ��� ����
		for (fi = 0; fi < N; fi++) { // ���� â�� ��ȣ�� ���� ����
			if (a[fi].cusNum != 0 && a[fi].remain == 0) { // ���� ���� ���
				waiting[wb] = a[fi].cusNum; // ��⿭�� �մ� ��ȣ ����
				wb++;
				a[fi].cusNum = 0;
			}
		} // for(fi)

		// ���� â�� ���� - ��� ���� ��� ����
		j = 0;
		while (c[i].time == 0) {
			while (j < N) {
				if (a[j].remain == 0) {
					a[j].cusNum = i + 1; // �մ� ��ȣ ����
					a[j].remain = a[j].time; // �ð� �Ҵ�
					c[i].numA = j; // â�� ��ȣ ����
					i++; // �մ� ��������
					break;
				}
				j++;
			} // while()
			if (j == N) break; // �� â���� ���� ���
		}

		// ���� â�� ���� - ���� ��� ����
		for (fi = 0; fi < M; fi++) {
			if (b[fi].cusNum != 0 && b[fi].remain == 0) {
				b[fi].cusNum = 0;
				end++;
				if (end == K) return;
			}
		}

		// ���� â�� ���� - ��� ���� ��� ����
		k = 0;
		while (wa < wb) {
			while (k < M) {
				if (b[k].remain == 0) {
					b[k].cusNum = waiting[wa]; // �մ� ��ȣ ����
					b[k].remain = b[k].time; // �ð� �Ҵ�
					c[waiting[wa]].numB = k; // â�� ��ȣ ����
					wa++; // ������ ��������
					break;
				}
				k++;
			} // while()
			if (k == M) break; // �� â���� ���� ���
		}

		// �ð� �帣��
		for (fi = 0; fi < N; fi++) a[fi].remain--;
		for (fi = 0; fi < M; fi++) b[fi].remain--;
		for (fi = 0; fi < K; fi++) c[fi].time--;

	} // while()
} // func()
