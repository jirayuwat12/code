#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct queue {
  int price;
  int weight;
  int amount;
  int ave;
  struct queue *bf;
  struct queue *n;
}Q;
