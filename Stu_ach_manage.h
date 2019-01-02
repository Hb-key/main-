#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define t 100

void Logic(struct student *s);
void Entry(struct student *s);
void Modify(struct student *s);
void Delete(struct student *s);
void Search(struct student *s);
void Print(struct student *s);
void number(struct student *s);
void classes(struct student *s);

struct student
{
	char num[20];
	char name[20];
	char spec[20];
	int  grade;
	char sex[20];
};