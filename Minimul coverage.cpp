#include<bits/stdc++.h>
using namespace std;
int main()
{
    int testCase,M,l,r;
    scanf("%d",&testCase);
    while(testCase--)
    {
        scanf("%d",&M);

        vector<pair<int,int>>intervals;

        while(scanf("%d %d",&l,&r),l||r)
        {
            intervals.push_back({l,r});
        }
        sort(intervals.begin(),intervals.end());

        vector<int>ans;

        int cur = 0;

        for(int i=0;i<intervals.size()&&cur<M;i++)
        {
            if(intervals[i].first>cur)
            {
                ans.clear();
                break;
            }

            int futherMost = intervals[i].second;

            int pos = i;

            while(i+1<intervals.size()&&intervals[i+1].first<=cur)
            {
                i++;
                if(futherMost<intervals[i].second)
                {
                    futherMost = intervals[i].second;
                    pos = i;
                }
            }

            ans.push_back(pos);

            cur = futherMost;
        }

        if(cur<M)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",ans.size());

            for(auto &i : ans)
            {
                printf("%d %d\n",intervals[i].first,intervals[i].second);
            }
        }
        if(testCase)cout<<endl;
    }
}
