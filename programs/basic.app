inum funct add{inum a, inum b}[
    return a plus b;
]

inum funct main{}[
    inum x;
    inum y ~ 3;
    x ~ 1 plus 4 plus 3 minus 2 mult 8;

    inum z ~ add{x, y};

    return 0;
]