(*SIMONNOT Florent - G3 - TP6*)

(*EXERCICE 1*)

type tree = 
	| Leaf of int 
	| Node of char * tree list
;; 

let example_tree = 
	Node ('a', 
		[
			Node ('b', [Leaf 1; Leaf 2; Leaf 3]);
			Node ('c', 
				[
					Node ('d', [Leaf 4; Leaf 5;]);
					Node ('e', [Leaf 6])
				]); 
			Leaf 7; 
			Node (
					'f', 
					[Node ('g', [Leaf 8]); Leaf 9])
		]
	)

let rec count_nodes_in_list tree = 
	let rec aux l = 
		match l with 
		| [] -> 0
		| Leaf (_) :: reste -> aux reste 
		| Node (_, children) :: reste -> 1 + (aux children) + (aux reste)
	in aux [tree]
;; 

(*count_nodes_in_list example_tree;;*)

let tree_list_leaves t =
	let rec aux t acc =
		match t with
		| Leaf(e) -> acc @ [e]
		| Node(_, fils) -> aux2 fils acc
	and
	aux2 l acc =
		match l with
		| [] -> acc
		| e :: reste -> (aux e []) @ (aux2 reste acc)
	in aux t []
;;

(*tree_list_leaves example_tree;;*)

(*EXERCICE 2*)

type fs_item_name = string 

type fs_folder = Folder of fs_item_name

type fs_file_type = 
	| PDF
	| DOC
	| PNG 
	| JPG 
	| AVI
	| MKV

type fs_file_size = int

type fs_file = File of fs_item_name * fs_file_type * fs_file_size

type fs_item = 
	| FolderItem of fs_folder * fs_item list
	| FileItem of fs_file
;;

let files item = 
	let rec aux liste =
		match liste with
		| [] -> []
		| FileItem (file) :: reste -> file :: (aux reste)
		| FolderItem (folder, fils) :: reste -> (aux fils) @ (aux reste)
	in aux [item]
;;

let folders item = 
	let rec aux liste =
		match liste with
		| [] -> []
		| FileItem (file) :: reste -> (aux reste)
		| FolderItem (folder, fils) :: reste -> folder :: (aux fils) @ (aux reste)
	in aux [item]
;;

let my_fs2 : fs_item =
  FolderItem (Folder "root",
    [ FolderItem (Folder "Documents",
      [
        FileItem (File ("doc 1", DOC, 32))
      ; FileItem (File ("doc 2", DOC, 64))
      ; FileItem (File ("doc 3", PDF, 1024))
      ; FileItem (File ("doc 4", PDF, 2048))
      ; FileItem (File ("mov 1", AVI, 1024))
      ; FileItem (File ("img 1", PNG, 1024))
      ])
    ; FileItem (File ("Documents", DOC, 28))
    ])
;;

(*files my_fs2;;
folders my_fs2;;*)

let is_image file = 
	match file with 
	| File (_, JPG, _) -> true
	| File (_, PNG, _) -> true
	| _ -> false
;;

(*is_image (File ("doc 1", DOC, 32));;
is_image (File ("img 1", JPG, 32));;*)

let is_movie file = 
	match file with 
	| File (_, AVI, _) -> true
	| File (_, MKV, _) -> true
	| _ -> false
;;

(*is_movie (File ("doc 1", DOC, 32));;
is_movie (File ("mov 1", MKV, 32));;*)

let is_document file = 
	match file with 
	| File (_, DOC, _) -> true
	| File (_, PDF, _) -> true
	| _ -> false
;;

(*is_document (File ("doc 1", DOC, 32));;
is_document (File ("mov 1", MKV, 32));;*)

let images fs = (List.filter is_image (files fs));;
let documents fs = (List.filter is_document (files fs));;
let movies fs = (List.filter is_movie (files fs));;

(*images my_fs2;;
documents my_fs2;;
movies my_fs2;;*)

let rec rec_search_list listOfFiles name = 
	match listOfFiles with 
	| [] -> []
	| File (nameFile, x, y) :: reste when (String.compare nameFile name) == 0 -> File(name, x, y) :: (rec_search_list reste name)
	| File (nameFile, _, _) :: reste -> (rec_search_list reste name)
