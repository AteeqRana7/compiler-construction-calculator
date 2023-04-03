%{
  #include<stdio.h>
  int flag=0;
%}
  
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%nonassoc UMINUS  
%%
  
ArithmeticExpression: E{
         printf("\nResult=%d\n", $$);
         return 0;
        };
 E:E'+'E {$$=$1+$3;}
 |E'-'E {$$=$1-$3;}
 |E'*'E {$$=$1*$3;} 
 |E'/'E { if($3 == 0)
 			yyerror("divide by zero");
 	  else
               $$=$1/$3;
        }
 |'('E')' {$$=$2;}
 |'-'E %prec UMINUS {$$=-$2;}  
 | NUMBER {$$=$1;}
 ;
%%
  
 
void main()
{
   printf("\nEnter Your Arithmetic Expression:\n");
   yyparse();
   if(flag==0)
   		printf("\nValid Arithmetic Expression.\n\n");
}
  
void yyerror()
{
   flag=1;
   printf("\nThe Arithmetic Expression is not correct\n\n");
}
