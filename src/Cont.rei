type t('r, 'a);

let cont: (('a => 'r) => 'r) => t('r, 'a);

let run: (t('r, 'a), 'a => 'r) => 'r;

let make: 'a => t('r, 'a);

let map: ('a => 'b, t('r, 'a)) => t('r, 'b);

let apply: (t('r, 'a => 'b), t('r, 'a)) => t('r, 'b);

let bind: ('a => t('r, 'b), t('r, 'a)) => t('r, 'b);

let callCC: (('a => t('r, 'b)) => t('r, 'a)) => t('r, 'a);

let reset: t('a, 'a) => t('r, 'a);

let shift: (('a => 'r) => t('r, 'r)) => t('r, 'a);

module Operators: {
  let (>>=): (t('r, 'a), 'a => t('r, 'b)) => t('r, 'b);
  let (>=>): ('a => t('r, 'b), 'b => t('r, 'c), 'a) => t('r, 'c);
};