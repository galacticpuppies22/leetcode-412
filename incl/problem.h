/*
Constraints:

m == accounts.length
n == accounts[i].length
1 <= m, n <= 50
1 <= accounts[i][j] <= 100s
*/

/*------------------------Case 1------------------------*/
const int case1AccountsSize = 2;
const int case1AccountsColSize[2] = {3, 3};
int case1InputNums[2][3] = {
                    {1, 2, 3},
                    {3, 2, 1}
                };

/*------------------------Case 2------------------------*/
const int case2AccountsSize = 3;
const int case2AccountsColSize[3] = {2, 2, 2};
int case2InputNums[3][2] = {
                    {1, 5},
                    {7, 3},
                    {3, 5}
                };

/*------------------------Case 3------------------------*/
const int case3AccountsSize = 3;
const int case3AccountsColSize[3] = {3, 3, 3};
int case3InputNums[3][3] = {
                    {2, 8, 7},
                    {7, 1, 3},
                    {1, 9, 5}
                };

const int case1OutputNums = 6;
const int case2OutputNums = 10;
const int case3OutputNums = 17;

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize);