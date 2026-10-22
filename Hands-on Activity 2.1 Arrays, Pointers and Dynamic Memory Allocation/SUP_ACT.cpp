#include <iostream>
#include <string>

// to access the private variables, use the getter functions at the very bottom
// to get the subtotal, use the subfSum function
class Fruit {
private:
    std::string fname;
    float fprice = 0;
    int fquantity = 0;

public:

    //constructor
    Fruit (std::string defName = "", float defPrice = 0, int defQuantity = 0) {
        this->fname = defName;
        this->fprice = defPrice;
        this->fquantity = defQuantity;
        std::cout << "constructed!\n";
    }

    //deconstructor
    ~Fruit() {
        std::cout << "deconstructed!\n";
    }

    //copy constructor
    Fruit (const Fruit &copyFruit) {
        this->fname = copyFruit.fname;
        this->fprice = copyFruit.fprice;
        this->fquantity = copyFruit.fquantity;
        std::cout << "copied!";
    }

    //copy assignment operator
    Fruit& operator=(const Fruit &otherFruit) {
        if (this == &otherFruit) {
            return *this;
        }
        this->fname = otherFruit.fname;
        this->fprice = otherFruit.fprice;
        this->fquantity = otherFruit.fquantity;
        std::cout << "rewritten!";
        return *this;
    }

    //to be able to print out the private variables
    std::string getfName() const {
        return fname;
    }
    float getfPrice() const {
        return fprice;
    }
    int getfQuantity() const {
        return fquantity;
    }

    //get the subtotal of the items
    float subfSum() const {
        return fprice * fquantity;
    }
};

// to access the private variables, use the getter functions at the very bottom
// to get the subtotal, use the subvSum function
class Veggy {
private:
    std::string vname;
    float vprice = 0;
    int vquantity = 0;

public:

    //constructor
    Veggy (std::string defName = "", float defPrice = 0, int defQuantity = 0) {
        this->vname = defName;
        this->vprice = defPrice;
        this->vquantity = defQuantity;
        std::cout << "constructed!\n";
    }

    //deconstructor
    ~Veggy() {
        std::cout << "deconstructed!\n";
    }

    //copy constructor
    Veggy (const Veggy &copyVeggy) {
        this->vname = copyVeggy.vname;
        this->vprice = copyVeggy.vprice;
        this->vquantity = copyVeggy.vquantity;
        std::cout << "copied!\n";
    }

    //copy assignment operator
    Veggy& operator=(const Veggy &otherVeggy) {
        if (this == &otherVeggy) {
            return *this;
        }
        this->vname = otherVeggy.vname;
        this->vprice = otherVeggy.vprice;
        this->vquantity = otherVeggy.vquantity;
        std::cout << "rewritten!\n";
        return *this;
    }

    //to be able to print out the private variables
    std::string getvName() const {
        return vname;
    }
    float getvPrice() const {
        return vprice;
    }
    int getvQuantity() const {
        return vquantity;
    }

    //get the subtotal of the items
    float subvSum() const {
        return vprice * vquantity;
    }
};


//distinguishing if it's a fruit or a vegetable
class itemType {
public:
    bool isFruit;
    Fruit fItem;
    Veggy vItem;

    itemType (Fruit f) : fItem(f), vItem(), isFruit(true) {}
    itemType (Veggy v) : fItem(), vItem(v), isFruit(false) {}

};

float TotalSum(itemType* list[], int s) {
    float total = 0;
    for (int i = 0 ; i < s ; i++) {
        if (list[i] != nullptr) {
            if (list[i]->isFruit) {
                total += list[i]->fItem.subfSum();
            }
            else {
                total += list[i]->vItem.subvSum();
            }
        }
    }
    return total;
}

int searchIndex(std::string name, itemType* list[], int s) {
    for (int i = 0 ; i < s ; i++) {
        if (list[i] != nullptr) {
            if (list[i]->isFruit) {
                if (list[i]->fItem.getfName() == name) {
                    return i;
                }
            }
            else {
                if (list[i]->vItem.getvName() == name) {
                    return i;
                }
            }
        }
    }
}

int main() {

    const size_t s = 4;
    itemType* GroceryList[s];

    GroceryList[0] = new itemType(Fruit("Apple", 10, 7));
    GroceryList[1] = new itemType(Fruit("Banana", 10, 8));
    GroceryList[2] = new itemType(Veggy("Broccoli", 60, 12));
    GroceryList[3] = new itemType(Veggy("Lettuce", 50, 10));

    std::cout << "\n\n Grocery list \n";
    for (int i = 0 ; i < s ; i++) {
        if (GroceryList[i] != nullptr) {
            if (GroceryList[i]->isFruit) { 
                std::cout << "Fruit: " << GroceryList[i]->fItem.getfName() << ": PHP ";
                std::cout << GroceryList[i]->fItem.getfPrice() << "qty. ";
                std::cout << GroceryList[i]->fItem.getfQuantity() << " = PHP ";
                std::cout << GroceryList[i]->fItem.subfSum() << "\n";
            }
            else {
                std::cout << "Veg: " << GroceryList[i]->vItem.getvName() << ": PHP ";
                std::cout << GroceryList[i]->vItem.getvPrice() << "qty. ";
                std::cout << GroceryList[i]->vItem.getvQuantity() << " = PHP ";
                std::cout << GroceryList[i]->vItem.subvSum() << "\n";
            }
        }

    }

    std::cout << "Total Price: PHP " << TotalSum(GroceryList, s) << "\n";

    //to find lettuce
    std::cout << "\n\n Deleting Lettuce... \n";
    int tempIndex = searchIndex("Lettuce", GroceryList, s);
    delete GroceryList[tempIndex];
    GroceryList[tempIndex] = nullptr;

    std::cout << "\n\n Grocery list \n";
    for (int i = 0 ; i < s ; i++) {
        if (GroceryList[i] != nullptr) {
            if (GroceryList[i]->isFruit) {
                std::cout << "Fruit: " << GroceryList[i]->fItem.getfName() << ": PHP ";
                std::cout << GroceryList[i]->fItem.getfPrice() << "qty. ";
                std::cout << GroceryList[i]->fItem.getfQuantity() << " = PHP ";
                std::cout << GroceryList[i]->fItem.subfSum() << "\n";
            }
            else {
                std::cout << "Veg: " << GroceryList[i]->vItem.getvName() << ": PHP ";
                std::cout << GroceryList[i]->vItem.getvPrice() << "qty. ";
                std::cout << GroceryList[i]->vItem.getvQuantity() << " = PHP ";
                std::cout << GroceryList[i]->vItem.subvSum() << "\n";
            }
        }

    }

    std::cout << "\n Updated Total Price: PHP " << TotalSum(GroceryList, s) << "\n";
    for (int i = 0 ; i < s ; i++) {
        if (GroceryList[i] != nullptr) {
            delete GroceryList[i];
            GroceryList[i] = nullptr;
        }
    }

    return 0;
}