#include<stdio.h>

int arr[15][15];

int main() {
	for (int i = 0; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			if (i == 0)
				arr[0][j] = j;
			else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", arr[a][b]);
	}
}