(*Florent SIMONNOT G3*)

(*-------------EXERCICE 1----------------*)
type bintree = 
	Empty | Node of bintree * int * bintree
;;

let arbre = Node(
				Node(
					Node(
						Empty, 
						4, 
						Empty
					), 
					2,
					Node(
						Node(Empty, 7, Empty) , 
						5, 
						Node(Empty, 8, Empty)
					)
				), 
				1,  
				Node(
					Empty,
					3,
					Node(
						Node(Empty, 9, Empty), 
						6, 
						Empty
					)
				)
			)
;;

(*------------EXERCICE 2-----------------*)
let rec bintree_count_nodes tree = 
	match tree with 
		| Empty -> 0
		| Node (g, _, d) ->  (1 + (bintree_count_nodes g) + (bintree_count_nodes d))
;;

let rec bintree_count_leaves tree = 
	match tree with 
		| Empty -> 0
		| Node (Empty, _, Empty) -> 1
		| Node (g, _, d) ->  bintree_count_leaves g + bintree_count_leaves d
;;

let rec bintree_count_internal_nodes tree = 
	match tree with 
		| Empty -> 0
		| Node (Empty, _, Empty) -> 0
		| Node (g, _, Empty) -> 1 + bintree_count_internal_nodes g
		| Node (Empty, _, d) -> 1 + bintree_count_internal_nodes d
		| Node (g, _, d) -> 1 + bintree_count_internal_nodes g + bintree_count_internal_nodes d
;;

let rec bintree_count_right tree = 
	match tree with 
		| Empty -> 0
		| Node (Empty, _, Empty) -> 0
		| Node (g, _, Empty) -> bintree_count_right g
		| Node (Empty, _, d) -> 1 + bintree_count_right d
		| Node (g, _, d) -> 1 + bintree_count_right g + bintree_count_right d
;;

let rec bintree_count_left tree = 
	match tree with 
		| Empty -> 0
		| Node (Empty, _, Empty) -> 0
		| Node (g, _, Empty) -> 1 + bintree_count_left g
		| Node (Empty, _, d) -> bintree_count_left d
		| Node (g, _, d) -> 1 + bintree_count_left g + bintree_count_left d
;;

(*---------------EXERCICE 3----------------*)
let rec bintree_height tree = 
	match tree with 
	| Empty -> 0
	| Node (g, _, d) -> 1 + (max (bintree_height g) (bintree_height d))
;;

let rec bintree_is_mirror tree tree2 = 
	match tree, tree2 with 
	| (Empty, Empty) -> true
	| Empty, _ -> false
	| _, Empty -> false
	| Node(fg1, _, fd1), Node(fg2, _, fd2) -> (bintree_is_mirror fg1 fd2) && (bintree_is_mirror fg2 fd1)
;;

let rec bintree_is_symmetric tree = 
	match tree with 
	| Empty -> true 
	| Node(Empty, _, Empty) -> true
	| Node(Empty, _, fd) -> false 
	| Node(fg, _, Empty) -> false
	| Node(fg, _ , fd) -> (bintree_is_symmetric fg) && (bintree_is_symmetric fd)
;;

(*-----------------Exercice 4-----------------*)
let rec bintree_collect_nodes tree =
	match tree with
		| (Empty) -> []
		| (Node (g, e, d)) -> e :: bintree_collect_nodes g @ bintree_collect_nodes d;;

let rec bintree_collect_leaves tree =
	match tree with
		| Empty -> []
		| Node (Empty, e, Empty) -> [e]
		| Node (g, _, d) -> bintree_collect_leaves g @ bintree_collect_leaves d;;

let rec bintree_collect_internal_nodes tree =
	match tree with
		| Empty -> []
		| Node (Empty, _, Empty) -> []
		| Node (g, e, d) -> e :: bintree_collect_internal_nodes g @ bintree_collect_internal_nodes d;;


let rec bintree_collect_level tree level =
	match tree, level with
		| Empty, _ -> []
		| Node (_, e, _), 1 -> [e]
		| Node (g, e, d), _ -> bintree_collect_level g (level - 1) @ bintree_collect_level d (level - 1);;

let rec bintree_collect_canopy tree =
	match tree with
		| Empty -> []
		| Node (Empty, _, Empty) -> []
		| Node (Node (Empty, _, Empty), _, Node (Empty, _, Empty)) -> [0; 1]
		| Node (g, _, Node (Empty, _, Empty)) -> bintree_collect_canopy g @ [1]
		| Node (Node (Empty, _, Empty), _, d) -> 0 :: bintree_collect_canopy d
		| Node (g, _, d) -> bintree_collect_canopy g @ bintree_collect_canopy d;;

