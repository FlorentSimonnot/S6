(* Exercice 1 *)

type bintree = 	
	Empty |
	Node of bintree * int * bintree ;;
	

let a1 = (Node(Empty, 7, Empty));;
let a2 = (Node(Empty, 8, Empty));;
let a3 = (Node(Empty, 4, Empty));;
let a4 = (Node(Empty, 9, Empty));;
let a5 = (Node(a1, 5, a2));;
let a6 = (Node(a3, 2, a5));;
let a7 = (Node(a4, 6, Empty));;
let a8 = (Node(Empty, 3, a7));;
let example_tree = (Node(a6, 1, a8));;

(* Exercice 2 *)

let rec bintree_count_nodes tree = 
	match tree with 
		| Empty -> 0
		| Node(fg, _ , fd) -> (1 + bintree_count_nodes fg + bintree_count_nodes fd)
;;


let rec bintree_count_leaves tree = 
	match tree with 
		| Empty -> 0
		| Node(Empty, _, Empty) -> 1
		| Node(fg, _, fd) -> (bintree_count_leaves fg + bintree_count_leaves fd)
;;

		
let rec bintree_count_internal_nodes tree = 
	match tree with 
		| Empty -> 0 
		| Node(Empty, _, Empty) -> 0
		| Node(fg, _, Empty) -> 1 + bintree_count_internal_nodes(fg)
		| Node(Empty, _, fd) -> 1 + bintree_count_internal_nodes(fd)
		| Node(fg, _, fd) -> (bintree_count_internal_nodes(fg) + 1 + bintree_count_internal_nodes(fd))
;;


let rec bintree_count_right tree = 
	match tree with 
		| Empty -> 0 
		| Node(Empty, _, Empty) -> 0 
		| Node(fg, _, Empty) -> bintree_count_right(fg)
		| Node(Empty, _, fd) -> 1 + bintree_count_right(fd)
		| Node(fg, _, fd) -> (bintree_count_right(fg) + 1 + bintree_count_right(fd))
;;


let rec bintree_count_left tree = 
	match tree with 
		| Empty -> 0 
		| Node(Empty, _, Empty) -> 0 
		| Node(fg, _, Empty) -> 1 + bintree_count_left(fg)
		| Node(Empty, _, fd) -> bintree_count_left(fd)
		| Node(fg, _, fd) -> (bintree_count_left(fg) + 1 + bintree_count_left(fd))
;;


(* Exercice 3 *)

let rec bintree_height tree = 
	match tree with 
		| Empty -> 0
		| Node(fg, _, fd) -> 1 + (max (bintree_height fg) (bintree_height fd))
;;


let rec bintree_is_mirror tree1 tree2  = 
	match tree1, tree2 with 
		| Empty, Empty -> true 
		| _, Empty -> false
		| Empty, _ -> false
		| Node(fg1, _, fd1), Node(fg2, _, fd2) -> (bintree_is_mirror fg1 fd2) && (bintree_is_mirror fg2 fd1)
;;

bintree_is_mirror Empty Empty;;
bintree_is_mirror (Node(Empty, 1, Empty)) (Node(Empty, 2, Empty));;
bintree_is_mirror (Node(Empty, 1, Node(Empty, 3, Empty))) (Node(Node(Empty, 4, Empty), 2, Empty));;

let rec bintree_is_symmetric tree = 
	match tree with 
		| Empty-> true 
		| Node(Empty, _, Empty) -> true
		| Node(fg, _, Empty) -> false
		| Node(Empty, _, fd) -> false 
		| Node(fg, _, fd) -> (bintree_is_symmetric fg) && (bintree_is_symmetric fd)
;;

bintree_is_symmetric Empty;;
bintree_is_symmetric (Node(Empty, 1, Empty));;
bintree_is_symmetric (Node(Node(Empty, 2, Empty), 1, Node(Empty, 2, Empty)));;
bintree_is_symmetric (Node(Node(Empty, 2, Empty), 1, Node(Empty, 3, Empty)));;
bintree_is_symmetric (Node(Node(Empty, 2, Empty), 1, Empty));;

(* Exercice 4 *)

let rec bintree_collect_nodes tree = 
	match tree with 
		| Empty-> []
		| Node(fg, n, Empty) -> n :: (bintree_collect_nodes fg)
		| Node(Empty, n, fd) -> n :: (bintree_collect_nodes fd)
		| Node(fg, n, fd) -> n :: (bintree_collect_nodes fg) @ (bintree_collect_nodes fd)
;;

bintree_collect_nodes example_tree;;

let rec bintree_collect_leaves tree = 
	match tree with 
		| Empty-> []
		| Node(Empty, p, Empty) -> [p]
		| Node(fg, p, fd) -> (bintree_collect_leaves fg) @ (bintree_collect_leaves fd)
