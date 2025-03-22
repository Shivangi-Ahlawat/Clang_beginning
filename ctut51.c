#include <stdio.h> //rock paper scissor game
#include <stdlib.h>
#include <time.h> //random number generation

int generaterandomnumber(int n)// random number generation
{
     srand(time(NULL)); // srand takes seed as a input
     return rand() % n;
}

int greater(char c1, char c2)
{
     if (c1 == c2)
     {
          return 0;
     }
     else if ((c1 == 'r') && (c2 == 's'))
     {
          return 1;
     }
     else if ((c1 == 'r') && (c2 == 'p'))
     {
          return -1;
     }
     else if ((c1 == 'p') && (c2 == 's'))
     {
          return -1;
     }
     else if ((c1 == 'p') && (c2 == 'r'))
     {
          return 1;
     }
     else if ((c1 == 's') && (c2 == 'r'))
     {
          return -1;
     }
     else if ((c1 == 's') && (c2 == 'p'))
          return 1;
}

int main()
{
     int temp, playerscore = 0, comscore = 0;
     char playerchar, comchar;
     int age;
     char name[52];
     char dict[] = {'r', 'p', 's'};

     printf("Welcome to the rock paper scissors.\n");
     printf("Choose 1 for rock, 2 for paper, 3 for scissors\n");
     printf("Enter your age\n");
     scanf("%d",&age);
     getchar();
     printf("Enter your name\n");
     scanf("%[^\n]s", name);

     for (int i = 0; i < 3; i++)
     {
          printf("%s's turn:\n", name);
          scanf("%d", &temp);
          playerchar = dict[temp - 1];
          printf("%s chooses %c\n", name, playerchar);

          if (temp < 1 || temp > 3)
          {
               printf("Invalid choice! Choose 1, 2, or 3.\n");
               i--;
               continue;
          }

          printf("Computer's turn:\n");
          temp = generaterandomnumber(3);
          comchar = dict[temp];
          printf("Computer chooses %c\n", comchar);

          if (greater(comchar, playerchar) == 1)
          {
               printf("Computer wins\n");
               comscore += 1;
          }
          else if (greater(comchar, playerchar) == -1)
          {
               printf("%s wins\n", name);
               playerscore += 1;
          }
          else
          {
               printf("Draw\n");
               continue; // no change
          }
     }

     printf("\n\n");
     if (comscore > playerscore)
     {
          printf("Computer wins\n");
     }
     else if (comscore < playerscore)
     {
          printf("%s wins\n", name);
     }
     else if (comscore == playerscore)
     {
          printf("Draw\n");
     }

     return 0;
}
