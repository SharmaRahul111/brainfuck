#include<stdio.h>
unsigned char tape[90];
short pointer = 0;
// char command[500] = "++++++[>++++++<-]>.";
// char command[100] = "++++++++++++++++++++++++++++++++++....";
// char command[500] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++";
// char command[500]=",+.>,+++.";
// char command[500] = "+>>+++++++++++++++++++++++++++++<<[>>>[>>]<[[>>+<<-]>>-[<<]]>+<<[-<<]<]>+>>[-<<]<+++++++++[>++++++++>+<<-]>-.----.>.";
char command[100]="++++++++[>++++++++++++<-]>+.";
short code_pointer = 0;
short loop_start = -1;
short loop_end = -1;

int match_opening_braces(int);
int match_closing_braces(int);
void error(int code);
int main(){
  while(command[code_pointer]!='\0'){
    // printf("\nCode pointer at: %d[%c]", code_pointer, command[code_pointer]);
    switch(command[code_pointer]){
      case '+':
        tape[pointer]++;
        // printf("\n[Increment value to %d[%d]", pointer, tape[pointer]);
        break;
      case '-':
        tape[pointer]--;
        // printf("\n[Decrement value to %d]", pointer);
        break;
      case '>':
        pointer++;
        // printf("\n[Increment pointer to %d]", pointer);
        break;
      case '<':
        pointer--;
        // printf("\n[Decrement pointer to %d]", pointer);
        break;
      case '.':
        // printf("\n[Output:%d]", tape[pointer]);
        printf("%c", tape[pointer]);
        break;
      case ',':
        // printf("\n[Input:]");
        scanf(" %c", &tape[pointer]);
        // printf("\n[Got:%d]", tape[pointer]);
        break;
      case '[':
        if (!tape[pointer]) {
          code_pointer = match_closing_braces(code_pointer);
          // printf("\nNeeds code jump");
        }
        break;
      case ']':
        if (tape[pointer]) {
          code_pointer = match_opening_braces(code_pointer);
          // printf("\nNeeds code jump");
        }
        break;
      default:
        ; // ignore
    }
    code_pointer++;
  }
  return 0;
}

int match_opening_braces(int index){
  int nesting = 0;
  int i=index-1;
  while(1){
    if (command[i]==']') {
      nesting++;
    } else if(command[i]=='['){
      if (nesting) {
        nesting--;
      }else{
        return i;
      }
    }else if (command[i]=='\0') {
      error(1);
    }
    i--;
  }
}

int match_closing_braces(int index){
  int nesting = 0;
  int i=index+1;
  while(1){
    if (command[i]=='[') {
      nesting++;
    } else if(command[i]==']'){
      if (nesting) {
        nesting--;
      }else{
        return i;
      }
    }else if(i<0){
      error(1);
    }
    i++;
  }
}
