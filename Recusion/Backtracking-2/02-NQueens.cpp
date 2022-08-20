#include <bits/stdc++.h>
using namespace std;

/**
 * Question : we have to place n queesn in n rows such that no one kill other queen 
 * 
 */

//? Normal Solutions
//? branch And Bound

#include<bits/stdc++.h>
using namespace std;

bool isqueensafe(vector<vector<int>> chess, int row ,int col )
{
    
    for(int i=row-1, j=col ; i>=0; i--)
    {
        if(chess[i][j]==1)
        {
            return false;
        }
    }
     for(int i=row-1, j=col-1 ; i>=0 && j>=0; i--,j--)
    {
        if(chess[i][j]==1)
        {
            return false;
        }
    }
    
     for(int i=row-1, j=col+1 ; i>=0 && j<chess.size(); i--,j++)
    {
        if(chess[i][j]==1)
        {
            return false;
        }
    }
    
    return true;
}


void printNQueens(vector<vector<int>> chess, string qsf, int row) {
  //write your code here
  if(row==chess.size()) {
    cout<<qsf<<endl;
    return ;
  }
  
  for(int col=0; col=chess.size(); col++)
  {
        if(isqueensafe(chess,row,col))
        {
            chess[row][col]=1;
            printNQueens(chess,qsf+to_string(row)+"-"+to_string(col)+",",row+1);
            chess[row][col]=0;
        }
  }

}

void printNQueens(vector<vector<int>> chess, int row,vector<bool> col,vector<bool>ndiag,vector<bool> rdiag,string asf) {
    
    if(row==chess.size())
    {
        cout<<asf<<"."<<endl;
        return ;
    }
    for(int i=0; i<chess.size(); i++)
    {
        if(col[i]==false && rdiag[i+row]==false && ndiag[row-i+chess.size()-1]==false)
        {
            chess[row][i]=1;
            col[i]=true;
            rdiag[row+i]=true;
            ndiag[row-i+chess.size()-1]=true;
            printNQueens(chess,row+1,col,ndiag,rdiag,asf+to_string(row)+"-"+to_string(i)+", ");
             chess[row][i]=0;
            col[i]=false;
            rdiag[row+i]=false;
            ndiag[row-i+chess.size()-1]=false;
        }
        
    }
    
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> chess(n, vector<int> (n));
  vector<bool> col(n,false);
  vector<bool> ndiag(2*n-1,false);
  vector<bool> rdiag(2*n-1,false);

  printNQueens(chess, 0, col,ndiag,rdiag,"");

}