inum funct main{}[

  inum m;
  inum n;
  inum o;

  n ~ 5;
  check{n gte 100} [
    outp{n};
  ]
    
  then[
    m ~ n minus 1;
    outp{m};
  ]

  outp{o};
  
]
