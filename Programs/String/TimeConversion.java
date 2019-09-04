/*
Given a time in -hour AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.

Function Description

Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

timeConversion has the following parameter(s):

s: a string representing time in  hour format

Link: https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true
*/


import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class TimeConversion {

    /*
     * Complete the timeConversion function below.
     */
    static String timeConversion(String s) {
        
        String hours = s.substring(0, s.indexOf(":"));
        int hoursInt =  Integer.parseInt(hours);

        if(s.endsWith("AM") && hoursInt == 12 )
        return "00" + s.substring(s.indexOf(":"), s.length()- "AM".length());
        if(s.endsWith("AM") && hoursInt != 12 )
        return(s.substring(0, s.length()- "AM".length()));
                
        if(s.endsWith("PM") && hoursInt == 12 )
        return(s.substring(0, s.length()- "PM".length()));
        else
        return hoursInt+12 + s.substring(s.indexOf(":"), s.length()- "PM".length());

    }

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scan.nextLine();

        String result = timeConversion(s);

        bw.write(result);
        bw.newLine();

        bw.close();
    }
}
