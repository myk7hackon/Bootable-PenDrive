#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
using namespace std;

int main (int argv,char* argc[])
{
   system("cls");
   cout<<"\n\n\t\tBOOTABLE PD(Windows 7,8,8.1,10)\n";
   cout<<"\t\t_______________________________\n\n";
   char ch;
   
   char command[50]="format x: /FS:NTFS /q /V:Boot_Win /X";
   
   system("wmic logicaldisk where drivetype=2 get deviceid, volumename, description");
   
   cout<<"Enter Drive To format: ";
   
   cin>>ch;
   
   command[7]=ch;

   system(command);                                               //formar fs=ntfs quick
   
   strcpy(command,"bootsect.exe/nt60 x:");
   
   command[18]=ch;
   
   cout<<command;
   
   int s=system(command);                                         //Mapping of bootloader
   
   if(s==0) cout<<"BootLoader Successfully Mapped To your Device\n";
   
   else if(s==1){ cout<<"No Admin Access Detected\n";exit(0);}
   
   else  {cout<<"Fatal Error\n";exit(0);}
   
   cout<<"Enter DVD/iso Location\n";
   
   strcpy(command,"xcopy h:\\ g:\\ /E /V /C /Q /H /Y");
   
   command[10]=ch;
   
   cin>>ch;
   
   command[6]=ch;
   
   cout<<command;
   
   system(command);                                                 //copying file
   
   return(0);
}
//xcopy h:\ g:\ /E /V /C /Q /H /Y /Z /L
