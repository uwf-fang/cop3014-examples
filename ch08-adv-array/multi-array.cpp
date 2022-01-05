
#include <iostream>

using namespace std;

int main() {


  const int NUM_ELEMENTS = 14;

  // use multiple arrays sharing indices
  // pro: no complex data structures
  // con: two separate arrays are hard to maintain, cannot scale when more
  //      fields are needed

  // Weights in ounces
  double letterWeights[NUM_ELEMENTS] = {1.0, 2.0, 3.0, 3.5,  4.0,  5.0,  6.0,
                                        7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
  // Costs in cents (usps.com 2017)
  int postageCosts[NUM_ELEMENTS] = {49,  70,  91,  112, 161, 182, 203,
                                    224, 245, 266, 287, 308, 329, 350};


  // using pair
  // pro: no need of extra struct/class
  // con: first, second are not meaningful names
  pair<double, int> weightAndCost1[NUM_ELEMENTS];

  cout << "Weight: " << weightAndCost1[2].first;
  cout << " Cost: " << weightAndCost1[2].second << endl;

  // best way
  // pro: field names are meaningful
  struct WeightAndCost {
    double weight;
    int cost;
  };

  WeightAndCost weightAndCost2[NUM_ELEMENTS];

  cout << "Weight: " << weightAndCost2[2].weight;
  cout << " Cost: " << weightAndCost2[2].cost << endl;

}