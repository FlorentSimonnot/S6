open List;;

exception Empty_list;;


(*-Question 1-*)
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


list_copy[1, 2, 3];;
let l = random_list 10 2;;
let l2 = [1; 2; 3; 4; 5; 6; 7; 8; 9];;
reverse l2 = [9; 8; 7; 6; 5; 4; 3; 2; 1];;
flatten_list [[1; 2]; []; [3; 4; 5]; [6]] = [1; 2; 3; 4; 5; 6];;