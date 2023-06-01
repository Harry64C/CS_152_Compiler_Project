inum funct main{}[

  inum a;
  inum b;
  inum c;
  a ~ 100;
  b ~ 50;

  check{a lt b} [
    c ~ b;
  ]
    
  #or{a gt b}[
  #  c ~ a;
  #]
  
  then[
    c ~ a;
  ]

  outp{c}; # This should print out 100
]
