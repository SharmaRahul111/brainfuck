#include<stdio.h>
#include<string.h>
#define VERSION "1.0.0"
unsigned char tape[30000];
short pointer = 0;
// char command[500] = "++++++[>++++++<-]>.";
// char command[100] = "++++++++++++++++++++++++++++++++++....";
// char command[500] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++";
// char command[500]=",+.>,+++.";
// char command[500] = "+>>+++++++++++++++++++++++++++++<<[>>>[>>]<[[>>+<<-]>>-[<<]]>+<<[-<<]<]>+>>[-<<]<+++++++++[>++++++++>+<<-]>-.----.>.";
// char command[100]="++++++++[>++++++++++++<-]>+.";
// Hard coded file length
// Gotta implement dynamic allocation later
char command[1000];
short code_pointer = 0;
short loop_start = -1;
short loop_end = -1;

int match_opening_braces(int);
int match_closing_braces(int);
void usage(char []);
void error(int code);
void copy_to_memory(FILE *);
int main(int argc, char *argv[]){
  FILE *fp;
  if (argc>2) {
    usage(argv[0]);
    return 1;
  } else if(argc == 2){
    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help") || argv[1][0] == '-') {
      usage(argv[0]);
    } else if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")) {
      printf("%s\n", VERSION);
      return 0;
    } else {
      fp = fopen(argv[1], "r");
      if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
      } else {
        copy_to_memory(fp);
        return 0;
      }
    }
  }
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
void usage(char program_name[]){
  printf("Usage:\n");
  printf("%s filename \texecute from a file\n", program_name);
  printf("%s          \trepl mode\n", program_name);
  printf("%s -h       \tsee usage\n", program_name);
  printf("%s --help   \tsee usage\n", program_name);
  printf("%s -v       \tversion number\n", program_name);
  printf("%s --version\tversion number\n", program_name);

}

void copy_to_memory(FILE *fp){
  int c;
  int i=0;
  while(1){
    c = fgetc(fp);
    if (c == EOF) {
      break;
    }
    printf("%c", c);
  }
}
