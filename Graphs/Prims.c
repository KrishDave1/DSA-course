#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct List
{
  int i;
  float w;
  struct List *next;
};

struct Tree
{
  int i;
  float p;
};


struct List *
newedge (struct List *node, int i, float w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

int A[100000], B[100000], n = 6;
float H[100000];
struct Tree H1[100000];
void
MaxBottomupheapify1 (int i)
{
  int p = (i - 1) / 2, t;
  struct Tree temp;

  while (p > -1)
    {
      if (H1[i].p > H1[p].p)
	{
	  temp = H1[i];
	  H1[i] = H1[p];
	  H1[p] = temp;
	  B[H1[p].i] = p;
	  B[H1[i].i] = i;
	  i = p;
	  p = (i - 1) / 2;

	}

      else
	p = -1;
    }

}

void
MaxTopdownheapify1 (int i, int n)
{
  int c, t;
  struct Tree temp;

  while (2 * i + 2 < n)
    {

      if (H1[2 * i + 1].p > H1[2 * i + 2].p)
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H1[i].p < H1[c].p)
	{
	  temp = H1[i];
	  H1[i] = H1[c];
	  H1[c] = temp;
	  B[H1[i].i] = i;
	  B[H1[c].i] = c;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H1[i].p < H1[c].p)
    {
      temp = H1[i];
      H1[i] = H1[c];
      H1[c] = temp;

      B[H1[i].i] = i;
      B[H1[c].i] = c;
      i = c;
    }

}

void
MaxAdd1 (float X, int *n)
{

  H1[*n].p = X;
  H1[*n].i = *n;
  B[H1[*n].i] = *n;
  *n = *n + 1;

  MaxBottomupheapify1 (*n - 1);
}

void
DeleteMax1 (int *n)
{
  int t1;
  struct Tree t;
  *n = *n - 1;
  t = H1[0];
  H1[0] = H1[*n];
  H1[*n] = t;
  B[H1[0].i] = 0;
  B[H1[*n].i] = *n;
  MaxTopdownheapify1 (0, *n);
}

void
MaxBuildHeap1 (int n)
{

  int i = n / 2;
  while (i > -1)
    {
      MaxTopdownheapify1 (i--, n);
    }

}

void
Bottomupheapify1 (int i)
{
  int p = (i - 1) / 2, t;
  struct Tree temp;

  while (p > -1)
    {
      if (H1[i].p < H1[p].p)
	{
	  temp = H1[i];
	  H1[i] = H1[p];
	  H1[p] = temp;
	  B[H1[i].i] = i;
	  B[H1[p].i] = p;
	  i = p;
	  p = (i - 1) / 2;

	}

      else
	p = -1;
    }

}

void
Topdownheapify1 (int i, int n)
{
  int c, t;
  struct Tree temp;

  while (2 * i + 2 < n)
    {

      if (H1[2 * i + 1].p < H1[2 * i + 2].p)
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H1[i].p > H1[c].p)
	{
	  temp = H1[i];
	  H1[i] = H1[c];
	  H1[c] = temp;
	  B[H1[c].i] = c;
	  B[H1[i].i] = i;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H1[i].p > H1[c].p)
    {
      temp = H1[i];
      H1[i] = H1[c];
      H1[c] = temp;
      B[H1[c].i] = c;
      B[H1[i].i] = i;
      i = c;
    }

}

void
Add1 (float X, int *n)
{

  H1[*n].p = X;
  B[H1[*n].i] = *n;
  *n = *n + 1;

  Bottomupheapify1 (*n - 1);
}

void
DeleteMin1 (int *n)
{
  struct Tree t;
  int t1;
  *n = *n - 1;
  t = H1[0];
  H1[0] = H1[*n];
  H1[*n] = t;
  B[H1[0].i] = 0;
  B[H1[*n].i] = *n;
  Topdownheapify1 (0, *n);
}

void
BuildHeap1 (int n)
{

  int i = n / 2;
  while (i > -1)
    {
      Topdownheapify1 (i--, n);

    }

}

void
DecreaseKey1 (int i, float X)
{

  H1[i].p = X;

  Bottomupheapify1 (i);


}

void
IncreaseKey1 (int i, float X)
{

  H1[i].p = X;

  MaxBottomupheapify1 (i);


}


void
Dijkstra1 (struct List *list[], int s, int n)
{
  struct List *node;
  int i, u, v, m = n;
  bool V[n];
  int Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H1[i].p = INT_MAX;
      H1[i].i = i;
      B[i] = i;
      V[i] = false;
    }

  H1[0].p = 0;
  Phi[s] = -1;
  H1[0].i = s;
  H1[s].i = 0;
  B[0] = s;
  B[s] = 0;
  for (i = 0; i < n && H1[0].p < INT_MAX; ++i)
    {
      u = H1[0].i;
      V[u] = true;
      node = list[u];
      DeleteMin1 (&m);
      while (node)
	{
	  v = node->i;
	  if (!V[v] && H1[B[v]].p > H1[B[u]].p + node->w)
	    {
	      DecreaseKey1 (B[v], H1[B[u]].p + node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
  printf (" \n The shortest path from %d is\n", s);
  for (i = 0; i < n; ++i)
    printf (" %d %f %d", i, H1[B[i]].p, Phi[i]);


}

void
PrimsMin1 (struct List *list[], int s, int n)
{
  struct List *node;
  float mst = 0;
  int i, u, v, m = n;
  bool V[n];
  int Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H1[i].p = INT_MAX;
      H1[i].i = i;
      B[i] = i;
      V[i] = false;
    }
  H1[0].p = 0;
  Phi[s] = -1;
  H1[0].i = s;
  H1[s].i = 0;
  B[0] = s;
  B[s] = 0;
  for (i = 0; i < n && H1[0].p < INT_MAX; ++i)
    {
      u = H1[0].i;
      V[u] = true;
      node = list[u];
      DeleteMin1 (&m);
      while (node)
	{
	  v = node->i;
	  if (!V[v] && H1[B[v]].p > node->w)
	    {
	      DecreaseKey1 (B[v], node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }

  for (i = 0; i < n; ++i)
    mst += H1[i].p;

  printf (" \n Minimim Spanning Tree is %f\n", mst);
  for (i = 0; i < n; ++i)

    printf (" %d %f %d", i, H1[B[i]].p, Phi[i]);


}

void
PrimsMax1 (struct List *list[], int s, int n)
{
  struct List *node;
  float mst = 0;
  int i, u, v, m = n;
  bool V[n];
  int Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H1[i].p = INT_MIN;
      H1[i].i = i;
      B[i] = i;
      V[i] = false;
    }

  H1[0].p = 0;
  Phi[s] = -1;
  H1[0].i = s;
  H1[s].i = 0;
  B[0] = s;
  B[s] = 0;
  for (i = 0; i < n && H1[0].p > INT_MIN; ++i)
    {
      u = H1[0].i;
      V[u] = true;
      node = list[u];
      DeleteMax1 (&m);
      while (node)
	{
	  v = node->i;
	  if (!V[v] && H1[B[v]].p < node->w)
	    {
	      IncreaseKey1 (B[v], node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
  for (i = 0; i < n; ++i)
    mst += H1[B[i]].p;

  printf (" \n Maximum Spanning Tree is %f\n", mst);
  for (i = 0; i < n; ++i)

    printf (" %d %f %d", i, H1[B[i]].p, Phi[i]);


}

void
BFS (struct List *list[], int s, int n)
{
  bool V[n];
  int Phi[n], i;

  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
    }
  struct List *head = (struct List *) malloc (sizeof (struct List));
  head->i = s;
  head->next = NULL;
  V[s] = true;
  Phi[s] = -1;
  struct List *tail = head, *temp;
  while (head)
    {
      temp = list[head->i];
      while (temp)
	{
	  if (!V[temp->i])
	    {
	      tail->next = (struct List *) malloc (sizeof (struct List));
	      tail = tail->next;
	      tail->i = temp->i;
	      tail->next = NULL;
	      V[temp->i] = true;
	      Phi[temp->i] = head->i;
	    }
	  temp = temp->next;
	}
      head = head->next;
    }
  printf (" \n BFS from %d is\n", s);

  for (i = 0; i < n; ++i)
    printf ("(%d,%d)", Phi[i], i);

}

void
DFS (struct List *list[], int s, int n)
{
  bool V[n];
  int Phi[n], i;
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
    }

  struct List *head = (struct List *) malloc (sizeof (struct List));
  head->i = s;
  head->next = NULL;
  Phi[s] = -1;
  struct List *temp, *t1, *h1;
  while (head)
    {
      if (!V[head->i])
	{
	  V[head->i] = true;
	  temp = list[head->i];

	  if (temp)
	    {
	      h1 = head;
	      head = head->next;
	      while (temp)
		{
		  if (!V[temp->i])
		    {
		      head = newedge (head, temp->i, 0);

		      Phi[temp->i] = h1->i;

		    }


		  temp = temp->next;
		}


	    }
	  else
	    head = head->next;
	}
      else
	head = head->next;

    }
  printf (" \n DFS Tree from %d is\n", s);


  for (i = 0; i < n; ++i)
    printf ("(%d,%d)", Phi[i], i);

}

void
MaxBottomupheapify (int i)
{
  int p = (i - 1) / 2, t;
  float temp;

  while (p > -1)
    {
      if (H[i] > H[p])
	{
	  temp = H[i];
	  H[i] = H[p];
	  H[p] = temp;
	  t = A[i];
	  A[i] = A[p];
	  A[p] = t;
	  B[A[p]] = p;
	  B[A[i]] = i;
	  i = p;
	  p = (i - 1) / 2;

	}

      else
	p = -1;
    }

}

void
MaxTopdownheapify (int i, int n)
{
  int c, t;
  float temp;

  while (2 * i + 2 < n)
    {

      if (H[2 * i + 1] > H[2 * i + 2])
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H[i] < H[c])
	{
	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  t = A[i];
	  A[i] = A[c];
	  A[c] = t;
	  B[A[i]] = i;
	  B[A[c]] = c;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H[i] < H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
      t = A[i];
      A[i] = A[c];
      A[c] = t;

      B[A[i]] = i;
      B[A[c]] = c;
      i = c;
    }

}

void
MaxAdd (float X, int *n)
{

  H[*n] = X;
  A[*n] = *n;
  B[A[*n]] = *n;
  *n = *n + 1;

  MaxBottomupheapify (*n - 1);
}

void
DeleteMax (int *n)
{
  int t1;
  float t;
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  t1 = A[0];
  A[0] = A[*n];
  A[*n] = t1;
  B[A[0]] = 0;
  B[A[*n]] = *n;
  MaxTopdownheapify (0, *n);
}

void
MaxBuildHeap (int n)
{

  int i = n / 2;
  while (i > -1)
    {
      MaxTopdownheapify (i--, n);
    }

}


void
Bottomupheapify (int i)
{
  int p = (i - 1) / 2, t;
  float temp;

  while (p > -1)
    {
      if (H[i] < H[p])
	{
	  temp = H[i];
	  H[i] = H[p];
	  H[p] = temp;
	  t = A[i];
	  A[i] = A[p];
	  A[p] = t;
	  B[A[i]] = i;
	  B[A[p]] = p;
	  i = p;
	  p = (i - 1) / 2;

	}

      else
	p = -1;
    }

}

void
Topdownheapify (int i, int n)
{
  int c, t;
  float temp;

  while (2 * i + 2 < n)
    {

      if (H[2 * i + 1] < H[2 * i + 2])
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H[i] > H[c])
	{
	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  t = A[i];
	  A[i] = A[c];
	  A[c] = t;
	  B[A[c]] = c;
	  B[A[i]] = i;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H[i] > H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
      t = A[i];
      A[i] = A[c];
      A[c] = t;

      B[A[c]] = c;
      B[A[i]] = i;
      i = c;
    }

}

void
Add (float X, int *n)
{

  H[*n] = X;
  A[*n] = *n;
  B[A[*n]] = *n;
  *n = *n + 1;

  Bottomupheapify (*n - 1);
}

void
DeleteMin (int *n)
{
  float t;
  int t1;
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  t1 = A[0];
  A[0] = A[*n];
  A[*n] = t1;
  B[A[0]] = 0;
  B[A[*n]] = *n;
  Topdownheapify (0, *n);
}

void
BuildHeap (int n)
{

  int i = n / 2;
  while (i > -1)
    {
      Topdownheapify (i--, n);

    }

}

void
DecreaseKey (int i, float X)
{

  H[i] = X;

  Bottomupheapify (i);


}

void
IncreaseKey (int i, float X)
{

  H[i] = X;

  MaxBottomupheapify (i);


}

void
Dijkstra (struct List *list[], int s, int n)
{
  struct List *node;
  int i, u, v, m = n;
  bool V[n];
  int Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H[i] = INT_MAX;
      A[i] = i;
      B[i] = i;
      V[i] = false;
    }

  H[0] = 0;
  Phi[s] = -1;
  A[0] = s;
  A[s] = 0;
  B[0] = s;
  B[s] = 0;
  for (i = 0; i < n && H[0] < INT_MAX; ++i)
    {
      u = A[0];
      V[u] = true;
      node = list[u];
      DeleteMin (&m);
      while (node)
	{
	  v = node->i;
	  if (!V[v] && H[B[v]] > H[B[u]] + node->w)
	    {
	      DecreaseKey (B[v], H[B[u]] + node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
  printf (" \n The shortest path from %d is\n", s);
  for (i = 0; i < n; ++i)
    printf (" %d %f %d", i, H[B[i]], Phi[i]);


}

void
PrimsMin (struct List *list[], int s, int n)
{
  struct List *node;
  float mst = 0;
  int i, u, v, m = n;
  bool V[n];
  int Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H[i] = INT_MAX;
      A[i] = i;
      B[i] = i;
      V[i] = false;
    }

  H[0] = 0;
  Phi[s] = -1;
  A[0] = s;
  A[s] = 0;
  B[0] = s;
  B[s] = 0;
  for (i = 0; i < n && H[0] < INT_MAX; ++i)
    {
      u = A[0];
      V[u] = true;
      node = list[u];
      DeleteMin (&m);
      while (node)
	{
	  v = node->i;
	  if (!V[v] && H[B[v]] > node->w)
	    {
	      DecreaseKey (B[v], node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
  for (i = 0; i < n; ++i)
    mst += H[B[i]];

  printf (" \n Minimim Spanning Tree is %f\n", mst);
  for (i = 0; i < n; ++i)

    printf ("%d %f %d", i, H[B[i]], Phi[i]);


}

void
PrimsMax (struct List *list[], int s, int n)
{
  struct List *node;
  float mst = 0;
  int i, u, v, m = n;
  bool V[n];
  int Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H[i] = INT_MIN;
      A[i] = i;
      B[i] = i;
      V[i] = false;
    }

  H[0] = 0;
  Phi[s] = -1;
  A[0] = s;
  A[s] = 0;
  B[0] = s;
  B[s] = 0;
  for (i = 0; i < n && H[0] > INT_MIN; ++i)
    {
      u = A[0];
      V[u] = true;
      node = list[u];
      DeleteMax (&m);
      while (node)
	{
	  v = node->i;
	  if (!V[v] && H[B[v]] < node->w)
	    {
	      IncreaseKey (B[v], node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
  for (i = 0; i < n; ++i)
    mst += H[B[i]];

  printf (" \n Maximum Spanning Tree is %f\n", mst);
  for (i = 0; i < n; ++i)

    printf (" %d %f %d", i, H[B[i]], Phi[i]);


}

void
main ()
{
  int m, i, j, k;
  bool AM[1000][1000];


  struct List *list[n], *temp, *list1[n];
  for (i = 0; i < n; ++i)
    list[i] = NULL;
  for (i = 0; i < n; ++i)
    for (k = 0; k < n / 2; ++k)
      {
	j = rand () % n;
	if (!AM[i][j] & i != j)
	  {
	    AM[i][j] = true;
	    list[i] = newedge (list[i], j, i * j * 2.23 + 1);
	    ++m;
	    //printf ("(%d %d %f)", i, j, i * j * 2.23 + 1);
	  }
      }
/*
  printf ("\n%d\n", m);
  Dijkstra (list, 0, n);
  BFS (list, 0, n);
  DFS (list, 0, n);
  printf ("\n%d\n", m);
*/

  Dijkstra (list, 0, n);
  Dijkstra1 (list, 0, n);
  printf ("\n");
  m = 0;
  for (i = 0; i < n; ++i)
    {
      j = rand () % n;
      while (j < n)
	{
	  if (i == j)
	    j++;
	  list1[i] = newedge (list1[i], j, i * j * 2.23 + 1);
	  list1[j] = newedge (list1[j], i, i * j * 2.23 + 1);

	  ++m;
	  printf ("(%d %d %f)", i, j, i * j * 2.23 + 1);
	  j += rand () % n + 1;
	}
    }
  printf ("\n%d .......\n", m);
  Dijkstra (list1, 0, n);
  Dijkstra1 (list1, 0, n);

  PrimsMin (list1, 0, n);
  PrimsMin1 (list1, 0, n);

  PrimsMax (list1, 0, n);
  PrimsMax1 (list1, 0, n);
}
