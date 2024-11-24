#include "../incl/main.h"
#include "../incl/problem.h"

int main(void)
{
    testCaseN(case1N, &case1ReturnSize, case1Output);
    testCaseN(case2N, &case2ReturnSize, case2Output);
    testCaseN(case3N, &case3ReturnSize, case3Output);
    return 0;
}

void testCaseN(int caseN, int* caseNReturnSize, const char** caseNOutput)
{
    bool rollingFlag = false;
    
    //TEST CASE n
    char** caseNReturnedCharArray = fizzBuzz(caseN, caseNReturnSize);
    for (int i = 0; i < caseN; i++)
    {
#ifdef DEBUG
        printf("i=%d\t%s[i]=%s\t%s[i]=%s\n", 
                        i, 
                        STRINGIFY(caseNReturnedCharArray), 
                        caseNReturnedCharArray[i], 
                        STRINGIFY(caseNOutput), 
                        caseNOutput[i]
        );
#endif /* DEBUG */
        if (strcmp(caseNReturnedCharArray[i], caseNOutput[i]) == 0)
        {
            rollingFlag = true;
        }
        else
        {
            //one of the returned values is not in the solution set at index i,
            //hence the returned values fail the test
            rollingFlag = false;
            break;
        }
    }
    printf("Test case %ld ", ++currentTestCase);
    if (rollingFlag == true)
    {
        printf("passed!\n");
    }
    else
    {
        printf("FAILED!\n");
    }
}