set<int> calculateFactor(int n) 
{ 
    // Note that this loop runs till square root 
  set<int> temp;
  int l = sqrt(n);
    for (int i=1; i<=l; i++) 
    { 
        if (n%i == 0) 
        { 
            temp.insert(i);
            temp.insert(n/i);
        }
    } 
    return temp;
} 
