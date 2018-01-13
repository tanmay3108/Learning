import java.util.*;
import java.lang.*;
import java.io.*;
/*
Print the printCommonAncestors for the given two nodes. Here we have taken 21 and 24. LCA is 16 hence we are printing the path from root to 16.
*/

class Node
{
    int data;
    Node left;
    Node right;
    public Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
        
    }
}
class Codechef
{
    public int printCommonAncestors(Node head, int a )
    {
        if(head == null)
        return -1;
        
        if(head.data == a)
        {
            System.out.println(head.data);
            return head.data;
        }
        
        int x = printCommonAncestors(head.left,a);
        if(x!=-1)
        {
            if(head.left.data==x || head.right.data == x)
            {
                System.out.println(head.data);
                return head.data;
            }
        }
        
        int y = printCommonAncestors(head.right,a);
        if(y!=-1)
        {
            if(head.left.data==y || head.right.data == y)
            {
                System.out.println(head.data);
                return head.data;
            }
        }
        
        return -1;
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		int n =2;
		Node root = new Node(10);
		root.left = new Node(5);
		root.left.right = new Node(16);
		root.left.right.left = new Node(21);
		root.left.right.right = new Node(24);
		root.left.right.right.left = new Node(26);
		root.left.right.right.right = new Node(40);
		root.left.left = new Node(18);
	    root.right = new Node(12);
	    root.right.left = new Node(15);
	    root.right.right = new Node(20);
	    
		
		Codechef obj =new Codechef();
		obj.printCommonAncestors(root, 16);
		
	}
}
