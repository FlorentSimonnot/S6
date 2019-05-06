(*-Question 1-*)

let rec integers_1 n = 
	if n < 0 then 
		[] 
	else 
		n :: integers_1 (n - 1);;

(*Cette liste est écrite dans le sens inverse voulu. On a les nombres de n à 0.*)

(*-Question 2-*)

let rec integers_2 n = 
	if n < 0 then 
		[] 
	else 
		(integers_2 (n - 1)) @ [n];;

(*C'est beaucoup trop lent pour 100 000 valeurs*)

(*-Question 3-*)

let integers_3 n = 
	List.rev (integers_1 n);;

(*-Question 4-*)

let integers_1' n = 
	let rec aux n acc = 
		if n = 0 then
			[]
		else  
			acc :: (aux (n-1) (acc+1))
	in (aux n 0)
;;