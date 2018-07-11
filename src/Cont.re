type t('r, 'a) = {cont: ('a => 'r) => 'r};

let cont = c => {cont: c};

let run = ({cont}, k) => cont(k);

let make = x => {cont: k => k(x)};

let map = (f, m) => {cont: k => m.cont(x => x |> f |> k)};

let apply = (f, m) => {cont: k => f.cont(g => m.cont(x => x |> g |> k))};

let bind = (f, m) => {cont: k => m.cont(x => f(x).cont(k))};

let callCC = f => {cont: k => f(x => {cont: _c => k(x)}).cont(k)};

let id = x => x;

let reset = e => {cont: k => k(e.cont(id))};

/* let shift e = {cont = fun k ->
   (e (fun v -> {cont = fun c -> c (k v)})).cont id} */
let shift = (f: ('a => 'r) => t('r, 'r)) : t('r, 'a) => {
  cont: k => f(k).cont(id),
};

module Operators = {
  let (>>=) = (f, c) => bind(c, f);
  let (>=>) = (f, g, x) => f(x) >>= g;
};