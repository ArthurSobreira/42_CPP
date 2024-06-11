#include "Point.hpp"
#include "Fixed.hpp"

static Fixed	getArea( Point const a, Point const b, Point const c ) {
	Fixed area = 0;

	area = area + (a.getX() * (b.getY() - c.getY()));
	area = area + (b.getX() * (c.getY() - a.getY()));
	area = area + (c.getX() * (a.getY() - b.getY()));
	area = area / 2;
	if (area < 0) {
		area = area * -1;
	}
	return (area);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed const abc = getArea(a, b, c);
	Fixed const abp = getArea(a, b, point);
	Fixed const bcp = getArea(b, c, point);
	Fixed const cap = getArea(c, a, point);

	if (abp == 0 || bcp == 0 || cap == 0) {
		return (false);
	}
	return (abc == abp + bcp + cap);
}
