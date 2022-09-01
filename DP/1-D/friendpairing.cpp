//friend pairing 

/*******
 *  12 -
 *      1-2
 *      12
 * 123-
 *      1-2-3
 *      1-23
 *      12-3
 *      13-2
 * ************
 * dp[i]=dp[i-1]+dp[i-2]*(i-1)
 * n --have two options 
 *      1. kisi ke saat ne jaaye 1-fun(n-1)
 *      2. or kisi ke saat pair kar le khud ko chor ke --fun(n-2)*(n-1)
 * **************/