(*---------------EXERCICE 5---------------*)
let rec bintree_pre tree =
	match tree with
		| Empty -> []
		| Node (g, e, d) -> e :: bintree_pre g @ bintree_pre d;;

let rec bintree_post tree =
	match tree with
		| Empty -> []
		| Node (g, e, d) -> bintree_post g @ bintree_post d @ [e];;

let rec bintree_in tree =
	match tree with
		| Empty -> []
		| Node (g, e, d) -> bintree_in g @ [e] @ bintree_in d;;

(*---------------EXERCICE 6---------------*)
let rec bintree_insert tree value = 
	match tree with
	| Empty -> Node(Empty, value, Empty)
	| Node(l, x, r) -> 
		if value < x then Node((bintree_insert l value), x, r)
		else Node(l, x, (bintree_insert r value))
;;

let rec bintree_search tree value = 
	match tree with 
	| Empty -> false
	| Node(l, x, r) when x = value -> true
	| Node(l, x, r) -> 
		if value < x then bintree_search l value
		else bintree_search r value
;;

(*--------------EXERCICE 7----------------*)
let rec bintree_double tree =
	match tree with
		| Empty -> Empty
	 	| Node (g, e, d) -> Node (bintree_double g, e * 2, bintree_double d);;

let rec bintree_apply tree func =
	match tree with
		| Empty -> Empty
		| Node (g, e, d) -> Node (bintree_apply g func, (func e), bintree_apply d func);;

let bintree_double' tree =
	match tree with
	 	| Empty -> Empty
	 	| _ -> bintree_apply tree (fun x -> x * 2);;

let rec bintree_rotate tree =
	match tree with
		| Empty -> Empty
		| Node (g, e, d) -> Node (bintree_rotate d, e, bintree_rotate g);;

let rec bintree_sum_nodes tree =
	match tree with
		| Empty -> 0
		| Node (Empty, e, Empty) -> e
		| Node (g, e, d) -> e + bintree_sum_nodes g + bintree_sum_nodes d;;

let bintree_sum_subtree tree =
	let rec aux tree acc =
		match tree with
			 	| Empty -> Empty
			 	| Node (Empty, e, Empty) -> tree
			 	| Node (g, e, d) -> Node (aux g (bintree_sum_nodes g), acc, aux d (bintree_sum_nodes d))
	in aux tree (bintree_sum_nodes tree);;


(*------------------TEST----------------------*)
print_string "\n\nCompter les noeuds, feuilles, la hauteur...\n\n";;
let res = bintree_count_nodes arbre;;
let res2 = bintree_count_leaves arbre;;
let res3 = bintree_count_internal_nodes arbre;;
let res4 = bintree_count_right arbre;;
let res5 = bintree_count_left arbre;;
let res6 = bintree_height arbre;;

print_string "\n\nQuelques propriétés...\n\n";;

bintree_is_mirror (Node(Empty, 1, Empty)) (Node(Empty, 2, Empty));;
bintree_is_mirror (Node(Empty, 1, Node(Empty, 3, Empty))) (Node(Node(Empty, 4, Empty), 2, Empty));;

bintree_is_symmetric Empty;;
bintree_is_symmetric (Node(Empty, 1, Empty));;
bintree_is_symmetric (Node(Node(Empty, 2, Empty), 1, Empty));;

print_string "\n\nCollection \n\n";;

bintree_collect_nodes arbre;;
bintree_collect_leaves arbre;;
bintree_collect_internal_nodes arbre;;

print_string "\n\nParcours\n\n";;

bintree_pre arbre;;
bintree_post arbre;;
bintree_in arbre;;

print_string "\n\nArbre de recherche\n\n";;

bintree_insert Empty 1;;
bintree_insert (bintree_insert Empty 1) 2;;
let bin1 = bintree_insert (bintree_insert (bintree_insert Empty 1) 2) 3;;
let bin2 = bintree_insert (bintree_insert (bintree_insert Empty 1) 2) 0;;

bintree_search;;
bintree_search bin1 3;; 
bintree_search bin1 0;;

print_string "\n\nSomme, Rotation et application de fonction\n\n";;

bintree_double arbre;;
bintree_apply arbre (function x -> x+1);;
bintree_rotate arbre;;
bintree_sum_subtree arbre;;