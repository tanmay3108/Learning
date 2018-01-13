/**
 * Created by Tanmay on 09-07-2017.
 * Printing Next greater elemnt towards right
 * HINT--Traverse the array from right to left
 */
public class NextGreaterElement
{
    //static int  arr[] = {98, 23, 54, 12, 20, 7, 27};
    //static int  arr[] = {13, 7, 6, 12};
    static int  arr[] = {4, 5, 2, 25};

    public static void nge(int n)
    {
        System.out.println(-1);
        int lastElm = -1;
        while (n>=1)
        {
            if(arr[n]>arr[n-1])
            {
                System.out.println(arr[n]);
                lastElm = arr[n];
                n--;
                continue;
            }
            if(arr[n]<=arr[n-1])
            {
                if(arr[n-1]>lastElm)
                {
                    System.out.println(-1);
                    lastElm = -1;
                }

                else
                    System.out.println(lastElm);
                n--;
                continue;
            }
        }
    }

    public static void main(String args[])
    {
        int n = arr.length;
        nge(n-1);
    }

}
