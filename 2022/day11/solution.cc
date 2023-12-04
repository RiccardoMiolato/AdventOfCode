#include <iostream>
#include "monkey.h"

using namespace std;

int main(){
    int dim, divisor = 1;
    bool test = false;

    if(test) dim = 4;
    else dim = 8;

    monkey *m[dim];

    if(test){
        init(m[0], 0, 23);
        init(m[1], 1, 19);
        init(m[2], 2, 13);
        init(m[3], 3, 17);

        m[0]->true_test = m[2];
        m[0]->false_test = m[3];
        
        m[1]->true_test = m[2];
        m[1]->false_test = m[0];
        
        m[2]->true_test = m[1];
        m[2]->false_test = m[3];
        
        m[3]->true_test = m[0];
        m[3]->false_test = m[1];

        cout << "Item assignation..." << endl;
        add_item(m[0]->items, 79);
        add_item(m[0]->items, 98);
        

        add_item(m[1]->items, 54);
        add_item(m[1]->items, 65);
        add_item(m[1]->items, 75);
        add_item(m[1]->items, 74);

        add_item(m[2]->items, 79);
        add_item(m[2]->items, 60);
        add_item(m[2]->items, 97);
        
        add_item(m[3]->items, 74);
    }else{
        init(m[0], 0, 19);
        init(m[1], 1, 7);
        init(m[2], 2, 17);
        init(m[3], 3, 13);
        init(m[4], 4, 11);
        init(m[5], 5, 2);
        init(m[6], 6, 5);
        init(m[7], 7, 3);

        m[0]->true_test = m[5];
        m[0]->false_test = m[6];
        
        m[1]->true_test = m[5];
        m[1]->false_test = m[0];
        
        m[2]->true_test = m[1];
        m[2]->false_test = m[0];
        
        m[3]->true_test = m[1];
        m[3]->false_test = m[2];

        m[4]->true_test = m[3];
        m[4]->false_test = m[7];

        m[5]->true_test = m[4];
        m[5]->false_test = m[6];

        m[6]->true_test = m[4];
        m[6]->false_test = m[7];

        m[7]->true_test = m[2];
        m[7]->false_test = m[3];

        cout << "Item assignation..." << endl;
        add_item(m[0]->items, 72);
        add_item(m[0]->items, 97);
        

        add_item(m[1]->items, 55);
        add_item(m[1]->items, 70);
        add_item(m[1]->items, 90);
        add_item(m[1]->items, 74);
        add_item(m[1]->items, 95);

        add_item(m[2]->items, 74);
        add_item(m[2]->items, 97);
        add_item(m[2]->items, 66);
        add_item(m[2]->items, 57);
        
        add_item(m[3]->items, 86);
        add_item(m[3]->items, 54);
        add_item(m[3]->items, 53);

        add_item(m[4]->items, 50);
        add_item(m[4]->items, 65);
        add_item(m[4]->items, 78);
        add_item(m[4]->items, 50);
        add_item(m[4]->items, 62);
        add_item(m[4]->items, 99);

        add_item(m[5]->items, 90);

        add_item(m[6]->items, 88);
        add_item(m[6]->items, 92);
        add_item(m[6]->items, 63);
        add_item(m[6]->items, 94);
        add_item(m[6]->items, 96);
        add_item(m[6]->items, 82);
        add_item(m[6]->items, 53);
        add_item(m[6]->items, 53);

        add_item(m[7]->items, 70);
        add_item(m[7]->items, 60);
        add_item(m[7]->items, 71);
        add_item(m[7]->items, 69);
        add_item(m[7]->items, 77);
        add_item(m[7]->items, 70);
        add_item(m[7]->items, 98);
    }
    
    cout << "After assignation: " << endl;
    for(int i = 0; i < dim; i++){
        divisor *= m[i]->test;
        print_items(m[i]);
    }
    cout << endl;
    
    for(int i = 0; i < 10000; i++){
        for(int i = 0; i < dim; i++)
            if(test)
                process_items_test(m[i], divisor);
            else
                process_items_puzzle(m[i], divisor);

        
        if(i == 19 || (i + 1) % 1000 == 0){
            cout << "Round " << i + 1 << endl;
            for(int i = 0; i < dim; i++)
                print_items(m[i]);
            
            cout << endl;
        }
    }

    long long int max1 = 0, max2 = 0;

    for(int i = 0; i < dim; i++)
        if(m[i]->items_processed >= max1){
            max2 = max1;
            max1 = m[i]->items_processed;
        }else if(m[i]->items_processed >= max2)
            max2 = m[i]->items_processed;

    long long int res = max1 * max2;
    cout << "Monkey business: " << res << endl;

    return 0;
}