# This is a simple loop that counts from 1 to 10

inum funct main{}[

    inum i;

    i ~ 0;
    until{i lt 10}  [
        inum z ~ 9;
        i ~ i plus 1;
        outp{i};
    ]
    outp{z};
]
