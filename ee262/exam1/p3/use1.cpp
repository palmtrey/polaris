#include <iostream>
#include <cmath>
#include "coords.h"

using std::endl;
using std::cout;

using coords::rect_coords;
using coords::polar_coords;

int main(void) {
  cout<<"--- Test 1 --- "<<endl;
  rect_coords rdef;
  cout<<"rdef: "<<rdef<<endl;
  cout<<endl;
   

  cout<<"--- Test 2 --- "<<endl;
  rect_coords r1(40, 22);  
  cout<<"r1: "<<r1<<endl;
  polar_coords r1p = r1.toPolar();
  cout<<"r1p: "<<r1p<<endl;
  cout<<endl;

  cout<<"--- Test 3 --- "<<endl;
  polar_coords p2last(false, 45.6508, 0.502843);
  cout<<"p2last: "<<p2last<<endl;
  rect_coords p2last_r = p2last.toRectangular();
  cout<<"p2last_r"<<p2last_r<<endl;
  cout<<endl;

  cout<<"--- Test 4 --- "<<endl;
  rect_coords wr1(-10, 120);
  cout<<"wr1: "<<wr1<<endl<<endl;

  cout<<"--- Test 5 --- "<<endl;
  polar_coords pdef;  //Polar origin 
  cout<<"pdef: "<<pdef<<endl; //polar origin represented as (0, PI/6)
  rect_coords pdefr = pdef.toRectangular();
  cout<<"pdefr: "<<pdefr<<endl;
  cout<<endl;

  cout<<"--- Test 6 --- "<<endl;
  polar_coords p1(false, 100, 20); //false (this point is not the polar origin)
  cout<<"p1: "<<p1<<endl; // since angle of p1 was too large as per prob stmt, the Polar origin is used
  polar_coords p2(p1);
  cout<<"p2: "<<p2<<endl;
  cout<<endl;
  
  cout<<"--- Test 7 --- "<<endl;
  polar_coords p3(false, 25, M_PI/3); 
  cout<<"p3: "<<p3<<endl;
  p1 = p3;
  cout<<"{{p1 = p3}}"<<endl;
  cout<<"p1: "<<p1<<endl;
  rect_coords p1_r = p1.toRectangular();
  cout<<"p1_r: "<<p1_r<<endl;
  cout<<endl;
  
  cout<<"--- Test 8 --- "<<endl;
  polar_coords p4(true, 0, M_PI/3); //the polar origin; r=0; angle will be ignored in favor a fixed value (see problem statement)
  cout<<"p4: "<<p4<<endl;
  p4.print("p4");
  rect_coords p4r = p4.toRectangular();
  cout<<"p4r: "<<p4r<<endl;
  cout<<endl;
     
  cout<<"--- Test 9 --- "<<endl;
  rect_coords r5(0, 0);
  cout<<"r5: "<<r5<<endl;    
  polar_coords r5p = r5.toPolar();
  cout<<"r5p "<<r5p<<endl;    

  return 0;
}
