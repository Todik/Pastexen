/* Prolog test file */
male(john).
male(peter).

female(vick).
female(christie).

parents(john, peter, christie).
parents(vick, peter, christie).

/* X is a brother of Y */
brother(X, Y) :- male(X), parents(X, F, M), parents(Y, F, M).
