#ifndef __INPUT_OUTPUT__
#define __INPUT_OUTPUT__

/* Parse les arguments de programme */
void option_parsing(int argc, char **argv);

/* Ecrit le début du code asm (fonction print, tableau de global ...etc) */
void print_start(int globals_vars_size, int globals_const_size, char vars[64][64], long vals[64], char consts[64][64], long cvals[64]);

/* Ecrit la fin du code asm (return et syscall de fin) */
void print_end();

#endif