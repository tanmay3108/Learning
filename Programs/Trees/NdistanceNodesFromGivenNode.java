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
    private int distances(Node head, Node node, int n)
    {
        if(head == null)
        return -1;
        if(head.data == node.data)
        {
            //System.out.println(head.data+" "+0+" ");
            NdistanceNodeFromRoot(node,n);
            System.out.println();
            return 0;
        }
        
        int dl = distances(head.left,node,  n);
        if(dl>=0)
        {
            //System.out.println(head.data+" "+(dl+1)+" ");
            
            if(dl+1 == n)
            System.out.println(head.data);
            else
            NdistanceNodeFromRoot(head.right,(n-(dl+1+1)));    
            
            return dl+1;
        }
        int dr = distances(head.right,node, n);
        if(dr>=0)
        {
            if(dr+1 == n)
            System.out.println(head.data);
            else
            NdistanceNodeFromRoot(head.left,(n-(dr+1+1)));    

            return dr+1;
        }

        return -1;
    }
    
    private void NdistanceNodeFromRoot(Node root, int n)
    {
        if(root == null)
        return;
        if(n == 0)
        {
            System.out.print(root.data);
            System.out.print("::");
        }
        NdistanceNodeFromRoot(root.left,n-1);
        NdistanceNodeFromRoot(root.right,n-1);
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		int n =2;
		Node root = new Node(10);
		root.left = new Node(5);
	    root.right = new Node(20);
		root.left.left = new Node(3);
		root.left.right = new Node(7);
		root.left.left.left = new Node(1);
		root.left.left.right = new Node(2);
		root.left.left.right.left = new Node(0);
		root.left.left.left.left = new Node(-1);
		Codechef obj =new Codechef();
		obj.distances(root, root.left.left, n);
		
		
	}
}
