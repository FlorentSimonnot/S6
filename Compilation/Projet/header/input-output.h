#ifndef __INPUT_OUTPUT__
#define __INPUT_OUTPUT__

/* Parse les arguments de programme */
void option_parsing(int argc, char **argv);

/* Ecrit le début du code asm (fonction print, tableau de global ...etc) */
void print_start(int globals_size);

/* Ecrit la fin du code asm (return et syscall de fin) */
void print_end();

#endif