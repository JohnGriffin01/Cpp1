#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct{
  string parkname;
  string state;
  int area;
}Park;

void addPark(Park parks[], string parkname, string state, int area, int length)
{
  parks[length].parkname = parkname;
  parks[length].state = state;
  parks[length].area = area;
}
//function to print out parks array
void printList(const Park parks[], int length){
  for(int i = 0; i < length; i++) {
    cout << parks[i].parkname << " [" << parks[i].state << "] area: "<< parks[i].area << endl;
  }
}
int main(int argc, char const *argv[]) {
  int newArea;
  string minArea;
  ifstream myfile;
  Park parks[100];
  myfile.open(argv[1]);
  int length = 0;
  int i = 0;
  string line, parkname, state, area;

  while(getline(myfile, line)) // while lines to read
      {
          float sum = 0, numScores = 0;
          stringstream ss(line); // use a string stream for reading the line
          getline(ss, parkname, ','); //read the line until a comma is read
          getline(ss, state, ',');
          while(getline(ss, area, ','))
          {
              newArea = newArea + stoi(area); //convert to float
          }
          addPark(parks, parkname, state, stoi(area), length);
          length++;
          i++;
      }
      myfile.close();
      printList(parks, length);
      ofstream output;
      output.open(argv[2]);
      for(int i = 0; i < length; i++)
      {
        if(parks[i].area >= atoi(argv[3]))
        {
          output << parks[i].parkname << "," << parks[i].state <<"," << parks[i].area << endl;
        }
      }
      output.close();

  return 0;
}
