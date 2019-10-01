ll totient(ll n){
    ll result = n;
    for (ll p = 2; p * p <= n; p++) { 
        if (n % p == 0) {  
            while (n % p == 0){
                // Divide all the prime factor from n. E.g:- if n=12 and p=2, divide 12/2 = 6 again by 2 = 3.. 
                n /= p;
            } 
            // result = result* (1-(1/p)); If p divdes n then first divide by n and then multiply by (p-1);
            result /= p; 
            result *= (p-1); 
        } 
    }
    if(n>1){
        result /= n;
        result *= (n-1);
    } 
    return result;
}
