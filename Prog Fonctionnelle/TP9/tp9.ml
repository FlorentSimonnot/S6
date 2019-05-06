open List;; 

(* point type definition *)
type point = float * float;;

(* Question 1 *)
(* float -> float -> point *)
(* make_point *)
let make_point a b : point = (a, b);;
let p1 = make_point 5. 2.5;;
let p2 = make_point 1. (-1.);;


(* Question 2 *)
(* point -> float *)
(* point_x *) 
let point_x ((x, y) : point) = x;;
point_x p1;;
point_x p2;;

(* point -> float *) 
(* point_y *)  
let point_y ((x, y) : point) = y;;
point_y p1;; 
point_y p2;;

(* Question 3 *)
(* point -> point -> bool *) 
(* point_domination *)  
let point_domination ((x1, y1) : point) ((x2, y2) : point) = 
	x1 >= x2 && y1 >= y2;;

let p1 = make_point 0. 0.
and p2 = make_point 0. 1. 
and p3 = make_point 1. 1.
;;

point_domination p1 p1, point_domination p1 p2, point_domination p1 p3;;


(* -------------------------------------------------------------------------- *)

(* rectangle type definition *)
type rectangle = point * point;;


(* Question 4 *)
(* point -> point -> rectangle *) 
(* make_rectangle *)  
let make_rectangle (p1 : point) (p2 : point) = 
	(p1, p2)
;;

let p1 = make_point 0. 0. and p2 = make_point 1. 2.;;
let rect = make_rectangle p1 p2;;

(* Question 5 *)
(* rectangle -> point *) 
(* rectangle_lower_left *) 
let rectangle_lower_left (rect : rectangle) = 
	fst rect
;;

rectangle_lower_left rect;;

(* rectangle -> point *)
(* rectangle_upper_right *)  
let rectangle_upper_right (rect : rectangle) = 
	snd rect
;;

rectangle_upper_right rect;;

(* Question 6 *)
(* rectangle -> float *) 
(* rectangle_width *)  
let rectangle_width (rect : rectangle) = 
	(fst (snd rect)) -. (fst (fst rect))
;;

(* rectangle -> float *) 
(* rectangle_height *)  
let rectangle_height (rect : rectangle) = 
	(snd (snd rect)) -. (snd (fst rect))
;;

let r = make_rectangle (make_point 0. 0.) (make_point 1. 2.);;
rectangle_width r = 1.;; 
rectangle_height r = 2.;;
(* Question 7 *)
(* rectangle -> point -> bool *) 
(* rectangle_contains_point *)  
let rectangle_contains_point (rect : rectangle) ((x, y) : point) = 
	x >= fst(fst rect) && x <= (fst(snd rect))
	&& y >= snd(fst rect) && y <= (snd(snd rect))
;;

let r = make_rectangle (make_point 0. 0.) (make_point 1. 1.);; 
let p1 = make_point 0. 0.
and p2 = make_point 0.5 0.5
and p3 = make_point 0.5 1.5;; 

rectangle_contains_point r p1;; 
rectangle_contains_point r p2;; 
rectangle_contains_point r p3;; 

(* Question 8 *)
(* rectangle -> point list -> point list *) 
(* rectangle_contains_points *)  
let rectangle_contains_points (rect : rectangle) liste = 
	filter (fun x -> rectangle_contains_point rect x) liste
;;

rectangle_contains_points r [p1; p2; p3];;
(* -------------------------------------------------------------------------- *)

(* quadtree type definition *)
type quadtree = | Leaf of point list * rectangle
                | Node of quadtree * quadtree * quadtree * quadtree * rectangle;;


(* Question 9 *)
(* rectangle -> rectangle * rectangle * rectangle * rectangle  *)
(* rectangle_split_four *)
let rectangle_split_four ((p1, p2): rectangle) =  
	let x1, y1, x2, y2 = fst p1, snd p1, fst p2, snd p2 in
		let cx, cy = ((x2+.x1)/.2., (y2+.y1)/.2.) in 
			(((x1, cy), cx, y1), ((cx, cy), (x2, y2)), ((x1, y1), (cx, cy)), ((cx, y1), (x2, cy)))
