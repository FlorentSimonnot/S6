(*Nensy SAM*)

(**********************************************************************)
(***************************** Exercice 1 *****************************)
(**********************************************************************)

(* 1.1. *)
(* val interval : int -> int -> int list = <fun> *)

let interval inf sup = 
	let rec aux n acc =
    	if n < inf then 
    		acc 
    	else 
    		aux (n-1) (n :: acc)
    in aux sup []
;;

interval 0 8;;
interval 2 5;;
interval 3 3;;
interval (-5) 2;;
interval 9 3;;


(* 1.2. *)
(* val string_of_list : 'a list -> ('a -> string) -> string = <fun> *)

let rec string_of_list l f = 
	match l with 
	| [] -> ""
	| x :: reste -> f x ^ (string_of_list reste f)
;;

string_of_list [0; 1; 2] string_of_int;;
string_of_list [] string_of_int;;
string_of_list [true; false; true] string_of_bool;;
string_of_list [2; 0; 101; 0; 0] (fun x -> if x = 0 then "." else "*")

(* 1.3. *)
(* val compose_iter : ('a -> 'a) -> 'a -> int -> 'a list = <fun> *)
let rec compose_iter f a b =
    if b < 0 then
        []
    else
        [a]@(compose_iter f (f a) (b-1))
;;

compose_iter (fun x -> x + 1) 0 5;;
compose_iter (fun x -> -x) 8 6;;
compose_iter (fun u -> u ^ "a") "b" 5;;
compose_iter (fun u -> u) "a" 0;;

(* 1.4. *)
(* val is_prefix_lists : 'a list -> 'a list -> bool = <fun> *)

let rec is_prefix_lists l1 l2 = 
	match l1, l2 with 
	| [], _ -> true
	| _, [] -> false 
	| h1::t1, h2::t2 -> h1 = h2 && is_prefix_lists t1 t2
;;

is_prefix_lists [] [];;
is_prefix_lists [2; 1; 3] [3; 2; 1];; 
is_prefix_lists [2; 1; 3] [2; 1; 3; 2];;

(* 1.5. *)
(* val is_factor_lists : 'a list -> 'a list -> bool = <fun> *)
let rec is_factor_lists l1 l2 =
    match l2 with
    [] -> l1 = []
    | u :: rest -> is_prefix_lists l1 l2 || is_factor_lists l1 rest
;;

is_factor_lists [2; 1; 3] [4; 2; 1; 3; 4];;
is_factor_lists [2; 1; 3] [2; 1; 3; 4];;
is_factor_lists [2; 1; 3] [4; 2; 1; 3];;
is_factor_lists ['a'; 'a'] ['a'; 'b'; 'a'];;
is_factor_lists [] ['a'];;
is_factor_lists [] [];;


(* 1.6. *)
(* val is_subword_lists : 'a list -> 'a list -> bool = <fun> *)
let is_subword_lists l1 l2 =
    let rec aux l1 l2 acc =
        if l1 = [] then
            acc
        else if l2 = [] then
            not acc
        else if (List.hd l1) = (List.hd l2) then
            aux (List.tl l1) l2 acc
        else
            aux l1 (List.tl l2) acc
    in
    aux l1 l2 true
;;

is_subword_lists [1; 3; 5] [1; 2; 3; 4; 5];;
is_subword_lists [1; 5; 3] [1; 2; 3; 4; 5];;
is_subword_lists ['a'; 'b'] ['a'; 'b'; 'c'];;
is_subword_lists ['a'; 'b'] ['a'; 'b'; 'c'];;
is_subword_lists [] [];;


(* 1.7. *)
(* val is_duplicate_free : 'a list -> bool = <fun> *)
let is_duplicate_free list =
    let rec aux list acc =
        if list = [] then
            acc
        else if List.mem (List.hd list) (List.tl list) then
            not acc
        else
            aux (List.tl list) acc
    in
    aux list true
;;

is_duplicate_free [1; 2; 3];;
is_duplicate_free [1; 2; 1];;
is_duplicate_free [1; 2; 1; 1; 2];;
is_duplicate_free [3];;
is_duplicate_free [];;


(**********************************************************************)
(***************************** Exercice 2 *****************************)
(**********************************************************************)

type 'a automaton = {
    ribbon : int -> 'a;
    evol : 'a * 'a * 'a -> 'a;
    void : 'a
}

(* 2.1. *)
(* val create : ('a * 'a * 'a -> 'a) -> 'a -> 'a automaton = <fun> *)

let create evol void = {ribbon = (fun x -> void); evol = evol; void = void;};;
create (fun (a, b, c) -> a + b + c) 0;;

(* 2.2. *)
(* val get_value : 'a automaton -> int -> 'a = <fun> *)

let get_value automaton i = automaton.ribbon i;;

let aut1 = create (fun (a, b, c) -> a + b + c) 0;;
get_value aut1 10;;


