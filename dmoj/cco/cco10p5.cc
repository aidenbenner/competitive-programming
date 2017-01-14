#include <cstdio>
#include <cmath>


typedef struct {
  double x; 
  double y;
  double z;
  double v;
  double r;
  bool visited; 
} Planet; 

typedef struct {
  double x;
  double y;
  double z; 
} Waypoint;

typedef struct {
  double x;
  double y;
  double z; 
} Vec;

Planet planets[1001]; 
Planet waypoints[1001]; 
int M, N, D;

double vec_dot(Vec a, Vec b)
{
  double result = 0; 
  result += a.x * b.x;
  result += a.y * b.y;
  result += a.z * b.z;
  return result;
}

Vec vec_add(Vec a, Vec b)
{
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

Vec vec_print(Vec a)
{
  printf("%f %f %f\n", a.x, a.y, a.z);
}

Vec vec_sub(Vec a, Vec b)
{
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

double vec_length(Vec a)
{
  return sqrt(fabs(vec_dot(a,a)));
}

Vec vec_proj(Vec a, Vec b)
{
  printf("vec proj passed : \n");
  vec_print(a);
  vec_print(b);
  double result = vec_dot(a,b);
  printf("a dot b is %lf\n",result );
  result /= vec_dot(b,b); 
  printf("vec result is %lf\n",result );
  b.x *= result; 
  b.y *= result; 
  b.z *= result; 
  printf("output\n ");
  vec_print(b);
  return b; 
}

Vec vec_cap(Vec a, Vec b, Vec c)
{
  Vec ac = vec_sub(a,c); 
  Vec bc = vec_sub(b,c); 
  Vec ab = vec_sub(a,c); 
  
  double lenAC = vec_length(ac); 
  double lenBC = vec_length(bc); 

  double vec_len = vec_length(ab); 
  if(vec_length(ac) > vec_len)
  {
    if(lenAC < lenBC)
      return a; 
    else
      return b;
  }
  else if (vec_length(bc) > vec_len)
  {
    if(lenAC < lenBC)
      return a; 
    else
      return b;
  }
  return c; 
}


int main () 
{
  scanf("%d", &M); 
  
  for(int i = 0; i<M; i++)
  {
    double x,y,z,v,r; 
    scanf("%lf %lf %lf %lf %lf ", &x, &y, &z, &v, &r); 
    planets[i].x = x;
    planets[i].y = y;
    planets[i].z = z;
    planets[i].v = v;
    planets[i].r = r;
    planets[i].visited = false;
  }
  scanf("%d", &N); 

  for(int i = 0; i<N; i++)
  {
    scanf("%lf %lf %lf", &waypoints[i].x, &waypoints[i].y, &waypoints[i].z);
  }

  scanf("%d", &D); 

  //get line from current position to each waypoint
  Vec curr; 
  curr.x = 0;
  curr.y = 0;
  curr.z = 0;
  
  long supplies = 0; 
  for(int i = 0; i<N; i++)
  {

    Vec wp;
    Vec dir, plan; 
    wp.x = waypoints[i].x; 
    wp.y = waypoints[i].y; 
    wp.z = waypoints[i].z; 
    //find the direction vector of our line
    dir.x = wp.x - curr.x; 
    dir.y = wp.y - curr.y; 
    dir.z = wp.z - curr.z; 

    for(int k = 0; k<N; k++)
    {
      if(planets[i].visited)
        continue;
      plan.x = planets[i].x; 
      plan.y = planets[i].y; 
      plan.z = planets[i].z; 
      //project waypoints[i] onto wpx 
      //x * d / (d * d) * d
      //
      Vec result_vec = vec_proj(plan, dir); 
      vec_print(result_vec); 

      result_vec = vec_add(result_vec, curr); 
      //resulting vector must be between curr and end 

      double dist = vec_length(result_vec); 

      vec_print(result_vec); 
      result_vec = vec_cap(curr,wp,result_vec); 
      vec_print(result_vec); 

      dist = vec_length(result_vec); 
      result_vec = vec_sub(result_vec,plan); 

      dist = vec_length(result_vec); 
      if(dist < planets[i].r + D)
      {
        printf("%d is in range\n", i);
        supplies += planets[i].v; 
        planets[i].visited = true;
      }
    } 
  }
  printf("%ld", supplies); 
}
