/* Write a program that takes a user's full name
 * (two and only two command line arguments).
 * Next, print out a greeting to the user that
 *         includes their first name
 */
 
 #include <cs50.h>
 #include <stdio.h>
 #include <string.h>
 
 int main(int argc, string argv[])
 {
     if (argc != 3)
     {
         return 1;
     }
     printf("hello %s\n", argv[1]);
 }
