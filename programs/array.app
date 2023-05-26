inum funct main{}[

    arr a(20);
    inum b;
    inum c;

    b ~ 3;
    c ~ 5;
    
    outp{((b plus c) mult 3)};

    a(0) ~ b plus c;
    outp{a(0)};    ## should print out 8

    a(1) ~ 100;
    outp{(a(1))};    ## should print out 100

    a(2) ~ 200;
    outp{a(2)};   ## should print out 200

    a(3) ~ a(0) mult (a(1) plus c);
    outp{a(3)};    ## should print out 840; since 840 = 8 * (100 + 5)
    return 0;
]
