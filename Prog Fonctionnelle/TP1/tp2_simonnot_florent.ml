(*--- Florent Simonnot - G3 ---*)
(*--------------------EXERCICE 1--------------------*)

let rec fact n = 
	if n <= 1 then 
		1
	else 
		n * fact(n - 1);;


(*--------------------EXERCICE 2--------------------*)

let rec fib n = 
	if n <= 1 then 
		n
	else 
		fib(n - 2) + fib(n - 1);;	


(*--------------------EXERCICE 3--------------------*)

let rec pgcd m n = 
	if m = 0 then 
		n
	else 
		if m > n then 
			pgcd n m
		else 
			pgcd (n mod m) m;;


(*--------------------EXERCICE 4--------------------*)

let rec ackermann m n =
	if m = 0 then 
		n + 1 
	else
		if m >= 1 && n = 0 then 
			ackermann (m - 1) 1
		else 
			ackermann (m - 1) (ackermann m (n - 1));;


(*--------------------EXERCICE 5--------------------*)

let rec binom n k =
	if k = 0 then 
		1
	else 
		if n < k then 
			0
		else 
			binom (n - 1) (k - 1) + binom (n - 1) k;;

let rec verifbinom n k = 
	if binom n k = fact n / (fact k * fact(n-k)) then 
		"true"
	else 
		"false"


(*--------------------EXERCICE 6--------------------*)

let rec is_even n = 
	if n = 0 then 
		true
	else 
		is_odd (n - 1)
and
	is_odd n = 
		if n = 0 then 
			false
		else 
			is_even (n - 1);;


(*--------------------EXERCICE 7--------------------*)

let fact' n = 
	let rec fact2 n accfact =
		if n <= 1 then 
			accfact
		else 
			fact2 (n - 1) n * accfact
	in fact2 n 1;;


(*--------------------EXERCICE 8--------------------*) 

let fib' n = 
	let rec fib2 n f_moins_1 f_moins_2 = 
		if n <= 1 then 
			f_moins_1
		else
			fib2(n - 1) (f_moins_1 + f_moins_2) f_moins_1
	in fib2 n 1 0;;		


(*--------------------EXERCICE 9--------------------*)

let rec syracuse n =
	if n = 1 then 
		0
	else 
		if n mod 2 = 0 then 
			1 + syracuse (n / 2)
		else 
			1 + syracuse (n * 3 + 1);;


(*--------------------EXERCICE 10--------------------*)

(*Question 1*)
let rec exp x n =
	if n = 0 then 
		1
	else 
		x * exp x (n - 1);;

(*Question 2*)
let rec exp' x n =  
	let rec exp2 x n accexp =
		if n = 0 then 
			accexp
		else 
			exp2 x (n - 1) (accexp * x)
	in exp2 x n 1

(*Question 3*)
let rec fast_exp x n = 
	if n = 0 then 
		1 
	else 
		if n mod 2 = 0 then 
			fast_exp x (n / 2) * fast_exp x (n / 2)
		else
			fast_exp x (n / 2) * fast_exp x (n / 2) * x;;

(*Question 4*)

let rec exp'' x n =
	if n = 0 then 
		1,0
	else 
		let a,b = exp'' x (n-1) in (x*a), (b+1);;

(*Question 5*)

let first (x, n) = x;;

let fast_exp' x n =
	let rec aux n acc a =
		if n = 0 then
			1, (a + 1)
		else if n = 1 then
			acc, (a + 1)
		else if (n mod 2) = 0 then
			aux (n / 2) (first (aux (n / 2) (acc * x) (a + 1))) (a + 1)
		else
		aux (n / 2) ((first (aux (n / 2) (acc * x) (a + 1))) * x) (a + 1)
	in aux n x 0;;

(*--------------------EXERCICE 11--------------------*)

(*Question 1*)

let sum1 n m =
    let rec aux1 a sum =
        let rec aux2 b sum =
            if b = m then
                sum + b
            else
                (aux2 (b+1) (sum+b))
        in
            if a > m then
                sum
            else if a = m then
                (aux2 a sum)
            else
                (aux1 (a+1) (aux2 a sum))
    in (aux1 n 0)
;;


let sum2 n =
    let rec aux1 j sum =
        let rec aux2 k sum =
            if k >= j then
                sum
            else
                (aux2 (k+.1.) (sum +. k/.j))
        in
            if j > (float_of_int n) then
                sum
            else
                (aux1 (j+.1.) (aux2 0. sum))
    in (aux1 0. 0.)
;;