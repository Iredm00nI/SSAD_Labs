#include <iostream>
#include <vector>

using namespace std;

class RecipeTemplate
{
protected:
    vector<string> ingredients;
public:
    void listIngredients() {
        cout << "Ingredients:" << endl;
        for (string ingredient : ingredients) {
            cout << "    - " << ingredient << endl;
        }
    }
    virtual void prepareRecipe() = 0;
    void serve() {
        cout << "Serve the dish" << endl;
    }
    virtual void makeRecipe() final {
        this->listIngredients();
        this->prepareRecipe();
        this->serve();
        cout << endl;
    }
};

class CakeRecipe : virtual public RecipeTemplate
{
public:
    CakeRecipe() {
        this->ingredients = {"flour", "salt", "water", "sugar"};
    }
    void prepareRecipe() override {
        cout << "Steps:" << endl;
        cout << "    - make the dough" << endl;
        cout << "    - put it in the oven" << endl;
        cout << "    - remove the finished product from the oven" << endl;
    }
};

class SaladRecipe : virtual public RecipeTemplate
{
public:
    SaladRecipe() {
        this->ingredients = {"cucumbers", "tomatoes", "sour cream", "salt"};
    }
    void prepareRecipe() override {
        cout << "Steps:" << endl;
        cout << "    - cut the products" << endl;
        cout << "    - put it in a bowl" << endl;
    }
};

int main() {
    RecipeTemplate* cake = new CakeRecipe();
    RecipeTemplate* salad = new SaladRecipe();
    cake->makeRecipe();
    salad->makeRecipe();
    return 0;
}