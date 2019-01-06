#pragma once
#include<stdio.h>
#include<string.h>
#define info 100

struct student
{
	char num[20];
	char name[20];
	char spec[20];
	int  score;
	char sex[20];
};

void Logic(struct student *s);
void Entry(struct student *s);
void Modify(struct student *s);
void Delete(struct student *s);
void Search(struct student *s);
void Print(struct student *s);
void Number(struct student *s);
void Score(struct student *s);