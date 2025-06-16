class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int z=n;
        int c=0;
        while(n>0){
            int x = n%10;
         if (x != 0 && z % x == 0)
            c++;
            n =n/10;
            
        }
        return c;
    }
};