(* 2.3. *)
(* val set_value : 'a automaton -> int -> 'a -> 'a automaton = <fun> *)

let set_value automaton i value = {ribbon = (fun x -> if x == i then value else automaton.void); evol = automaton.evol; void = automaton.void};;

let aut1 = create (fun (a, b, c) -> a + b + c) 0;;
let aut2 = set_value aut1 10 1024;;
get_value aut2 10;;

(**********************************************************************)
(***************************** Exercice 3 *****************************)
(**********************************************************************)

type bunch = int * int

(* 3.1. *)
(* val get_bunch_values : 'a automaton -> bunch -> 'a list = <fun> *)
let rec get_bunch_values auto bunch =
    let a, b = bunch in
        if a <= b then
            [get_value auto a]@(get_bunch_values auto (a+1, b))
        else
            []
;;

let aut1 = create (fun (a, b, c) -> a + b + c) 0;;
let aut1 = set_value aut1 3 4;;
let aut1 = set_value aut1 (-1) 2;;
get_bunch_values aut1 (-2, 6);;

(* 3.2. *)
(* val to_string : 'a automaton -> bunch -> ('a -> string) -> string = <fun> *)
let to_string auto bunch f =
    let list = get_bunch_values auto bunch in
        string_of_list list f
;;

to_string aut1 (-2, 6) string_of_int;;
to_string aut1 (-2, 6) (fun x -> if x = 0 then "." else "*");;


(* 3.3. *)
(* val has_factor : 'a automaton -> bunch -> 'a list -> bool = <fun> *)
let has_factor auto bunch l =
    let list = get_bunch_values auto bunch in
        is_factor_lists l list
;;

let aut1 = set_value aut1 5 9;;
has_factor aut1 (1, 8) [4; 0; 9; 0];;
has_factor aut1 (1, 5) [4; 0; 9; 0];;


(* 3.4. *)
(* val has_subword : 'a automaton -> bunch -> 'a list -> bool = <fun> *)
let has_subword auto bunch l =
    let list = get_bunch_values auto bunch in
        is_subword_lists l list
;;

has_subword aut1 (1, 8) [4; 9];;
has_subword aut1 (7, 8) [4; 9];;

(**********************************************************************)
(***************************** Exercice 4 *****************************)
(**********************************************************************)

(* 4.1. *)
(* val shift : 'a automaton -> int -> 'a automaton = <fun> *)
let shift automaton k = {
    ribbon = (fun x -> get_value automaton (x+k));
    evol = automaton.evol;
    void = automaton.void;
}
;;

(* 4.2. *)
(* val mirror : 'a automaton -> 'a automaton = <fun> *)
let miror automaton = {
    ribbon = (fun x -> get_value automaton (-x));
    evol = automaton.evol;
    void = automaton.void;
}
;;

(* 4.3. *)
(* val map : 'a automaton -> ('a -> 'a) -> 'a automaton = <fun> *)
let map automaton f = {
    ribbon = (fun x -> f (get_value automaton (x)));
    evol = automaton.evol;
    void = automaton.void;
};;

(* 4.4. *)
(* val evolution : 'a automaton -> 'a automaton = <fun> *)
let evolution automaton = {
    ribbon = (fun x -> automaton.evol (get_value automaton (x-1), get_value automaton x, get_value automaton (x+1)));
    evol = automaton.evol;
    void = automaton.void;
};;

(* 4.5. *)
(* val evolutions : 'a automaton -> int -> 'a automaton list = <fun> *)
let evolutions automaton n = 
    compose_iter evolution automaton n;; 

(* 4.6. *)
(* val evolutions_bunch : 'a automaton -> bunch -> int -> 'a list list
    = <fun> *)
let evolutions_bunch aut bun n = 
    List.map (fun aut -> get_bunch_values aut bun) (evolutions aut n);;

(* 4.7. *)
(* val is_resurgent : 'a automaton -> bunch -> int -> bool *)
let is_resurgent aut bun n =
    not (is_duplicate_free (evolutions_bunch aut bun n));;

let aut = create (fun (a, b, c) -> a + b) 0;;
let aut = set_value aut 0 1;;
is_resurgent aut (-1, -1) 4;;
is_resurgent aut (-1, 0) 4;;
is_resurgent aut (-1, 1) 4;;

(**********************************************************************)
(***************************** Exercice 5 *****************************)
(**********************************************************************)
(* 5.1. *)
(* val sierpinski : int automaton = {ribbon = <fun>; evol = <fun>; void = 0} *)
let sierpinski = create (fun (a, b, c) -> (a + b + c) mod 2) 0;;
let aut = set_value sierpinski 0 1;; 
print_string (String.concat "\n"
    (List.map
        (fun a -> to_string a (8, 8) string_of_int)
        (evolutions aut 8)
    )
);;

(* 5.2. *)
(* Type wb. *)
type wb = 
    | White
    | Black;;

let chaos = create (fun (a, b, c) -> 
            match a, b, c with
            | (Black, Black, Black) -> White
            | (Black, Black, White) -> White
            | (Black, White, Black) -> White
            | (Black, White, White) -> Black
            | (White, Black, Black) -> Black
            | (White, Black, White) -> Black
            | (White, White, Black) -> Black
            | (White, White, White) -> White
            )
