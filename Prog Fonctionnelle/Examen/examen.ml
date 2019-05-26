open List;; 
open String;;
#use "skeleton.ml";;

let char_list_to_string chaine = 
    let rec aux chaine liste index = 
        if index = length chaine then             
            liste
        else 
            aux chaine (liste @ [get chaine index]) (index+1)
    in aux chaine [] 0
;;

char_list_to_string "pinguin";;

let string_of_char c = make 1 c;;

let string_of_char_list char_list = 
    fold_left (fun acc b -> acc ^ string_of_char b) "" char_list
;;

string_of_char_list ['p'; 'i'; 'n'; 'g'; 'u'; 'i'; 'n'];; 

let rec join_strings_with_string delim char_list =  
    match char_list with 
       [] -> ""
    |   deb :: fin when fin <> [] -> concat delim [deb; join_strings_with_string delim fin]
    |   deb :: fin -> deb ^ (join_strings_with_string delim fin)
;; 

join_strings_with_string "-" ["cat";"dog";"bird";"fly"];;

let rec join_chars_with_string delim char_list = 
    match char_list with 
       [] -> ""
    |   deb :: fin when fin <> [] -> concat delim [string_of_char deb; join_chars_with_string delim fin]
    |   deb :: fin -> (string_of_char deb) ^ (join_chars_with_string delim fin)  
;; 

join_chars_with_string "*" ['p'; 'i'; 'n'; 'g'; 'u'; 'i'; 'n'];; 

let rec contains_only l1 l2 = 
    match l1 with
        [] -> true 
    |   deb :: fin -> (mem deb l2) && (contains_only fin l2)
;;     

contains_only ['a'; 'b'; 'c'] ['a'; 'c'; 'd'];;
contains_only ['a'; 'b'; 'c'] ['a'; 'c'; 'd'; 'b'];;

let rec fzip f l1 l2 = 
    match l1, l2 with 
        [], _ -> []
    |   _, [] -> []
    |   deb::fin, deb2::fin2 -> (f deb deb2) :: (fzip f fin fin2);;

fzip (+) [1;2] [5;6;7];;

let rec zip l1 l2 = 
    match l1, l2 with 
        [], _ -> []
    |   _, [] -> []
    |   deb::fin, deb2::fin2 -> (deb, deb2) :: (zip fin fin2)
;; 

zip [1; 2; 3] [4; 5; 6];;

let unzip l = 
    let rec aux l acc1 acc2 = 
        if l = [] then 
            (acc1, acc2)
        else 
            (aux (tl l)) (acc1 @ [fst(hd l)]) (acc2 @ [snd(hd l)])
    in aux l [] []
;;

unzip(zip [1; 2; 3] [4; 5; 6]);;

let check_msg message = 
    contains_only (char_list_to_string message) (fst (unzip morse_translation));; 

let morse_letter_of_char c = 
    snd (find (fun a -> c = (fst a)) morse_translation)
;;

morse_letter_of_char 'a';;

let char_of_morse_letter morse = 
    fst (find (fun a -> morse = (snd a)) morse_translation)
;;

char_of_morse_letter [Dot; Dash];;

let morse_code message = 
    if check_msg message then 
        fold_left (fun a b -> a @ [(morse_letter_of_char b)]) [] (char_list_to_string message)
    else 
        []
;;

let msg = "happy otter day";;
let morse_code_example = morse_code msg;;

morse_letter_of_char 'b';;

let render_letter_code morse = 
    let rec aux morse acc = 
        match morse with 
            [] -> acc
        |   Dot::fin -> if fin <> [] then 
                            [RDot; SymbSpace] @ (aux fin acc)
                        else 
                            [RDot]
        |   Dash::fin -> if fin <> [] then 
                            [RDash; SymbSpace] @ (aux fin acc)
                        else 
                            [RDash]
        |   Blank::fin -> [WordSpace] @ (aux fin acc)
    in aux morse []
;;

render_letter_code (morse_letter_of_char 'b');;


(*let msg = "happy otter day";;
let res = fold_left (fun a b -> a @ [morse_letter_of_char ' '] @ b) [] (morse_code msg);;
*)

(*tl pour enlever le premier LetterSpace*)
let render_morse_code message = 
    tl (fold_left (fun a b -> a @ (LetterSpace::(render_letter_code b))) [] (morse_code msg))
;;


let msg = "happy otter day";;
let render_morse_translation_msg = render_morse_code morse_code_example;;

[] :: [];;

let split_list s lst =   
    tl (rev (fold_left (fun acc b -> 
        if acc <> [] then
            if b = s && (hd (rev acc) <> []) then 
                [] :: (rev acc)
            else 
                 ([b] @ (hd (rev acc))) :: (tl (rev acc))
        else 
            if b <> s then
                [b] :: (acc)
            else
                [] :: (acc)
    ) [] lst))
;;

split_list 0 [1; 0; 2; 3; 0; 0; 4];;

(*

let join_list_with s lst = 
    tl (fold_left (fun a b -> a  @ [s] @ b) [] lst)
;;

join_list_with 0 [[1];[2;3];[4]];;

let rendering_to_morse symb = 
    match symb with 
        RDot -> Dot
    |   RDash -> Dash 
    |   WordSpace -> Blank
    |   _ -> NotAMorseSymbol
;; 

rendering_to_morse RDot;;

let render_morse_decode message =
    fold_left (
                fun acc b -> if b = LetterSpace then 
                    [] @ acc else 
                ) [] (render_morse_code message)
;;


let morse_translation_msg = render_morse_decode render_morse_translation_msg;;*)