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

char *enter_name() {

   char* name = malloc(100);

   printf("Enter name:\n");
   scanf("%40s", name);
   if (strlen(name) > 40) {
      printf("Nice try, not gonna work this time >:)");
      printf("I'll just cut it off");
   }

   return name;
}

int enter_age() {

   int age; 

   printf("Enter age:\n");
   scanf("%10d", &age);

   return age;
}

void magic_word() {

   char magic_word[20];

   printf("whats the magic word?\n> ");
   scanf("%s", magic_word);

   printf("hmmm Nope! :3\n");

}


void play() {

   char *name = enter_name();
   int age    = enter_age();

   struct MenuItem items[2];

   items[0].num = 0;
   items[0].name = "print flag";
   items[0].func = &magic_word;

   items[1].num = 1;
   items[1].name = "give up";
   items[1].func = &quit;

   int ans = 0;

   while (1) {
      print_menu(items, name, 2);

      scanf("%d", &ans);
      fflush(stdin);

      if (ans < SIZE) {
         items[ans].func();
      } else {
         printf("Not an option!\n");
      }
   }


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
      fflush(stdin);

      if (ans < SIZE) {
         items[ans].func();
      } else {
         printf("Not an option!\n");
      }
   }



}
