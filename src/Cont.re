type t('r, 'a) =
  | Cont(('a => 'r) => 'r);

let cont = c => Cont(c);

let run = (Cont(f), k) => f(k);

let make = a => Cont(k => k(a));

let map = (f, c) => Cont(k => run(c, x => k(f(x))));

let apply = (f, c) => Cont(k => run(f, g => run(c, x => k(g(x)))));

let bind = (f, c) => Cont(k => run(c, x => run(f(x), k)));

let callCC = f => Cont(k => run(f(x => Cont(_c => k(x))), k));

module Operators = {
  let (>>=) = (f, c) => bind(c, f);
  let (>=>) = (f, g, x) => f(x) >>= g;
};