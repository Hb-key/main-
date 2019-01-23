#ifndef __CommentConvert_H__
#define __CommentConvert_H__


#include<stdio.h>
#include<stdlib.h>

typedef enum State
{
	NUL_state,
	C_state,
	Cpp_state,
	End_state
}State;

//调用函数
void CommentConvert(FILE *pRead, FILE *pWrite);
void DO_Cpp_state(FILE *pRead, FILE *pWrite, State *state);
void Do_C_state(FILE *pRead, FILE *pWrite, State *state);
void Do_NUL_state(FILE *pRead, FILE *pWrite, State *state);

#endif   // __CommentConvert_H__   
