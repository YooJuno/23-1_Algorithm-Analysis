#include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <string.h>
// #include <time.h>

// // GLOBAL VARIANCES and CONSTANT
// const int n = 4;
// const int W = 16;
// int w[] = {0, 2, 5, 10, 5}; // w[0] is meaningless
// int p[] = {0, 40, 30, 50, 10}; // p[0] is meaningless
// char include[][4] = {"", "", "", "", ""};
// char bestset[][4] = {"", "", "", "", ""};
// int prm_node_cnt = 0;
// int nprm_node_cnt = 0;
// int numbest = 0;
// int maxprofit = 0;

// void knapsack(int i, int profit, int weight);
// bool promising(int i, int profit, int weight);

// void knapsack(int i, int profit, int weight)
// {
//     // This set is best so far. Set numbest to number of items considered.
//     // Set bestset to this solution.
//     if (weight <= W && profit > maxprofit)
//     {
//         maxprofit = profit;
//         numbest = i;
//         memcpy(bestset, include, sizeof(include));
//     }

//     if (promising(i, profit, weight))
//     {
//         ++prm_node_cnt; // Count the number of promising node
//         strcpy(include[i + 1], "YES"); // Include w[i+1]
//         knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
//         strcpy(include[i + 1], "NO"); // Do not include w[i+1]
//         knapsack(i + 1, profit, weight);
//     }
//     else
//     {
//         ++nprm_node_cnt; // Count the number of non-promising node
//     }
// }

// bool promising(int i, int profit, int weight)
// {
//     int j, k;
//     int totweight;
//     float bound;

//     // Node is promising only if we should expand to its children.
//     // There must be some capacity left for the children.
//     if (weight >= W)
//     {
//         return false;
//     }
//     else
//     {
//         j = i + 1;
//         bound = (float)profit;
//         totweight = weight;

//         while (j <= n && totweight + w[j] <= W)
//         {
//             // Grab as many items as possible.
//             totweight = totweight + w[j];
//             bound = bound + p[j];
//             ++j;
//         }

//         k = j; // Use k for consistency with formula in text.
//         if (k <= n) // Grab fraction of kth item.
//             bound = bound + (W - totweight) * (p[k] / (float)w[k]);

//         return (bound > maxprofit);
//     }
// }

int main()
{
    // clock_t start, end;
    printf("hi\n");
    // start = clock();
    // knapsack(0, 0, 0);
    // end = clock();

    // for (int j = 1; j <= numbest; ++j)
    //     printf("w%d: %s   ", j, bestset[j]);

    // printf("\nThe answer: $%d\n", maxprofit);
    // printf("The num of promising node: %d\n", prm_node_cnt);
    // printf("The num of nonpromising node: %d\n", nprm_node_cnt);
    // double result = (double)(end - start) / CLOCKS_PER_SEC;
    // printf("Elpased time is: %f sec.\n", result);

    return 0;
}
