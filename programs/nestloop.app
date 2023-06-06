inum funct main{}[

    inum i;
    inum j;

    i ~ 0;
    until{i lt 2}  [
        j ~ 1;
        until{j lte 3}  [
            outp{j};
            j ~ j plus 1;
        ]
        i ~ i plus 1;
    ]
]