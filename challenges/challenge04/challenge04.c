#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 3

char FLAG_GUESS[600];

struct MenuItem {
   int   num;
   char *name;
   void (*func)(void);
};

void quit() {
   printf("Goodbye\n");
   exit(0);
}

void print_menu(struct MenuItem* items, char* title, int len) {

   printf("----[%s]----\n", title);
   for (int i = 0; i < len; i++) 
      printf("%d] %s\n", items[i].num, items[i].name);

   printf("-----------------------------\n");

}


char * read_flag() {
   int fd = open("./flag.txt", O_RDONLY);
   char *flag = malloc(100);
   memset(flag, 0, 100);
   if (fd < 0) {
      fprintf(stderr, "no flag.txt here, run against the server\n");
      return NULL;
   }
   char ch;

   int read_size = read(fd, &ch, 1);
   int i = 0;
   while (read_size) {
      flag[i++] = ch;
      read_size = read(fd, &ch, 1);
   }

   close(fd);
   return flag;
   
}

void enter_guess() {


   printf("Make sure your guess is in the proper format\n");
   printf("guess: ");
   scanf("%s", FLAG_GUESS);


   return;
}


void check_guess() {

   int x = 0xdeadbeef;
   int y = 0xc0ffedad;
   int res = 0;
   char decoy[100]; 
   char buf[100];


   strncpy(buf, read_flag(), 100);
   strncpy(decoy, "AAAAABBBBBCCCCC", 100);
   memcpy(decoy+14, &x, 4);
   memcpy(decoy+18, &y, 4);
   printf(FLAG_GUESS);
   putchar('\n');
   res = strncmp(FLAG_GUESS, buf, strlen(FLAG_GUESS));

   if (res != 0 ) {
      printf("Nope not the flag try again :)\n");
   } else {
      printf("How you do that!?\n");
      exit(0);
   }
   

}




int main() {

   struct MenuItem items[SIZE];

   items[0].num = 0;
   items[0].name = "Make Guess";
   items[0].func = &enter_guess;

   items[1].num = 1;
   items[1].name = "Check Guess";
   items[1].func = &check_guess;

   items[2].num = 2;
   items[2].name = "Quit";
   items[2].func = &quit;

   printf("This game is a little different\n");
   printf("if you can guess the flag i'll give it to you\n");
   printf("promise :), I have it behind my back\n\n\n");


   int ans = 0;

   while (1) {
      print_menu(items, "Welcome to the Game", SIZE);

      scanf("%d", &ans);
      fflush(stdin);

      if (ans < SIZE) {
         items[ans].func();
      } else {
         printf("Not an option!\n");
      }
   }



}
