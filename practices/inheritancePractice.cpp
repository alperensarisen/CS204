#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class Item{
    public:
        Item(int _id, int _pr, string _cl):id(_id),price(_pr),color(_cl){}
        virtual ~Item(){}

        int getId() const{return id;}
        int getPrice() const{return price;}
        string getColor() const{return color;}

        virtual void print() const = 0;
        virtual Item* clone() const = 0;            //! Polymorph'c copy
    protected:
        int id;
        int price;
        string color;
};

class Jacket: public Item{
    public:
        Jacket(int _id, int _pr, string _cl, int s, const char *str):Item(_id,_pr,_cl){
            brand = new char[strlen(str) + 1];
            strcpy(brand, str);
        }
        ~Jacket() override{delete[]brand;}
        //Copy ctor
        Jacket(const Jacket & other):Item(other.id,other.price,other.color),size(other.size){
            brand = new char[strlen(other.brand) + 1];
            strcpy(brand, other.brand);
        }
        //Copy assignment
        Jacket& operator=(const Jacket& rhs){
            if(this == &rhs) return *this;
            id = rhs.id;
            price = rhs.price;
            color = rhs.color;
            size = rhs.size;
            delete [] brand;
            brand = new char[strlen(rhs.brand) + 1];
            strcpy(brand, rhs.brand);
            return *this;
        }
        void print() const override{
            cout << "[Jacket] id=" << id
             << " price=" << price
             << " color=" << color
             << " size=" << size
             << " brand=" << brand << "\n";
        }
            Item* clone() const override{
                return new Jacket(*this);   //uses copy ctor
            }

    protected:
        int size;
        char *brand;
};
class CandyBox: public Item{
    public:
        CandyBox(int _id, int _pr, string _cl, int gr, const char* str):Item(_id,_pr,_cl),grams(gr){
            label = new char[strlen(str) + 1];
            strcpy(label, str);
        }
        ~CandyBox() override{delete [] label;}
        CandyBox(const CandyBox & other):Item(other.id, other.price, other.color),grams(other.grams){
            label = new char[strlen(other.label) + 1];
            strcpy(label, other.label);
        }
        CandyBox& operator=(const CandyBox& rhs){
            if(this == &rhs) return *this;
            id = rhs.id;
            price = rhs.price;
            color = rhs.color;
            grams = rhs.grams;
            delete [] label;
            label = new char[strlen(rhs.label) + 1];
            strcpy(label, rhs.label);
            return *this;
        }
        void print() const override{
            cout << "[CandyBox] id=" << id
             << " price=" << price
             << " color=" << color
             << " grams=" << grams
             << " label=" << label << "\n";
        }
        Item* clone() const override{
            return new CandyBox(*this);
        }
    protected:
        int grams;
        char *label;
};
class Inventory{
    public:
        ~Inventory(){clear();}
        void add(const Item & item){
            items.push_back(item.clone());
        }
        void list() const{
            if(items.empty()) cout<<"Inventory is empty!\n";
            for(auto p: items)
                p->print();
        }
        void removeById(int id){
            for(int i = 0; i<items.size();i++){
                if(items[i]->getId() == id){
                    delete items[i];
                    items.erase(items.begin() + i);
                    break;
                }
            }
        }
        void clear() {
            for (auto p : items) delete p;
            items.clear();
        }

    private:
        vector<Item*> items;
};
int main() {
    Inventory inv;

    Jacket j1(101, 200.0, "Black", 42, "LV");
    CandyBox c1(201, 50.0, "Red", 250, "Chocolate Box");

    inv.add(j1);
    inv.add(c1);

    inv.list();

    cout << "Removing id=101...\n";
    inv.removeById(101);
    inv.list();
}