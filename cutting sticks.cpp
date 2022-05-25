#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
bool shouldCut[10001];
int memo[1001][1001];

int optimalCut(int indexStart,int indexEnd)
{
    int memorizedResult = memo[indexStart][indexEnd];

    if(memorizedResult != INF)
    {
        return memorizedResult;
    }

    int minSubcutCost = INF;

    for(int i = indexStart+1;i<indexEnd;i++)
    {
        if(shouldCut[i])
        {
            int length =indexEnd - indexStart;

            int cost = length + optimalCut(indexStart,i)+ optimalCut(i,indexEnd);

            if(cost<minSubcutCost)
            {
                minSubcutCost = cost;
            }
        }
    }

    if(minSubcutCost == INF)
    {
        minSubcutCost = 0;
    }

    memo[indexStart][indexEnd] = minSubcutCost;


    return minSubcutCost;
}
int main()
{
    for(;;)
    {
        int stickLength;
        cin>>stickLength;

        if(stickLength==0)break;


        for(int i=0;i<=1000;i++)
        {
            shouldCut[i] =false;
            for(int j=0;j<=1000;j++)
            {
                memo[i][j] = INF;
            }
        }

        int numberOfCuts;

        int cutIndex;

        cin>>numberOfCuts;

        for(int cut = 0;cut<numberOfCuts;cut++)
        {
            cin>>cutIndex;
            shouldCut[cutIndex] = true;
        }

        int optimalCost = optimalCut(0,stickLength);

        printf("The minimum cutting is %d.\n",optimalCost);
    }
}
