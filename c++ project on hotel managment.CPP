/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			 *******************

			 *** HEADER FILES***

			 *******************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 */

#include<iostream.h>

#include<conio.h>

#include<stdlib.h>

#include<stdio.h>

#include<fstream.h>

#include<ctype.h>

#include<dos.h>

#include<process.h>

#include<string.h>



/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			 **********************

			 *** GLOBAL VARIABLE ***

			 **********************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 */

int ac=50;

int non_ac=50;

int no_of_room=100;



 /*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			 *****************

			 *** STRUCTURE ***

			 *****************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 */

struct hotel

 {

  int day,year,month;

  int no_of_person;

  int no_of_room;

  char name[30];

  char nationality[20];

  int ac;

  int room_no;

  int non_ac;

  int no_of_day;

  char address[20];

 }h;



 /*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			 ***************

			 *** WELCOME ***

			 ***************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 */



void welcome()

{





		   getch();           clrscr();

			 cout<<"\n\n\n\n\n\n\n\t\t\t*****************************";

			 cout<<"\n\t\t\t  !!!!HOTEL MANAGEMENT!!!!\n";







		   getch();

     cout<<"\n\n\n\n\n\t\tPress any key to continue";

}

 /*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				   **************

				   *** CREATE ***

				   **************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/



void create()

  {

   clrscr();

   char ch;

   ofstream fo("hotel.dat",ios::app);

   cout<<"\n\t\t\nCREATING FILE";

   cout<<"\nDate of Arrival:";

   cin>>h.day;

   cout<<"\nMonth: ";

   cin>>h.month;

   cout<<"\nYear: ";

   cin>>h.year;

   cout<<"\nNo_of_person: ";

   cin>>h.no_of_person;

   cout<<"\nName: ";

   gets(h.name);

   cout<<"\nAddress: ";

   gets(h.address);

   cout<<"\nNationality: ";

   gets(h.nationality);

   if(no_of_room>0)

    {

      cout<<"\nEnter choice (A for ac & N for non_ac): ";

      cin>>ch;

      if(ch=='A')

       {

	  if(ac>0)

	   {



	     cout<<"\nENTER ROOM NO: ";

	     cin>>h.room_no;

	     ac=ac-1;

	   }

	    no_of_room=no_of_room-1;

	    cout<<"\nNow total room available: "<<no_of_room;

       }

      else

	  {

	   if(non_ac>0)

	    {



	     cout<<"\nENTER ROOM NO : ";

	     cin>>h.room_no;

	     non_ac=non_ac-1;

	     }

	     no_of_room=no_of_room-1;

	     cout<<"\nNow total room available: "<<no_of_room;

	   }

      }

	   fo.write((char *)&h,sizeof(h));

	    fo.close();



  }

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				   **************

				   *** INTIAL ***

				   **************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/



void intial()

 {

  clrscr();

  h.ac=50;

  h.no_of_room=100;

 }

 /*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				   **************

				   *** STATUS ***

				   **************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/



void status()

  {

    clrscr();

    ifstream fi("hotel.dat",ios::binary|ios::app|ios::in);

    cout<<"\n\t\t\tSTATUS";

    while(!fi.eof())

     {

      fi.read((char*)&h,sizeof(h));

     }

      fi.close();



       cout<<"\n";

       cout<<"\n    No of AC  room : "<<ac;

       cout<<"\nNo. of NON  AC room : "<<non_ac;

       cout<<"\n No. of room available in the Hotel : "<<no_of_room;










  }

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				   **************

				   **** READ ****

				   **************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/



void read()

 {

   clrscr();

   int y=12;

   ifstream fi("hotel.dat",ios::binary|ios::app|ios::in);

    gotoxy(32,5);

    cout<<"\nPEOPLE STAYING IN THE HOTEL";

    gotoxy(6,6);





     gotoxy(10,7);

    cout<<"\nROOM NO:"<<h.room_no;



    cout<<"\nNAME:"<<h.name;



   cout<<"\nADDRESS:"<<h.address;



    cout<<"\nNATIONALITY"<<h.nationality;




    while(fi.read((char*)&h,sizeof(h)))

    {

      gotoxy(10,y);

      cout<<h.room_no;

      gotoxy(25,y);

      cout<<h.name;

      gotoxy(35,y);

      cout<<h.address;

      gotoxy(50,y);

      cout<<h.nationality;

      gotoxy(65,y);



      cout<<endl;

      y=y+1;

      getch();

     }

    fi.close();

 }

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				   **************

				   *** SEARCH ***

				   **************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/



void search()

  {

   clrscr();

   int f=0;

   char n[20];

   ifstream fi("hotel.dat",ios::binary|ios::app|ios::in);

   cout<<"\nEnter name to whose record to be search: ";

   gets(n);

   while(fi.read((char*)&h,sizeof(h)))

    {

     if(strcmp(n,h.name)==0)

      {

       cout<<"\n\t\tRecord FOUND";

       cout<<"\n\n";

       cout<<"\t\tDetails of record:"<<endl;

       cout<<"\n\tName: "<<h.name;

       cout<<"\n\tNationality: "<<h.nationality;

       cout<<"\n\tDate of Arrival:"<<h.day<<"\t"<<h.month<<"\t"<<h.year;

       cout<<"\n\tNo. of person:"<<h.no_of_person;

       f=1;

       break;

      }

    }

    if(f==0)

      cout<<"\nRECORD DOES NOT EXISTS :";

     fi.close();

     getch();

  }

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				   **************

				   *** MODIFY ***

				   **************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/



void modify()

  {

    clrscr();

    int a=0;

    char n[20];

    fstream fo;

    fo.open("hotel.dat",ios::out|ios::in);

    cout<<"\t\tMODIFY";

    cout<<"\nEnter name of person whose record is to be modify: ";

    gets(n);

    while(fo.read((char*)&h,sizeof(h)))

      {

       if(strcmp(n,h.name)==0)

	  {

	    long p=fo.tellp()-sizeof(h);

	    cout<<"\n\tEnter new detail";

	    cout<<"\nEnter no_of_person: ";

	    cin>>h.no_of_person;

	    cout<<"\nEnter Name: ";

	    gets(h.name);

	    cout<<"\nEnter Address: ";

	    gets(h.address);

	    cout<<"\nEnter Nationality: ";

	    gets(h.nationality);

	    a=1;

	    fo.seekp(p,ios::beg);

	    fo.write((char*)&h,sizeof(h));

	    break;

	  }

      }

      if(a==0)

	  cout<<"\nEMPTY RECORD";

	  fo.close();

	  getch();

  }

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				   **************

				   *** DELETE ***

				   **************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

void delet()

  {

   clrscr();

   int f=0;

   char c;

   char n[30];

   fstream fi;

   fi.open("hotel.dat",ios::in);

   fstream fo;

   fo.open("new.dat",ios::out);

   clrscr();

   cout<<"\t\t\tDELETE";

   cout<<"\nEnter name of person whose record is to be deleted : ";

   gets(n);

   while(fi.read((char*)&h,sizeof(h)))

   {

    if(strcmp(n,h.name)==0)

      {

       f=1;

       cout<<"\nDetail of person: ";

       cout<<h.name<<"\n";

       cout<<h.nationality<<"\n";

       cout<<h.address<<"\n";

       cout<<"\nDate of Arrival:"<<h.day<<"\t"<<h.month<<"\t" <<h.year;

       }

       else

	  fo.write((char*)&h,sizeof(h));

    }

    fi.close();

    fo.close();

    if(f==0)

    cout<<"\nRECORD DOES NOT EXISTS";



    remove("hotel.dat");

    rename("new.dat","hotel.dat");

     getch();

  }

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				       ************

				       *** MAIN ***

				       ************

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

void main()

{

clrscr();

welcome();

int c;

char ch;




	   clrscr();

	   cout<<"\t\t";
	   top:

		   cout<<"\n\n\t\tMAIN MENU\n\n";




	  cout<<"\n\t\tPress:\n(1) to Create"

	      <<"\n\t\t(2) to Check status"

	      <<"\n\t\t(3) to Delete a record"

	      <<"\n\t\t(4) to Modify a record"

	      <<"\n\t\t(5) to Search a record"

	      <<"\n\t\t(6) to Read all the records"

	      <<"\n\t\t(7) to Exit";




	  cout<<"\n\n\n\t\t\t\tEnter your choice: ";

	  cin>>c;

	  switch(c)

	  {

		   case 1:

			     create();

			     break;

		   case 2:

			     intial();

			     status();

			     break;



		   case 3:

			     delet();

			     break;

		   case 4:

			  modify();

			  break;

		   case 5:

			     search();

			     break;

		   case 6:

			     read();

			      break;

		   case 7:

			     clrscr();

			     cout<<"\n\n\n";

			     cout<<"\t\t\t\tPLEASE WAIT...";

			     cout<<"\n\n\n";

			     cout<<"\t\t\t\t   EXITING";

			     delay(1500);

			     exit(0);





		   default:

			     clrscr();

			     cout<<"\n\n\t\t\t\t!!Invalid choice!!";

			     cout<<"\n\n\n";

		   }

		   cout<<"\n\nWant to continue(Y/N)";

		   cin>>ch;

   if(ch=='y'||ch=='Y')
	goto top;
   else
	exit(0);

   getch();

 }