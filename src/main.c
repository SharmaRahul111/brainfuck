#include<stdio.h>

int main(){
    unsigned char tape[30000];
    unsigned short int pointer = 0;
    char command[1000] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++";
    unsigned short int code_pointer = 0;
    while(command[code_pointer]!='\0'){
        switch(command[code_pointer]){
            case '+':
                tape[pointer]++;
                break;
            case '-':
                tape[pointer]--;
                break;
            case '>':
                pointer++;
                break;
            case '<':
                pointer--;
                break;
            case '.':
                printf("%c", tape[pointer]);
            case ',':
                scanf("%d", &tape[pointer]);
            case '[':
                // will implement later
                break;
            case ']':
                // later
                break;
            default:
                ; // ignore
        }
    }
    return 0;
}