;;

(*rec_search_list (files my_fs2)  "doc 1";;*)

let tail_rec_search_list listOfFiles name =
	let rec aux listOfFiles acc =
		match listOfFiles with
		| [] -> acc
		| File (e, x, y) :: reste when (compare name e) == 0 -> aux reste (File(e, x, y)::acc)
		| File (e, _, _) :: reste -> aux reste acc
	in aux listOfFiles []
;;

(*tail_rec_search_list (files my_fs2)  "doc 1";;*)

let not_rec_search_list fs_list name =
	List.filter (fun f -> match f with
	| File (e, x, y) when (compare name e) == 0 -> true
	| File (e, _, _) -> false) (fs_list)
;;

(*not_rec_search_list (files my_fs2) "doc 1";;*)

let search_documents fs name =
	not_rec_search_list (documents fs) name

let search_documents_fun func fs name =
	func (documents fs) name


let size_images fs =
	List.fold_left (fun acc f -> match f with
	| File (_, _, size) -> size + acc) 0 (images fs)

let fs_filter p fs =
	let rec aux p fs acc =
		match fs with
		| FileItem (file) when not (p (FileItem (file))) -> acc
		| FileItem (File(e, x, y)) -> e :: acc
		| FolderItem (folder, reste) when not (p (FolderItem (folder, reste))) -> list_folders p reste acc
		| FolderItem (Folder(e), reste) -> list_folders p reste (e :: acc)	
	
	and list_folders p l acc =
		match l with
		| [] -> acc
		| f :: reste -> (aux p f []) @ (list_folders p reste acc)

	in (aux p fs [])

let item_names_with_large6_name fs =
	fs_filter (fun f -> match f with
	| FileItem (File(e, _, _)) when not (String.length(e) >= 6) -> false
	| FolderItem (Folder(e), _) when not (String.length(e) >= 6) -> false
	| FileItem (_) -> true
	| FolderItem (_, _) -> true) fs

(* 2. *)

let digit_in_names fs =
	fs_filter (fun f -> match f with
	| FileItem (File(e, _, _))  -> 	List.fold_left(fun acc num -> 
										acc || (String.contains e num)) false
										['1'; '2'; '3'; '4'; '5'; '6'; '7'; '8'; '9']

	| FolderItem (Folder(e), _) -> 	List.fold_left (fun acc num -> 
										acc || (String.contains e num)) false
										['1'; '2'; '3'; '4'; '5'; '6'; '7'; '8'; '9']) fs

(* 13. *)

let full_paths fs = 
	let rec aux fs path acc =
		match fs with
		| FileItem (file) -> (add_file file path) :: acc
		| FolderItem (folder, reste) ->
			let new_path = add_folder folder path
		in add_list reste new_path (new_path :: acc)
	
	and add_file file path =
		match file with
		| File (e, _, _) -> String.concat "/" [path; e]

	and add_folder file path =
		match file with
		| Folder (e) -> String.concat "/" [path; e]

	and add_list l path acc  =
		match l with
		| [] -> acc
		| f :: reste -> (aux f path []) @ (add_list reste path acc)

	in (aux fs "" [])


(* 14. *)

let name_with_ext fs = 
	let rec aux fs ext acc =
		match fs with
		| FileItem (file) -> (ext_file file) :: acc
		| FolderItem (Folder(e), _) -> e :: acc
	
	and ext_file file =
		match file with
		| File (e, ext, _) when ext = PDF -> String.concat "." [e; "pdf"]
		| File (e, ext, _) when ext = DOC -> String.concat "." [e; "doc"]
		| File (e, ext, _) when ext = PNG -> String.concat "." [e; "png"]
		| File (e, ext, _) when ext = JPG -> String.concat "." [e; "jpg"]
		| File (e, ext, _) when ext = AVI -> String.concat "." [e; "avi"]
		| File (e, ext, _) when ext = MKV -> String.concat "." [e; "mkv"]
		| File (e, ext, _) -> ""

	in (aux fs "" [])


(* 15. *)

