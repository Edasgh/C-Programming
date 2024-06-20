#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Rock,paper,scissors game in c
three choices : 0. Rock ,1. Paper and 2. Scissor
First user chooses any of these choices
and computer chooses randomly (generate a random number between 0 to 2)

Rock vs Paper => Paper wins, //same as paper & rock
Rock vs Scissor => Rock Wins,
Paper vs Scissor => Scissor wins,

so, the winning combinations of Rock will be: {0,2},{2,0}
so, the winning combinations of Paper will be: {0,1},{1,0}
so, the winning combinations of Scissor will be: {1,2},{2,1}


 */