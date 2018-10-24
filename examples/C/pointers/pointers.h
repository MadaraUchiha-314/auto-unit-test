/*
* This will have all the scenarios regarding functions which take, manipulate and return pointers.
*/
/*
* Lets define a person
*/
struct Person {
    int age;
    int weight;
};

/*
* Function which take a pointer.
*/
int getRank(struct Person* p) {
    return p->age * p->weight;
}
