/*
Project: No More Traffic
Course: Design and Analysis of Algorithms (DAA)

Description:
This program implements a Graph-Based Platoon Traffic Signal Scheduling Algorithm.
The road network is modeled as a directed graph where intersections are nodes
and roads are edges with travel time.

Vehicle platoons enter the network at a given entry time and follow predefined paths.
The algorithm computes arrival times at intersections and schedules traffic signals
to allow platoons to move through the network without conflicts.

Time Complexity: O(P × L)

Where:
P = Number of platoons
L = Number of intersections in a platoon path
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXV 100
#define MAXT 1000
#define MAXPATH 50
#define MAXP 100


/* -------- Graph Structure -------- */

struct Edge
{
    int to;
    int time;
    struct Edge *next;
};

struct Edge *graph[MAXV];


/* -------- Platoon Structure -------- */

struct Platoon
{
    int entry_time;
    int path[MAXPATH];
    int length;
};


/* -------- Signal Schedule -------- */

int signal[MAXV][MAXT];
int load[MAXV];


/* -------- Add Edge -------- */

void addEdge(int u,int v,int t)
{
    struct Edge *newEdge = (struct Edge*)malloc(sizeof(struct Edge));

    newEdge->to = v;
    newEdge->time = t;
    newEdge->next = graph[u];

    graph[u] = newEdge;
}


/* -------- Get Travel Time -------- */

int getTravelTime(int u,int v)
{
    struct Edge *temp = graph[u];

    while(temp != NULL)
    {
        if(temp->to == v)
            return temp->time;

        temp = temp->next;
    }

    return -1;
}


/* -------- Sort Platoons by Entry Time -------- */

void sortPlatoons(struct Platoon p[],int n)
{
    int i,j;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].entry_time > p[j+1].entry_time)
            {
                struct Platoon temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}


/* -------- Process Platoon Movement -------- */

int processPlatoon(struct Platoon p,int id)
{
    int time = p.entry_time;
    int i;

    printf("\nPlatoon %d Simulation\n",id);

    for(i=0;i<p.length-1;i++)
    {
        int u = p.path[i];
        int v = p.path[i+1];

        int travel = getTravelTime(u,v);

        if(travel == -1)
        {
            printf("Invalid road %d -> %d\n",u,v);
            return 0;
        }

        time += travel;

        load[v]++;

        if(signal[v][time] == 0)
        {
            signal[v][time] = 1;

            printf("Time %d : Intersection %d GREEN for %d -> %d\n",
                   time,v,u,v);
        }
        else
        {
            printf("Time %d : Intersection %d RED\n",time,v);
            return 0;
        }
    }

    return 1;
}


/* -------- Main Function -------- */

int main()
{
    int V,E;
    int u,v,t;

    struct Platoon platoons[MAXP];

    int P;
    int i,j;


    /* -------- Initialization -------- */

    for(i=0;i<MAXV;i++)
    {
        graph[i] = NULL;
        load[i] = 0;

        for(j=0;j<MAXT;j++)
            signal[i][j] = 0;
    }


    /* -------- Input Graph -------- */

    printf("Enter number of intersections: ");
    scanf("%d",&V);

    printf("Enter number of roads: ");
    scanf("%d",&E);

    printf("Enter roads (u v travel_time):\n");

    for(i=0;i<E;i++)
    {
        scanf("%d %d %d",&u,&v,&t);
        addEdge(u,v,t);
    }


    /* -------- Input Platoons -------- */

    printf("Enter number of platoons: ");
    scanf("%d",&P);

    for(i=0;i<P;i++)
    {
        printf("\nPlatoon %d\n",i+1);

        printf("Entry time: ");
        scanf("%d",&platoons[i].entry_time);

        printf("Path length: ");
        scanf("%d",&platoons[i].length);

        printf("Enter path: ");

        for(j=0;j<platoons[i].length;j++)
            scanf("%d",&platoons[i].path[j]);
    }


    /* -------- Sort Platoons by Entry Time -------- */

    sortPlatoons(platoons,P);


    /* -------- Main Scheduling Loop --------
       Processes each platoon and simulates movement
       Time Complexity: O(P × L)
    */

    int success = 0;

    for(i=0;i<P;i++)
    {
        if(processPlatoon(platoons[i],i+1))
            success++;
    }


    /* -------- Results -------- */

    printf("\n\n------ RESULTS ------\n");

    printf("Successful Platoons: %d\n",success);
    printf("Blocked Platoons: %d\n",P-success);

    float rate = ((float)success/P)*100;

    printf("Success Rate: %.2f%%\n",rate);

    printf("\nTraffic Load per Intersection\n");

    for(i=0;i<V;i++)
    {
        printf("Intersection %d : %d vehicles\n",i,load[i]);
    }

    return 0;
}
