#ifndef Vector_h__
#define Vector_h__

class Vect {
    public:
        Vect() {
            x = y = 0;
        }

        Vect(const double x, const double y) {
            this->x = x;
            this->y = y;
        }

        ~Vect() {

        }

        double getLength();

        void add (Vect *V);

        void sub (Vect *V);

        double mult (Vect *V);

        void setX(const double x);

        void setY(const double y);

        double getX();

        double getY();

        void operator +(Vect V);

        void operator -(Vect V);

        double operator *(Vect V);

    private:
        double x, y;
};
#endif
