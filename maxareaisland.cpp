using namespace std;
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <vector>


class Solution {
public:

    void dfsutil(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int& islandsize)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        visited[i][j] = true;
        islandsize++;
        
        static int rowNbr[] = {-1, 0, 0, 1}; // only horizontal and vertical neighbours allowed 
        // for diagonal row neigbours - {-1, -1, -1 0, 0, 1, 1, 1};

        static int colNbr[] = {0, -1, 1, 0}; // only horizontal and vertical neighbours allowed
        // for diagonal col neighbours - {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for(int k=0; k<4; k++)
        {
            if( (i+rowNbr[k] < row && i+rowNbr[k] >= 0) &&
               (j+colNbr[k] < col && j+colNbr[k] >= 0) &&
               grid[i+rowNbr[k]][j+colNbr[k]] == 1 &&
               visited[i+rowNbr[k]][j+colNbr[k]] == false)
                dfsutil(grid, i+rowNbr[k], j+colNbr[k], visited, islandsize);
        }
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //int islandcnt=0; // used for matrix island count
        int maxislandsize = 0;
        int islandsize = 0;
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();
        vector<bool> v(col, false);
        vector<vector<bool>> visited(row, v);
        
        for(int i=0; i<row; i++)
           for(int j=0; j<col; j++)
           {
               if(grid[i][j] == 1 && !visited[i][j])
               {
                   dfsutil(grid, i, j, visited, islandsize);
                   if(maxislandsize < islandsize)
                       maxislandsize = islandsize;
                   islandsize = 0;
                   //islandcnt++; // used for island count in matrix
               }
           }
        return maxislandsize;
    }
};
