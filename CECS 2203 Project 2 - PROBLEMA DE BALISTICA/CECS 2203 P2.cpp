#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
   float v0=10, v0x, v0y, angle=53, g=9.81;
   float thmax, tmax, t, xpos, ypos, vxt, vyt;
   int maxIterations, x;

   do
   {
   cout << "Enter initial velocity: ";
   cin >> v0;
   cout << "Enter the angle: ";
   cin >> angle;
   cout << "Initial speed v0 :" << v0 << ". Angle: " << angle << endl;

   v0x = v0*cos (angle*M_PI/180);
   v0y = v0*sin (angle*M_PI/180);

   cout << fixed << setprecision(2);
   cout << "v0x: " << v0x << endl;
   cout << "v0y: " << v0y << endl;

   thmax = v0y/g;
   tmax = 2*thmax;

   cout << "tFinal: " << tmax << endl;

   maxIterations = ceil(tmax/0.1);

   cout << "Number of measures: " << maxIterations << endl;
   cout << "t: \t secs. \t xpos. \t ypos. \t vx: \t vy. \n";

   for(int i=0; i<maxIterations; i++)
   {
       t = i*0.1;
       vxt = v0x;
       xpos = vxt*t;
       vyt = v0y-g*t;
       ypos = v0y*t-0.5*g*pow(t,2);

       cout << "t" << i << ": \t" << t << " \t " << xpos << " \t" << ypos;
       cout << " \t" << vxt << "\t" << vyt << "\n";

   }

   xpos = vxt*tmax;
   vyt = v0y-g*tmax;
   ypos = v0y*tmax-0.5*g*pow(tmax, 2);

   cout << "t" << maxIterations << ": \t " << tmax << " \t " << xpos << " \t " << ypos;
   cout << " \t" << vxt << "\t" << vyt << "\n";

   cout << "Do you wish to continue using the program?\n";
   cout << "Type '1' to continue:\n";
   cout << "Type '0' to end the program\n";
   cin >> x;
   } while(x!=0);

   return 0;
}
