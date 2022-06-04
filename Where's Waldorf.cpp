#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dirs = {{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int main()
{
    int testCase,n,m,q;
    string st;
    cin>>testCase;

    while(testCase--)
    {
        cin>>n>>m;

        vector<string>grid;

        for(int i=0;i<n;i++)
        {
            cin>>st;

            transform(st.begin(),st.end(),st.begin(),::tolower);
            grid.push_back(st);
        }
        cin>>q;

        for(int i=0;i<q;i++)
        {
            cin>>st;
            transform(st.begin(),st.end(),st.begin(),::tolower);

            bool found = false;

            for(int i=0;i<n&&!found;i++)
            {
                for(int j=0;j<m&&!found;j++)
                {
                    for(auto& dir : dirs)
                    {
                        int x = i,y=j,len = 0;

                        while(len<st.length())
                        {
                            if(x<0||y<0||x>=n||y>=m||grid[x][y]!=st[len])break;

                            len++;

                            if(len == st.length())
                            {
                                found = true;
                            }

                            x+=dir[0],y+=dir[1];
                        }
                        if(found)
                        {
                            printf("%d %d\n",i+1,j+1);
                            break;
                        }
                    }
                }
            }
        }
        if(testCase)printf("\n");
    }
}