;;

let r = make_rectangle (make_point 0. 0.) (make_point 1. 2.);;
rectangle_split_four r;;

(* Question 10 *)
(* ’a list -> ’a *)
(* smallest *)
let smallest liste = 
	fold_left (fun x a -> if compare x a < 0 then x else a) (hd liste) liste
;;

let l = [2; 4; 6; 1; 8; 4; 3; 1];;
smallest l;;

(* ’a list -> ’a *)
(* greatest *) 
let greatest liste = 
	fold_left (fun x a -> if compare x a > 0 then x else a) (hd liste) liste
;;
greatest l;;

(* Question 11 *)
(* point list -> rectangle *)
(* enclosing_rectangle *) 
let enclosing_rectangle (lst : point list) : rectangle =
	let x = map (fun e -> point_x e) lst
	and y = map (fun e -> point_y e) lst
	in make_rectangle (make_point (smallest x) (smallest y)) (make_point (largest x) (largest y));;

let p1 = make_point	0. 0.
and p2 = make_point 0.5 0.5
and p3 = make_point 0.5 1.5;;
enclosing_rectangle [p1; p2; p3];;

(* Question 12 *)
(* point list -> int -> quadtree *)
(* quadtree_make *)   
let quadtree_make (lst : point list) n : quadtree =
	let rec aux r l =
		match (length l) with
			| len when len <= n -> Leaf (l, r)
			| _ -> let (a, b, c, d) = rectangle_split_four r
				in Node (aux a (rectangle_contains_points a l), aux b (rectangle_contains_points b l), aux c (rectangle_contains_points c l), aux d (rectangle_contains_points d l), r)
	in aux (enclosing_rectangle lst) lst;;

let p1 = make_point 0. 0.
and p2 = make_point 0.5 0.5
and p3 = make_point 0.5 1.5;;
quadtree_make [p1; p2; p3] 1;;

(* Question 13 *)
(* quadtree -> int  *)
(* quadtree_count *)  
let rec quadtree_count (qtree : quadtree) =
	match qtree with
		| Leaf (l, _) -> length l
		| Node (a, b, c, d, _) -> quadtree_count a + quadtree_count b + quadtree_count c + quadtree_count d;;

quadtree_count (quadtree_make [p1; p2; p3] 1);;

(* Question 14 *)
(* quadtree -> int list *)
(* quadtree_signature *)
let rec quadtree_signature (qtree : quadtree) =
	match qtree with
		| Leaf (l, _) -> [length l]
		| Node (a, b, c, d, _) -> quadtree_signature a @ quadtree_signature b @ quadtree_signature c @ quadtree_signature d;;

quadtree_signature (quadtree_make [p1; p2; p3] 1);;

(* Question 14 *)
(* quadtree -> int list *)
(* quadtree_signature *)
let rec quadtree_signature (qtree : quadtree) =
	match qtree with
		| Leaf (l, _) -> [length l]
		| Node (a, b, c, d, _) -> quadtree_signature a @ quadtree_signature b @ quadtree_signature c @ quadtree_signature d;;

quadtree_signature (quadtree_make [p1; p2; p3] 1);;

(* -------------------------------------------------------------------------- *)


(* Question 15 *)
(* quadtree -> point list  *)
(* quadtree_all_points *)  
let rec quadtree_all_points (qtree : quadtree) : point list =
	match qtree with
		| Leaf (l, _) -> l
		| Node (a, b, c, d, _) -> quadtree_all_points a @ quadtree_all_points b @ quadtree_all_points c @ quadtree_all_points d;;

quadtree_all_points (quadtree_make [p1; p2; p3] 1);;

(* rectangle -> rectangle -> bool *)
let rectangle_contains_rectangle r1 r2 = 
	rectangle_contains_point r1 (rectangle_lower_left r2) &&
	rectangle_contains_point r1 (rectangle_upper_right r2);;

