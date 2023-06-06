inum funct main{}[

    inum i;
    inum j;
    inum z;
    i ~ 0;
    j ~ 0;
    until{j lt 10}  [
        until{i lt 10}  [
            i ~ i plus 1;
        ]
        z ~ z plus i;
        i ~ 0;
        j ~ j plus 1;   
    ]
    #Output should be 100
    outp{z};
]