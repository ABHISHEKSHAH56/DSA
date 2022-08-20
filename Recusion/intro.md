**Recursion** 
there is 2 approch 
1. High level thinking 
	* expectations 
	* faith 
	* expectations +faith 

## List of questions
1. Permutation - 1
	 1. You are give a number of boxes (nboxes) and number of non-identical items (ritems).  
	2. You are required to place the items in those boxes and print all such configurations possible.

**General concept** 

> For selections(combinations)  we use nCr and for arrangment (permutations)  we use nPr 
> n!/(r!)(n-r)! and n!/(n-r)!

Solutions 
**1.  Level pe items and options me boxes** 
	

       void fun(vector<int>arr,int ci, int nb){
       if(ci>nb){
	       for(int i=0; i<arr.size(); i++){
		       cout<<arr[i]<<" ";
	       }
	       cout<<endl;
	       return ;
       }
	       for(int i=0; i<arr.size(); i++){
		       arr[i]=ci;
		       fun(arr,ci+1,nb);
		       arr[i]=0;
	       }
       }


2. Permutations -2
	1. You are give a number of boxes (nboxes) and number of non-identical items (ritems).  
	2. You are required to place the items in those boxes and print all such configurations possible.
		

**Solutions**

    void fun(int cb, int tb, int items[]), int ssf ,int ts ,string asf){
    if(cb>tb){
	    if(ssf==ts){
		    cout<<asf<<endl;
	    }
	    return ;
	 }
	 for(int i=0; i<ts; i++){
		 if(items[i]==0){
			 items[i]=1;
			 fun(cb+1,tb,items,ssf+1,ts,asf+(i+1));
		 }
		 fun(cb+1,tb,items,ssf,ts,asf);		 
	  }
    }
  
  3.  Cobinations-1
	  1. You are give a number of boxes (nboxes) and number of identical items (ritems).  
		2. You are required to place the items in those boxes and print all such configurations possible

**Level pe boxes hai ..options yeah hai ki lega ki nhi lega**
	
**Solutions** 

    void fun(int cb , int tb , int ssf ,int ts, string asf )
    {
	    if(cb>tb){
		    if(ssf==ts){
			    cout<<asf<<endl;
		    }
		    return ;
	    }
	    fun(cb+1,tb,ssf,ts,asf+"_");
	    fun(cb+1,tb,ssf+1,ts,asf+"i");
    }
    
 4.  Cobinations-2
	  1. You are give a number of boxes (nboxes) and number of identical items (ritems).  
		2. You are required to place the items in those boxes and print all such configurations possible
	
**Solutions** 

    void fun(vector<bool>arr,int ci, int ti, int lb)
    { 
	    if(ci>nb){ 
		    for(int i=0; i<arr.size(); i++)
			{ 
				if(arr[i]) cout<<arr[i];
				else cout<<<"_";
			 }
			  cout<<endl;
		 return ;
	 } 
	 for(int i=lb+1; i<arr.size(); i++){ 
		 if(!arr[i]){
			 arr[i]=true; 
			 fun(arr,ci+1,ti, i); 
			 arr[i]=false; 
		 }
		}
	 }
    
