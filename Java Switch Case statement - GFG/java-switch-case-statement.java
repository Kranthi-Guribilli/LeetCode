//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int choice = Integer.parseInt(in.readLine());
            String a[] = in.readLine().trim().split("\\s+");
            List<Double> arr = new ArrayList<Double>();
            for(int i = 0;i < choice;i++)
                arr.add(Double.parseDouble(a[i]));
            
            Solution ob = new Solution();
            if(choice == 1)
                System.out.println(ob.switchCase(choice, arr));
            else
                System.out.println((int)ob.switchCase(choice, arr));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution{
    static double switchCase(int choice, List<Double> arr){
        // code here
        double ans=0;
        switch(choice){
            case 1:
                ans=(3.141592653589793*(arr.get(0))*(arr.get(0)));
                break;
            case 2:
                ans=((arr.get(0))*(arr.get(1)));
        }
        return ans;
    }
}