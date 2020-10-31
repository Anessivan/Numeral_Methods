#pragma once



#include <iostream>
#include <cmath>

double* EulerMethod(const double left, const double right, const double y0, const double power, const double dx)
{
  int length = floor((abs(right - left)) / dx) + 1;  // Вычисление количества элементов массива
  double* data = nullptr;
  data = new double[length];
  data[0] = y0;
  for (int i = 1; i < length; i++)
  {
    data[i] = data[i - 1] + data[i - 1] * power * dx * dx * i; // x(t) * (1 + x'(t)*eps)
  }
  return data;
}

double* RungeKutta(const double left, const double right, const double y0, const double power, const double dx)
{
  int length = floor((abs(right - left)) / dx) + 1;
  double* data = new double[length];
  double k1 = y0, k2 = y0, k3 = y0, k4 = y0;
  data[0] = y0;
  double x = y0;
  int i = 0;
  for (int i = 0; i < length - 1; i++)
  {
    k1 = power * data[i];
    k2 = power *(data[i] + dx * k1 / 2.0 );
    k3 = power * (data[i] + dx * k2 / 2.0 );
    k4 = power * (data[i] + dx * k3);
    data[i + 1] = data[i] + (dx / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
  }
  return data;
}