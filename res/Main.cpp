#include <iostream>
#include <fstream>



#include "Methods.h"



void Print(double* data, int length)
{
  for (int i = 0; i < length; i++)
    std::cout << std::endl << data[i];
}

void FPrint(double* data, int length, std::ofstream& out, double power, double left, double right, double dx)
{
  if (out.is_open())
  {
    out << " (" << left << "; " << right << ")  power = " << power << "  dx = " << dx;
    for (int i = 0; i < length; i++)
      out << std::endl << data[i];
  }
  out.close();
}

double* Error(double* methoddata, int length, double power, double left, double right, double dx)
{
  double* ErrorData = new double[length];
  for (int i = 0; i < length; i++)
    ErrorData[i] = abs(exp(power *(left + i * dx)) - methoddata[i]);
  return ErrorData;
}

int main()
{
  double left = 0;
  double right = 2;
  double power = 2;
  double y0 = 1;
  double dx = 0.01;
  double* EulerData = nullptr;
  double* RungeKuttaData = nullptr;
  EulerData = EulerMethod(left, right, y0, power, dx);
  RungeKuttaData = RungeKutta(left, right, y0, power, dx);
  int length = floor((abs(right - left)) / dx) + 1;
  double* ErrorEuler = nullptr;
  ErrorEuler = Error(EulerData,length, power, left, right, dx);
  double* ErrorRungeKutta = nullptr;
  ErrorRungeKutta = Error(RungeKuttaData, length, power, left, right, dx);
  std::cout << "Euler Method";
  Print(EulerData, length);
  std::cout << "Runge-Kutta Method";
  Print(RungeKuttaData, length);
  std::ofstream out;
  out.open("..//Euler.txt");
  FPrint(EulerData, length, out, power, left, right, dx);
  out.close();
  out.open("..//Runge-Kutta.txt");
  FPrint(RungeKuttaData, length, out, power, left, right, dx);
  out.close();
  out.open("..//ErrorEuler.txt");
  FPrint(ErrorEuler, length, out, power, left, right, dx);
  out.close();
  out.open("..//ErrorRungeKutta.txt");
  FPrint(ErrorRungeKutta, length, out, power, left, right, dx);
  out.close();
  delete[] ErrorRungeKutta;
  delete[] ErrorEuler;
  delete[] EulerData;
  delete[] RungeKuttaData;
}