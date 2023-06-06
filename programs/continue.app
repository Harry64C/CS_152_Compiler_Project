inum funct main{}
[
	inum i;
	i ~ 0;
	until{i lte 10}
	[
		outp{i};
		check{i lt 5}
		[
            i ~ i plus 1;
        	go;
		]
        stop;
	]
	outp{i};
]