;;

bintree_collect_leaves example_tree;;

let rec bintree_collect_internal_nodes tree = 
	match tree with 
		| Empty-> []
		| Node(Empty, p, Empty) -> []
		| Node(fg, p, fd) -> p :: (bintree_collect_internal_nodes fg) @ (bintree_collect_internal_nodes fd)
;;

bintree_collect_internal_nodes example_tree;;

let bintree_collect_level tree n = 
	let rec aux tree m acc = 
		match tree with 
		| Empty -> acc
		| Node(fg, p, fd) ->
			if m = n then 
				p :: acc
			else
				acc @ (aux fg (m+1) acc) @ (aux fd (m+1) acc)
	in aux tree 1 []
;;

bintree_collect_level example_tree 1;;
bintree_collect_level example_tree 2;;
bintree_collect_level example_tree 3;;
bintree_collect_level example_tree 4;;
bintree_collect_level example_tree 5;;


let rec bintree_collect_canopy bintree =
	let lst = [] in
		match bintree with
			| Empty -> []
			| Node(Empty, p, Empty) -> [0]
			| Node(fg, p, fd) ->  	lst
									@
									begin 
										match fg with
											| Empty-> []
											| Node(Empty, p, Empty) -> [0]
											| Node(_,_,_) -> (bintree_collect_canopy fg)
									end
									@
									begin 
										match fd with
											| Empty -> []
											| Node(Empty, p, Empty) -> [1]
											| Node(_,_,_) -> (bintree_collect_canopy fd)
									end
;;

bintree_collect_canopy example_tree;;

(* Exercice 5 *)

let rec bintree_pre bintree =
	match bintree with
		| Empty -> []
		| Node(fg, p ,fd) -> p :: (bintree_pre fg) @ (bintree_pre fd)

;;

bintree_pre example_tree;;

let rec bintree_post bintree =
	match bintree with
		| Empty -> []
		| Node(fg, p ,fd) -> (bintree_post fg) @ (bintree_post fd) @ [p]
;;

bintree_post example_tree;;

let rec bintree_in bintree =
	match bintree with
		| Empty -> []
		| Node(fg, p ,fd) -> (bintree_in fg) @ [p] @ (bintree_in fd)
;;

bintree_in example_tree;;

(* Exercice 6 *)
let rec bintree_insert tree value = 
	match tree with
	| Empty -> Node(Empty, value, Empty)
	| Node(fg, x, fd) -> 
		if value < x then Node((bintree_insert fg value), x, fd)
		else Node(fg, x, (bintree_insert fd value))
;;

let rec bintree_search tree value = 
	match tree with 
	| Empty -> false
	| Node(fg, x, fd) when x = value -> true
	| Node(fg, x, fd) -> 
		if value < x then bintree_search fg value
		else bintree_search fd value
;;

bintree_insert Empty 1;;
bintree_insert (bintree_insert Empty 1) 2;;
let bin1 = bintree_insert (bintree_insert (bintree_insert Empty 1) 2) 3;;
let bin2 = bintree_insert (bintree_insert (bintree_insert Empty 1) 2) 0;;

bintree_search;;
bintree_search bin1 3;; 
bintree_search bin1 0;;


(* Exercice 7 *)
let rec bintree_double tree =
	match tree with
		| Empty -> Empty
	 	| Node (fg, e, fd) -> Node (bintree_double fg, e * 2, bintree_double fd);;

bintree_double example_tree;;

let rec bintree_apply tree func =
	match tree with
		| Empty -> Empty
		| Node (fg, e, fd) -> Node (bintree_apply fg func, (func e), bintree_apply fd func);;

bintree_apply example_tree (function x -> x + 1);;

let bintree_double' tree =
	match tree with
	 	| Empty -> Empty
	 	| _ -> bintree_apply tree (fun x -> x * 2);;


bintree_double' example_tree;;

let rec bintree_rotate tree =
	match tree with
		| Empty -> Empty
		| Node (fg, e, fd) -> Node (bintree_rotate fd, e, bintree_rotate fg);;


bintree_rotate example_tree;;

let rec bintree_sum_nodes tree =
	match tree with
		| Empty -> 0
		| Node (Empty, e, Empty) -> e
		| Node (fg, e, fd) -> e + bintree_sum_nodes fg + bintree_sum_nodes fd;;

bintree_sum_nodes example_tree;;

let bintree_sum_subtree tree =
	let rec aux tree acc =
		match tree with
			 	| Empty -> Empty
			 	| Node (Empty, e, Empty) -> tree
			 	| Node (fg, e, fd) -> Node (aux fg (bintree_sum_nodes fg), acc, aux fd (bintree_sum_nodes fd))
	in aux tree (bintree_sum_nodes tree);;

bintree_sum_subtree example_tree;;
