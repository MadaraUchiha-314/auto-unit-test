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

struct Person* getPerson(int age, int weight) {
    struct Person* p = (struct Person*) malloc(sizeof(struct Person));
    p->age = age;
    p->weight = weight;
    return p;
}

int modifyInt(int* i) {
    *i += 1;
    return *i;
}

int* getInt(int *i) {
    int* j = (int*) malloc(sizeof(int));
    *j = *i;
    return j;
}
