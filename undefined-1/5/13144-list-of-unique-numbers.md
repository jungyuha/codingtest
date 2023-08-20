# 13144(List of Unique Numbers)

#### **first Registered : 2023-08-20**

#### last modified : **2023-08-20**

#### 자바코드

```java
package codetest;

import java.util.*;
import java.io.*;

public class Main {
	static int n,res=0;
	static int[] lst1;
	static boolean[] lst2;
	static StringTokenizer st ;
	 public static void main(String[] args) throws IOException {
		 BufferedReader in  = new BufferedReader(new InputStreamReader(System.in));
		 n=Integer.parseInt(in.readLine());
		 st=new StringTokenizer(in.readLine());
		 lst1 = new int[n+1];
		 lst2 = new boolean[10];
		 
		 for(int i=0;i<n;i++) {
			 lst1[i]= Integer.parseInt(st.nextToken());
		 }
		 int start = 0,end=1;
		 lst2[lst1[0]]=true;
		 for(start=0;start<n;start++) {	
			 while(!lst2[lst1[end]] && end < n) {lst2[lst1[end]]=true;end++;}
			 if(lst2[lst1[end]]) {
				 res+=(end-start);
				 lst2[lst1[end]]=false;
			 }
			 else {
				 res+=(((end-start)*(end-start+1))/2);
				 break;
			 }
		 }
		 System.out.println(res);
	 }
	 static void print_(int idx) {
		 //System.out.println();
		 if(idx==1) { // lst1
			 for(int i=0;i<n;i++) {
				 System.out.print(lst1[i]+" ");
			 }
		 }
		 if(idx==2) { // lst2
			 for(int i=0;i<10;i++) {
				 int tp=lst2[i]?1:0;
				 System.out.print(tp+" ");
			 }
			 System.out.println();
		 }
	 }
}
/*
5
1 2 3 1 2
*/
```
