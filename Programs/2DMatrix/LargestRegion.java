/**
 * Created by Tanmay on 10-07-2017.
 * Consider a matrix with rows and columns,
 * where each cell contains either a ‘0’ or a ‘1’ and
 * any cell containing a 1 is called a filled cell.
 * Two cells are said to be connected
 * if they are adjacent to each other horizontally, vertically, or diagonally .
 * If one or more filled cells are also connected, they form a region.
 * find the length of the largest region.
 * Input : M[][5] =
 * { 0 0 1 1 0
     1 0 1 1 0
     0 1 0 0 0
     0 0 0 0 1
 }
     Output : 6
 Ex: in the following example,
 there are 2 regions one with length 1 and the other as 6.
 so largest region : 6
 */
public class LargestRegion
{
    static  int  arr[][] = {
            {0, 0, 1, 1, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1}};
    static int n = 5;
    static int Xmovement[] = {1, -1, 0, 0, 1, -1, 1, -1};
    static int Ymovement[] = {0, 0, -1, 1, 1, 1, -1, -1};
    static int max =0;
    static int count = 0;
    public static boolean isValid(int x, int y)
    {
        if((x>=0 && x<4)&&(y>=0 && y<n))
        {
            if(arr[x][y]==1)
                return true;
        }
        return false;
    }
    public static void largesRegion()
    {
        for(int i =0;i<4;i++)
        {
            for (int j = 0;j<n;j++)
            {
                if(isValid(i,j))
                {

                    dfs(i,j);
                    if(count>max)
                        max = count;
                    count = 0;
                }
            }

        }
    }
    public static void dfs(int x,int y)
    {
        if(!isValid(x,y))
            return;
        else
        {
            arr[x][y]=-1; //Marking visited
            count++;
        }
        for(int i =0;i<=7;i++ )
        {
            dfs(x+Xmovement[i],y+Ymovement[i]);
        }
    }
     public static void main(String args[])
     {
        largesRegion();
        System.out.println(max);
     }

}
