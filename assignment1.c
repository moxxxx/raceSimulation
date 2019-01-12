#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_POS 70
#define MAX_STR 32
#define TRUE     1
#define FALSE    0
#define MAX_NUM 10

int  randomInt(int);
void printPosition(char * array);
void setPosition(char * path, int positionH,int positionT);
int  tortMove(int random, int position);
int  hareMove(int random, int position);
int  gameover(int positionH, int positionT);



int main()
{
  char  path[MAX_POS];
  int   positionT = 0;
  int   positionH = 0;
  srand(time(NULL));

  while(1){
    positionH = hareMove(randomInt(MAX_NUM),positionH);
    positionT = tortMove(randomInt(MAX_NUM),positionT);
    setPosition(path, positionH,positionT);
    //fill the path array

    //print position
    printPosition(path);

    //see if someone win
    if (gameover(positionH,positionT) == 1)break;
  }
  return 0;
}


/*
  Function:  randomInt
  Purpose:   returns a random number in the range [0,max)
  Parameters:
    in:      maximum of range
    return:  randomly generated number
*/

int randomInt(int max)
{
  return(rand() % max);
}

/*
  Function:  printPosition
  Purpose:   print the positions of competitors and the path onto console
  Parameters:
    in:      array of position to be printed
*/
void printPosition(char * array){
  printf("|");
  for (int i = 0; i < MAX_POS; ++i){
    printf("%c",array[i]);
  }
  printf("|\n");
}

/*
  Function:  tortMove
  Purpose:   returns the position of Tortoise after made a random move.
Randomness should depends on instruction on chartA. Any invalid movement
should be adjusted

  Parameters:
    in:      a random Integer range from[0,9]
    in:      Integer representing the previous position of Tortoise
    return:  Integer representing the current position of Tortoise
*/
int  tortMove(int random, int position){
  if (random<5){// fast plod
    position +=3;
  }else if(random<8){//slow plod
    position++;
  }else{//slip
    position -=6;
  }
  if (position <= 0) return 0;// in real world situation, animals can only fail on the ground
  if (position >= 70) return 69;// if it exceeds #69, treated as it reach the moutain top
  return position;
}

/*
  Function:  hareMove
  Purpose:   returns the position of Hare after made a random move.
Randomness should depends on instruction on chartA. Any invalid movement
should be adjusted.

  Parameters:
    in:      a random Integer range from[0,9]
    in:      Integer representing the previous position of Hare
    return:  Integer representing the current position of Hare
*/
int  hareMove(int random, int position){
  if (random<2){//big hop
    position +=9;
  }else if(random<5){//small hop
    position++;
  }else if(random<6){//big slip
    position -=12;
  }else if(random<8){//small slip
    position -=2;
  }// do nothing if sleep
  if (position <= 0) return 0;// in real world situation, animals can only fail on the ground
  else if (position >= 70) return 69;// if it exceeds #69, treated as it reach the moutain top
  return position;
}

/*
  Function:  gameover
  Purpose:   Decide whether should end the race. Claim the winner of the race.

  Parameters:
    in:      Integer indicating the Hare's position
    in:      Integer indicating the Tortoise's position
    return:  integer indicating whether the race is over
*/
int gameover(int positionH, int positionT){
  if (positionH == 69 && positionT == 69){
    printf("Tie!\n");
    return 1;
  }else if(positionH == 69) {
    printf("Winner is Harold!!!\n");
    return 1;
  }else if (positionT == 69){
    printf("Winner is Timmy!!!\n");
    return 1;
  }
  return 0;
}

/*
  Function:  setPosition
  Purpose:   updated the new position of competitors in path array

  Parameters:
    in&out:  Array representing the position of competitors and path
    in:      Integer indicating the Hare's position
    in:      Integer indicating the Tortoise's position

*/
void setPosition(char * path, int positionH,int positionT){
  for (int i = 0; i< MAX_POS;++i){
    if (i == positionH && i == positionT){
      path[i] = 'B'; //competitors are in same position
    }else if (i == positionH){
      path[i] = 'H';
    }else if (i == positionT){
      path[i] = 'T';
    }else{
      path[i] = ' ';
    }
  }
}
