set<long long> calculateFactor(long long n) 
{ 
   // Note that this loop runs till square root 
  set<long long> temp;
  long long l = sqrt(n);
    for (long long i=1; i<=l; i++) 
    { 
        if (n%i == 0) 
        { 
            temp.insert(i);
            temp.insert(n/i);
        }
    } 
    return temp;
} 
