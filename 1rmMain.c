#include <stdio.h>
#include <string.h>
#include <math.h>
#include "1rm.h"

#define newline() printf("\n")
#define clear() printf("\033[H\033[J")
void oneRMscreen(struct oneRMrecord* oneRMRec);
void mainScreen();
void controller(int selection);

int main(void)
{
	struct oneRMrecord oneRMRec;
	oneRMscreen(&oneRMRec);

	return 0;
}

void oneRMscreen(struct oneRMrecord* oneRMRec)
{
	float weight;
	int reps;
	char exercise[20];
	printf ("Enter Exercise Name :");
	scanf("%[^\n^\t]s", exercise);
	printf("Enter Amount of Weight: ");
	scanf("%f",&weight);
	printf("Enter Amount of Reps: ");
	scanf("%d", &reps);
	newline();
   
	calc1RMweighted(exercise,weight,reps,oneRMRec);
	printf("1RM Formulas for %s\n",oneRMRec->exercise);
	printf("Brzycki : %f\n",oneRMRec->brzycki);
	printf("Eppley  : %f\n",oneRMRec->eppley);
	printf("Landers : %f\n",oneRMRec->landers);
	printf("Lomardi : %f\n",oneRMRec->lombardi);
	newline();
	printf("1RM Percentiles for %s @ %d\n",oneRMRec->exercise,oneRMRec->max);
	printf("95%%  %d\n",oneRMRec->percentiles._95);
	printf("90%%  %d\n",oneRMRec->percentiles._90);
	printf("85%%  %d\n",oneRMRec->percentiles._85);
	printf("80%%  %d\n",oneRMRec->percentiles._80);
	printf("75%%  %d\n",oneRMRec->percentiles._75);
	printf("70%%  %d\n",oneRMRec->percentiles._70);
	printf("65%%  %d\n",oneRMRec->percentiles._65);
	printf("60%%  %d\n",oneRMRec->percentiles._60);
	printf("95%%  %d\n",oneRMRec->percentiles._55);
	printf("90%%  %d\n",oneRMRec->percentiles._50);
	newline();
}

void mainScreen()
{
	int selection;
	printf("1. Calculate 1RM for an Exercise\n");
	printf("2. Save to File");
	printf("3. Exit App");
	scanf("%d",&selection);
}

void controller(int selection)
{
	switch(selection)
	{
		case 1: mainScreen();
			break;
	
	}


}	