inum funct add{inum x, inum y}
[
	return x plus y;
]

inum funct multiply{inum x, inum y}
[
	return x mult y;
]

inum funct main{}
[
	inum w;
	inum x;
	inum y;
	inum z;

	w ~ 100;
	x ~ 50;
	y ~ add{w, x};
	#prints "150", the sum of 100 and 50;

	z ~ multiply{w, y};
	#prints "22500", the result of 150 * 150;
	outp{z};	
]
