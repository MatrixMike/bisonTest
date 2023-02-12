/* Lexical analyzer returns a double floating point 
   number on the stack and the token NUM, or the ASCII
   character read if not a number.  Skips all blanks
   and tabs, returns 0 for EOF. */

#include <ctype.h>
#include <stdio.h>
double   yylval ;  // added to permit compilation
int yylex ()  // check return type
{
  int c;

  /* skip white space  */
  while ((c = getchar ()) == ' ' || c == '\t')  
    ;
  /* process numbers   */
  if (c == '.' || isdigit (c))                
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval);
    //   return NUM;// commented to see other errors
    }
  /* return end-of-file  */
  if (c == EOF)                            
    return 0;
  /* return single chars */
  return c;                                
}
