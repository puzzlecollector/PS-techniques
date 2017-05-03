// the recursive version is 
int fib(int n){
  if (n <= 2) return 1; 
  return fib(n-1)+fib(n-2);  
}
// the above code is exponential is time complexity. It is in fact O(2^n) and it can be proved by solving the 
// recurrence relation T(n) = T(n-1)+T(n-2) or by drawing a recursion tree. 

// One way to reduce time complexity is by memoization, or caching values so that we avoid 
// solving already solved suproblems. Below i
int cache[MAXN]; 
int fib(int n){
  if (n <= 2) return 1; 
  int &ret = cache[n]; 
  if (ret != -1) return ret;  
  return ret = fib(n-1)+fib(n-2);  
} 
int solve(int n){
  memset(cache,-1,sizeof(cache));  
  return fib(n);  
}
// Another approach is to use bottom up dynamic programming, where you start from small subproblems, and add up 
// the result of sub problems to obtain the final answer.  
int dp[MAXN];  
int solve(int n){
  dp[1] = dp[2] = 1; 
  for (int i = 3; i <= n; i++){
    dp[i] = dp[i-1]+dp[i-2]; 
  }
  return dp[n]; 
} 
// One thing to note is that although the above algorithms are linear time, the value of fib[n] grows very quickly, 
// and int overflow happens for a relatively small n (maybe when n is around 40~50).  
