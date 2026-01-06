#include<stdio.h>
unsigned char tape[3000];
short pointer = 0;
char command[100] = "++++++++++++++++++++++++++++++++++";
// char command[100] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++";
short code_pointer = 0;
short loop_start = -1;
short loop_end = -1;

int match_opening_braces(short i);
int match_closing_braces(short i);
void error(int code);
int main(){
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
        scanf("%c", &tape[pointer]);
      case '[':
        if (!tape[pointer]) {
          code_pointer = match_closing_braces(code_pointer);
        }
        break;
      case ']':
        if (tape[pointer]) {
          code_pointer = match_opening_braces(code_pointer);
        }
        break;
      default:
        ; // ignore
    }
    code_pointer++;
  }
  return 0;
}

int match_opening_braces(short index){
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
    }else if (command[i]=='\0') {
      error(1);
    }
    i++;
  }
}

int match_closing_braces(short index){
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
    }else if(i<0){
      error(1);
    }
    i--;
  }
}
