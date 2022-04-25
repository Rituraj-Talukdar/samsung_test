#include <iostream>
#include<bits/stdc++.h>

int N,M;
int Answer[100],AnswerN;
using namespace std;
vector<int> ans,temp;
void printAns(int v)
{
    ans.push_back(v);
    for(int i=temp.size()-1;i>=0;i--)
    {
        if(temp[i]!=v)
            ans.push_back(temp[i]);
        else
            break;
    }
}
bool isCyclicUtil(vector<vector<int>>&graph,int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
        temp.push_back(v);
        vector<int>::iterator i;
        for(i = graph[v].begin(); i != graph[v].end(); ++i)
        {

            if ( !visited[*i] && isCyclicUtil(graph,*i, visited, recStack))
                return true;
            else if (recStack[*i])
            {
                printAns(*i);
                return true;
            }
        }

    }
    temp.pop_back();
    recStack[v] = false;
    return false;
}

bool isCyclic(vector<vector<int>>&graph,int V)
{
    bool *visited = new bool[V+1];
    bool *recStack = new bool[V+1];
    for(int i = 0; i < V+1; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 1; i <= V; i++)
    {
        if ( !visited[i] && isCyclicUtil(graph,i, visited, recStack))
            return true;
        temp.clear();
    }

    return false;
}
int main()
{
    for(int testcase=1;testcase<=10;testcase++)
    {
        cin>>N>>M;
        vector<vector<int>>graph(N+1);
        int a,b;
        for(int i=0;i<M;i++)
        {
            cout<<i;
            cin>>a>>b;
            graph[a].push_back(b);
        }
        cout<<"#"<<testcase<<" ";
        if(isCyclic(graph,N))
        {
            sort(ans.begin(),ans.end());
            for(int a:ans)
            {
                cout<<a<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
        ans.clear();temp.clear();
    }
    return 0;
}