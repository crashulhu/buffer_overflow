#include <stdio.h>

void run_me() {
   printf("You win!\n");
}

void challenge() {

   char buf[32];

   printf(">");
   gets(buf);

   return;
}


int main() {

   challenge();

}
