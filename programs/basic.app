inum funct add{inum a, inum b}[
    return a plus b;

]

inum funct main{}[
    inum x;
    #inum y;
    inum y ~ 1 plus 1 plus 3;
    x ~ 1 plus 4 plus 3 minus 2 mult 8;
    
    y ~ -5;
    arr c(3);
    c(0) ~ 5;
    x ~ -1 plus 2 mult -8;
    c(1) ~ 5 plus 8;
    x ~ c(0);
    x ~ 1 minus 6 plus -2;

    c(0) ~ c(1);
    x ~ 1 plus 4 plus -3 minus 2 mult 8;

    inum z; 
    z ~ add{x, y};

]
