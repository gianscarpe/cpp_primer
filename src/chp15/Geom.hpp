#ifndef GEOM_HPP
#define GEOM_HPP

class Figure{
public:
  Figure(int _n) : n_dimension(_n) {};

protected:
  int n_dimension;
};

class Point: public Figure{
  friend Point operator+ (const Point& lhs, const Point& rhs);
  friend  Point operator- (const Point& lhs, const Point & rhs);
  
public:  
  Point() : Figure(0) {};
  Point &operator+= (Point & rhs);

  Point &operator-= (Point & rhs);

  double value;
};

class Segment: public Figure{
public:
  Segment() : Figure(1) {};
  double get_length() { return (end - start).value; };

protected:
  Point start;
  Point end;
};

class PlaneFigure: public Figure{
public:
  PlaneFigure() : Figure(2) {};
  virtual double get_area();
  virtual double get_perimeter();
};

class Rectangle: public PlaneFigure{
public:
  Rectangle(double up_length, double down_length) : PlaneFigure(),
						    height(up_length), base(down_length){};
  double get_area() override {return 1.0;};
  double get_perimeter() override {return 1.0;};
private:

  double height;
  double base;
};

class Square: public Rectangle{
public:
  Square(double length) : Rectangle(length, length) {};
};

class Solid : public Figure{
  friend class PlaneFigure;
  Solid() : Figure(3) {};
};


#endif
