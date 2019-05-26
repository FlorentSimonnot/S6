open List ;; 
open String;; 

let explose l = 
    rev (fold_left (fun acc b -> [b] :: acc) [] l)
;;

explose [1;2;4;5;6];;

let etend_listes x ll = 
    fold_left (fun acc b -> ([x] @ b) :: acc) [] ll
;;

etend_listes 3 [[1; 2]; [4; 6]; [7; 8]];;

let rec rallonge_listes l ll = 
    match l with 
    |   [] -> []
    |   deb::fin -> (etend_listes deb ll)@(rallonge_listes fin ll)
;;

rallonge_listes [1;2] [[3];[4;5]];;

let trois_elements a b c = 
    rallonge_listes a (rallonge_listes b (explose c))
;; 

let semaine l = 
    rallonge_listes l (rallonge_listes l (rallonge_listes l (rallonge_listes l (explose l))))
;;

let g = [(1,[2;3]);(2,[4]);(3,[4]);(4,[1;5]);(5,[])];;

let tete paire = 
    fst paire
;; 

let successeurs paire = 
    snd paire
;;

let rec appartient x l = 
    match l with
        t::r -> (x = t) or (appartient x r)
    |    _   -> false;;

tete (5, [3; 2]);;
successeurs (5, [3; 2]);;

let toutes_les_tetes graphe = 
    fold_left (fun acc paire -> [tete paire] @ acc ) [] graphe
;;

toutes_les_tetes g;;

let tous_les_successeurs graphe = 
    fold_left (fun acc paire -> successeurs paire @ acc) [] graphe
;;

tous_les_successeurs g;;
