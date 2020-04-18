/* This program is for evaluation of prefix expression
 * This program assume that there are only four operators
 * (*, /, +, -) in an expression and operand is single digit only
 * Further this program does not do any error handling e.g.
 * it does not check that entered prefix expression is valid
 * or not.
 * */

 #include<stdio.h>
 #include<ctype.h>


 # define MAXSTACK 100        /* for max size of stack */
 # define prefixSIZE 100     /* define max number of charcters in prefix expression */

 /* declare stack and its top pointer to be used during prefix expression
	evaluation*/
 int stack[MAXSTACK];
 int top = -1 ;             /* because array index in C begins at 0 */
 /* can be do this initialization somewhere else */

 /* define push operation */
 void push(int item)
 {

	 if(top >= MAXSTACK -1)
	 {
		 printf("stack over flow");
		 return;
	 }
	 else
	 {
		 top = top + 1 ;
		 stack[top]= item;
	 }
 }

 /* define pop operation */
 int pop()
 {
	 int item;
	 if(top <0)
	 {
		printf("stack under flow");
	 }
	 else
	 {
		 item = stack[top];
		 top = top - 1;
		 return item;
	 }
 }

 /* define function that is used to input prefix expression and to evaluate it */
 void Evalprefix(char prefix[])
 {

	int i ;
	char ch;
	int val;
	int A, B ;


	/* evaluate prefix expression */
	for (i = 0 ; prefix[i] != ')'; i++)
	{
		ch = prefix[i];
		if (isdigit(ch))
		{
			/* we saw an operand,push the digit onto stack
			ch - '0' is used for getting digit rather than ASCII code of digit */
			push(ch - '0');
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			/* we saw an operator
			* pop top element A and next-to-top elemnet B
			* from stack and compute B operator A
			*/
			A = pop();
			B = pop();

			switch (ch) /* ch is an operator */
			{
				case '*':
				val = B * A;
				break;

				case '/':
				val = B / A;
				break;

				case '+':
				val = B + A;
				break;

				case '-':
				val = B - A;
				break;
			}

			/* push the value obtained above onto the stack */
			push(val);
		}
	}
	printf( " \n Result of expression evaluation : %d \n", pop()) ;
 }

 int main()
 {

	int i ;

	/* declare character array to store prefix expression */
	char prefix[prefixSIZE];
	printf("ASSUMPTION: There are only four operators(*, /, +, -) in an expression and operand is single digit only.\n");
	printf( " \nEnter postfix expression,\npress right parenthesis ')' for end expression : ");

	/* take input of prefix expression from user */

	for (i = 0 ; i <= prefixSIZE - 1 ; i++)
	{
		scanf("%c", &prefix[i]);

		if ( prefix[i] == ')' ) /* is there any way to eliminate this if */
		{ break; } /* and break statement */
	}

	/* call function to evaluate prefix expression */

	Evalprefix(prefix);
	
	return 0;
 }

