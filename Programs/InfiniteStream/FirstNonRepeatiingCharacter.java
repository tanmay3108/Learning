import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * Created by Tanmay on 01-11-2017.
 */
public class FirstNonRepeatiingCharacter
{
    public static List li = new LinkedList<Character>();
    public static Map hm = new<Character,Integer>HashMap();


    public static char getFirstNonRepeatingCharacter(Character ch)
    {
         if(hm.containsKey(ch))
         {
             int count = (int)hm.get(ch);
             count++;
             hm.put(ch,count);
             li.remove(ch);
         }
         else
         {
             hm.put(ch,1);
             li.add(ch);
         }

        if(li.size() != 0)
        return (char)li.get(0);
         else
             return '1';
    }
    public static void main(String args[])
    {
        String str = "AABBCDDEFA";
        for (int i =0;i<str.length();i++)
        {
            Character ch = str.charAt(i);
            char c = FirstNonRepeatiingCharacter.getFirstNonRepeatingCharacter(ch);
            System.out.println(c);
        }
    }
}
