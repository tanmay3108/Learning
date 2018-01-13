/**
 * Created by Tanmay on 24-07-2017.
 *Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
 *Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
 *Output:  True  //There is a subset (4, 5) with sum 9.
 *Time Complexity O(2^N)
*/
public class subSetProblem
{
    public static int arr[] = {3,34,4,12,5,2};
    public static int n = arr.length;
    static int count =0;
    public static boolean subSetSumProblem(int k,int sum,int i)
    {
        count++;//Worst Case 2^N+1 (127)
        if(sum == k)
            return true;
        if(i>=n)
            return false;
        return subSetSumProblem(k,sum,i+1)||subSetSumProblem(k,sum+arr[i],i+1);
    }
    public static void main(String args[])
    {
        System.out.println(subSetProblem.subSetSumProblem(9,0,0));
        System.out.println(count);
        count =0;
        System.out.println(subSetProblem.subSetSumProblem(6,0,0));
        System.out.println(count);
        count =0;
        System.out.println(subSetProblem.subSetSumProblem(13,0,0));
        System.out.println(count);
        count =0;
        System.out.println(subSetProblem.subSetSumProblem(29,0,0));
        System.out.println(count);
        count =0;

    }
}
