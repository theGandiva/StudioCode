#include <iostream>

using namespace std;
struct linked_list
{
    int data = 10;
    linked_list *next = nullptr;
};

int main()
{
    linked_list ll[3];

    linked_list *head = &ll[0];

    for (int i = 0; i < 2; ++i)
    {
        ll[i].next = &ll[i + 1];
    }

    linked_list *iterate = head;
    while (iterate != nullptr)
    {
        cout << (iterate->data) << endl;
        iterate = iterate->next;
    };

    return 0;
}