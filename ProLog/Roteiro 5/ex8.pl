s --> foo,bar,wiggle.

foo --> [chu].
foo --> foo,foo.

bar --> mar,zar.
mar --> me,my.
me --> [eu].
my --> [sou].
zar --> blar,car.
blar --> [um].
car --> [trem].
wiggle --> [tchu].
wiggle --> wiggle,wiggle.



/*
O Prolog entende --> como uma lista de diferenca

E a consulta resulta em: 
?- s(X, []).
X = [chu, eu, sou, um, trem, tchu] ;
X = [chu, eu, sou, um, trem, tchu, tchu] ;
X = [chu, eu, sou, um, trem, tchu, tchu, tchu] ;

*/