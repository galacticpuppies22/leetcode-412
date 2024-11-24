/*
Problem: https://leetcode.com/problems/fizz-buzz/
*/

#include "../incl/util.h"
#include "../incl/problem.h"

// #ifdef DEBUG
//     char* soln[] = {"1", "2", "Fizz"};
//     // char* soln[] = {"1", "2", "Fizz", "4", "Buzz"};
// #endif /* DEBUG */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Constraints: 1 <= n <= 10^4
 * (hence the #define MAX_RESULT_STR_LEN = 5 in problem.h)
 */
char** fizzBuzz(int n, int* returnSize)
{
    char** result = malloc(n * sizeof(char*)); // Allocate memory for n pointers to strings
    *returnSize = n; // since n = number of elements to be returned //TODO: fix this

    if(result == NULL)
    {
        fprintf(stderr, "Memory allocation of %s failed!\n", STRINGIFY(result));
        exit(1);
    }

    for(int i = 1; i <= n; i++)
    {
        result[i-1] = malloc(MAX_RESULT_STR_LEN * sizeof(char));

        if (result[i-1] == NULL)
        {
            fprintf(stderr, "Memory allocation of %s[%d] failed!\n", STRINGIFY(result), i);
            // Free previously allocated memory before exiting 
            for (int j = 0; j < i; j++) 
            {
                free(result[j]);
            } 
            free(result); 
            exit(1);
        }

        // if ((i % 3) == 0 && (i % 5) == 0)
        if (i % 15 == 0)
        {
            // strncpy(result[i-1], "FizzBuzz", 8);
            result[i-1] = "FizzBuzz";
        }
        else if ((i % 3) == 0)
        {
            // strncpy(result[i-1], "Fizz", 4);
            result[i-1] = "Fizz";
        }
        else if ((i % 5) == 0)
        {
            // strncpy(result[i-1], "Buzz", 4);
            result[i-1] = "Buzz";
        }
        else
        {
            // char str[(int) pow(10, 4)]; //10 ** 4 == 10000
            sprintf(result[i-1], "%d", i);
        }
    }

// #ifdef DEBUG
//     result = soln;
// #endif /* DEBUG */
    return result;
}
