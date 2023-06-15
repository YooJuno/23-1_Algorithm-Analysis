#include <stdio.h>

char coin_names[5][256] = {
  "half_dollar", // 하프 달러(50¢)
  "quarter", // 쿼터(25¢)
  "dime", // 다임(10¢)
  "nickel", // 니켈(5¢)
  "penny" // 페니(1¢)
};

int coin_prices[] = {50, 25, 10, 5, 1};
const int COINT_TYPE_CNT = 5;

int FindCoins(int cents, int* coins_needed);
void PrintCoinsNeeded(int* coins_needed);

int main(void) {
  int cents;
  printf("Enter money in cents: ");
  scanf("%d", &cents);
  
  int coins_needed[COINT_TYPE_CNT] = {0,};
  int totalCoinsCnt = FindCoins(cents, coins_needed);

  printf("%d cents =\n", cents);
  PrintCoinsNeeded(coins_needed);
  
  printf("Total number of coins: %d\n", totalCoinsCnt);
  
  return 0;
}

int FindCoins(int cents, int* coins_needed)
{	
	// your code here
	for(int i=0; i<COINT_TYPE_CNT; i++){
		while(cents >= coin_prices[i]){
			cents -= coin_prices[i];
			coins_needed[i] += 1;
		}
	}
	
	int sum = 0;
	for(int i=0; i<COINT_TYPE_CNT; i++)
		sum += coins_needed[i];
	return sum;
}

void PrintCoinsNeeded(int* coins_needed)
{
	// your code here
	for(int i=0 ; i<COINT_TYPE_CNT ; i++){
		printf("%d(%s)", coins_needed[i], coin_names[i]);
		if(i!=4) printf(" + ");
		else printf("\n");
	}	
}
