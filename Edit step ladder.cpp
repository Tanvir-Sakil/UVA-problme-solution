#include<bits/stdc++.h>
using namespace std;
char word[25005][20];
int len[25005];

bool check_1(int x,int y)
{
    int cnt = 0;

    for(int i=0; i<len[x]; i++)
    {
        if(word[x][i]!=word[y][i])
        {
            cnt++;
        }
    }
    if(cnt!=1)return false;
    return true;
}
bool check_2(int x,int y)
{
    int cnt =0;

    for(int i=0,j=0; i<len[x]; i++)
    {
        if(word[x][i]!=word[y][j])
        {
            cnt++;
        }
        else
        {
            j++;
        }
    }
    if(cnt != 1)return false;
    return true;
}
int main()
{
    int n=0,dp[25005]= {0},maxx =0;

    while(gets(word[n]))
    {
        len[n] = strlen(word[n]);
        n++;
    }

    for(int i=0; i<n; i++)
    {
        dp[i] = 1;

        for(int j=0; j<i; j++)
        {
            if(len[i]==len[j]&&check_1(i,j)&&dp[j]>=dp[i])
            {
                dp[i]= dp[j]+1;
            }
            else if(len[i]==len[j]+1&&check_2(i,j)&&dp[j]>=dp[i])
            {
                dp[i]= dp[j]+1;
            }
            else if(len[i]==len[j]-1&&check_2(j,i)&&dp[j]>=dp[i])
            {
                dp[i]= dp[j]+1;
            }

        }
        if(dp[i]>maxx)
        {
            maxx = dp[i];
        }
    }
    printf("%d\n",maxx);
    return 0;
}
