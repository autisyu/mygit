#include<iostream>
using namespace std;
struct list_head {
    struct list_head *next, *prev;
};
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE*)0)->MEMBER)
#define container_of(ptr, type, member) ({         \
         const typeof(((type*)0)->member)* __mptr = (ptr);   \
	 (type*)((char*)__mptr - offsetof(type, member));})
static inline void INIT_LIST_HEAD(struct list_head *list) 
{

}
struct eaxmple {
    int d;
    struct list_head list;
    int a, b, c;
    int z;
    eaxmple() {
    a = b = c =10;
    z = 100;
    list.next = list.prev = 0;
    }
};
int main()
{
    int x = 4;
    //typeof(&x) m;
    //cout<<((size_t)&((struct eaxmple*)0)->c)<<endl;
    struct eaxmple* eax = new eaxmple();
    //cout<<eax->a<<endl;
    struct list_head* lists = &(eax->list);
    //cout<<offsetof(struct eaxmple, list)<<endl;
    cout<<container_of(lists, struct eaxmple, list)->z<<endl;
    cout<<container_of(lists, struct eaxmple, list)<<endl;
    cout<<lists<<endl;
    return 0;
}
