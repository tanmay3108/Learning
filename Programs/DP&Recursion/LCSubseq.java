/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;


class Codechef
{
    int n1;
    int m1;
    public int valid(int T[][],int i, int j)
    {
        if((i<0 || i>n1)||(j<0 || j>m1))
        {
            return 0;
        }
        return T[i][j];
    }
    public int lcs(String s1, String s2)
    {
        int n = s1.length();
        int m = s2.length();
        int T[][] = new int[n][m];
        
        for (int i=0; i<n; i++ )
        {
           for (int j=0; j<m; j++ )
           {
               if(s1.charAt(i) == s2.charAt(j))
               {
                     T[i][j] = 1+valid(T,i-1,j-1);    
                   
               }
               else
               {
                   T[i][j] = Math.max(valid(T,i,j-1),valid(T,i-1,j));
               }
           }
        }
        return T[n-1][m-1];
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		String s1 = "abcdgh";
        String s2 = "aedfhr";
        Codechef c = new Codechef();
        c.n1 = s1.length()-1;
        c.m1 = s1.length()-1;
        System.out.println(c.lcs(s1,s2));
    
	}
}
