#include<stdio.h>
#include<string.h>
#define VERSION "1.0.0"
unsigned char tape[30000];
short pointer = 0;
// Hard coded file length
// Gotta implement dynamic allocation later
char command[50000];
short code_pointer = 0;
short loop_start = -1;
short loop_end = -1;

// global controls
int repl_mode = 0;
int error = 0;
int match_opening_braces(int);
int match_closing_braces(int);
void usage(char []);
void copy_to_memory(FILE *);
void exec();
void repl();
int main(int argc, char *argv[]){
  FILE *fp;
  if (argc>2) {
    usage(argv[0]);
    return 1;
  } else if(argc == 2){
    if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")) {
      printf("%s\n", VERSION);
    } else if (!strcmp(argv[1], "--about")) {
      printf("Developer: Pramendra Sharma\nGithub: https://github.com/sharmarahul111\n" );
    } else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help") || argv[1][0] == '-') {
      usage(argv[0]);
    } else {
      fp = fopen(argv[1], "r");
      if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
      } else {
        copy_to_memory(fp);
      }
    }
  } else {
    //REPL
    repl_mode = 1;
    repl();
  }
  while(command[code_pointer]!='\0' && error==0){
    // printf("\nCode pointer at: %d[%c]", code_pointer, command[code_pointer]);
    exec();

    code_pointer++;
  }
  return 0;
}
void exec(){
  switch(command[code_pointer]){
    case '+':
      tape[pointer]++;
      break;
    case '-':
      tape[pointer]--;
      break;
    case '>':
      if (pointer!=30000) {
        pointer++;
      } else {
        printf("Error: Maximum tape length exceeded\n");
        error = 1;
      }
      pointer++;
      break;
    case '<':
      if(pointer>0){
        pointer--;
      } else {
        printf("Error: Tried to access negative memory block\n");
        error = 1;
        break;
      }
      break;
    case '.':
      printf("%c", tape[pointer]);
      break;
    case ',':
      scanf(" %c", &tape[pointer]);
      break;
    case '[':
      if (!tape[pointer]) {
        code_pointer = match_closing_braces(code_pointer);
      }
      break;
    case ']':
      if (tape[pointer]) {
        code_pointer = match_opening_braces(code_pointer);
        if (code_pointer<=0) {
          error = 1;
        }
      }
      break;
    default:
      ; // ignore
  }
}
void repl(){
  printf("Brainfuck %s, by Pramendra Sharma\n", VERSION);
  while(repl_mode){
    code_pointer = 0;
    printf(">>>");
    scanf(" %s", command);
    while(command[code_pointer]!='\0' && error==0){
      exec();

      code_pointer++;
    }
  }
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
    }else if (i<=0) {
      printf("Error: Couldn't find corresponding '['\n");
      error = 1;
      return i;
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
    }else if(command[i]=='\0'){
      if (!repl_mode) {
        printf("Error: Couldn't find corresponding ']'");
      }
      error = 1;
      return i;
    }
    i++;
  }
}
void usage(char program_name[]){
  printf("Usage:\n");
  printf("%s <file>   \texecute from a file\n", program_name);
  printf("%s          \trepl mode\n", program_name);
  printf("%s -h       \tsee usage\n", program_name);
  printf("%s --help   \tsee usage\n", program_name);
  printf("%s -v       \tversion number\n", program_name);
  printf("%s --version\tversion number\n", program_name);
  printf("%s --about  \tabout author\n", program_name);

}

void copy_to_memory(FILE *fp){
  int c;
  int i=0;
  while(1){
    c = fgetc(fp);
    if (c == EOF) {
      command[i] = '\0';
      break;
    }
    command[i] = c;
    i++;
  }
}

