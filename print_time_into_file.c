#include<stdio.h>
#include<time.h> /*time() ctime()*/
#include<unistd.h> /* usleep() */

int main(int argc,char* argv[]){

   char* formatted_time;
   time_t current_time;
   FILE* time_writer = fopen("time_log.txt", "w");
   if(!time_writer){
       fprintf(stderr, "Error: Unable to open file.\n");
   }
   while(1){
       current_time = time(NULL);
       formatted_time = ctime(&current_time);
       fprintf(time_writer, "%s\n", formatted_time);
       fprintf(stdout,"%s-Successfully written...\n",formatted_time );
       usleep(10 * 1000000);
   }
   fclose(time_writer);
   return 0;
}
