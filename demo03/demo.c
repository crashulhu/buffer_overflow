#include <stdio.h>


void challenge() {

   char buf[32];

   printf(">");
   gets(buf);

   return;
}


int main() {

   
   challenge();
   execve("/bin/sh", 0, 0);

}
