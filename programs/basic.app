inum funct add{inum x, inum y}
[
	return x plus y;
]

inum funct main{}[
    inum x;
    inum y;
    x ~ 15;

    #x ~ 1 plus 4 plus 3 minus 2 mult 8;

    y ~ add{x, 3};

    return 0;
]
