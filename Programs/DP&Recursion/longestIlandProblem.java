/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    int r[] = {1,-1,0,0,1,1,-1,-1};
    int c[] = {0,0,1,-1,-1,1,-1,1};
    int row;
    int column;
    static int c1=0;
    static int max = 0;
    public boolean isValid(int i,int j, int T[][])
    {
        if(i>=row || i<0)
        return false;
        if(j>=column || j<0)
        return false;
        if(T[i][j]==0 || T[i][j]==-1)
        return false;
        return true;
    }
    
    public void dfs(int i,int j,int T[][])
    {
        if(!isValid(i,j,T))
        return;
        else
        {
            T[i][j] = -1;
            c1++;
            if(c1>max)
            max=c1;
            for(int ii=0;ii<8;ii++)
            {
                    dfs(i+r[ii],j+c[ii],T);
            }
        }
    
        
    }
    public int findMaxIsland(int T[][])
    {
        int count = 0;
        for (int i =0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if(T[i][j]==0 || T[i][j]==-1)
                continue;
                else
                {
                    count++;
                    c1=0;
                    dfs(i,j,T);
                    
                }
            }
        }
        
        return count;
        
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
	   Codechef obj = new Codechef();
	   obj.row = 5;
	   obj.column = 5;
	   int T[][] = { {1, 1, 0, 0, 0},
                     {0, 1, 0, 0, 1},
                     {1, 0, 0, 1, 1},
                     {1, 0, 0, 0, 0},
                     {1, 0, 1, 0, 1}} ;
                     
        System.out.println(obj.findMaxIsland(T));
	    System.out.println(Codechef.max);
	}
}
