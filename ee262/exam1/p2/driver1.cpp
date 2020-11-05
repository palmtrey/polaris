int main(int argc, char** argv) {
  cout<<my_strcat("test1", " hello.")<<endl;
  cout<<my_strcat("now", " this.")<<endl<<endl;

  char v1[] = "the time ";
  char v2[] = "has come ";
  char v3[] = "for all good men to come to the aid ... of the party. ";
  char v4[] = "End of filler text.";
    
  char* r1 = my_strcat(v1, v2);
  char* r2 = my_strcat(r1, v3);
  char* r3 = my_strcat(r2, v4);
  cout<<"r3: "<<r3<<endl<<endl;


  
  char t1[] = "Woodrow ";
  char t2[] = "Wilson ";
  char t3[] = "listed Fourteen Points.";
  char* lst14 = my_strcat(t1, my_strcat(t2, t3));
  cout<<"lst14: "<<lst14<<endl;
    
  return 0;
}
