inum funct add{inum x, inum y}
[
    inum z ~ 7;
	return x plus y;
]

inum funct main{}[
    inum x ~ 1;
    inum y ~ 2;
    inum sum;
    sum ~ add{x, y};
    outp{z};
]
