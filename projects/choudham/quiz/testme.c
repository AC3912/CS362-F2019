//Amena Choudhury
//CS362 Random Testing Quiz
//testme.c
//Implement random tester for
//the function testeme()


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    char c; //define char variable
    c = rand()%127; //generate random character 
    return c; //return randomly generated character
}

char *inputString()
{
    // TODO: rewrite this function
    int r; 
    static char s[6]; //random string stored in static array

    //Determines value of each position in string based on 
    //what the random value generated is  
    for(int i=0; i<6; i++){
	r=rand()%6;
	if(r==0){ 
    	    s[i] = 'r';
        }
        else if(r==1){ 
    	    s[i] = 'e';
    	}
        else if(r==2){ 
    	    s[i] = 's';
    	}
        else if(r==3){ 
    	    s[i] = 'e';
    	}
        else if(r==4){ 
    	    s[i] = 't';
    	}
        else if(r==5){ 
    	    s[i] = '\0';
    	}
    }

    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
