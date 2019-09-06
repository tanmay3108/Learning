
/*
Array Manuplation
https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
Hackerrank:https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
*/


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class RangeQuery {

    // Complete the arrayManipulation function below.
    static long arrayManipulation(int n, int[][] queries) {

        long arr[] = new long[n];
        long diffArray[] = new long[n+1];
        for(int i = 0; i < n+1; i++){
            if(i == 0){
                diffArray[i] = arr[i];
                continue;
            }
            
            if(i == n){
                diffArray[n] = 0;
                continue;
            }
            

            diffArray[i] = arr[i]-arr[i-1];
        }

        for(int j =0; j< queries.length; j++){

                int l = queries[j][0]-1;
                int r = queries[j][1]-1;
                int value = queries[j][2];
                diffArray[l] = diffArray[l]+value;
                diffArray[r+1] = diffArray[r+1] -value; 
                
        }

        long max = -100;            
        for(int k = 0; k < n; k++){
            if (k == 0) 
                arr[k] = diffArray[k];
                             
            else
                arr[k] = diffArray[k] + arr[k - 1]; 
            if(arr[k]>max)
            max = arr[k];    

        }
                return max;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        int[][] queries = new int[m][3];

        for (int i = 0; i < m; i++) {
            String[] queriesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int queriesItem = Integer.parseInt(queriesRowItems[j]);
                queries[i][j] = queriesItem;
            }
        }

        long result = arrayManipulation(n, queries);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

