type t('r, 'a);

let run: (t('r, 'a), 'a => 'r) => 'r;

let make: 'a => t('r, 'a);

let map: ('a => 'b, t('r, 'a)) => t('r, 'b);

let apply: (t('r, 'a => 'b), t('r, 'a)) => t('r, 'b);

let bind: ('a => t('r, 'b), t('r, 'a)) => t('r, 'b);

module Operators: {let (>>=): (t('r, 'a), 'a => t('r, 'b)) => t('r, 'b);};