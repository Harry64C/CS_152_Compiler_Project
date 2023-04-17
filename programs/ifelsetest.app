inum funct main{}[

  inum m;
  inum n;
  inum o;

  n = system.inp{}
  check{n gte 100} [
    outp{n};
  ]
    
  then[
    m ~ n minus 1;
    outp{m};
  ]

outp{o};

]
