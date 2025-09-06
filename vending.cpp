#include <iostream>
using namespace std;

class Vending {
    private:
        int amount_of_chips {0};
        int cost_of_chips {1};
        int amount_of_water {0};
        int cost_of_water {2};
        int total_transactions {0};
        int total_money {0};

    public: 
        int restock() {
            int money_before = total_money;
            amount_of_chips = 20;
            amount_of_water = 20;
            total_transactions = 0;
            total_money = 0;
            return money_before;
        }

        int vend_chips(int amount) {
            int cost = amount * cost_of_chips;
            cout << "Bought " << amount << " chips for $" << cost << endl; 
            total_transactions++;
            amount_of_chips -= amount;
            total_money += cost;
            return cost;
        }

        int vend_water(int amount) {
            int cost = amount * cost_of_water;
            cout << "Bought " << amount << " water bottles for $" << cost << endl; 
            total_transactions++;
            amount_of_water -= amount;
            total_money += cost;
            return cost;
        }

        void print_data() {
            cout << "\n-------Vending Machine Stats------"<<endl<<endl;
            cout << "Item      Amount Remaining   Value"<<endl;
            cout << "----------------------------------"<<endl;
            cout << "Chips       "<<amount_of_chips<<"                $"<< amount_of_chips*cost_of_chips<<endl;
            cout << "Water       "<<amount_of_water<<"                $"<< amount_of_water*cost_of_water<<endl;
            cout << "----------------------------------"<<endl;
            cout << "Total transactions = " << total_transactions <<endl;
            cout << "Total money collected = $" << total_money <<endl<<endl;
        }
};

int main() {
    Vending machine;
    machine.restock();
    cout << "Created a Vending machine" << endl;
    machine.vend_chips(3);
    machine.vend_water(2);
    machine.vend_chips(4);
    machine.vend_water(1);
    machine.print_data();
    cout << "Restocked machine and $" << machine.restock() << " was inside!" <<endl;
}