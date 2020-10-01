#include<stdio.h>
#include<ctype.h>




#include<string.h>




#include<stdlib.h>


char stack[100];



int top=-1;



int size=99;









                                                 void push(char item)
{
    if(top>size)


        {
        printf("stack full");
        }


    else


        {
        top=top+1;
        stack[top]=item;
        }


}











                                               char pop()


{
	char item ;

	if(top <0)
	{
		printf("empty stack");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

                                int operatorcheck(char symbol)
{
	if(   symbol == '-'
       || symbol == '/'
       || symbol == '*'
       || symbol == '+'
       || symbol =='^')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedencecheck(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' )
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}

	else if(symbol == '/' )
	{
		return(2);
	}

	else
	{
		return(0);
	}
}
void InfixToPostfix(char infixexp[], char postfixexp[])
{
	int i, j;
	char item;
	char x;

	push('(');
	strcat(infixexp,")");
	i=0;
	j=0;
	item=infixexp[i];
while(item != '\0')
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfixexp[j] = item;
			j++;
		}
		else if(operatorcheck(item) == 1)
		{
			x=pop();
			while( precedencecheck(x)>= precedencecheck(item))
			{
				postfixexp[j] = x;
				j++;
				x = pop();
			}
			push(x);


			push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfixexp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\n!!!!!!ERROR!!!!!!.\n");
			getchar();
			exit(1);
		}
		i++;


		item = infixexp[i];
	}
	if(top>size)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}

	postfixexp[j] = '\0';

}
int main()
{printf("\n***************CONVERTER***************\n");
	while(1)
    {int a=1;
    printf("\nQuestion 1:\n");
    a++;


	char infix[100];
	char postfix[100];

	printf("\nEnter infix expression : ");

	gets(infix);

	InfixToPostfix(infix,postfix);
	printf("\nAnswer:\n");
	printf("postfix expression: ");

	int b,i;
	b=strlen(postfix);
	for(i=0;i<b;i++)
    {
        printf("%c",postfix[i]);
    }printf("\n\n");
    }



}







