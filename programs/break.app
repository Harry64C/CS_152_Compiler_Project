#main has a (while) loop with a break statement;

noreturn function main{}
[
	inum i;
	i ~ 0;
	until{i lte 10}
	[
		outp{i};
		check{i gt 3}
		[
			stop;
		]
		i ~ i plus i;
	]
]