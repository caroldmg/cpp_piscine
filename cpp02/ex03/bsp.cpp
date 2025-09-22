#include "Point.hpp"

// area de un triangulo: area = (base x altura) /2
// desde llos tres vértices: 
// Para calcular el área de un triángulo desde los tres vértices (x₁, y₁), (x₂, y₂) y (x₃, y₃),
// A = (x₁ (y₂ - y₃) + x₂ (y₃ - y₁) + x₃ (y₁ - y₂) ) / 2

float calculateArea(Point const a, Point const b, Point const c)
{
	Fixed area;
	Fixed a1;
	Fixed b1;
	Fixed c1;
	float result;

	a1 = a.getX() * (b.getY() - c.getY()); // x₁ (y₂ - y₃)
	b1 = b.getX() * (c.getY() - a.getY()); // x₂ (y₃ - y₁)
	c1 = c.getX() * (a.getY() - b.getY()); // x₃ (y₁ - y₂)
	area =  (a1+ b1 + c1);
	if (area < 0)
		area = area * (-1);
	area = area / 2;
	result = area.toFloat();
	return (result);
}

/**
 *  a, b, c: The vertices of our beloved triangle.
 * point: The point to check.
 * Returns: True if the point is inside the triangle. False otherwise.
 * Thus, if the point is a vertex or on an edge, it will return False.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// primero teng que conseguir el área del triangulo con esas coordenadas
	// luego tengo que calcular el área de los "subtriangulos" con vertices de dos de estos vértices + el punto a buscar
	// si la suma de estas áreas es mayor que el área del triangulo original, está fuera
	// si uno de estos tiene área = 0, está en un borde asi que no válido
	float areaABC;
	float areaPBC;
	float areaAPC;
	float areaABP;
	float sum;

	areaABC = calculateArea(a, b, c);
	areaPBC = calculateArea(point, b, c);
	areaAPC = calculateArea(a, point, c);
	areaABP = calculateArea(a, b, point);
	sum = areaABP + areaAPC + areaPBC;
	if (sum > areaABC)
		return (false);
	if (roundf(areaPBC) == 0 || roundf(areaAPC) == 0 || roundf(areaABP) == 0)
		return (false);
	return (true);
}