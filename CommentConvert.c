#define _CRT_SECURE_NO_WARNINGS
#include"CommentConvert.h"

void CommentConvert(FILE *pRead, FILE *pWrite)
{
	State state = NUL_state;
	while (state != End_state)
	{
		switch (state)
		{
		case NUL_state:
			Do_NUL_state(pRead, pWrite, &state);
			break;
		case C_state:
			Do_C_state(pRead, pWrite, &state);
			break;
		case Cpp_state:
			DO_Cpp_state(pRead, pWrite, &state);
			break;
		}
	}
}

void Do_NUL_state(FILE *pRead, FILE *pWrite, State *state)
{
	int first = fgetc(pRead);
	switch (first)
	{
		case '/':
		{
			int second = fgetc(pRead);
			switch (second)
			{
				case '*':
				{
					fputc('/', pWrite);
					fputc('/', pWrite);
					*state = C_state;
				}
				break;
				case '/':
				{
					fputc(first, pWrite);
					fputc(second, pWrite);
					*state = C_state;
				}
				break;
				default:
				{
					fputc(first, pWrite);
					ungetc(second, pRead);
				}
				break;
			}
		}
		break;
		case EOF :
		{
			 *state = End_state;
		}
			break;
		default:
		{
			fputc(first, pWrite);
		}
			break;
	}
}

void Do_C_state(FILE *pRead, FILE *pWrite, State *state)
{
	int first = fgetc(pRead);
	switch (first)
	{
		case '*':
		{
			int second = fgetc(pRead);
			switch (second)
			{
				case'/':
				{
					int third = fgetc(pRead);
					if (third == '\n')
					{
						fputc(third, pWrite);
					}
					else
					{
						fputc('\n', pWrite);
						ungetc(third, pRead);
					}
					*state = NUL_state;
				}
				break;
				case '*':
				{
					fputc(first, pWrite);
					ungetc(second, pRead);
				}
				break;
				default:
				{
					fputc(first, pWrite);
					ungetc(second, pRead);
				}
				break;
			}
		break;
		}
		case'\n':
		{
			fputc(first, pWrite);
			fputc('\n', pWrite);
			fputc('\n', pWrite);
		}
			break;
		default:
		{
			fputc(first, pWrite);
		}
		break;
	}
}

void DO_Cpp_state(FILE *pRead, FILE *pWrite, State *state)
{
	int first = fgetc(pRead);
	switch (first)
	{
		case'\n':
		{
			fputc(first, pWrite);
			*state = NUL_state;
		}
			break;
		case EOF:
		{
			*state = End_state;
		}
		break;
		default:
		{
			fputc(first, pWrite);
		}
		break;
	}
}