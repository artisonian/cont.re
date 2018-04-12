{
  open Cont.Operators;
  let add = (x, y) => Cont.make(x + y);
  let square = x => Cont.make(x * x);
  let pythagoras = (x, y) =>
    square(x) >>= (x' => square(y) >>= (y' => add(x', y')));
  Cont.run(pythagoras(3, 4), Js.log);
};