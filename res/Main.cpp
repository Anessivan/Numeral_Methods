#include <iostream>
#include <fstream>

#include "Methods.h"
#include <cmath>


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
    ErrorData[i] = fabs(exp(power *(left + i * dx)) - methoddata[i]);
  return ErrorData;
}
int FinalErrorEuler(double left, double right, double y0, double power, double dx)
{
  int length = floor((abs(right - left)) / dx) + 1;
  double* EulerData = EulerMethod(left, right, y0, power, dx);
  double* EulerError = Error(EulerData, length, power, left, right, dx);
  double ErrorFirst = EulerError[1];
  double ErrorLast = EulerError[length - 1];
  if(ErrorLast < ErrorFirst) return 1; // требуется увдичивать шаг
  else if(ErrorLast > ErrorFirst ) return -1; // требуетсяя уменьшить шаг
  delete[] EulerData;
  delete[] EulerError;
  return 0; // Найден необходимый dx
}
double FinddxEuler(double left, double right, double power, double y0)
{
    double dx = 1.0 / 2.0;
    double dxprev = 1.0;
    double dxleft = dx - fabs(dx - dxprev) / 2;
    double dxright = dx + fabs(dx - dxprev)/2;
    double flag = FinalErrorEuler(left, right, y0, power, dx);
    double dxconst = 0;
    while(!dxconst)
    {
        
      std::cout  << flag << std::endl;
      if(flag < 0)
      {
          dxprev = dx;
          dx = dxleft;
      }
      else if(flag > 0)
      {
          dxprev = dx;
          dx = dxright;
      }
      else 
          dxconst = dx;
      dxleft = dx - fabs(dx - dxprev) / 2.0;
      dxright = dx + fabs(dx - dxprev) / 2.0;
      int length = floor((abs(right - left)) / dx) + 1;
      double* EulerData = EulerMethod(left, right, y0, power, dx);
      double* EulerError = Error(EulerData, length, power, left, right, dx);
      double ErrorFirst = EulerError[1];
      double ErrorLast = EulerError[length - 1];
      std::ofstream out;
      out.open("..//doc//ConstError.txt", std::ios::app);
      out << std::endl << " ErrorFirst = " << ErrorFirst << " ErrorLast = " << ErrorLast << " dx: " << dx;
      out.close();
      flag = FinalErrorEuler(left, right, y0, power, dx);
    }
    return dxconst;
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
  out.open("..//doc//Euler.txt");
  FPrint(EulerData, length, out, power, left, right, dx);
  out.close();
  out.open("..//doc//Runge-Kutta.txt");
  FPrint(RungeKuttaData, length, out, power, left, right, dx);
  out.close();
  out.open("..//doc//ErrorEuler.txt");
  FPrint(ErrorEuler, length, out, power, left, right, dx);
  out.close();
  out.open("..//doc//ErrorRungeKutta.txt");
  FPrint(ErrorRungeKutta, length, out, power, left, right, dx);
  out.close();
  delete[] ErrorRungeKutta;
  delete[] ErrorEuler;
  delete[] EulerData;
  delete[] RungeKuttaData;
  
  
  double dxconst = FinddxEuler(left, right, power, y0);
  out.open("..//doc//ConstError.txt");
  out << "dx = " << dxconst;
  out.close();
}
