Question : https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0


import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
	    Scanner scan = new Scanner(System.in);
	    int t = scan.nextInt();
	    while(t-- > 0)
	    {
	        int r = scan.nextInt(), c = scan.nextInt();
	        int arr[][] = new int[r][c];
	        for(int i=0;i<r;i++)
	        {
	            for(int j=0;j<c;j++)
	            {
	                arr[i][j] = scan.nextInt();
	            }
	        }
    	    int maxSum = -999999;
    	    for(int i=0;i<c;i++)
    	    {
    	        int temp[] = new int[r];
    	        for(int j=i;j<c;j++)
    	        {
    	            int sum = 0;
    	            for(int k = 0;k<r;k++)
    	            {
    	                temp[k] += arr[k][j];
    	                sum += temp[k];
    	                if(maxSum < sum)
    	                {
    	                    maxSum = sum;
    	                }
    	                if(sum < 0)
    	                    sum = 0;
    	            }
    	        }
    	    }
    	    System.out.println(maxSum);
	    }
	}
}
