type morse =
  Dash | Dot | Blank | NotAMorseSymbol;;

type morse_rendering = RDash | RDot | SymbSpace | LetterSpace | WordSpace| NotAMorseRenderingSymbol

type morse_letter = morse list;;

let blank_translation : (char * morse_letter) list =
  [' ', [Blank]];;

let num_translation : (char * morse_letter) list =
  ['1', [Dot; Dash; Dash; Dash; Dash];
  '2', [Dot; Dot; Dash; Dash; Dash];
  '3', [Dot; Dot; Dot; Dash; Dash];
  '4', [Dot; Dot; Dot; Dot; Dash];
  '5', [Dot; Dot; Dot; Dot; Dot];
  '6', [Dash; Dot; Dot; Dot; Dot];
  '7', [Dash; Dash; Dot; Dot; Dot];
  '8', [Dash; Dash; Dash; Dot; Dot];
  '9', [Dash; Dash; Dash; Dash; Dot];
  '0', [Dash; Dash; Dash; Dash; Dash]];;

let char_translation : (char * morse_letter) list =
  ['a', [Dot; Dash];
  'b', [Dash; Dot; Dot; Dot];
  'c', [Dash; Dot; Dash; Dot];
  'd', [Dash; Dot; Dot];
  'e', [Dot];
  'f', [Dot; Dot; Dash; Dot];
  'g', [Dash; Dash; Dot];
  'h', [Dot; Dot; Dot; Dot];
  'i', [Dot; Dot];
  'j', [Dot; Dash; Dash; Dash];
  'k', [Dash; Dot; Dash];
  'l', [Dot; Dash; Dot; Dot];
  'm', [Dash; Dash];
  'n', [Dash; Dot];
  'o', [Dash; Dash; Dash];
  'p', [Dot; Dash; Dash; Dot];
  'q', [Dash; Dash; Dot; Dash];
  'r', [Dot; Dash; Dot];
  's', [Dot; Dot; Dot];
  't', [Dash];
  'u', [Dot; Dot; Dash];
  'v', [Dot; Dot; Dot; Dash];
  'w', [Dot; Dash; Dash];
  'x', [Dash; Dot; Dot; Dash];
  'y', [Dash; Dot; Dash; Dash];
  'z', [Dash; Dash; Dot; Dot]
  ];;



let morse_translation = blank_translation @ num_translation @ char_translation;;