inum funct main{}[
    inum x ~ 100;
    inum y ~ 50;
    inum z;

    #addition of x and y which should be 150 since 100 + 50 = 150
    z ~ x plus y;
    outp{z};

    #subtraction should be 50
    z ~ x minus y;
    outp{z};

    #multiply should be 5000
    z ~ x mult y;
    outp{z};

    #divide should be 2
    z ~ x divi y;
    outp{z};

    # complex equation should be 240
    x ~ 2;
    y ~ 8;
    z ~ (x plus y) mult 24;
    outp{z};

]
