inum funct main{}[

  inum m;
  inum n;
  inum o ~ 3;
  outp{o};

  n ~ 5;
  check{((n gte 100) gte 10) OR (n lte 10)} [
    outp{n};
  ]
    
  then[
    m ~ 10;
    outp{m};
  ]

  outp{o};
  
]
