mys([], [ [] ] ).
mys([X|T],P):- mys(T,PT), amys(X,PT,P).
amys(X,[],[]).
amys(X, [S|ST], [ [X|S], S | PT] ):- amys(X,ST,PT).
