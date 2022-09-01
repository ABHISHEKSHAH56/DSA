#include<bits/stdc++.h>
using namespace std;
// #include<bits/stdc++.h>
// using namespace std;

class Solution {
public:
    bool BFS(int i, int j ,vector<vector<int>>& arr, vector<vector<bool>>visit)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        int count=0; 
        while(!q.empty())
        {
           
            int x=q.size();           
            for(int i=0; i<x; i++)
            {
                auto it=q.front();
                q.pop();
                if(visit[it.first][it.second]) continue;
                visit[i][j]=true;
                if(it.first==0 || it.second==0)
                {
                    count++;
                    if(count==2) return true;
                }
                else if(it.first==arr.size()-1 ||it.second==arr[0].size()-1){
                    count++;
                    if(count==2)  return true;
                }
                else 
                {
                    if( (!arr[it.first+1][it.second]) && (arr[it.first+1][it.second]<=arr[it.first][it.second]))   q.push({it.first+1,it.second});
                    if((!arr[it.first-1][it.second]) && (arr[it.first-1][it.second]<=arr[it.first][it.second]))   q.push({it.first-1,it.second});
                    if((!arr[it.first][it.second+1]) && (arr[it.first][it.second+1]<=arr[it.first][it.second]))   q.push({it.first,it.second+1});
                    if((!arr[it.first][it.second-1]) && (arr[it.first][it.second-1]<=arr[it.first][it.second]))   q.push({it.first,it.second-1});
                }
            }  
            
            
        }
        return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& hei) {
        //bfs
        vector<vector<bool>>visit(hei.size()+1);
        vector<vector<int>>ans;
        for(int i=0; i<hei.size(); i++)
        {
          
            for(int j=0; j<hei[0].size(); j++)
            {
                vector<int>it;
                if(BFS(i,j, hei,visit)){
                    it.push_back(i);
                    it.push_back(j);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};