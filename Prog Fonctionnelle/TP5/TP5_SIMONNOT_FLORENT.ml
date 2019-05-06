open List;;
open Random;;
open String;;
open Char;;

(*EXERCICE 1*)

let sqr x = x * x;; 

let my_list = [3; 12; 3; 40; 6; 4; 6; 0];;

(*
fun f_sum : ('a -> int) -> int -> int -> int
*)

let f_sum op a b = 
	(op a) + (op b);;


let new_f_sum op a = 
	(fun b -> (op b) + (op a));;

let f1 a b = 
	a + b;;

let f2 op = 
	(op 0) + 0;;

let f3 op a = 
	(op 0) + a;;

let f4 op = 
	(fun a -> (op 0) + a) ;; 

let f5 op = 
	(op (fun a -> a + 0 )) + 0;;

let my_list_sqr = List.map sqr my_list;;
let my_list_double = List.map (( * ) 2) my_list;;

(*make_list : int -> (unit -> 'a) -> 'a list *)

let f () = 0;;

let rec make_list n f =
	match n with
		| a when a < 0 -> (failwith "error")
		| 0 -> []
		| 1 -> [f ()]
		| _ -> (f ()) :: make_list (n - 1) f;;

let entiers = [2; 5; 7; 3; 12; 4; 9; 2; 11];;
let animaux = ["Wombat"; "aXolotl"; "pangolin"; "suricate"; "paresseuX"; "quoKKa"; "lemurien"];;

f_sum sqr 2 3;;
f_sum (fun x -> x + 1) 2 3;;

new_f_sum sqr 2;;
(new_f_sum sqr 2) 3;;

make_list 8 f;;

make_list 64 Random.bool;;
make_list 16 (fun () -> Random.int 101);;

(*EXERCICE 2*)

List.map String.length animaux;;
List.map String.uppercase_ascii animaux;; (*Version 4.05*)
List.filter ( fun s -> s = String.lowercase_ascii s) animaux;;
List.filter ( fun s -> String.length s mod 2 = 0) animaux;;

List.combine entiers (List.map (
	fun n -> 
		if n mod 2 = 0 then 
			"pair"
		else "impair" )entiers);;

List.map (fun a -> make_list a (fun () -> a)) entiers;;

List.exists (fun s -> contains_from s 0 's') animaux;;

List.for_all (fun s -> String.length s mod 5 = 2) animaux;;

(*EXERCICE 3*)

let sum l = fold_left (+) 0 l;;

sum entiers;;

let size l = List.length l;;

size entiers;;

let last l = nth l ((size l) - 1);;

last entiers;;

let nb_occ e l = size (List.filter (fun s -> s = e) l);;

nb_occ "suricate" animaux;;
nb_occ 7 entiers;;

let max_list l = hd (sort (fun a b -> if a < b then 1 else 0) l);;

max_list entiers;;

let average l = (float_of_int (fold_left (+) 0 l)) /. (float_of_int (List.length l));;

average entiers;;

(*EXERCICE 4*)

let test = [2; 2; 2; 2; 1];;

let rec my_for_all p l =
	match l with
		| [] -> true
		| e1 :: reste ->
			if p e1 then
				my_for_all p reste
			else
				false;;

my_for_all (fun x -> x mod 2 = 0) test;;

let my_for_all2 p l =
	fold_left (fun x y -> x && y) true (List.map p l);;

my_for_all2 (fun x -> x mod 2 = 0) test;;

let my_for_all2' p l =
	fold_left (fun x y -> x && y) true l;;

my_for_all2' (fun x -> x mod 2 = 0) (List.map (fun x -> x mod 2 = 0) test);;

let my_for_all3 p l =
	fold_right (fun x y -> x && y) (List.map p l) true;;

my_for_all3 (fun x -> x mod 2 = 0) test;;

let my_exists p l =
	fold_left (fun x y -> x || y) false (List.map p l);;

my_exists (fun x -> x mod 2 = 0) test;;

let rec none p l =
	match l with
		| [] -> true
		| [x] -> not (p x)
		| x :: reste -> not (p x) && none p reste;;

none (fun x -> x mod 2 = 0) test;;


let not_all p l =
	fold_left (fun x y -> not x || not y) false (List.map p l);;

not_all (fun x -> x mod 2 = 0) test;;


let rec ordered p l =
	match l with
		| [] -> true
		| [x] -> true
		| x :: y :: reste -> (p x y) && ordered p (y ::reste);;

ordered (<) [1; 2; 3];;
ordered (<) [1; 4; 3];;
ordered (fun x y -> x + y >= 1) [1; 4; -3; 6];;
ordered (fun x y -> x + y >= 1) [1; 4; -5; 6];;


let rec filter2 p l1 l2 =
	match l1, l2 with
		| [], [] -> []
		| _::_, [] -> []
		| [], _::_ -> []
		| [x], [y] when p x y -> [(x, y)]
		| x :: reste, y :: reste2 ->
			if p x y then
				[(x, y)] @ filter2 p reste reste2
			else
				filter2 p reste reste2;;

filter2 (<) [2; 2; 3] [1; 4; 5];;

(*EXERCICE 6*)

type bintree = Empty | Node of int * bintree *  bintree;;
let example_tree = 
		Node(1, 
			Node(2, 
				Node(4, Empty, Empty), 
				Node(5,
					Node(7, Empty, Empty), 
					Node(8, Empty, Empty)
				)
			),
			Node(3, 
				Empty, 
				Node(6, 
					Node(9, 
						Empty, 
						Empty
					), 
					Empty
				)
			)
		);;


let rec map_tree p bintree =
	match bintree with
	 | Empty -> Empty
	 | Node(n, fg, fd) -> Node((p n), (map_tree p fg), (map_tree p fd))
;;

map_tree (fun x -> x * 2) example_tree;;

let rec fold_tree f bintree acc =
	match bintree with
	| Empty -> acc
	| Node(n, fg, fd) -> (f n) (fold_tree f fg acc) (fold_tree f fd acc);;

let bintree_count_internal_nodes t =
	fold_tree (fun n fg fd -> 1 + fg + fd) t 0
;;

bintree_count_internal_nodes example_tree;; 


let bintree_collect_internal_nodes t = 
	fold_tree (fun n fg fd -> [n] @ fg @ fd) t []	
;;

bintree_collect_internal_nodes example_tree;; 
