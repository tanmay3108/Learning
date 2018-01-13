/**
 * Created by Tanmay on 15-07-2017.
 */
public class FlippingSingleZeroToGetMax
{
    static int arr[] = {1,1,1,0,0,1,1,1,0,1,1,1};
    public static int getMaxSeq()
    {
        int cwSize =0;
        int nI = 0;
        int max =-1;
        int i=0;
        int n =arr.length;
        int start =0;
        int end =0;
        System.out.println(n);
        while(i<n)
        {
            if(cwSize == 0)
            {
                start =i;
            }
            if(arr[i]==1)
            {
                cwSize++;
                i++;
                if(cwSize>max)
                    max = cwSize;
                continue;
            }
            if(arr[i]==0)
            {
                if(nI == 0)
                {
                    cwSize++;
                    if(cwSize>max)
                        max = cwSize;
                    nI++;
                    i++;
                    continue;
                }
                else
                {
                    if(cwSize>max)
                        max = cwSize;
                    nI=0;
                    cwSize =0;

                    if(arr[start]==0)
                        i=start+1;


                }
            }
        }
        return max;
    }
    public static void main(String args[])
    {
        System.out.println("hi");
        System.out.println(getMaxSeq());
        System.out.println("hi");
    }

}
