// https://www.acmicpc.net/problem/12865

#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j, n, k;
	int *warr, *varr, *arr;

	scanf("%d %d", &n, &k); // 아이템 갯 수, 배낭 용량


	warr = (int *)malloc(sizeof(int) * n);
	varr = (int *)malloc(sizeof(int) * n);
	arr = (int *)malloc(sizeof(int) * (k+1));

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &warr[i], &varr[i]);
		if (varr[i] == 0)
			warr[i] = 0;
	}

	for (i = 0; i < k; i++)
    {
		arr[i] = 0;
    }

	for (i = 0; i < n; i++) // 갯 수 별로
	{
		for (j = k; j > 0; j--) // 용량 최대치까지
		{
			if (warr[i] <= j)
			{
				if (arr[j] < arr[j - warr[i]] + varr[i])
                {
					arr[j] = arr[j - warr[i]] + varr[i];
                }
			}
		}
	}

	printf("%d", arr[k]);

	free(warr);
	free(varr);
	free(arr);



    return 0;
}


