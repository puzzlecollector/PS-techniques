/*
prime factorization algorithm 
using C++ std::map 
runs in time complexity O(sqrt(n)) 
*/ 
map<int,int> primeFact(int n){
  map<int,int> res; 
  for (int i = 2; i*i<=n; i++){
    while (n%i == 0){
      ++res[i]; 
      n /= i; 
    }
  } 
  if (n != 1) res[n] = 1; 
  return res; 
}
