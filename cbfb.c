#include <stdio.h>
#include <stdlib.h>

const char* header =
    "#include <stdio.h>\n"
    "#include <stdint.h>\n"
    "uint32_t t[30000];"
    "uint32_t s[30000];"
    "uint32_t ss = 0;"
    "uint32_t i = 0;"
    "int main(void) {";
    
const char* footer = 
    "return 0;"
    "}";

int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: cbfb [file]");
        exit(1);
    }
    
    char *input_file = argv[1];
    
    FILE* ifd = fopen(input_file, "r");
    
    FILE* ofd = fopen("a.c","w");
    
    fprintf(ofd, header);
    
    while(!feof(ifd)) {
        char c = fgetc(ifd);
        
        switch (c) {
            case '+': {
                fprintf(ofd,"t[i]++;");
            } break;
            case '-': {
                fprintf(ofd,"t[i]--;");
            } break;
            case '>': {
                fprintf(ofd,"i++;");
            } break;
            case '<': {
                fprintf(ofd,"i--;");
            } break;
            case '.': {
                fprintf(ofd,"putc(t[i],stdout);");
            } break;
            case ',': {
                fprintf(ofd,"t[i]=getc(stdin);");
            } break;
            case '[': {
                fprintf(ofd,"while(t[i]){");
            } break;
            case ']': {
                fprintf(ofd,"}");
            } break;
            case '#': {
                fprintf(ofd,"s[ss++]=t[i];");
            } break;
            case '$': {
                fprintf(ofd,"t[i]=s[--ss];");
            } break;
            case ';': {
                fprintf(ofd,"scanf(\"%%d\",&t[i]);");
            } break;
            case ':': {
                fprintf(ofd,"printf(\"%%d\",t[i]);");
            } break;
            case '(': {
                fprintf(ofd,"for(uint32_t _=t[i];_>0;--_){");
            } break;
            case ')': {
                fprintf(ofd,"}");
            } break;
        }
        
    }

    fprintf(ofd, footer);
    fclose(ifd);
    fclose(ofd);
    
    return 0;
}