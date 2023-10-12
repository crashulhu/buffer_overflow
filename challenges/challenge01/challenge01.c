#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 2

void print_flag() {
   int fd = open("./flag.txt", O_RDONLY);
   if (fd < 0) {
      fprintf(stderr, "no flag.txt here, run against the server\n");
      return;
   }
   char ch;

   
   int read_size = read(fd, &ch, 1);
   while (read_size) {
      putchar(ch);
      read_size = read(fd, &ch, 1);
   }

   close(fd);
   
}


void win() {
   printf("You win!\n");
   print_flag();

   exit(0);
}

void play() {

   int number_found = 0;
   char name[30];
   srand(time(NULL));
   int random_number = rand();
   int random_guess;

   printf("Enter name:\n");
   scanf("%s", name);

   printf("Can you guess what I'm thinking? :3\n");
   printf("Guess a number: ");
   scanf("%20d", &random_guess);

   if (random_guess == random_number) 
      number_found = 1;

   if (number_found) {
      printf("Wow you got it good job :0\n");
      win();
   } else {
      printf("Haha nope! better luck next time\n");
      exit(0);
   }

}

void quit() {
   printf("Goodbye\n");
   exit(0);
}

struct MenuItem {
   int   num;
   char *name;
   void (*func)(void);
};


void print_menu(struct MenuItem* items, int len) {

   printf("----[Welcome to the Game]----\n");
   for (int i = 0; i < len; i++) 
      printf("%d] %s\n", items[i].num, items[i].name);

   printf("-----------------------------\n");

}


int main() {

   struct MenuItem items[SIZE];

   items[0].num = 1;
   items[0].name = "Guessing Game";
   items[0].func = &play;

   items[1].num = 2;
   items[1].name = "Quit";
   items[1].func = &quit;

   int ans = 0;

   while (1) {
      print_menu(items, SIZE);

      scanf("%10d", &ans);
      fflush(stdin);



      if (ans <= SIZE && ans > 0) {
         items[ans-1].func();
      } else {
         printf("Not an option!\n");
      }
   }


   





}
