#ifndef TRANSPORTCOMPANY_OBJECT_H
#define TRANSPORTCOMPANY_OBJECT_H


class Object {
protected:
    Object() {}
    virtual ~Object() = default;

public:
    virtual Object* clone() = 0;
};


#endif //TRANSPORTCOMPANY_OBJECT_H
