#include <stdio.h>

#include "stack.h"

#define LESS	'<'
#define GREAT	'>'
#define EQUAL	'='
#define UNKOWN	'0'

//虽然操作数的类型是整型，操作符的是字符型
//但字符型也是一种整型，因此这里就只用一种类型的栈，无需使用两种
typedef Stack nStack;
typedef Stack strStack;

bool Match(char ch, char str)
{		
	return  (ch == '(' && str == ')')
		 || (ch == '[' && str == ']')
		 ||	(ch == '{' && str == '}');
}

bool InOpSet(char ch, char *opset)
{
	for (char *p = opset; *p != '\0'; ++p)
		if (ch == *p) return true;

	return false;
}

char Priority(char x, char ch)
{
	switch(x)
	{
	case '+':
	case '-':
		return InOpSet(ch, "+-)#") ? GREAT : LESS;

	case '*':
	case '/':
		return InOpSet(ch, "(") ? LESS : GREAT;

	case '(':
		if (InOpSet(ch, "+-*/("))
			return LESS;	
		else if (InOpSet(ch, ")"))
			return EQUAL;	
		else if (InOpSet(ch, "#"))
			return UNKOWN;	
		break;

	case ')':
		if (InOpSet(ch, "+-*/)#"))
			return GREAT;	
		else if (InOpSet(ch, "("))
			return UNKOWN;	
		break;

	case '#':
		if (InOpSet(ch, "+-*/("))
			return LESS;	
		else if (InOpSet(ch, "#"))
			return EQUAL;	
		else if (InOpSet(ch, ")"))
			return UNKOWN;	
		break;
	}

	return UNKOWN;
}	

int Compute(int a, char op, int b)
{
	switch (op)
	{
	case '+':
		return a + b;

	case '-':
		return a - b;

	case '*':
		return a * b;

	case '/':
		return a / b;
	}

	return 0;
}

int ExprEval()
{
	int op;
	int a, b, v;
	char expr[128];
	char *ch = expr;
	
	nStack oprd; //操作数栈
	strStack optr; //操作符栈

	InitStack(&oprd);
	InitStack(&optr);
	Push(&optr, '#');
	
	printf("\nPlease input an expression (Ending with #) :\n");
	fgets(ch, 127, stdin);
 	
 	GetTop(&optr, &op);

 	while (*ch != '#' || op != '#')
   	{
		//注意：输入的字符串中不能有空格之类的东西
		//如果有，那么需要跳过这些空格，例如:' '、'\t'
		//请自行考虑如何跳过
		if (*ch >= '0' && *ch <= '9')
		{
			//将数字字符串转换为数
			int temp = 0;
			while (*ch >= '0' && *ch <= '9')
			{
				temp = temp * 10 + *ch - '0';
				++ch;
			}  
   			Push(&oprd, temp);
		}
		else
		{
      		switch (Priority(op, *ch))
			{
	 			case LESS: 
					Push(&optr, *ch); 
					++ch;
					break;

	 			case EQUAL: 
					Pop(&optr, &op); 
					++ch;
					break;

				case GREAT: 
					Pop(&optr, &op);
					Pop(&oprd, &b);
					Pop(&oprd, &a);
					v = Compute(a, op, b);
					Push(&oprd, v);
					break;
			}
		}

		GetTop(&optr, &op);
	}
	GetTop(&oprd, &v);

	ClearStack(&optr);
	ClearStack(&oprd);

	return v;
}

int main()
{
    printf("%d\n", ExprEval());

	return 0;
}