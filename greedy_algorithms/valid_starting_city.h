#include <vector>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
  int indexOfStartingCity = 0;
  int milesRemaining = 0;
  int milesRemainingAtStartingCity = 0;
  for(int city = 1; city < distances.size(); city++) {
    int distanceTravelled = distances[city-1];
    int fuelConsumed = fuel[city - 1];
    milesRemaining += (fuelConsumed*mpg) - distanceTravelled;
    if(milesRemaining < milesRemainingAtStartingCity) {
      milesRemainingAtStartingCity = milesRemaining;
      indexOfStartingCity = city;
    }
  }
  return indexOfStartingCity;
}
