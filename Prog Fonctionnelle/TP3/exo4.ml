open List;;

(*Exercice 4*)

let f_split lst1 = 
	let rec f_split_aux l1 l2 lst2 = 
		if lst2 = [] then
			(rev l1),(rev l2)
		else 
			(f_split_aux ((hd lst2)::l1) ((hd (tl lst2))::l2) (tl(tl lst2)))
            (*On ajoute la tete de liste dans l1 et la tete de liste sans la première dans l2. On appel
            la fonction avec ces deux premières valeurs en moins.*)

	in (f_split_aux [] [] lst1)
;; 


let f_merge l1 l2 =
	let rec f_merge_aux lst l1 l2 =
		if l1 = [] && l2 = [] then
			rev (lst) (*Comme recursif la liste est construite à l'envers. Donc en renvoit l'inverse*)
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
res_2 = [6; 18; 19; 35; 37; 40; 41; 42; 47; 58; 58; 58; 58; 59; 72; 86; 92; 92; 94; 95];;

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