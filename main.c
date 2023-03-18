#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int player_health = 100;
int menu_type = 0;

int floor = 1;
int room = 1;
int level = 1;

struct weapon arr_weapons_all[4] = {arr_weapons1, arr_weapons2, arr_weapons3, arr_weapons4};

void generateFloor()
{
    struct chest arr_chests[10];
    struct enemy arr_enemies[10];

    for (int i = 0; i < 2; i++){
            arr_chests[i].level = myRand(0, level+1);
            sleep(1);
        }

        int e_last = myRand(0, level);
        if (e_last > 0){
            for (int e = 0; e < e_last; e++){
                arr_enemies[i]
            }
        }
}

int clampInteger(int value, int min, int max)
{
    int return_value;
    if (value < min){
        return_value = min;
    }
    else if (value > max){
        return_value = max;
    }
    else { return_value = value; }
    return return_value;
}


int myRand(int min, int max)
{
    srand(time(NULL));
    int a = 0;
    do{
        a = rand()%(max+1);
    } while (a < min || a > max);

    return a;
    
}

void looseCondition()
{
    if (player_health <= 0){
        printf("Player Died\n");
    }
}

void menu(int type)
{
    // 0 - main menu
    printf("My Roguelike!!!\n");
    int pass = 0;
    while (pass == 0){
        pass = 1;
        int input = -1;
        printf("====================\n1 - Start Game\n2 - Quit Game\n====================\n");

        while (input == -1) {
            input = getch();
            input -= 48;
            //printf("%d\n", input);
        }

        if (input == 1){
            printf("Game Started!\n");
        }
        else if (input == 2){
            printf("Game Quited\n");
        }
        else{
            pass = 0;
            printf("I don't understand you.\n");
        }
    }
}

struct weapon
{
    int type; // 0-sword; 1-bow; 2-axe
    int level;
    char name[100];
    int damage;
    int hit_chance; //шанс попасть при замахе (в процентах)
};

struct enemy
{
    int level;
    char name[100];
    int damage;
    int hit_chance;
    int health;
};

struct armor
{
    int type;
    int level;
    char name[20];
    int protect_amount; //процент поглощаемого урона
};

struct chest
{
    int level;
};

struct weapon arr_weapons1[3] = { {0, 1, ("Light Sword"), 20, 70}, {1, 1, ("Bow-1"), 30, 60}, {2, 1, ("Axe-1"), 50, 40} };
struct weapon arr_weapons2[3] = { {0, 2, ("Soldier Sword"), 40, 80}, {1, 2, ("Bow-2"), 55, 68}, {2, 2, ("Axe-2"), 75, 55} };
struct weapon arr_weapons3[3] = { {0, 3, ("Knight Sword"), 65, 90}, {1, 3, ("Bow-3"), 70, 77}, {2, 3, ("Axe-3"), 90, 65} };
struct weapon arr_weapons4[3] = { {0, 4, ("Fire Sword"), 80, 98}, {1, 4, ("Bow-4"), 95, 87}, {2, 4, ("Axe-4"), 110, 75} };

struct weapon arr_swords[4] = { {0, 1, ("Light Sword"), 20, 70}, {0, 2, ("Soldier Sword"), 60, 30}, {0, 3, ("Knight Sword"), 65, 90}, {0, 4, ("Fire Sword"), 80, 98} };
struct weapon arr_bows[4] = { {1, 1, ("Bow-1"), 30, 60}, {1, 2, ("Bow-2"), 55, 68}, {1, 3, ("Bow-3"), 70, 77}, {1, 4, ("Bow-4"), 95, 87} };
struct weapon arr_axes[4] = { {2, 1, ("Axe-1"), 50, 40}, {2, 2, ("Axe-2"), 75, 55}, {2, 3, ("Axe-3"), 90, 65}, {2, 4, ("Axe-4"), 110, 75} };

struct enemy arr_enemies_1[4] = { {1, "Imp", 16, 65, 40},{1, "Demonized Warrior", 22, 45, 80} };
struct enemy arr_enemies_2[4] = { {1, "Imp", 16, 65, 40},{1, "Demonized Warrior", 22, 45, 80} };
struct enemy arr_enemies_3[4] = { {1, "Imp", 16, 65, 40},{1, "Demonized Warrior", 22, 45, 80} };

int main()
{
    char *locale = setlocale(LC_ALL, "");

    struct chest arr_chests[10];
    struct enemy arr_enemies[10][10];

    menu(0);

// генерация локаций
    printf("-Generating floor-\n")
    for (int i = 0; i < 2; i++){ //этажи
        generateFloor();
        level++;
    }

    while (player_health > 0){
        player_health -= 25;
    }

    looseCondition();
}