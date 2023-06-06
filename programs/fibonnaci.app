inum funct fibonacci {inum k}
[
    inum k1;
    inum k2;
    check{k lte 1}
    [
        return 1;
    ]
    k1 ~ k minus 1;
    k2 ~ k minus 2;
    k1 ~ fibonacci{k1};
    k2 ~ fibonacci{k2};

    return k1 plus k2;
]

inum funct main{}[
    inum n;
    inum fibN;

    n ~ 5;

    fibN ~ fibonacci{n};
    outp{fibN};
]