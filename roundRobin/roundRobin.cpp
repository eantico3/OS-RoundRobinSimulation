#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <list>
#include <string>

using namespace std;

const int TIMESLICE = 3;
bool alarmFired = false;


void sigalarm_handler(int signum)
{
    // To simulate a preemptive, timesliced scheduling system, a signal handler
    // must be registered that simulates the CPU timer that fires whenever the
    // system has to schedule another process.

   alarmFired = true;
}

int main(void)
{
   list<pair<string,int>> process; //linked list to store processes

   string name; //process name
   int time;  //process time

   while (!cin.eof()) //read until end of file
   {
      cin >> name >> time;
      if(cin.eof())
         break;
      process.push_back(make_pair(name,time)); //push process name and time onto list

   }

   cout << endl;


  signal(SIGALRM, sigalarm_handler); //call sigalarm


   while (!process.empty())//continue until no more processes
   {
      pair<string,int> currProcess = process.front(); //create pair list from process list
      process.pop_front();
      

      alarm(TIMESLICE); //alarm(3)


      sleep(currProcess.second); //sleep for time remaining


      if (alarmFired==true) //check if timeslice expired
      {
         currProcess.second -= TIMESLICE; //update time remaining

      }

      else //remaining time has expired
      {
         currProcess.second -= currProcess.second; //no time remaininig
      }


      /*check if process has finished by checking if time remaining
       * is less than or equal to zero
       * if it is, the process has finished
      */
      if (currProcess.second <= 0)
      {
         cout << currProcess.first << " Finished" << endl;
      }

      /*there is still time remaining
       * print out the process and remaining time
       * put this pair at the back of the list
      */
      else
      {

         cout << currProcess.first << " " << currProcess.second  << endl;
         process.push_back(make_pair(currProcess.first, currProcess.second));
      }

      //reset alarm
      alarmFired = false;


  }
  //no processes left
  cout << "No processes left" << endl;

