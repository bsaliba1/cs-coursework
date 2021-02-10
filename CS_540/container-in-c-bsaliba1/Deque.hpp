#define Deque_DEFINE(t)

struct MyClass
{
    int id;
    char name[10];
};

struct Deque_MyClass;

struct MyClass dummy = {-9999, "Invalid"};

//ITERATOR
struct Deque_MyClass_Iterator
{
    Deque_MyClass *deq;
    size_t start;
    size_t end;
    size_t index;

    void (*inc)(Deque_MyClass_Iterator *);
    void (*dec)(Deque_MyClass_Iterator *);
    MyClass &(*deref)(Deque_MyClass_Iterator *);
};
void iterator_ctor(Deque_MyClass_Iterator *it);

//DEQUE
struct Deque_MyClass
{

    //Data Members
    char type_name[sizeof("Deque_MyClass")] = "Deque_MyClass";
    MyClass *data = (MyClass *)malloc(10 * sizeof(MyClass));
    size_t max_elements = 10;
    size_t num_elements;
    size_t front_index;
    size_t back_index;

    //Function prototypes
    bool (*idLess)(const MyClass &, const MyClass &);
    size_t (*size)(Deque_MyClass *);
    bool (*empty)(Deque_MyClass *);
    void (*push_back)(Deque_MyClass *, MyClass obj);
    void (*push_front)(Deque_MyClass *, MyClass obj);
    MyClass &(*front)(Deque_MyClass *);
    MyClass &(*back)(Deque_MyClass *);
    void (*pop_back)(Deque_MyClass *deq);
    void (*pop_front)(Deque_MyClass *deq);

    Deque_MyClass_Iterator &(*begin)(Deque_MyClass *);
    Deque_MyClass_Iterator &(*end)(Deque_MyClass *);

    MyClass &(*at)(Deque_MyClass *, size_t i);
    void (*clear)(Deque_MyClass *);
    void (*dtor)(Deque_MyClass *);
};

//Deque Functions;

size_t Deque_MyClass_size(Deque_MyClass *deq)
{
    return deq->num_elements;
}

bool Deque_MyClass_empty(Deque_MyClass *deq)
{
    if (deq->num_elements != 0)
    {
        return false;
    }
    return true;
}

MyClass &Deque_MyClass_front(Deque_MyClass *deq)
{
    return deq->data[deq->front_index];
}

MyClass &Deque_MyClass_back(Deque_MyClass *deq)
{
    return deq->data[deq->back_index];
}

void resize_Deque(Deque_MyClass *deq)
{
    if (deq->num_elements + 1 == deq->max_elements)
    {
        MyClass *temp = (MyClass *)realloc(deq->data, sizeof(MyClass) * deq->max_elements * 2);
        deq->data = temp;

        if (deq->front_index > deq->back_index)
        {
            int num_to_change = deq->max_elements - deq->front_index;
            for (int i = num_to_change; i > 0; i--)
            {
                deq->data[deq->max_elements * 2 - i] = deq->data[deq->max_elements - i];
            }
            deq->front_index = deq->max_elements * 2 - num_to_change;
        }
        deq->max_elements *= 2;
    }
}

void init_empty(Deque_MyClass *deq, MyClass obj)
{
    deq->data[0] = obj;
    deq->front_index = 0;
    deq->back_index = 0;
    deq->num_elements++;
}

//PUSH
void Deque_MyClass_push_back(Deque_MyClass *deq, MyClass obj)
{
    resize_Deque(deq);

    if (deq->empty(deq))
    {
        init_empty(deq, obj);
    }
    else
    {
        deq->back_index++;
        if (deq->back_index == deq->max_elements)
        {
            deq->back_index = 0;
        }
        deq->data[deq->back_index] = obj;
        deq->num_elements++;
    }
}
void Deque_MyClass_push_front(Deque_MyClass *deq, MyClass obj)
{
    resize_Deque(deq);

    if (deq->empty(deq))
    {
        init_empty(deq, obj);
    }
    else
    {
        if (deq->front_index == 0)
        {
            deq->front_index = deq->max_elements - 1;
        }
        else
        {
            deq->front_index--;
        }
        deq->data[deq->front_index] = obj;
        deq->num_elements++;
    }
}

