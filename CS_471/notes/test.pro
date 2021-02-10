/* Clauses */
assert(woman(jody)).
assert(man(brian)).
assert(married(brian, jody):= woman(jody), man(brian)).


/* Queries */
woman(jody).
man(brian).
married(brian, jody).

