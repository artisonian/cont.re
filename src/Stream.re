type failK('ans) = unit => 'ans;

type successK('a, 'ans) = ('a, failK('ans)) => 'ans;

type t('a) = {stream: 'ans .(successK('a, 'ans), failK('ans)) => 'ans};

