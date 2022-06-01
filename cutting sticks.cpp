#include <bits/stdc++.h>
using namespace std;

vector <int> graph[250];
int color[250];

int dfs_color_selection(int node)
{
    int visit[250] = {0},variable,i,cnt = 0,contradiction = 0;
    stack <int> use;
    variable = 0;
    use.push(variable);
    cnt++;
    color[variable] = 1;
    visit[variable] = 1;
    while(1)
    {
        if(use.empty() == 1)
        {
            break;
        }
        variable = use.top();
        if(graph[variable].size() == 0)
        {
            use.pop();
            continue;
        }
        for(i = 0; i < graph[variable].size(); i++)
        {
            int got = graph[variable][i];
            if(visit[got] == 0)
            {
                visit[got] = 1;
                use.push(got);
                cnt++;
                if(color[variable] == 1) {
                    color[got] = 2;
                }
                else {
                    color[got] = 1;
                }

                break;
            }
            if(visit[i] == 1 && i < graph[variable].size() - 1) {
                 if(color[got] == color[variable]) {
                    contradiction = 1;
                    cout<<"hello"<<endl;
                    break;
                }
            }



            if(visit[got] == 1 && i == graph[variable].size() - 1)
            {
                if(color[got] == color[variable]) {
                    contradiction = 1;
                    break;
                }
                use.pop();

            }
        }
        if(contradiction == 1) {
            break;
        }

    }
    return contradiction;

}

int main(void)
{
    int node,edge,i,a,b;
    while(scanf("%d",&node) == 1)
    {
        if(node == 0)
        {
            break;
        }
        scanf("%d",&edge);
        for(i = 1; i <= edge; i++)
        {
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int found = dfs_color_selection(node);
        if(found == 1)
        {
            printf("NOT BICOLORABLE.\n");
        }
        else
        {
            printf("BICOLORABLE.\n");
        }
        for( i = 0; i < node; i++)
        {
            graph[i].clear();
        }

    }
    return 0;

}
