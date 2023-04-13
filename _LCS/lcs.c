#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int LCS(char* X, char* Y, int i, int j);
int FindMax(int a, int b);


int main(){
    char X[1000];
    char Y[1000];

    scanf("%s",X);
    scanf("%s",Y);

    int len_X = strlen(X);
    int len_Y = strlen(Y);



    LCS(X, Y, len_X, len_Y);




    return 0;
}


int LCS(char* X, char* Y, int i, int j)
{
    int c;
    if(i==0 || j==0){
        c = 0;
    }

    else if(X[i] == Y[i]){
        c = LCS(X,Y,i-1,j-1) + 1;

    }

    else{
        c = FindMax(LCS(X,Y,i,j-1) , LCS(X,Y,i-1,j));

    }

    return 0;

}

int FindMax(int a, int b)
{
  if (a >= b) 
    return a;
  else
    return b;
}

