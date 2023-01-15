#include <stdio.h>
#include "simpio.h"

typedef struct
{
    int width;
    int height;
    int depth;
    int area;
    int volume;
} box;

box readData(box a_box);
void calc_box_area(box *a_box);
void calc_box_volume(box *a_box);

int main()
{
    box a_box;

    a_box=readData(a_box);

    calc_box_area(&a_box);
    calc_box_volume(&a_box);

    printf("To emvadon tou koutiou einai %d cm2\n", a_box.area);
    printf("O ogos tou koutiou einai %d cm3\n", a_box.volume);

    return 0;
}

box readData(box a_box)
{
	printf("Dose to mikos tou koutiou se cm: ");
	a_box.width=GetInteger();
	printf("Dose to ypsos tou koutiou se cm: ");
	a_box.height=GetInteger();
	printf("Dose to vathos tou koutiou se cm: ");
	a_box.depth=GetInteger();
	a_box.area=0;
	a_box.volume=0;
	return a_box;
}

void calc_box_area(box *a_box)
{
    (*a_box).area = 2*((*a_box).width * (*a_box).depth + (*a_box).width * (*a_box).height + (*a_box).depth * (*a_box).height);
}

void calc_box_volume(box *a_box)
{
    (*a_box).volume = (*a_box).width * (*a_box).height * (*a_box).depth;
}

/*Μπορεί εναλλακτικά να χρησιμοποιηθεί και ο παρακάτω τρόπος

void calc_box_area(box *a_box)
{
    a_box->area = 2*(a_box->width * a_box->depth + a_box->width * a_box->height + a_box->depth * a_box->height);
}

void calc_box_volume(box *a_box)
{
    a_box->volume = a_box->width * a_box->height * a_box->depth;
}

*/
