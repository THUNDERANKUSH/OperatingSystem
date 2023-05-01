#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct node {
    int arrival;
    int burst;
    int turnaround;
    int waiting;
    int finish;
    int name;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int empty() {
    if (head == NULL)
        return 1;
    else
        return 0;
}

void append(struct node *temp) {
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp->next = NULL;
    } else {
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
}

struct node *serve() {
    struct node *temp;
    if (!empty()) {
        temp = head;
        head = head->next;
        return temp;
    } else {
        temp = new(node);
        temp->name = 0;
        return temp;
    }
}

int main() {
    int max;
    struct node *p[10];
    struct node *exe;
    int period = 0;
    int count = 0;
    int i;
    double totalWaiting = 0;
    double totalTurnaround = 0;
    double avgWaiting;
    double avgTurnaround;

    cout << "Enter number of processes: ";
    scanf("%d", &max);

    for (i = 0; i < max; i++) {
        p[i] = new(node);
        p[i]->turnaround = 0;
        p[i]->waiting = 0;
        p[i]->finish = 0;
        p[i]->name = i + 1;
        p[i]->next = NULL;
    }

    for (i = 0; i < max; i++) {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        scanf("%d", &p[i]->arrival);
        cout << "Enter burst time for process " << i + 1 << ": ";
        scanf("%d", &p[i]->burst);
    }

    int t = 0;
    while (count < max) {
        while (t < max && p[t]->arrival <= period) {
            append(p[t]);
            t = t + 1;
        }
        exe = serve();
        if (exe->name != 0) {
            period = period + exe->burst;
            exe->finish = period;
            exe->turnaround = exe->finish - exe->arrival;
            exe->waiting = exe->turnaround - exe->burst;
            count++;
            totalWaiting = totalWaiting + exe->waiting;
            totalTurnaround = totalTurnaround + exe->turnaround;
        } else {
            period = period + 1;
        }
    }

    avgWaiting = totalWaiting / max;
    avgTurnaround = totalTurnaround / max;

    cout << "Avg waiting time and Turnaround time: " << endl;
    printf("%.2f\n", avgWaiting);
    printf("%.2f\n", avgTurnaround);

    return 0;
}
