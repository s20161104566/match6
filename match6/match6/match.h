
#ifndef _STUDENT
#define _STUDENT

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <iostream>

struct Teacher
{
	char name[10];
	char sex[5];
	long num;
};
struct Teacher t[100];
struct Student
{
	int snum;
	char name[10];
	char sex[5];
	char showname[30];
	char type[3];
	char showtype[5];
	char stuclass[10];
	long num;
	float grade;
};
struct Student s[100];
struct Student sing[100];
struct Student dance[100];
extern int samount;
extern int damount;
extern int menu_select();
extern void teacher_output();
extern void student_output();
extern void referee();
extern void display();
extern void ranking();
extern void save();
#endif
