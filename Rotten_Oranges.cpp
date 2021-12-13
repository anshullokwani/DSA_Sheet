//Question : Rotten Oranges On LeetCode
//Question Link - https://leetcode.com/problems/rotting-oranges






class cell{
    int row, col, _time;
    public:
    cell(int row, int col, int _time)
    {
        this -> row = row;
        this -> col = col;
        this -> _time = _time;
    }
    int getrow()
    {
        return row;
    }
    int getcol()
    {
        return col;
    }
    int getTime()
    {
        return _time;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        //we are using a visited array to keep track of
        //what oranges we rott to avoid infinite loop
        //and to keep original data intact if interviewer
        //allows we can save the space and use grid array itself.
        vector<vector<int>>vis(rowSize, vector<int>(colSize, 0));
        
        
        

        //Storing co-ordinates to easily traverse in all 4 directions 
        int addToXaxis[] = {-1,0,1,0};
        int addToYaxis[] = {0,1,0,-1};
        
        //queue to do BFS with data type Cell
        //Cell(to store row, col, and time when it will be rotten)
        queue<cell>qu;
        
        //traversing to find co-ordinates of initially rotten oranges.
        for(int row = 0; row < rowSize; row++)
        {
            for(int col = 0; col < colSize; col++)
            {
                if(grid[row][col] == 2)
                {
                    //if rotten then push it into Queue
                    //to do multi - Source BFS.
                    cell currCell = cell(row, col, 0);
                    qu.push(currCell);
                    
                }
            }
        }

        //totalTime (max time to rott all oranges {if Possible})
        int totalTime = 0;
        
        //Performing Multi - Source BFS.
        while(!qu.empty())
        {

            //take out a cell from queue.
            cell currCell = qu.front();
            
            //store their values
            int row = currCell.getrow();
            int col = currCell.getcol();
            int _time = currCell.getTime();
            
            //pop out 
            qu.pop();
            
            //if time taken to rot this is more than
            //the totalTime then Update totalTime.
            totalTime = max(totalTime, _time);
            
            //do BFS in all four directions from Currcell.
            for(int directions = 0; directions < 4; directions++)
            {
                
                int nextrow = row + addToXaxis[directions];
                int nextcol = col + addToYaxis[directions];
                
                //if this orange is fresh and valid push it into queue.
                if(nextrow >= 0 && nextrow < rowSize && nextcol >= 0 && nextcol < colSize && grid[nextrow][nextcol] == 1 && vis[nextrow][nextcol] == 0)
                {
                    //rotten it.
                    vis[nextrow][nextcol] = 2;
                    
                    //it will take 1 more second to reach to this cell
                    cell nextCell = cell(nextrow, nextcol, _time + 1);
                    
                    //push this so that it can also do BFS from itself later
                    qu.push(nextCell);
                }
            }
        }
        
        //if there's any orange that is fresh
        //then we're sure that it's impossible to do so
        //so return -1;
        for(int row = 0; row < rowSize; row++)
        {
            for(int col = 0; col < colSize; col++)
            {
                //check if it was fresh and we haven't rotten it.
                if(grid[row][col] == 1 && vis[row][col] == 0)
                    return -1;
            }
        }
        return totalTime;
    }
};