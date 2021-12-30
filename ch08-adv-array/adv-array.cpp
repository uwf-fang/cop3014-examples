
// use multiple arrays sharing indices
const int NUM_ELEMENTS = 14;
// Weights in ounces
double letterWeights[NUM_ELEMENTS] = {1.0, 2.0, 3.0, 3.5,  4.0,  5.0,  6.0,
                                      7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
// Costs in cents (usps.com 2017)
int postageCosts[NUM_ELEMENTS] = {49,  70,  91,  112, 161, 182, 203,
                                  224, 245, 266, 287, 308, 329, 350};


// using pair
pair<double, int> weightAndCost[NUM_ELEMENTS] = {{1.0, 49}, };

cout << "Weight: " << weightAndCost[2].first << " Cost: " << weightAndCost[2].second;

// best way
struct WeightAndCost {
  double weight;
  int cost;
}

WeightAndCost weightAndCost[NUM_ELEMENTS] = {{1.0, 49}, };

cout << "Weight: " << weightAndCost[2].weight << " Cost: " << weightAndCost[2].cost;

