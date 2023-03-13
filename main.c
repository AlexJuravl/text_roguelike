#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct weapon
{
    int level;
    char name[20];
    int damage;
    int hit_chance; //шанс попасть при замахе (в процентах)
};

struct enemy
{
    int level;
    char name[20];
    int damage;
    int hit_chance;
};

struct armor
{
    int level;
    char name[20];
    int protect_amount; //процент поглощаемого урона
};

int main()
{
    int a;
    a = rand();

    printf("Bla bla bla\n");

    sleep(5);

    printf("a = %d", a);
}