//POP
void Deque_MyClass_pop_front(Deque_MyClass *deq)
{
    if (deq->empty(deq))
    {
        return;
    }

    deq->data[deq->front_index] = dummy;
    if (deq->front_index == deq->max_elements - 1)
    {
        deq->front_index = 0;
    }
    else
    {
        deq->front_index++;
    }
    deq->num_elements--;
}
void Deque_MyClass_pop_back(Deque_MyClass *deq)
{
    if (deq->empty(deq))
    {
        return;
    }

    deq->data[deq->back_index] = dummy;
    if (deq->back_index == 0)
    {
        deq->back_index = deq->max_elements - 1;
    }
    else
    {
        deq->back_index--;
    }
    deq->num_elements--;
}

Deque_MyClass_Iterator &Deque_MyClass_begin(Deque_MyClass *deq)
{
    static Deque_MyClass_Iterator retIt;
    retIt.index = deq->front_index;
    retIt.start = deq->front_index;
    retIt.end = deq->back_index + 1;
    retIt.deq = deq;
    iterator_ctor(&retIt);
    return retIt;
}

Deque_MyClass_Iterator &Deque_MyClass_end(Deque_MyClass *deq)
{
    static Deque_MyClass_Iterator retIt;
    retIt.index = deq->back_index + 1;
    retIt.start = deq->front_index;
    retIt.end = deq->back_index + 1;
    retIt.deq = deq;
    iterator_ctor(&retIt);
    return retIt;
}

MyClass &Deque_MyClass_at(Deque_MyClass *deq, size_t i)
{
    size_t ind = (deq->front_index + i) % deq->max_elements;
    if (deq->back_index > deq->front_index)
    {
        if (ind > deq->back_index || ind < deq->front_index)
        {
            throw;
        }
    }
    else
    {
        if (ind > deq->back_index && ind < deq->front_index)
        {
            throw;
        }
    }
    return deq->data[ind];
}

void Deque_MyClass_clear(Deque_MyClass *deq)
{
    memset(deq->data, 0, sizeof(MyClass) * deq->max_elements);
    deq->front_index = 0;
    deq->back_index = 0;
    deq->num_elements = 0;
    deq->max_elements = 10;
    MyClass *temp = (MyClass *)realloc(deq->data, sizeof(MyClass) * deq->max_elements);
    deq->data = temp;
}

void Deque_MyClass_dtor(Deque_MyClass *deq)
{
    free(deq->data);
}

bool Deque_MyClass_equal(Deque_MyClass *deq1, Deque_MyClass *deq2)
{
    bool retBool = false;
    if(deq1->num_elements == deq2->num_elements){
        for()
    }
    return retBool;
}

void Deque_MyClass_ctor(Deque_MyClass *deq, bool idLess(const MyClass &, const MyClass &))
{
    deq->idLess = idLess;
    deq->num_elements = 0;
    deq->front_index = 0;
    deq->back_index = 0;
    deq->size = Deque_MyClass_size;
    deq->empty = Deque_MyClass_empty;
    deq->push_back = Deque_MyClass_push_back;
    deq->push_front = Deque_MyClass_push_front;
    deq->front = Deque_MyClass_front;
    deq->back = Deque_MyClass_back;
    deq->pop_back = Deque_MyClass_pop_back;
    deq->pop_front = Deque_MyClass_pop_front;
    deq->begin = Deque_MyClass_begin;
    deq->end = Deque_MyClass_end;
    deq->at = Deque_MyClass_at;
    deq->clear = Deque_MyClass_clear;
    deq->dtor = Deque_MyClass_dtor;
}

//------------------------------------------
//Iterator Functions

bool Deque_MyClass_Iterator_equal(Deque_MyClass_Iterator i1, Deque_MyClass_Iterator i2)
{
    if (i1.index == i2.index && i1.start == i2.start && i1.end == i2.end && i1.deq == i2.deq)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Deque_MyClass_Iterator_inc(Deque_MyClass_Iterator *it)
{
    if (it->index != it->end)
    {
        if (it->index == it->deq->max_elements - 1)
        {
            it->index = 0;
        }
        else
        {
            it->index++;
        }
    }
}

void Deque_MyClass_Iterator_dec(Deque_MyClass_Iterator *it)
{
    if (it->index != it->start)
    {
        if (it->index == 0)
        {
            it->index = it->deq->max_elements - 1;
        }
        else
        {
            it->index--;
        }
    }
}

MyClass &Deque_MyClass_Iterator_deref(Deque_MyClass_Iterator *it)
{
    if (it->index == it->end)
    {
        throw;
    }
    return it->deq->data[it->index];
}
void iterator_ctor(Deque_MyClass_Iterator *it)
{
    it->inc = Deque_MyClass_Iterator_inc;
    it->dec = Deque_MyClass_Iterator_dec;
    it->deref = Deque_MyClass_Iterator_deref;
}