#include<bits/stdc++.h>
using namespace std;

int dpp[10005][110];
int arr[10005];
int n,k;

int dp(int indx, int rem)
{
    if(indx == n)
    {
        if(rem%k==0)
            return 1;
        else
            return 0;
    }

    if(dpp[indx][rem]!=-1)
    {
        return dpp[indx][rem];
    }

    int res1=0,res2=0,res3=0,res4=0;

    int sum = rem + arr[indx];

    if(sum>=0)
        res1=dp(indx+1,sum%k);
    else
        res2 = dp(indx+1,((sum%k)+k));

    sum = rem - arr[indx];

    if(sum>=0)
        res3 = dp(indx+1,sum%k);
    else
        res4 = dp(indx+1,((sum%k)+k));

    return dpp[indx][rem] = max({res1,res2,res3,res4});
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&k);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }

        memset(dpp,-1,sizeof(dpp));

        int ans = dp(0,0);

        if(ans)
        {
            printf("Divisible\n");
        }
        else
        {
            printf("Not divisible\n");
        }
    }
}
