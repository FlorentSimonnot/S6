(**********************************************************************)
(***************************** Exercise 1 *****************************)
(**********************************************************************)
open List;;
(* 1.1. *)
(* val interval : int -> int -> int list = <fun> *)
let interval a b = 
    let rec aux inf sup acc =
        if inf = sup+1 then
            acc
        else 
            aux (inf+1) sup (acc@[inf]) 
    in aux a b []
;;

interval 0 10;;

(* 1.2. *)
(* val interval_f : int -> int -> (int -> 'a) -> 'a list = <fun> *)
let interval_f a b func =
    map func (interval a b)
;; 

interval_f 0 10 (fun x -> 2*x);;

(* 1.3. *)
(* val is_positive_list : int list -> bool = <fun> *)

(* 1.4. *)
(* val is_sum_leq_list : int list -> int -> bool = <fun> *)

(* 1.5. *)
(* val are_equivalent_lists : 'a list -> 'b list -> ('a -> 'b -> bool)
        -> bool = <fun> *)

(* 1.6 *)
(* val cartesian_product_lists : 'a list -> 'b list -> ('a * 'b) list
        = <fun> *)
let cartesian_product_lists l1 l2 = 
    map (fun a -> map (fun b -> (a, b)) l2) l1;;

cartesian_product_lists [1;2;3] [4;5;6];;
(**********************************************************************)
(***************************** Exercise 2 *****************************)
(**********************************************************************)

(* Given type. *)
type state = Empty | Black

(* Given type. *)
type square = int * int

(* Given type. *)
type grid = {
    nb_rows : int;
    nb_columns : int;
    states : square -> state
}

(* Given function. *)
let state_to_string c =
    match c with
        |Empty -> "-"
        |Black -> "O"

(* Given function. *)
let grid_to_string grid =
    let index_rows = interval 1 grid.nb_rows
    and index_columns = interval 1 grid.nb_columns in
    List.fold_left
        (fun res i ->
            let line = List.fold_left
                (fun res j ->
                    res ^ (state_to_string (grid.states (i, j))) ^ "|")
                "|"
                index_columns
            in
            res ^ line ^ "\n")
        ""
        index_rows

(* 2.1. *)
(* val empty_grid : int -> int -> grid = <fun> *)

(* 2.2 *)
(* val fill_square : grid -> square -> grid = <fun> *)

(* 2.3. *)
(* val fill_squares : grid -> square list -> grid = <fun> *)

(* 2.4. *)
(* val row : grid -> int -> state list = <fun> *)

(* 2.5. *)
(* val column : grid -> int -> state list = <fun> *)

(**********************************************************************)
(***************************** Exercise 3 *****************************)
(**********************************************************************)

(* Given type. *)
type profile = int list

(* 3.1. *)
(* val profile : state list -> profile = <fun> *)

(* 3.2. *)
(* val are_profiles_compatible : profile -> profile -> bool = <fun> *)

(**********************************************************************)
(***************************** Exercise 4 *****************************)
(**********************************************************************)

(* Given type. *)
type spec = {
    rows : profile list;
    columns : profile list
}

(* 4.1. *)
(* val dimensions_spec : spec -> int * int = <fun> *)

(* 4.2. *)
(* val is_solution : spec -> grid -> bool = <fun> *)

(**********************************************************************)
(***************************** Exercise 5 *****************************)
(**********************************************************************)

(* 5.1. *)
(* val next_square : grid -> square -> square = <fun> *)

(* 5.2. *)
(* val is_square : grid -> square -> bool = <fun> *)

(* 5.3. *)
(* val solve_brute_force : spec -> bool * grid = <fun> *)

