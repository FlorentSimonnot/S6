#load "graphics.cma";;

open Graphics;;

let w = 512 and h = 512;;


type picture = int * int -> Graphics.color

let from_polar (rho, theta) =
    (int_of_float (rho *. cos theta), int_of_float (rho *. sin theta)) 

let to_polar (x, y) =
    let distance_to_origin (x, y) = sqrt (float_of_int (x * x + y * y)) in
    (distance_to_origin (x, y), atan2 (float_of_int y) (float_of_int x))

let black_on_black : picture = fun point -> black;; 

let half_plane color : 
	picture = fun (x, y) -> if x < w / 2 then color 
							else background;;

let render (f : picture) =
    open_graph (Printf.sprintf " %dx%d" w h);
    auto_synchronize false;
    for x = 0 to w - 1 do
        for y = 0 to h - 1 do
            set_color (f (x, y));
            plot x y
        done;
        set_color background
    done;
    synchronize ();
    (wait_next_event [Button_down; Key_pressed]) |> ignore; 
    close_graph ()
;;

(*render black_on_black;;
render (half_plane red);;*)

(*EXERCICE 1*)

let diagonal color : picture =
    (fun (x, y) -> if x * h = y * w then color else background)
;;

(*render (diagonal red);;*)

let square c color : picture =
    (fun (x, y) -> if (c/2 >= x && c/2 >= y && x >= 0-c/2 && y >= 0-c/2) then color else background)
;; 

(*render (square 300 green);;*)

let rectangle long larg color : picture =
    (fun (x, y) -> if (long/2 >= x && larg/2 >= y && x >= 0-long/2 && y >= 0-larg/2) then color else background)
;;

(*render (rectangle 512 200 blue);;*)

let disk r color : picture =
    (fun (x, y) -> if (x*x + y*y) < r*r then color else background)
;;

(*render (disk 300 cyan);;*)

let circle r color : picture =
    (fun (x, y) -> if (x*x + y*y) <r*r && (x*x + y*y) > (r*(r-2))
        then color else background)
;;

(*render (circle 300 cyan);;*)

let move pic (x_m, y_m) : picture = 
	(fun (x, y) -> pic (x - x_m, y - y_m))
;;

(*render (move (rectangle 128 64 green) (200, 200));;*)

let vertical_symmetry im : picture =
    ((fun (x, y) -> (im (-x, y))))
;;

let horizontal_symmetry im : picture =
    ((fun (x, y) -> (im (x, -y))))
;;

(*render (vertical_symmetry (move(disk 200 30) (-200, 300)));;*)


(*EXERCICE 2*)

let v_lines n : picture = 
	(fun (x, y) -> if (x mod n = 0) then black else background)
;;

(*render (v_lines 30);;*)

let v_stripes n : picture = 
	(fun (x, y) -> if (x/n mod 2 = 0) then black else background)
;;

(*render (v_stripes 30);;*)

let chessboard color n : picture =
    (fun (x, y) -> if (x/n mod 2 = y/n mod 2) then color else background);;

(*render (chessboard green 5);; *)

let concentric color n : picture =
    fun (x, y) ->   if (int_of_float (sqrt (float_of_int ((((x-w/2) * (x-w/2)) + ((y-h/2) * (y-h/2))) /(n*n))))) mod 2 = 0 then
                        color
                    else
                        background
;;

(*render (concentric black 6);;*)

(*EXERCICE 3*)

let compose_two image1 image2 : picture =
    fun (x, y) ->   if image2 (x, y) = background then
                        image1 (x, y)
                    else
                        image2 (x, y)
;;

(*render (compose_two (chessboard green 5) (concentric blue 15));;*)

(*render (
		compose_two (move (disk (w / 4) black) (w / 2, h / 2)) 
		(compose_two (move (disk (w / 6) black) (w / 4, h * 3 / 4)) (move (disk (w / 6) black) (w * 3 / 4, h * 3 / 4))));;
*) 

let compose list_images =
    let rec aux list_images acc =
        match list_images with
        | [] -> acc
        | image :: reste -> aux reste (compose_two acc image)
    in
        aux list_images (fun (x, y) -> background)
;;

let mickey =
    let ombre_g = move (disk (w / 6) black) (w / 4, h * 3 / 4)
    and ombre_d = move (disk (w / 6) black) (w * 3 / 4, h * 3 / 4)
    and ombre_tete = move (disk (w / 4) black) (w / 2, h / 2)
    and tete = move (disk (w * 2 / 9) 0xBBBBBB) (w / 2, h / 2)
    and nez = move (disk (w / 24) black) (w / 2, h / 2)
    and oeil_g = move (disk (w / 48) black) (w * 21 / 48, h * 27 / 48)
    and oeil_d = move (disk (w / 48) black) (w * 27 / 48, h * 27 / 48)
    in [ombre_g; ombre_d; ombre_tete; tete; nez; oeil_g; oeil_d]
;;

(*render (compose mickey);;*)

(*EXERCICE 4*)

let pi = (acos (-1.0));;

let rotate image angle : picture =
    fun (x, y) ->   let rho, theta = to_polar (x, y) in
                        image (from_polar (rho, theta -. angle))
;;

(*render (move (rotate (compose mickey) (pi /. 2.0)) (w, 0));;*)

let sun color : picture = 
	(fun (x, y) -> color)
;;

let compose_xor_two image1 image2 : picture =
    fun (x, y) ->   if image2 (x, y) = background then
                        image1 (x, y)
                    else if image1 (x, y) = background then
                        image2 (x, y)
                    else
                        background
;;

(*render (compose_xor_two (concentric black 6) (v_lines 30));;*)

let double_concentric width =
    let concentric color n (cx, cy): picture =
        fun (x, y) ->   let dist = sqrt (float_of_int ((cx - x) * (cx - x) + (cy - y) * (cy - y))) in
                            if int_of_float (dist /. (float_of_int n)) mod 2 = 0 then
                                color
                            else
                                background
    in
        compose_xor_two (concentric black width (w / 4, h / 2)) (concentric black width (w * 3 / 4, h / 2))
;;

let compose_xor list_images =
    let rec aux list_images acc =
        match list_images with
        | [] -> acc
        | image :: reste -> aux reste (compose_xor_two acc image)
    in
        aux list_images (fun (x, y) -> background)
;;

(*render (double_concentric 10);;*)
(*render (compose_xor mickey);;*)

let rosace n : picture =
    let concentric1 = double_concentric n
    and concentric2 = move (rotate (double_concentric n) (pi /. 2.0)) (w, 0)
    in compose_xor_two concentric1 concentric2
;;

render (rosace 12);;