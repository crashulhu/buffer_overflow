#include <stdio.h>

void run_me() {
   printf("You win!\n");
}

void challenge() {

   int check = 0;
   char buf[32];

   printf(">");
   gets(buf);

   if (check > 0 ) {
      run_me();
   }

   return;
}


int main() {

   challenge();

}
