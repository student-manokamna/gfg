//User function template for C++
class Solution{
public:
    bool isequal(  unordered_map<char,int> &m1,
	     unordered_map<char,int>&m2) {
        return m1==m2;
    }

	int search(string pat, string txt) {
	    unordered_map<char,int>pathstore;
	     unordered_map<char,int>currstore;
	     
	   //   find freq of path vali
	   for(auto c: pat){
	       pathstore[c]++;
	   }
	   int i=0;
	   int j=0;
	   int count=0;
	   int k= pat.size();
	   int n = txt.size();
	   while(j<n){
	       // curresntstore k ander store kro esko value ko 
	       currstore[txt[j]]++;  // like f add ho gya
	       // if size is 3 equalto path size then 
	       
	       if(j-i+1==k){
	           if(isequal(pathstore, currstore))
	           count++;
	           
	           // add ho hya na aab winfow age lker jani hh but usse phlephla i vala elem ki freq 
	           // hta do and vo elem bhi form currstore
	           currstore[txt[i]]--;
	           if(currstore[txt[i]]==0){
	               currstore.erase(txt[i]);
	           }
	           i++;
	           
	       }
	       j++; // ye toh her baar aage jayega 
	       
	   }
	   return count;
	}
};