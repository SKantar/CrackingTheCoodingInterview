/**
*   Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
*   out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
*   or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
*   that type). They cannot select which specific animal they would like. Create the data structures to
*   maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
*   and dequeueCat. You may use the built-in Linked list data structure.
**/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAXN 50

using namespace std;

enum Type{ DOG, CAT };

typedef struct Animal{
    string name;
    int rank;

    bool operator >(const Animal &a){
        return rank > a.rank;
    }

}Animal;

typedef struct Queue{

    int rank = 0;

    queue<Animal> dog;
    queue<Animal> cat;

    void push(string name, Type t){
        Animal a;
        a.name = name;
        a.rank = rank++;
        if(t == CAT)
            cat.push(a);
        else
            dog.push(a);
    }

    string pop_any(){
        Animal a;
        char res[MAXN];
        if(dog.front() > cat.front()){
            a = dog.front();
            dog.pop();
        } else {
            a = cat.front();
            cat.pop();
        }
        return a.name;
    }

    string pop_cat(){
        Animal a = cat.front();
        cat.pop();
        return a.name;
    }

    string pop_dog(){
        Animal a = dog.front();
        dog.pop();
        return a.name;
    }
}Queue;

int main(){
    Queue Q;
    Q.push("American Bobtail", CAT);
    Q.push("Devon Rex", CAT);
    Q.push("Korat", CAT);
    Q.push("Oriental", CAT);

    Q.push("Airedale Terrier", DOG);
    Q.push("Belgian Malinois", DOG);
    Q.push("Berger Picard", DOG);
    Q.push("Bulldog", DOG);

    cout << Q.pop_any() << "\n";
    cout << Q.pop_any() << "\n";
    cout << Q.pop_cat() << "\n";

    return 0;

}
