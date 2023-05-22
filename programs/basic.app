inum funct main{}[
    inum x;
    inum y;
    x ~ 15;

    x ~ 1 plus 4 plus 3 minus 2 mult 8;

    outp{x};

    arr a(20);
    a(0) ~ x;
    a(4) ~ 8;

    y ~ a(4);
    #a(0) ~ a(4);

]
