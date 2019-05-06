open List;;
exception Empty_list;;

(*Exercice 1*)

let rec integers_1 n = 
	if n < 0 then 
		[] 
	else 
		n :: integers_1 (n - 1) 

let rec integers_2 n =
	if n < 0 then 
		[] 
	else 
		integers_2 (n - 1) @ [n]

(* Renvoie la liste partant de 0 à ..*)

let integers_3 n =
	let rec integers_1 n = 
		if n < 0 then 
			[] 
		else 
			n :: integers_1 (n - 1) 
	in rev (integers_1 n)


let integers_4 n = 
	let rec aux n acc =
		if n < 0 then  
			acc
		else 
			aux (n-1) (n :: acc)
	in aux n []


(*Exercice 2*)

let three_or_more l =
	if l = [] then
		false
	else 
		if tl l = [] then 
			false
		else 
			if tl (tl l) = [] then
				false
			else
				true

let  size l =
	let rec aux l acc =
		if l = [] then
			acc
		else
			aux (tl l) (acc + 1)
	in aux l 0


let last l = 
	if  l = [] then
		raise Empty_list
	else 
		let rec aux l acc =
			if tl l = [] then
				acc
			else
				aux (tl l) (hd (tl l))
		in aux l (hd l)

let rec last_2 l =
	if l = [] then
		raise Empty_list
	else 
		if tl l = [] then
			hd l
		else 
			last_2 (tl l)



let rec is_increasing l =
	if l = [] || tl l = [] then
		true
	else 
		if hd l < hd (tl l) then
			is_increasing (tl l)
		else
			false

let rec even_odd l =
	if l = [] then
		true
	else 
		if hd l mod 2 <> 0 && tl l = [] then
			true
		else
			if hd l mod 2 <> 0 && hd (tl l) mod 2 = 0then
				even_odd (tl (tl l))
			else 
				false
	
	
let rec find e l =
	if l = [] then
		false
	else
		if hd l = e then
			true
		else 
			if tl l = [] then
				false
			else
				find e (tl l)
	

let rec member e l =
	if l = [] then 
		[]
	else
		if hd l = e && tl l = [] then
			[e]
		else 
			if hd l = e && tl l <> [] then
				l
			else
				member e (tl l)
	
	
let nb_occ e l =
	let rec aux e l acc =
		if l = [] || tl l = [] then 
			acc
		else
			if hd l = e then
				aux e (tl l) (acc+1)
			else
				aux e (tl l) (acc)
	in aux e l 0
	

let nth n l =
	let rec aux n l acc =
		if l = [] then
			raise Empty_list
		else 
			if acc = n then
				hd l
			else
				aux n (tl l) (acc+1)
	in aux n l 1
	
	
	
let max_list l =
	let rec aux l acc =
		if tl l = [] && acc > hd l then
			acc
		else
			if tl l = [] && acc < hd l then
				hd l
			else
				if hd l > acc then
					aux (tl l) (hd l)
				else
					aux (tl l) (acc)
	in aux l (hd l)
	
	
let nb_max l =
	let rec aux l acc acc2 =
		if tl l = [] && acc > hd l then
			acc2
		else
			if tl l = [] && acc < hd l then
				1
			else
				if hd l > acc then
					aux (tl l) (hd l) 0
				else
					aux (tl l) (acc) (acc2+1)
	in aux l (hd l)	0
	
	
let average l =
	let rec aux l acc acc2 =
		if tl l = [] then
			(acc +. hd l) /. acc2
		else
			aux (tl l) (acc. +. (hd l)) (acc2+1)
	in aux l 0. 1

let size_in_range a b l =
	let rec aux l acc =
		if l = [] then 
			(acc <= a && acc >= b) || (acc >= a && acc <= b)
        else
            (aux (tl l) (acc+1))
    in (aux l 0)
;;

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


	
(*Exercice 3*)	
	
let list_copy l =
    l @ [];;

Random.init;;
let random_list n max =
    let rec aux l i =
        if i >= n then
            l
        else
            (aux ((Random.int max)::l) (i+1))
    in
        (aux [] 0)
;;

let reverse l =
    let rec aux l acc_l =
        if l = [] then
            acc_l
        else
            (aux (tl l) ((hd l)::acc_l))
    in (aux l [])
;;

let flatten_list l =
    let rec aux l acc_l =
        if l = [] then
            acc_l
        else
            (aux (tl l) (acc_l@(hd l)))
    in
        (aux l [])
