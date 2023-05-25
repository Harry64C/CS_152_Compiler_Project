inum funct add{inum a, inum b}[
    return a plus b;

]

inum funct main{}[
    #inum x;
    #inum y;
    inum y ~ 1 plus 1 plus 3;
    #x ~ 1 plus 4 plus 3 minus 2 mult 8;
    
    y ~ 5;

    arr c(10);
    c(1) ~ 5;
    c(1) ~ 5 plus 8;
    inum x ~ c(1);

    #c(0) ~ c(1);

    #inum z; 
    #z ~ add{a, b};

    #inum j;
    #j ~ 1 plus add{a, b};

    return 0;
]
