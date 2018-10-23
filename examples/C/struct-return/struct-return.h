/*
* Lets define a person
*/
struct Person {
    int age;
    int weight;
};

struct Person getPerson(age, weight) {
    struct Person p;
    p.age = age;
    p.weight = weight;
    return p;
}
