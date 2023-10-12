#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 2

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

void play() {
   char buf[40];
   printf("Error!Error!Error!Error!Error!Error!Error!Error!Error!\n");
   printf("Challenge03 is defective!\n");
   printf("Please send error to CTF organziers\n");

   gets(buf);

   printf("Thank you\n");
   
   return;

}

int main() {

   struct MenuItem items[SIZE];

   items[0].num = 0;
   items[0].name = "Play";
   items[0].func = &play;

   items[1].num = 1;
   items[1].name = "Quit";
   items[1].func = &quit;

   int ans = 0;

   while (1) {
      print_menu(items, "Welcome to the Game", SIZE);

      scanf("%d", &ans);
      fflush(stdout);
      getchar();

      if (ans < SIZE) {
         items[ans].func();
      } else {
         printf("Not an option!\n");
      }
   }



}
