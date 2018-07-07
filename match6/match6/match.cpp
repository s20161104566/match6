#include "match.h"
int main()
{
	while (1)
	{
		switch (menu_select())
		{
		case 1:
			teacher_output();
			break;
		case 2:
			student_output();
			break;
		case 3:
			referee();
			break;
		case 4:
			display();
			break;
		case 5:
			ranking();
			break;
		case 0:
			save();
			printf("Thank you for using��\n");
			system("pause");
			return 0;
		}
	}
}
//�˵�ģ��
extern int menu_select()
{
	int MenuItem;
	printf("\n ");
	printf("         | ***********���ϵͳ*********** |          \n");
	printf("          | ------------------------------ |          \n");
	printf("          |            ���˵���            |          \n");
	printf("          | ------------------------------ |          \n");
	printf("          |	  1 --- ���������Ϣ       |          \n");
	printf("          |	  2 --- ���ѡ����Ϣ	   |          \n");
	printf("          |	  3 --- ���д�ֻ���	   |          \n");
	printf("          |	  4 --- ���ѡ�ֳɼ�	   |          \n");
	printf("          |	  5 --- ���ѡ������	   |          \n");
	printf("          |	  0 --- �˳�ϵͳ  	   |          \n");
	do
	{
		printf("\n������ѡ�0��5����");
		fflush(stdin);
		scanf("%d", &MenuItem);
	} while (MenuItem<0 || MenuItem>5);
	return MenuItem;
}
//������Ϣ���ģ��
extern void teacher_output()
{
	FILE *fp;
	int i;
	fp = fopen("teacher.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		printf(" ����  �Ա� �绰����\n");
		for (i = 0; i < 5; i++)
			fscanf(fp, "%s %s %ld\n", &t[i].name, &t[i].sex, &t[i].num);
		for (i = 0; i < 5; i++)
			printf("%2s %3s %8ld\n", t[i].name, t[i].sex, t[i].num);
	}
	fclose(fp);
}
//ѡ����Ϣ���ģ��
extern void student_output()
{
	FILE *fp;
	int i;
	fp = fopen("student.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		printf("���  ����   �Ա�  ��Ŀ���� ��� ��Ŀ���   �༶    �绰����\n");
		for (i = 0; i < 6; i++)
			fscanf(fp, "%d %s %s %s %s %s %s %ld\n", &s[i].snum, &s[i].name, &s[i].sex, &s[i].showname, &s[i].type, &s[i].showtype, &s[i].stuclass, &s[i].num);
		for (i = 0; i < 6; i++)
			printf("%3d %6s %4s %9s %3s %8s %10s %9ld\n", s[i].snum, s[i].name, s[i].sex, s[i].showname, &s[i].type, s[i].showtype, s[i].stuclass, s[i].num);
	}
	fclose(fp);
}
//���д��ģ��
extern void referee()
{
	float grade[10];
	float sum;
	int i, j, n, x;
	float temp;
	for (n = 0;n < 6;n++)
	{
		printf("---����� %d λѡ�ִ��---\n", s[n].snum);
		for (x = 0; x < 5; x++)
		{
			printf("��� %d λ���д��:\n", x + 1);
			scanf("%f", &grade[x]);
		}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (grade[j] > grade[j + 1])
				{
					temp = grade[j];
					grade[j] = grade[j + 1];
					grade[j + 1] = temp;
				}
			}
		}
		sum = 0;
		for (i = 1; i < 4; i++)
		{
			sum = sum + grade[i];
		}
		s[n].grade = sum / 3.0;
		printf("ƽ���ɼ���%.2f\n", s[n].grade);
	}
}
//��ʾѡ�ֳɼ�ģ��
extern void display()
{
	int i;
	printf("��� ����   �Ա�  ��Ŀ����  ���   ��Ŀ���   �༶    �绰����  ƽ���ɼ�\n");
	for (i = 0; i < 5; i++)
	{
		printf("%3d %6s %4s %9s %5s %9s %10s %9ld %8.2f\n", s[i].snum, s[i].name, s[i].sex, s[i].showname, &s[i].type, s[i].showtype, s[i].stuclass, s[i].num, s[i].grade);
	}
}
//��ʾѡ������ģ��
extern void ranking()
{
	int i, j;
	int x;
	struct Student t[100];
	struct Student temp;
	for (i = 0; i < 6; i++)
	{
		t[i] = s[i];
	}
	//����ѡ������
	//struct Student sing[100];
	x = 0;
	for (i = 0; i < 6; i++)
	{
		if (strcmp(t[i].type, "A") == 0)
		{
			sing[x] = t[i];
			x++;
		}
	}
	samount = x;
	for (i = 0; i < x - 1; i++)
	{
		for (j = 0; j < x - 1; j++)
		{
			if (sing[j].grade < sing[j + 1].grade)
			{
				temp = sing[j];
				sing[j] = sing[j + 1];
				sing[j + 1] = temp;
			}
		}
	}
	printf("----����������----\n");
	printf("��� ����   �Ա�  ��Ŀ���� ��� ��Ŀ���   �༶    �绰����  ƽ���ɼ�  ����\n");
	for (i = 0; i < x; i++)
	{
		printf("%3d %6s %4s %9s %3s %8s %10s %9ld %8.2f %5d\n", sing[i].snum, sing[i].name, sing[i].sex, sing[i].showname, &sing[i].type, sing[i].showtype, sing[i].stuclass, sing[i].num, sing[i].grade, i + 1);
	}
	//�赸ѡ������
	//struct Student dance[100];
	x = 0;
	for (i = 0; i < 6; i++)
	{
		if (strcmp(t[i].type, "B") == 0)
		{
			dance[x] = t[i];
			x++;
		}
	}
	damount = x;
	for (i = 0; i < x - 1; i++)
	{
		for (j = 0; j < x - 1; j++)
		{
			if (dance[j].grade < dance[j + 1].grade)
			{
				temp = dance[j];
				dance[j] = dance[j + 1];
				dance[j + 1] = temp;
			}
		}
	}
	printf("----�赸������----\n");
	printf("��� ����   �Ա�  ��Ŀ���� ��� ��Ŀ���   �༶    �绰����  ƽ���ɼ�  ����\n");
	for (i = 0; i < x; i++)
	{
		printf("%3d %6s %4s %9s %3s %8s %10s %9ld %8.2f %5d\n", dance[i].snum, dance[i].name, dance[i].sex, dance[i].showname, dance[i].type, dance[i].showtype, dance[i].stuclass, dance[i].num, dance[i].grade, i + 1);
	}
}
//����ģ��
int samount;
int damount;
extern void save()
{
	int i;
	FILE *fp;
	FILE *fw;
	fp = fopen("sing.txt", "w");
	fw = fopen("dance.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		for (i = 0; i<samount; i++)
		{
			fprintf(fp, "%d %s %s %s %s %s %s %ld %.2f %d\n", sing[i].snum, sing[i].name, sing[i].sex, sing[i].showname, &sing[i].type, sing[i].showtype, sing[i].stuclass, sing[i].num, sing[i].grade, i + 1);
		}
	}
	fclose(fp);
	if (fw == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		for (i = 0; i<damount; i++)
		{
			fprintf(fw, "%d %s %s %s %s %s %s %ld %.2f %d\n", dance[i].snum, dance[i].name, dance[i].sex, dance[i].showname, dance[i].type, dance[i].showtype, dance[i].stuclass, dance[i].num, dance[i].grade, i + 1);
		}
	}
	fclose(fp);
}