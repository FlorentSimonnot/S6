
open List;;

exception Empty_list;;

(*-Question 1-*)

let three_or_more l = 
	let rec aux l i = 
		if l = [] then 
			i >= 3 (*Renvoie true si i >= 3 et false sinon*)
		else 
			aux (tl l) (i+1)

	in (aux l 0);;

(*-Question 2-*)

let size l = 
	let rec aux l i = 
		if l = [] then 
			i
		else 
			aux (tl l) (i+1)
	in (aux l 0);;

(*-Question 3-*)

let last l =
    let rec aux l elem =
        if l = [] then
            elem
        else
            (aux (tl l) (hd l))
    in
    if l = [] then
        raise Empty_list
    else
        (aux (tl l) (hd l))
;;

(*-Question 4-*)

let is_increasing l = 
	let rec aux l elem = 
		if (tl l) = [] then 
			elem < (hd l)
		else 
			aux (tl l) (hd l)
	in 
	if l = [] then
		true
	else aux (tl l) (hd l)
;;

(*-Question 5-*)

let even_odd l =
    let rec aux l i =
        if l = [] then
            true
        else if (i mod 2) = 0 then
            if ((hd l) mod 2) = 0 then
                (aux (tl l) (i+1))
            else
                false
        else
            if ((hd l) mod 2) = 1 then
                (aux (tl l) (i+1))
            else
                false
    in
        (aux l 1)
;;

(*-Question 6-*)

let find l e = 
	let rec aux l e = 
		if l = [] then 
			false 
		else if (hd l) = e then 
			true 
		else 
			(aux (tl l) e)
	in (aux l e)
;;

(*-Question 7-*)

let member l e = 
	let rec aux l e = 
		if l = [] then 
			[]
		else if (hd l) = e then 
			l 
		else 
			aux (tl l) e
	in aux l e
;;

(*-Question 8-*)

let member_last l e = 
	let rec aux l e acc_l = 
		if l = [] then 
			acc_l
		else if (hd l) = e then 
			(aux (tl l) e l)
		else 
			(aux (tl l) e acc_l)
	in (aux l e [])
;;

(*-Question 9-*)

let nb_occ l e = 
	let rec aux l e acc = 
		if l = [] then 
			acc
		else if (hd l) = e then 
			(aux (tl l) e (acc+1))
		else 
			(aux (tl l) e (acc))
	in (aux l e 0)
;;

(*-Question 10-*)

let nth l n = 
	let rec aux l acc =
		if l = [] then 
			raise Empty_list
		else if acc = n then 
			(hd l)
		else 
			aux (tl l) (acc+1)
	in (aux l 0)
;;

(*-Question 11-*)

let max_list l = 
	let rec aux l max = 
		if l = [] then 
			max
		else if (hd l) > max then 
			aux (tl l) (hd l)
		else 
			aux (tl l) (max)
	in
	if l = [] then
		raise Empty_list
	else aux l (hd l)
;;

(*-Question 12-*)

let nb_max l =
    let rec aux l elem acc =
        if l = [] then
            acc
        else if elem < (hd l) then
            (aux (tl l) (hd l) 1)
        else if elem = (hd l) then
            (aux (tl l) elem (acc+1))
        else
            (aux (tl l) elem acc)
    in
    if l = [] then
        raise Empty_list
    else
        (aux (tl l) (hd l) 1)
;;

(*-Question 13-*)

let average l = 
	let rec aux l somme effectif = 
		if l = [] then 
			(float_of_int somme) /. (float_of_int effectif)
		else
			aux (tl l) (somme + (hd l)) (effectif + 1)
	in 
	if l = [] then 
		raise Empty_list
	else (aux (tl l) (hd l) 1)
;;

(*-Question 14-*)
let size_in_range a b l =
	let rec aux l acc =
		if l = [] then 
			(acc <= a && acc >= b) || (acc >= a && acc <= b)
        else
            (aux (tl l) (acc+1))
    in (aux l 0)
;;

(*-Question 15-*)
let find_pattern p l =
    let rec aux pp l =
        if pp = [] then
            true
        else if l = [] then
            false
        else
            if (hd l) = (hd pp) then
                (aux (tl pp) (tl l))
            else
                (aux p (tl l))
            
    in (aux p l)
;;
