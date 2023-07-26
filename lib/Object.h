#ifndef TRANSPORTCOMPANY_OBJECT_H
#define TRANSPORTCOMPANY_OBJECT_H


class Object {
protected:
    Object() {}
    virtual ~Object() = default;

public:
    Object* clone() {
        return this;
    }
};


#endif //TRANSPORTCOMPANY_OBJECT_H