let rec no_two_identical_names fs_name_list =
	match fs_name_list with
	| [] -> true
	| head :: suite -> (let rec aux suite acc =
							match suite with
							|[] -> true
							| tail :: reste when (compare head tail) <> 0 -> aux reste acc
							| tail :: reste -> false
						in aux suite true) && no_two_identical_names suite

(*========================TEST============================*)
(* toy file system *)
let my_fs : fs_item =
  FolderItem (Folder "root",
    [ FolderItem (Folder "Documents",
      [ FileItem (File ("doc 1", DOC, 32))
      ; FileItem (File ("doc 2", DOC, 64))
      ; FileItem (File ("doc 3", PDF, 1024))
      ; FileItem (File ("doc 4", PDF, 2048))
      ; FolderItem (Folder "2015",
        [ FileItem (File ("sujet tp note", PDF, 512))
        ; FileItem (File ("notes tp", DOC, 64))
        ])
      ;  FolderItem (Folder "2016",
        [ FileItem (File ("sujet tp note", PDF, 512))
        ; FileItem (File ("notes tp", DOC, 64))
        ])
      ])
    ; FileItem (File ("Documents", PDF, 512))
    ; FileItem (File ("config", DOC, 28))
    ; FolderItem (Folder "Downloads",
      [
        FileItem (File ("doc 1", DOC, 32))
      ; FileItem (File ("doc 2", DOC, 64))
      ; FileItem (File ("doc 1", PDF, 1024))
      ; FileItem (File ("doc 2", PDF, 2048))
      ])
    ; FolderItem (Folder "Movies",
      [ FolderItem (Folder "Rocky 1",
        [ FileItem (File ("Rocky 1", MKV, 4294967296))
        ; FileItem (File ("Rocky 1 - subtitle fr", DOC, 4096))
        ; FileItem (File ("Rocky 1 - subtitle en", DOC, 4096))
        ])
      ; FolderItem (Folder "Jaws 2",
        [
          FileItem (File ("Jaws 2", AVI, 16777216))
        ; FileItem (File ("Jaws 2 - subtitle fr", DOC, 4096))
        ])
      ; FolderItem (Folder "Alien 3",
        [ FileItem (File ("Alien 3", MKV, 4294967296))
        ])
      ; FileItem (File ("Seven", AVI, 1024))
      ; FileItem (File ("seen movies", DOC, 64))
      ])
    ; FolderItem (Folder "Pictures",
      [ FileItem (File ("Martine fait du chameau 1", PNG, 2048))
      ; FileItem (File ("Martine fait du chameau 2", JPG, 4096))
      ; FolderItem (Folder "Photos 2015",
        [ FileItem (File ("description 2015", DOC, 256))
        ; FileItem (File ("Martine au zoo 1", JPG, 2048))
        ; FileItem (File ("Martine au zoo 2", JPG, 2048))
        ; FileItem (File ("Martine au zoo 3", PNG, 2048))
        ])
      ; FolderItem (Folder "Photos 2016",
        [ FileItem (File ("description 2016", DOC, 512))
        ; FileItem (File ("Martine mange une pomme 1", JPG, 2048))
        ; FileItem (File ("Martine mange une pomme 2", JPG, 2048))
        ; FileItem (File ("Martine mange une pomme 3", PNG, 2048))
        ; FileItem (File ("Martine mange une pomme 4", PNG, 2048))
        ])
      ])
    ])

(* toy file system *)
let my_fs2 : fs_item =
  FolderItem (Folder "root",
    [ FolderItem (Folder "Documents",
      [
        FileItem (File ("doc 1", DOC, 32))
      ; FileItem (File ("doc 2", DOC, 64))
      ; FileItem (File ("doc 3", PDF, 1024))
      ; FileItem (File ("doc 4", PDF, 2048))
      ])
    ; FileItem (File ("Documents", DOC, 28))
    ])

(* toy file system *)
let my_fs3 : fs_item =
  FolderItem (Folder "root",
    [ FolderItem (Folder "Documents",
      [
        FolderItem (Folder "Documents",
        [
          FileItem (File ("doc 1", DOC, 32))
        ; FileItem (File ("doc 2", DOC, 64))
        ])
      ; FileItem (File ("doc 1", DOC, 32))
      ; FileItem (File ("doc 2", DOC, 64))
      ])
    ; FileItem (File ("Downloads", DOC, 28))
    ])

