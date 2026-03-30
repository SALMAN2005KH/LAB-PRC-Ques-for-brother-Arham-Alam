#include <iostream>
#include <string>
using namespace std;

class Product 
{
    private :
    const int prodId;
    string prodName;
    float price;
    static int totalProd;

    public : 
    Product(int id, string name, float p) : prodId(id), prodName(name), price(p) {
        totalProd++;
    }
    float getPrice() const {
        return price;
    }
    ~Product() {
        cout << "Product Expired." << endl;
    }
    void displayProduct() const{
        cout << "\n____Product Details____\n";
        cout << "Product Name : " << prodName << endl;
        cout << "Product ID : " << prodId << endl;
        cout << "Product Price : " << price << endl;
    }
    static void displaytotalProducts() {
        cout << "\nTotal products : " << totalProd << endl;
    }
};
int Product :: totalProd = 0;

class Cart 
{
    private :
    Product products[6];

    public :
    Cart() : products{
        Product(1, "Laptop", 120000),
        Product(2, "Mobile", 50000),
        Product(3, "Headphones", 5000),
        Product(4, "Keyboard", 3000),
        Product(5, "Mouse", 1500),
        Product(6, "Monitor", 25000)
    } {}

    ~Cart () {
        cout << "Cart Removed Successfully." << endl;
    }

    void displayAll() const {
        cout << "\n--- Cart Products ---\n";
        for(int i = 0; i < 6; i++) {
            products[i].displayProduct();
        }
    }

    void displayTotalBill() {
        float totalBill = 0;
        for (int i = 0; i < 6; i++)
        {
            totalBill += products[i].getPrice();
        }
        
    }
    void showExpensiveProduct() const {
        int maxIndex = 0;

        for(int i = 1; i < 6; i++) {
            if(products[i].getPrice() > products[maxIndex].getPrice()) {
                maxIndex = i;
            }
        }

        cout << "\n--- Most Expensive Product ---\n";
        products[maxIndex].displayProduct();
    }
};

int main() {
    Cart c;
    c.displayAll();
    c.displayTotalBill();
    c.showExpensiveProduct();

    Product :: displaytotalProducts();
return 0;
}