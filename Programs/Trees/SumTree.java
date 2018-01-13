/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
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
    
    public int tree2SumTree(Node head)
    {
        
        if(head == null)
        return 0;
        int prev =head.data;
        if(head.left == null && head.right == null)
        {
            head.data = 0;
            return prev;
        }
        
        int a = tree2SumTree(head.left);
        int b = tree2SumTree(head.right);
        head.data = a+b;
        return head.data+prev;
    
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		int n =2;
		Node root = new Node(10);
		root.left = new Node(5);
	    root.right = new Node(20);
	    root.left.left = new Node(3);
		/*
		root.left.right = new Node(7);
		root.left.left.left = new Node(1);
		root.left.left.right = new Node(2);
		root.left.left.right.left = new Node(0);
		root.left.left.left.left = new Node(-1);*/
		Codechef obj =new Codechef();
		obj.tree2SumTree(root);
		System.out.println(root.data);
		System.out.println(root.left.data);
		System.out.println(root.right.data);
		
		
	}
}
