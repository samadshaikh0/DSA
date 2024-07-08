int minCoinsRequired(int *coins, int sum, int n){
    int t[n+1][sum+1];
    // initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j == 0)
                t[i][j] = 0;
            if(i == 0)
                t[i][j] = INT_MAX - 1; 
        }
    }

    // this is a unique question in which we have to initialize the second row as well
    for(int j=1; j <= sum; j++){
        if(j % coins[j] == 0)
            t[1][j] =  j/coins[j];
        else
            t[1][j] = INT_MAX - 1;
    }

    // converting choice diagram
    // variation from prev code
    // max() -> min()

    for(int i=2; i<=n; i++){
        for(int j=2; j<=sum; j++){
            t[i][j] = coins[i-1] <= j ? min(t[i][j-coins[i-1]] + 1,t[i-1][j]) : t[i-1][j] ;
        }
    }
    return t[n][sum];
}