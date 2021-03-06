#include "../header/input-output.h"
#include "../header/decl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

static void print_usage(){
    fprintf(stderr, "./tcompil [< prog.asm] [-o OUTPUT]\n");
}

void option_parsing(int argc, char **argv){
    char option;
    unsigned char flag = 0;
    char file_name[BUFSIZ] = ""; 

    while ((option = getopt(argc, argv, "o:")) != -1){
        switch (option){
            case 'o':
                strcpy(file_name, optarg);
                flag = 1;
                break;
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }

    if (flag){
        stdout = fopen(file_name, "w");
    }
}

void print_start(int globals_vars_size, int globals_const_size, int globals_array_size, char vars[64][64], long vals[64], char consts[64][64], long cvals[64], char array[64][64], int dimension[64], int *size_par_dim[64]){
    int i, j, k; 
    fprintf(stdout, "extern printf\n\n");
    fprintf(stdout, "extern scanf\n\n");
    if (globals_vars_size > 0){
        fprintf(stdout, "section .data\n");
        for(i = 0; i < globals_vars_size; i++){
            fprintf(stdout, "    %s dq %ld\n", vars[i], vals[i]);
        }
    }
    if(globals_const_size > 0){
        for(i = 0; i < globals_const_size; i++){
            fprintf(stdout, "    %s equ %ld\n", consts[i], cvals[i]);
        }
    }
    for(i = 0; i < globals_array_size; i++){
        fprintf(stdout, "    %s dq ", array[i]);
        for(j = 0; j <= dimension[i]; j++){
            for(k = 0; k < size_par_dim[i][j]; k++){
                fprintf(stdout, "0, ");
            }
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "   __size___tab__ dq 8\n");
    //fprintf(stdout, "section .data\n");
    fprintf(stdout, "    format_ent db \"%%d\", 10, 0\n");
    fprintf(stdout, "    format_long db \"%%ld\", 10, 0\n");
    fprintf(stdout, "    format_sent db \"%%d\\n\", 10, 0\n\n");
    fprintf(stdout, "section .text\n\n");
    fprintf(stdout, "global _start\n\n");
    fprintf(stdout, "_print_car:\n");
    fprintf(stdout, "    mov rax, 1\n");
    fprintf(stdout, "    push rsi\n");
    fprintf(stdout, "    mov rdi, 1\n");
    fprintf(stdout, "    mov rsi, rsp\n");
    fprintf(stdout, "    mov rdx, 1\n");
    fprintf(stdout, "    syscall\n");
    fprintf(stdout, "    pop rsi\n");
    fprintf(stdout, "    ret\n\n");
    fprintf(stdout, "_print_ent:\n");
    fprintf(stdout, "    mov rdi, format_ent\n");
    fprintf(stdout, "    mov rax, 0\n");
    fprintf(stdout, "    call printf WRT ..plt\n");
    fprintf(stdout, "    ret\n\n");
    fprintf(stdout, "_print_long:\n");
    fprintf(stdout, "    mov rdi, format_long\n");
    fprintf(stdout, "    mov rax, 0\n");
    fprintf(stdout, "    call printf WRT ..plt\n");
    fprintf(stdout, "    ret\n\n");
    fprintf(stdout, "_readc:\n");
    fprintf(stdout, "    push 0\n    mov rax, 0\n");
    fprintf(stdout, "    mov rdi, 0\n    mov rsi, rsp\n");
    fprintf(stdout, "    mov rdx, 1\n");
    fprintf(stdout, "    syscall\n   pop rax\n");
    fprintf(stdout, "    ret\n\n");
    fprintf(stdout, "_reade:\n");
    fprintf(stdout, "    mov rax, 0\n");
    fprintf(stdout, "    mov rdi, format_sent\n");
    fprintf(stdout, "    call scanf\n");
    fprintf(stdout, "    pop rax\n  ret\n\n");
    fprintf(stdout, "_start:\n    call main\n    jmp _end\n\n");
}

void print_end(){
    fprintf(stdout, "_end:\n");
    
    switch (lookupFunction("main")) {
        case INTEGER :
            fprintf(stdout, "    mov rdi, rax\n"); break;
        case CHAR :
            fprintf(stdout, "    mov rdi, rax\n"); break;
        case VOIDTYPE :
            fprintf(stdout, "    mov rdi, 0\n"); break;
    }
    
    fprintf(stdout, "    mov rax, 60\n");
    fprintf(stdout, "    syscall\n");
}