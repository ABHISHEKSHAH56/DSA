#include<bits/stdc++.h>
using namespace std ;


bool isvalidmove(vector<vector<int>> chess,int i, int j,int pos)
{
    for(int row=0; row<9; row++)
    {
        if(chess[row][j]==pos) return false;
    }
    for(int row=0; row<9; row++)
    {
        if(chess[i][row]==pos) return false;
    }
    
    
    int lr=3*(i/3);
    int lc=3*(j/3);
    for(int k=0; k<3; lr++)
    {
        for(int z=0; z<3; z++)
        {
            if(chess[k+lr][z+lc]==pos) return false;
        }
    }
    return true;
}

/**
 * @brief 
    1. You are give a partially filled 9*9 2-D array(arr) which represents an incomplete sudoku state.
    2. You are required to assign the digits from 1 to 9 to the empty cells following some rules.
    Rule 1 -> Digits from 1-9 must occur exactly once in each row.
    Rule 2 -> Digits from 1-9 must occur exactly once in each column.
    Rule 3 -> Digits from 1-9 must occur exactly once in each 3x3 sub-array of the given 2D array.
 * 
 * @param chess 
 * @param i 
 * @param j 
 */

void print(vector<vector<int>> chess,int i, int j){
    if(i==chess.size()) return;
    
    int ni=0;
    int nj=0;
    if(nj==chess[0].size()-1)
    {
        nj=0;
        ni=i+1;
    }else{
        nj=j+1;
        ni=i;
    }
    
    if(chess[i][j]!=0)
    {
        print(chess,i,j);
    }
    else{
        for(int pos=1; pos<9; pos++)
        {
            if(isvalidmove(chess,i,j,pos))
            {
                chess[i][j]=pos;
                print(chess,ni,nj);
                chess[i][j]=0;
            }
        }
    }
}


int main()
{
    vector<vector<int>> sod(9,vector<int> (9,0));
    for(int i=0 ; i<9; i++){
        for(int j=0; j<9; j++)
        {
            cin>>sod[i][j];
        }
    }
    print(sod,0,0);
}