;;

let find e l =
    let rec aux e l =
        if l = [] then
            false
        else if (hd l) = e then
            true
        else
            (aux e (tl l))

    in (aux e l)
;;

let without_duplicates l =
    let rec aux l acc_l =
        if l = [] then
            (rev acc_l)
        else if (find (hd l) acc_l) then
            (aux (tl l) acc_l)
        else
            (aux (tl l) ((hd l)::acc_l))
    in (aux l [])
;;

let records l =
    let rec aux l max acc_l =
        if l = [] then
            (rev acc_l)
        else if (hd l) > max then
            (aux (tl l) (hd l) ((hd l)::acc_l))
        else
            (aux (tl l) max acc_l)
    in (aux (tl l) (hd l) [(hd l)])
;;

(*Exercice 4*)

let f_split lst1 = 
	let rec f_split_aux l1 l2 lst2 = 
		if lst2 = [] then
			(rev l1),(rev l2)
		else 
			(f_split_aux ((hd lst2)::l1) ((hd (tl lst2))::l2) (tl(tl lst2)))

	in (f_split_aux [] [] lst1)
;; 

let f_merge l1 l2 =
	let rec f_merge_aux lst l1 l2 =
		if l1 = [] && l2 = [] then
			rev (lst)
		else if l1 = [] && l2 <> [] then
			(f_merge_aux ((hd l2)::lst) l1 (tl l2))
		else if l1 <> [] && l2 = [] then
			(f_merge_aux ((hd l2)::lst) l1 (tl l2))
		else
			if(hd l1) >= (hd l2) then
				(f_merge_aux ((hd l2)::lst) l1 (tl l2))
			else
				(f_merge_aux ((hd l1)::lst) (tl l1) l2)
	in (f_merge_aux [] l1 l2)
;;

let fusion_sort lst =
	let l1, l2 = f_split lst in
		(f_merge (List.sort compare l1) (List.sort compare l2))
;;

let l = [58; 37; 58; 72; 19; 58; 18; 41; 58; 86; 94; 59; 92; 35; 40; 47; 92; 6; 42; 95];;
let l_2 = [58; 37; 58; 72; 19; 58; 18; 41; 58; 86; 94; 59; 92; 35; 40; 47; 92; 6; 42; 95];;
let l1, l2 = f_split l;;
let l1, l2 = (List.sort compare l1), (List.sort compare l2);;
let res = f_merge l1 l2;;
res = [6; 18; 19; 35; 37; 40; 41; 42; 47; 58; 58; 58; 58; 59; 72; 86; 92; 92; 94; 95];;
let res_2 = fusion_sort l_2;;

let q_split lst =
    let rec q_split_aux lst l1 l2 l3 =
        if lst = [] then
            rev(l1),rev(l2),rev(l3)
        else if hd(lst) < hd(l2) then
            (q_split_aux (tl(lst)) (hd(lst)::l1) l2 l3)
        else if hd(lst) = hd(l2) then
            (q_split_aux (tl(lst)) l1 (hd(lst)::l2) l3)
        else
            (q_split_aux (tl(lst)) l1 l2 (hd(lst)::l3))
    in (q_split_aux (tl(lst))[] [hd(lst)] [])
;;

let q_merge l1 l2 l3 =
    let rec q_merge_aux lst l1 l2 l3 =
        if l1 = [] && l3 = [] && l3 = [] then
            rev(lst)
        else if l1 <> [] then
            (q_merge_aux (hd(l1)::lst) (tl(l1)) l2 l3)
        else if l1 = [] && l2 <> [] then
            (q_merge_aux (hd(l2)::lst) l1 (tl(l2)) l3)
        else 
            (q_merge_aux (hd(l3)::lst) l1 l2 (tl(l3)))
    in (q_merge_aux [] l1 l2 l3) 

let quick_sort lst =
    let l1, l2, l3 = q_split lst in
        let l1, l2, l3 = (List.sort compare l1), l2, (List.sort compare l3) in
            q_merge l1 l2 l3
;;

let l = [58; 37; 58; 72; 19; 58; 18; 41; 58; 86; 94; 59; 92; 35; 40; 47; 92; 6; 42; 95];;
let res1, res2, res3 = q_split l;;
quick_sort l = [6; 18; 19; 35; 37; 40; 41; 42; 47; 58; 58; 58; 58; 59; 72; 86; 92; 92; 94; 95];;