(* rectangle -> rectangle -> bool *)
let rectangle_disjoint (p1,p2) (p3,p4) =
   	point_domination p3 p2 || point_domination p1 p4;;

(* rectangle -> rectangle -> rectangle *)
let rectangle_intersection ((p1,p2),(p3,p4))=
	let ll_x_max = largest [point_x p1; point_x p3] in
	let ll_y_max = largest [point_y p1; point_y p3] in
	let ur_x_min = smallest [point_x p2; point_x p4] in
	let ur_y_min = smallest [point_y p2; point_y p4] in
	let ll = make_point ll_x_max ll_y_max in
	let ur = make_point ur_x_min ur_y_min in
		make_rectangle ll ur;;


let remove_elt e l =
  	let rec go l acc = match l with
    	| [] -> List.rev acc
    	| x::xs when e = x -> go xs acc
    	| x::xs -> go xs (x::acc)
  	in go l []

let remove_duplicates l =
  	let rec go l acc = match l with
    	| [] -> List.rev acc
    	| x :: xs -> go (remove_elt x xs) (x::acc)
	in go l []


(* Question 16 *)
(* rectangle -> quadtree -> point list  *)
(* rectangle_query *) 
let rec quadtree_rectangle_query (r : rectangle) (qtree : quadtree) : point list =
	match qtree with
		| Node (a, b, c, d, r2) when (rectangle_disjoint r r2) -> []
		| Node (a, b, c, d, r2) -> quadtree_rectangle_query (rectangle_intersection (r, r2)) a
			@ quadtree_rectangle_query (rectangle_intersection (r, r2)) b
			@ quadtree_rectangle_query (rectangle_intersection (r, r2)) c
			@ quadtree_rectangle_query (rectangle_intersection (r, r2)) d
		| Leaf (l, r2) when (rectangle_contains_rectangle r r2) -> l
		| Leaf (_, _) -> [];;



let rec range i j = if i > j then [] else i::(range (i + 1) j);;

let cartesian l l' =
	concat (map (fun e -> map (fun e' -> (e, e')) l') l);;

let points m n =
	let xs = map float_of_int (range 0 m)
	and ys = map float_of_int (range 0 n) in
		map (fun (x, y) -> make_point x y ) (cartesian xs ys);;
let ps = points 4 4;;

let qt = quadtree_make ps 2;;

let points_in = let p1 = make_point 0. 0. and p2 = make_point 2. 3. in

let query = make_rectangle p1 p2 in
	remove_duplicates (quadtree_rectangle_query query qt);;

let points_in = let p1 = make_point 3. 3. and p2 = make_point 5. 5. in
	let query = make_rectangle p1 p2 in
		remove_duplicates (quadtree_rectangle_query query qt);;
let points_in = let p1 = make_point 2. (-1.) and p2 = make_point 3. 5. in
	let query = make_rectangle p1 p2 in
		remove_duplicates (quadtree_rectangle_query query qt);;

let points_in = let p1 = make_point 3.75 3.75 and p2 = make_point 6. 6. in
	let query = make_rectangle p1 p2 in
		remove_duplicates (quadtree_rectangle_query query qt);;
let points_in = let p1 = make_point 4.75 4.75 and p2 = make_point 6. 6. in
	let query = make_rectangle p1 p2 in
		remove_duplicates (quadtree_rectangle_query query qt);;


(* -------------------------------------------------------------------------- *)

(* Question 17 *)
(* quadtree -> int -> point -> quadtree *)
(* quadtree_insert *)
let rec quadtree_insert (qtree : quadtree) n (pt : point) : quadtree =
	match qtree with
		| Leaf (l, r) -> 	if length l < n then Leaf (l @ [pt], r)
							else Leaf (l, r)
		| Node (a, b, c, d, r) -> Node (quadtree_insert a n pt, quadtree_insert b n pt, quadtree_insert c n pt, quadtree_insert d n pt, r);;



(* Question 18 *)
(* quadtree -> point -> quadtree *)
(* quadtree_delete *)