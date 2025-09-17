#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    map<string, int> foodrate;               // Maps food names to their ratings
    map<string, string> foodcui;             // Maps food names to their cuisines
    map<string, set<pair<int, string>>> cuifood; // Maps cuisines to a set of (rating, food_name) pairs

public:
    // Constructor to initialize the food ratings system
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodrate[foods[i]] = ratings[i];  // Assign ratings to foods
            foodcui[foods[i]] = cuisines[i];  // Assign cuisines to foods
            cuifood[cuisines[i]].insert({-ratings[i], foods[i]}); // Insert into cuisine set (using negative rating for descending order)
        }
    }

    // Method to change the rating of a food
    void changeRating(string food, int newRating) {
        string cuiname = foodcui[food];  // Get the cuisine of the food
        auto oldele = cuifood[cuiname].find({-foodrate[food], food}); // Find the old rating entry in the set
        cuifood[cuiname].erase(oldele); // Remove the old entry
        foodrate[food] = newRating;     // Update the food's rating
        cuifood[cuiname].insert({-newRating, food}); // Insert the updated entry
    }

    // Method to get the highest-rated food in a given cuisine
    string highestRated(string cuisine) {
        auto highrate = *cuifood[cuisine].begin(); // Get the first (highest-rated) food in the set
        return highrate.second; // Return the food's name
    }
};

int main() {
    // Test case 1
    vector<string> foods1 = {"Pizza", "Burger", "Sushi"};
    vector<string> cuisines1 = {"Italian", "American", "Japanese"};
    vector<int> ratings1 = {5, 3, 4};

    FoodRatings foodRatings1(foods1, cuisines1, ratings1);

    cout << "Highest rated in Italian: " << foodRatings1.highestRated("Italian") << endl;  // Output: Pizza
    cout << "Highest rated in Japanese: " << foodRatings1.highestRated("Japanese") << endl; // Output: Sushi

    foodRatings1.changeRating("Sushi", 6);  // Change the rating of Sushi
    cout << "Highest rated in Japanese after rating change: " << foodRatings1.highestRated("Japanese") << endl; // Output: Sushi

    // Test case 2
    vector<string> foods2 = {"Pasta", "Taco", "Ramen"};
    vector<string> cuisines2 = {"Italian", "Mexican", "Japanese"};
    vector<int> ratings2 = {7, 9, 6};

    FoodRatings foodRatings2(foods2, cuisines2, ratings2);

    cout << "Highest rated in Italian: " << foodRatings2.highestRated("Italian") << endl; // Output: Pasta
    cout << "Highest rated in Mexican: " << foodRatings2.highestRated("Mexican") << endl; // Output: Taco
    cout << "Highest rated in Japanese: " << foodRatings2.highestRated("Japanese") << endl; // Output: Ramen

    foodRatings2.changeRating("Ramen", 10);  // Change the rating of Ramen
    cout << "Highest rated in Japanese after rating change: " << foodRatings2.highestRated("Japanese") << endl; // Output: Ramen

    return 0;
}
