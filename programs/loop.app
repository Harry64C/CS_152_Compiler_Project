# This is a simple loop that counts from 1 to 10

inum main{}[

    inum i;

    i ~ 0;
    until{i lt 10}  [
        i ~ i plus 1;
        output{i};
    ]

]