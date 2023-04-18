inum funct multiply{inum x, inum y}
[
	return x mult y;
]

inum funct main{}
[
	inum x;
	inum favoriteWord;
    inum 1n;
	inum z;
	inum t = 5 % 2;
    # line 10 should be an invalid identifier error
   # line 12 should also cause a symbol error;
	x ~ 3;
    1n ~ 7;
    favoriteWord ~ multiply{x, 1n};
	#prints "150", the sum of 100 and 50;
	outp{c};	
	inum a1_ ~ 2;
    z $ favoriteWord;
	outp{z};
    	
	return 1;
]