(* toy file system (not well-formed)*)
let my_fs4 : fs_item =
  FolderItem (Folder "root",
    [ FolderItem (Folder "Documents",
      [
        FileItem (File ("doc 1", DOC, 32))
      ; FileItem (File ("doc 2", DOC, 64))
      ; FileItem (File ("doc 1", PDF, 1024))
      ; FileItem (File ("doc 2", PDF, 2048))
      ])
    ; FolderItem (Folder "Documents",[])
    ])

(* toy file system (not well-formed)*)
let my_fs5 : fs_item =
  FolderItem (Folder "root",
    [ FolderItem (Folder "Documents",
      [
        FileItem (File ("doc 1", DOC, 32))
      ; FileItem (File ("doc 1", DOC, 64))
      ; FileItem (File ("doc 3", PDF, 1024))
      ; FileItem (File ("doc 4", PDF, 2048))
      ])
    ; FileItem (File ("Documents", DOC, 28))
    ])

(* toy file system (not well-formed)*)
let my_fs6 : fs_item =
  FolderItem (Folder "root",
    [ FolderItem (Folder "Documents",
      [
        FileItem (File ("doc 1", DOC, 32))
      ; FileItem (File ("doc 1", DOC, 64))
      ])
    ; FileItem (File ("AutresDocuments", DOC, 28))
    ])

let test1 = File ("file 1", DOC, 32)
and test2 = File ("file 2", PNG, 512)
and test3 = File ("file 3", AVI, 4294967296);;

print_string "files my_fs;;";;
files my_fs;;
print_string "\n";;

print_string "folders my_fs;;";;
folders my_fs;;
print_string "\n";;

print_string "is_image test1, is_image test2, is_image test3;;";;
is_image test1, is_image test2, is_image test3;;
print_string "is_movie test1, is_movie test2, is_movie test3;;";;
is_movie test1, is_movie test2, is_movie test3;;
print_string "is_document test1, is_document test2, is_document test3;;";;
is_document test1, is_document test2, is_document test3;;
print_string "\n";;

print_string "images my_fs;;";;
images my_fs;;
print_string "movies my_fs;;";;
movies  my_fs;;
print_string "documents my_fs;;";;
documents my_fs;;
print_string "\n";;

print_string "rec_search_list (files my_fs) \"notes td\";;";;
rec_search_list (files my_fs) "notes td";;
print_string "rec_search_list (files my_fs) \"notes tp\";;";;
rec_search_list (files my_fs) "notes tp";;
print_string "tail_rec_search_list (files my_fs) \"notes td\";;";;
tail_rec_search_list (files my_fs) "notes td";;
print_string "tail_rec_search_list (files my_fs) \"notes tp\";;";;
tail_rec_search_list (files my_fs) "notes tp";;
print_string "not_rec_search_list (files my_fs) \"notes td\";;";;
not_rec_search_list (files my_fs) "notes td";;
print_string "not_rec_search_list (files my_fs) \"notes tp\"";;
not_rec_search_list (files my_fs) "notes tp";;
print_string "\n";;

print_string "search_documents my_fs \"notes td\";;";;
search_documents my_fs "notes td";;
print_string "search_documents my_fs \"notes tp\";;";;
search_documents my_fs "notes tp";;
print_string "search_documents my_fs \"Rocky 1\";;";;
search_documents my_fs "Rocky 1";;
print_string "\n";;

print_string "size_images my_fs;;";;
size_images my_fs;;
print_string "\n";;

print_string "item_names_with_large6_name my_fs";;
item_names_with_large6_name my_fs;;
(*print_string "item_names_with_digit_in_name my_fs";;
item_names_with_digit_in_name my_fs;;
print_string "\n";;*)

print_string "full_paths my_fs;;";;
full_paths my_fs;;
print_string "\n";;

(*print_string "check my_fs, check my_fs2, check my_fs3, check my_fs4, check my_fs5, check my_fs6;;";;
check my_fs, check my_fs2, check my_fs3, check my_fs4, check my_fs5, check my_fs6;;
print_string "\n";;

print_string "du my_fs;;";;
du my_fs;;*)
