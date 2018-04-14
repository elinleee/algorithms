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

void func();

int T, N, M, K, A, B;
int a[20] = { 0 }, b[20] = { 0 }, c[1000] = { 0 }; // ���� â��, ���� â��, �մ� �ð�
int alist[20][2] = { 0 }, blist[20][2] = { 0 }; // �մ� ��ȣ, â�� ���� �ð�
int num1[1000] = { 0 }, num2[1000] = { 0 }; // �մ� �̿� â�� ��ȣ

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
	int num = 0, wa = 0, wb = 0, waiting[1000] = { 0 }; // �մԹ�ȣ 0����
	int end = 0;

	while (1) {

		n2 = 0; // â�� ��ȣ

		// ���� â�� ����
		for (i = wa; i < wb; i++) { // ��ٸ��� �մԵ� �߿�
			while (1) {
				if (blist[n2][1] == 0) { // �� â���� ������
					blist[n2][1] = b[n2]; // �ð� �Ҵ�
					blist[n2][0] = waiting[wa] + 1; // �մ� ��ȣ ����
					num2[waiting[wa]] = n2; // �̿� â�� ��ȣ ����
					wa++;
					break;
				} // if()
				n2++;
				if (n2 == M) break; // �� â���� �ϳ��� ���� ���
			} // while()
			if (n2 == M) break; // �� â���� �ϳ��� ���� ���
		}

		n1 = 0; // â�� ��ȣ

		// ���� â�� ����
		for (i = num; i < K; i++) { // �մԵ� �߿�
			if (c[i] != 0) break; // ����ϴ� �մ��� ������
			else { // ����ϴ� �մ��� ������
				while (1) {
					if (alist[n1][1] == 0) { // ���� â�� ��ȣ���� �ڸ��� ������
						alist[n1][1] = a[n1]; // �ð� �Ҵ�
						alist[n1][0] = i + 1; // �մ� ��ȣ ����
						num1[num] = n1;
						num++;
						break;
					} // if()
					n1++;
					if (n1 == N) break; // �� â���� �ϳ��� ���� ���
				} // while()
			} // if()
			if (n1 == N) break; // �� â���� �ϳ��� ���� ���
		} // for(i)

		// �ð� �帣�� �ϱ�
		for (i = num; i < K; i++) c[i]--;
		for (i = 0; i < N; i++) { // ���� â�� ����
			if (alist[i][1] - 1 == 0) { // ������ ���
				waiting[wb] = alist[i][0] - 1; // ��⿭�� ������
				alist[i][0] = 0;
				wb++;
			}
			if (alist[i][1] != 0) alist[i][1]--; // �ð� ����
		} // for(i)
		for (i = 0; i < M; i++) { // ���� â�� ����
			if (blist[i][1] - 1 == 0) { // ������ ���
				blist[i][0] = 0;
				end++;
			}
			if (blist[i][1] != 0) blist[i][1]--; // �ð� ����
		} // for(i)

		if (end == K) break;
	} // while()

} // func()