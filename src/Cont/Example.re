let delay = (ms, x) =>
  Cont.cont(k => Js.Global.setTimeout(() => k(x), ms) |> ignore);

{
  open Cont;
  open Cont.Operators;
  let add = (x, y) => make(x + y);
  let square = x => make(x * x);
  let pythagoras = (x, y) =>
    square(x) >>= (x' => square(y) >>= (y' => add(x', y')));
  run(pythagoras(3, 4), Js.log);
};

{
  open Cont;
  open Cont.Operators;
  let wait = delay(1000) >=> delay(1500) >=> delay(500);
  run(wait("hello"), Js.log);
};

{
  open Cont;
  let foo = x =>
    callCC(k =>
      switch (x * x + 3) {
      | y when y > 20 => k("over twenty")
      | y => make(string_of_int(y - 4))
      }
    );
  for (x in 1 to 10) {
    run(foo(x), Js.log);
  };
};

{
  /* From http://okmij.org/ftp/continuations/ContExample.hs */
  let ex1 =
    Cont.(
      make((+))
      |. apply(make(1))
      |. apply(
           reset @@
           make(( * ))
           |. apply(make(2))
           |. apply(shift @@ (k => make(10 |> k |> k))),
         )
    );
  Js.log(Cont.run(ex1, x => x));
};